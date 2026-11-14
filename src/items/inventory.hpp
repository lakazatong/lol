#pragma once

#include <vector>

#include "item.hpp"

class Inventory {
  public:
    explicit Inventory(unsigned int capacity);

    bool add(ItemId id);
    bool has(ItemId id) const;

    unsigned int size() const;
    unsigned int capacity() const;

  private:
    std::vector<ItemId> items;
    unsigned int capacity_;
};
