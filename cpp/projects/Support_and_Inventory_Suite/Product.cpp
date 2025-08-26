#include "Product.hpp"

Product::Product() {

};

Product::Product(string id, string name, string category, double basePrice) : id(move(id)), name(move(name)), category(move(category)), basePrice(move(basePrice)){

};

const string& Product::getId() const noexcept {
    return id;
};

const string& Product::getName() const  noexcept{
    return name;
};

double Product::getBasePrice() const noexcept{
    return basePrice;
};

void Product::setBasePrice(double newPrice) noexcept{
    basePrice = newPrice;
};

bool Product::operator==(const Product& other) const noexcept {
    return id == other.id;
};

bool Product::operator<(const Product& other) const noexcept {
    return id < other.id;
};
