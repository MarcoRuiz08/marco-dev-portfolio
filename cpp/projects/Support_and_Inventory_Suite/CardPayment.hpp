#include "PaymentMethod.hpp"

class CardPayment : public PaymentMethod {
    private:
    std::string maskedCard;
    std::string authCode;

    public:
    explicit CardPayment(std::string maskedCard);
    std::string getMaskedCard() const noexcept;
    std::string getAuthCode() const noexcept;
    std::string typePayment() const override;
    bool authorize(double amount) override;
};