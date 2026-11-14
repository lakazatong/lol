
#include <iostream>

#include "src/agents/champions/garen.hpp"
#include "src/agents/champions/nasus.hpp"
#include "src/events/events.hpp"
#include "src/items/item.hpp"
#include "src/world/world.hpp"

#include <magic_enum/magic_enum.hpp>

int main() {
    World world;

    Nasus nasus(world);
    Garen garen1(world);
    Garen garen2(world);

    nasus.inventory.add(ItemId::Morellonomicon);

    auto step_and_print = [&]() {
        while (auto id = world.step()) {
            std::cout << "\n[" << world.time << "s] "
                      << magic_enum::enum_name(*id)
                      << "\n  Garen 1 health: " << garen1.health
                      << "\n  Garen 1 Grievous Wounds: "
                      << (garen1.effects.has(EffectId::GrievousWounds)
                              ? "Active"
                              : "Inactive")
                      << "\n  Garen 2 health: " << garen2.health
                      << "\n  Nasus stacks: " << nasus.siphoning_strike_stacks;
        }
    };

    nasus.cast_q(garen1);
    step_and_print();

    world.fire(Events::deal_magic_damage(nasus, garen1, 80.0f));
    world.fire(Events::heal(garen1, garen1, 200.0f), 1.0f);
    world.fire(Events::heal(garen1, garen1, 10.0f), 4.0f);
    step_and_print();

    nasus.cast_q(garen1);
    nasus.cast_q(garen1);
    nasus.cast_q(garen1);
    nasus.cast_q(garen1);
    nasus.cast_q(garen1);
    nasus.cast_q(garen1);
    nasus.cast_q(garen1);
    nasus.cast_q(garen1);
    nasus.cast_q(garen1);
    nasus.cast_q(garen1);
    step_and_print();

    nasus.cast_q(garen2);
    step_and_print();

    return 0;
}
