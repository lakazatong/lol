#include <algorithm>
#include <cmath>
#include <stdexcept>
#include <utility>

#include "world.hpp"

void World::fire(Event event, float delay) {
    if (delay < 0.0f || !std::isfinite(delay))
        throw std::invalid_argument(
            "Event delay must be finite and non-negative");

    const float scheduled_time = time + delay;

    if (!std::isfinite(scheduled_time))
        throw std::overflow_error("Scheduled event time overflow");

    ScheduledEvent scheduled{std::move(event), scheduled_time};

    auto it =
        std::upper_bound(event_queue.begin(), event_queue.end(), scheduled.time,
                         [](float time, const ScheduledEvent &queued) {
                             return time < queued.time;
                         });

    event_queue.insert(it, std::move(scheduled));
}

void World::update(float delta_time) {
    if (delta_time < 0.0f || !std::isfinite(delta_time))
        throw std::invalid_argument(
            "Delta time must be finite and non-negative");

    const float target_time = time + delta_time;

    if (!std::isfinite(target_time))
        throw std::overflow_error("World time overflow");

    while (!event_queue.empty() && event_queue.front().time <= target_time)
        step();

    time = target_time;
}

std::optional<Events::Id> World::step() {
    if (event_queue.empty())
        return std::nullopt;

    ScheduledEvent event = std::move(event_queue.front());
    event_queue.erase(event_queue.begin());

    time = std::max(time, event.time);

    EventContext context{*this, *event.source, event.targets};

    Events::Id id = event.id;
    event.process(context);

    return id;
}
