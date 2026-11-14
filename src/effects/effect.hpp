#pragma once

#include <tuple>

enum class EffectId { GrievousWounds, Count };

struct GrievousWoundsStats {
    float healing_multiplier = 0.6f;
};

inline constexpr auto EFFECT_STATS = std::tuple{GrievousWoundsStats{}};

template <EffectId Id> constexpr const auto &get_effect_stats() {
    return std::get<static_cast<std::size_t>(Id)>(EFFECT_STATS);
}
