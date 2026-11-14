#pragma once

#include <events/event.hpp>

class World;

class Agent {
  protected:
    explicit Agent(World &world);

  public:
    World &world;
    bool alive = true;

    virtual ~Agent() = default;

    void fire(Event event, float delay = 0.0f);
};
