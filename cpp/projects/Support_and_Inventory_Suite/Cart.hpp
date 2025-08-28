#pragma once
#include <vector>
#include <utility>
#include <string>
#include <stdexcept>
#include <algorithm>

#include "CartLine.hpp"

class Cart {
    private:
    std::vector<CartLine> lines;

    public:
    Cart() = default;
    Cart(const Cart&) = default;
    Cart(std::vector<CartLine> lines) : lines(std::move(lines)) {};
    ~Cart() = default;

    void add(const Product& p, int qty, double price);
    void remove(const std::string& productId);
    double subtotal() const;
    size_t countTimes() const;
};