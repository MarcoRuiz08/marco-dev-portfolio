#include <string>

class PaymentMethod {
    public:
    virtual ~PaymentMethod() = default;
    virtual std::string typePayment() const = 0;
    virtual bool authorize(double amount) = 0;
};