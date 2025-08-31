#include "PaymentMethod.hpp"

class CashPayment : public PaymentMethod {
    private:
    double cashGiven;

    public:
    explicit CashPayment(double cashGiven);
    std::string typePayment() const override;
    bool authorize(double amount) override;
};