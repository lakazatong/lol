#pragma once

#include "event.hpp"

class Agent;

namespace Events {

Event nasus_q(Agent &source, Agent &target);

Event deal_magic_damage(Agent &source, Agent &target, float damage);

Event heal(Agent &source, Agent &target, float amount);

Event apply_grievous_wounds(Agent &source, Agent &target);

Event grievous_wounds_death(Agent &source, Agent &target);

} // namespace Events
