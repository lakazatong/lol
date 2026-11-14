#pragma once

#include "agent.hpp"

#include <effects/effect_pool.hpp>
#include <items/inventory.hpp>

class Champion : public Agent {
  protected:
    explicit Champion(World &world);

  public:
    float health;
    float shield;

    float physical_damage;
    float magical_damage;

    float physical_resistance;
    float magical_resistance;

    float critical_strike_chance;
    float critical_strike_multiplier;

    Inventory inventory{6};
    EffectPool effects;
};
