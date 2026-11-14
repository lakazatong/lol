#include "garen.hpp"

Garen::Garen(World &world) : Champion(world) {
    health = 690.0f;
    shield = 0.0f;

    physical_damage = 69.0f;
    magical_damage = 0.0f;

    physical_resistance = 36.0f;
    magical_resistance = 32.0f;

    critical_strike_chance = 0.0f;
    critical_strike_multiplier = 1.75f;
}
