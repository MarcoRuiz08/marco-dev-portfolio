#include "InventoryItem.hpp"

using namespace std;

InventoryItem::InventoryItem(Product product, int onHand, int reserved): product(std::move(product)), onHand(std::move(onHand)), reserved(std::move(reserved)) {

};

const Product& InventoryItem::getProduct() const {
    return product;
};
  
int InventoryItem::getAvailable() const {
    return onHand - reserved;
};

void InventoryItem::reserve(int qty) {
    if(qty < 0) {
        throw invalid_argument("qty needs to be greater than 0");
    }

    if(qty > getAvailable()) {
        throw invalid_argument("qty needs to be lower than the onHand inventory");
    }

    reserved += qty;
    ensureInvariant();
};
  
void InventoryItem::release(int qty) {
    if(qty < 0) {
        throw invalid_argument("qty needs to be greater than 0");
    }

    if(qty > reserved) {
        throw invalid_argument("Cannot release more than reserved");
    }
    reserved -= qty;
    ensureInvariant();
};

void InventoryItem::decrement(int qty) {
    if(qty < 0) {
        throw invalid_argument("qty needs to be greater than 0");
    }

    if(qty > reserved) {
        throw invalid_argument("Not enough reserved to decrement");
    }

    onHand -=qty;
    reserved -= qty;

    ensureInvariant();
};