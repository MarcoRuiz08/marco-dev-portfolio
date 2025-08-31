#pragma once
#include <string>

#include "PaymentMethod.hpp"

class DigitalWalletPayment : public PaymentMethod {
    private:
    std::string provider;
    std::string token;

    public:
    explicit DigitalWalletPayment(std::string provider, std::string token);
    std::string typePayment() const override;
    bool authorize(double amount) override;
};