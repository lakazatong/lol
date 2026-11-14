#pragma once

#include <agents/champion.hpp>

class Nasus : public Champion {
  public:
    explicit Nasus(World &world);

    unsigned int siphoning_strike_stacks = 0;

    void cast_q(Champion &target);
};
