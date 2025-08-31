#include <utility>
#include <stdexcept>

#include "Receipt.hpp"

Receipt::Receipt(std::string id, Cart cart, double tax, double total, std::unique_ptr<PaymentMethod> payment) :
    id(std::move(id)), cart(std::move(cart)), tax(tax), total(total), payment(std::move(payment)) {
        if(this->id.empty()) {
            throw std::invalid_argument("Id must not be empty");
        }

        if(this->tax <= 0) {
            throw std::invalid_argument("Tax must be greater than 0");
        }

        if(this->total <= 0) {
            throw std::invalid_argument("Total must be greater than 0");
        }

};
  
double Receipt::computeTotal() const {
    return cart.subtotal() + getTax();
};
  
const std::string& Receipt::getId() const {

};
  
Cart Receipt::getCart() const {
    return cart;
}
   
const double Receipt::getTax() const noexcept {
    return tax;
};
  
const double Receipt::getTotal() const noexcept {
    return total;
};

void Receipt::setId(std::string newId) {
    if(newId.empty()) {
        throw std::invalid_argument("NewId must not be empty");
    }
    id = std::move(newId);
};