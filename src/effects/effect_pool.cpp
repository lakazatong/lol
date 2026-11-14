#include <algorithm>

#include "effect_pool.hpp"

bool EffectPool::add(EffectId id) {
    if (has(id))
        return false;

    effects.push_back(id);
    return true;
}

bool EffectPool::remove(EffectId id) {
    auto it = std::find(effects.begin(), effects.end(), id);

    if (it == effects.end())
        return false;

    effects.erase(it);
    return true;
}

bool EffectPool::has(EffectId id) const {
    return std::find(effects.begin(), effects.end(), id) != effects.end();
}
