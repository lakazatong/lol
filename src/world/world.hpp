#pragma once

#include <optional>
#include <vector>

#include <events/event.hpp>

struct ScheduledEvent : Event {
    float time;
};

class World {
  public:
    float time = 0.0f;

    void fire(Event event, float delay = 0.0f);
    void update(float delta_time);
    std::optional<Events::Id> step();

  private:
    std::vector<ScheduledEvent> event_queue;
};
