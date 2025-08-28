#include "Cart.hpp"

void Cart::add(const Product& p, int qty, double price) {
    if(qty < 0) {
        throw invalid_argument("QTY needs to be gretaer than 0");
    }

    if(price <= 0) {
        throw invalid_argument("Price needs to be greater than 0");
    }

    if(p.getId().empty()) {
        throw invalid_argument("Product without ID"); 
    }

    auto it = find(lines.begin(), lines.end(), p.getId());

    if(it == lines.end()) {
        lines.push_back(CartLine(p,qty,price));
    }
    else {
        if(it.unitPrice == it.product->getPrice()) {
            it.qty += qty;
        }
        else {
            lines.push_back(CartLine(p,qty,price));
        }
    }
};

void Cart::remove(const std::string& productId) {
    lines.erase(find(lines.begin(), lines.end(), productId));
};
  
double Cart::subtotal() const {
    double sumatory = 0;

    for(auto it:lines) {
        
    }
};
  
size_t Cart::countTimes() const {

};