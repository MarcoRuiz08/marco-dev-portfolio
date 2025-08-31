#pragma once
#include <string>
#include <memory>

#include "Cart.hpp"
#include "PaymentMethod.hpp"

class Receipt {
    private:
    std::string id;
    Cart cart;
    double tax;
    double total;
    std::unique_ptr<PaymentMethod> payment;

    public:
    Receipt() = default;
    Receipt(Receipt&& ) noexcept = default;
    Receipt(std::string id, Cart cart, double tax, double total, std::unique_ptr<PaymentMethod> payment);
    Receipt& operator=(Receipt&&) noexcept = default;
    Receipt(const Receipt&) = delete;
    Receipt& operator=(const Receipt&) = delete;

    double computeTotal() const;
    const std::string& getId() const;
    Cart getCart() const;
    const double getTax() const noexcept;
    const double getTotal() const noexcept;
    
    void setId(std::string newId);
};