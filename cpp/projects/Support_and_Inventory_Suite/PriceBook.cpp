#include "PriceBook.hpp"

PriceBook::PriceBook() {

};

bool PriceBook::hasPrice(const string& productId) const noexcept {
    return priceByProduct.find(productId) != priceByProduct.end();
};
    
double PriceBook::getPrice(const string& productId) const {
    auto it = priceByProduct.find(productId);

    if(it == priceByProduct.end()) {
        throw invalid_argument("productId not found");
    }

    return it->second;
};

void PriceBook::setPrice(const string& productId, double price) {
    if(price < 0.0) {
        throw invalid_argument("price must be >= 0");
    }

    priceByProduct.insert_or_assign(productId,price);
};
    
void PriceBook::setPromo(const string& productId, double discountAmmount) {
    auto it = priceByProduct.find(productId);

    if(it == priceByProduct.end()) {
        throw invalid_argument("productId not found");
    }

    if( discountAmmount <= 0.0) {
        throw invalid_argument("discount must be >= 0");
    }

    if(discountAmmount > it->second) {
        throw invalid_argument("discount is higher than the real price");
    }

    promoByProduct.insert_or_assign(productId,discountAmmount);
};
    
void PriceBook::removePromo(const string& productId) {
    if (promoByProduct.erase(productId) == 0) {
        throw std::invalid_argument("productId has no active promo");
    }
};