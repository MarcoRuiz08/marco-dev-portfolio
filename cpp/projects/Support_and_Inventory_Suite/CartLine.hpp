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
    
    const Product& getProduct() const noexcept { return product; }
    const std::string& getProductId() const noexcept { return product.getId(); }
    int getQty() const noexcept { return qty;}
    int getUnitPrice() const noexcept { return unitPrice;}
    void addQty(int delta) {
        if (delta <= 0) throw std::invalid_argument("delta must be > 0");
        qty += delta;
    }
};