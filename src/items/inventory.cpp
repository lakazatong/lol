#include <algorithm>

#include "inventory.hpp"

Inventory::Inventory(unsigned int capacity) : capacity_(capacity) {
    items.reserve(capacity);
}

bool Inventory::add(ItemId id) {
    if (items.size() >= capacity_)
        return false;

    items.push_back(id);
    return true;
}

bool Inventory::has(ItemId id) const {
    return std::find(items.begin(), items.end(), id) != items.end();
}

unsigned int Inventory::size() const {
    return static_cast<unsigned int>(items.size());
}

unsigned int Inventory::capacity() const { return capacity_; }
