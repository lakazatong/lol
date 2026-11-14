#include <utility>

#include "agent.hpp"

#include <world/world.hpp>

Agent::Agent(World &world) : world(world) {}

void Agent::fire(Event event, float delay) {
    world.fire(std::move(event), delay);
}
