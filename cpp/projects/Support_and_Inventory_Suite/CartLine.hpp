#pragma once
#include <utility>
#include "Product.hpp"

class CartLine {
    private:
    Product product;
    int qty;
    double unitPrice;

    public:
    CartLine() = default;
    CartLine(Product product, int qty, double unitPrice): product(std::move(product)), qty(std::move(qty)), unitPrice(std::move(unitPrice)) {};
    // Copy/Move complete
    CartLine(const CartLine&) = default;
    CartLine(CartLine&&) noexcept = default;
    CartLine& operator=(const CartLine&) = default;
    CartLine& operator=(CartLine&&) noexcept = default;
    ~CartLine() = default;
    
    double lineTotal() const {
        return static_cast<double>(qty) * unitPrice;
    }
};