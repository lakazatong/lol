#include "events.hpp"

#include <agents/agent.hpp>
#include <agents/champion.hpp>
#include <agents/champions/nasus.hpp>
#include <items/item.hpp>
#include <world/world.hpp>

namespace Events {

Event nasus_q(Agent &source, Agent &target) {
    return {Id::NasusQ, &source, {&target}, [](EventContext &ctx) {
                auto &nasus = dynamic_cast<Nasus &>(ctx.source);
                auto &target = dynamic_cast<Champion &>(*ctx.targets[0]);

                if (!target.alive)
                    return;

                float raw_damage =
                    nasus.physical_damage + 30.0f +
                    static_cast<float>(nasus.siphoning_strike_stacks);

                float damage =
                    raw_damage * 100.0f / (100.0f + target.physical_resistance);

                target.health -= damage;

                if (target.health <= 0.0f) {
                    target.alive = false;
                    nasus.siphoning_strike_stacks += 6;
                }
            }};
}

Event deal_magic_damage(Agent &source, Agent &target, float damage) {
    return {
        Id::DealMagicDamage, &source, {&target}, [damage](EventContext &ctx) {
            auto &source = dynamic_cast<Champion &>(ctx.source);
            auto &target = dynamic_cast<Champion &>(*ctx.targets[0]);

            if (!target.alive)
                return;

            target.health -= damage;

            if (source.inventory.has(ItemId::Morellonomicon))
                ctx.world.fire(apply_grievous_wounds(source, target));
        }};
}

Event heal(Agent &source, Agent &target, float amount) {
    return {Id::Heal, &source, {&target}, [amount](EventContext &ctx) {
                auto &target = dynamic_cast<Champion &>(*ctx.targets[0]);

                if (!target.alive)
                    return;

                float multiplier = 1.0f;

                if (target.effects.has(EffectId::GrievousWounds))
                    multiplier = get_effect_stats<EffectId::GrievousWounds>()
                                     .healing_multiplier;

                target.health += amount * multiplier;
            }};
}

Event apply_grievous_wounds(Agent &source, Agent &target) {
    return {Id::ApplyGrievousWounds, &source, {&target}, [](EventContext &ctx) {
                auto &target = dynamic_cast<Champion &>(*ctx.targets[0]);

                if (target.effects.add(EffectId::GrievousWounds))
                    ctx.world.fire(grievous_wounds_death(ctx.source, target),
                                   3.0f);
            }};
}

Event grievous_wounds_death(Agent &source, Agent &target) {
    return {Id::GrievousWoundsDeath, &source, {&target}, [](EventContext &ctx) {
                auto &target = dynamic_cast<Champion &>(*ctx.targets[0]);

                target.effects.remove(EffectId::GrievousWounds);
            }};
}

} // namespace Events
