#pragma once

#include <functional>
#include <vector>

class World;
class Agent;

namespace Events {

enum class Id {
    NasusQ,
    DealMagicDamage,
    Heal,
    ApplyGrievousWounds,
    GrievousWoundsDeath
};

}

struct EventContext {
    World &world;
    Agent &source;
    std::vector<Agent *> &targets;
};

using EventProcess = std::function<void(EventContext &)>;

struct Event {
    Events::Id id;
    Agent *source;
    std::vector<Agent *> targets;
    EventProcess process;
};
