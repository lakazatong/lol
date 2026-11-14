#include "nasus.hpp"

#include <events/events.hpp>

Nasus::Nasus(World &world) : Champion(world) {
    health = 631.0f;
    shield = 0.0f;

    physical_damage = 67.0f;
    magical_damage = 0.0f;

    physical_resistance = 39.0f;
    magical_resistance = 32.0f;

    critical_strike_chance = 0.0f;
    critical_strike_multiplier = 1.75f;
}

void Nasus::cast_q(Champion &target) { fire(Events::nasus_q(*this, target)); }
