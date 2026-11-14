#pragma once

#include <vector>

#include "effect.hpp"

class EffectPool {
  public:
    bool add(EffectId id);
    bool remove(EffectId id);
    bool has(EffectId id) const;

  private:
    std::vector<EffectId> effects;
};
