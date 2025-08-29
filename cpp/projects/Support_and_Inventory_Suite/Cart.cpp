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

     const std::string& id = p.getId();

    auto it = std::find_if(lines.begin(), lines.end(),
        [&](const CartLine& line) {
            return line.getProductId() == id && line.getUnitPrice() == price;
        });

    if (it == lines.end()) {
        lines.emplace_back(p, qty, price);
    } else {
        it->addQty(qty);
    }
};

void Cart::remove(const std::string& productId) {
    auto it = std::find_if(lines.begin(), lines.end(),
    [&](const CartLine& line){ return line.getProductId() == productId; });

    if (it != lines.end()) {
        lines.erase(it);
    }
};
  
double Cart::subtotal() const {
    double sumatory = 0;

    for(const auto& line:lines) {
        sumatory = (line.lineTotal()) + sumatory; 
    }

    return sumatory;
};
  
size_t Cart::countTimes() const {
    return lines.size();
};