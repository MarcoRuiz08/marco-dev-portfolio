#pragma once
#include <stdexcept>

#include "Product.hpp"


class InventoryItem {
    private:
    Product product;
    int onHand;
    int reserved;

    void ensureInvariant() const {
    if (onHand < 0 || reserved < 0 || reserved > onHand) {
        throw std::logic_error("InventoryItem invariant violated");
    }
};

    public:
    InventoryItem() = default;
    InventoryItem(Product product, int onHand, int reserved);
    InventoryItem(const InventoryItem&) = default;
    InventoryItem(InventoryItem&&) noexcept = default;
    InventoryItem& operator=(const InventoryItem&) = default;
    InventoryItem& operator=(InventoryItem&&) noexcept = default;
    ~InventoryItem() = default;

    const Product& getProduct() const;
    int getAvailable() const;
    void reserve(int qty);
    void release(int qty);
    void decrement(int qty);
};