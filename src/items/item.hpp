#pragma once

#include <tuple>

enum class ItemId { Morellonomicon, Count };

struct MorellonomiconStats {
    float magic_damage = 0.0f;
    float ability_power = 70.0f;
};

inline constexpr auto ITEM_STATS = std::tuple{MorellonomiconStats{}};

template <ItemId Id> constexpr const auto &get_item_stats() {
    return std::get<static_cast<size_t>(Id)>(ITEM_STATS);
}
