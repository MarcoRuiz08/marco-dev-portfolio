#include <stdexcept>

#include "Inventory.hpp"

bool Inventory::exists(const string& productId) const {
    return findProduct(productId) != nullptr;
};

InventoryItem* Inventory::findProduct(const string& productId) {
    auto it = byId.find(productId);

     return (it == byId.end()) ? nullptr : &it->second;
};

const InventoryItem* Inventory::findProduct(const string& productId) const{
    auto it = byId.find(productId);

     return (it == byId.end()) ? nullptr : &it->second;
};
  
void Inventory::upsertItem(const InventoryItem& item) {
    const string id = item.getProduct().getId();

    byId.insert_or_assign(id, item);

    const auto& stored = byId.at(id);
    if (stored.getAvailable() <= LOW_STOCK_THRESHOLD) {
        lowStockIds.insert(id);
    } else {
        lowStockIds.erase(id);
    }
};
  
void Inventory::reserve(const string& productId, int qty) {
    
    if(qty <= 0) {
        throw invalid_argument("Qty needs to be greater than 0");
    }

    InventoryItem* item = findProduct(productId);

     if (!item)  {
        throw invalid_argument("Product ID not found");
    }
    item->reserve(qty);  // this enforces available >= qty

    // keep lowStockIds in sync (pick a threshold policy; here 10)
    
    if (item->getAvailable() <= LOW_STOCK_THRESHOLD) {
        lowStockIds.insert(productId);
    } else {
        lowStockIds.erase(productId);
    }
};
  
void Inventory::commitSale(const string& productId, int qty) {
    if (qty <= 0) {
        throw std::invalid_argument("Qty must be > 0");
    }

    InventoryItem* item = findProduct(productId);
    if (!item) {
        throw std::invalid_argument("Product ID not found");
    }

    item->decrement(qty);  // reduces onHand and reserved (per your InventoryItem policy)

    if (item->getAvailable() <= LOW_STOCK_THRESHOLD) {
        lowStockIds.insert(productId);
    } else {
        lowStockIds.erase(productId);
    }
};
  
vector<InventoryItem> Inventory::topLowStock(size_t n) const {
    vector<InventoryItem> out;
    out.reserve(n);

    if (n == 0) return out;

    for (const auto& id : lowStockIds) {
        auto it = byId.find(id);
        if (it != byId.end()) {
            out.push_back(it->second);   // copy by value
            if (out.size() == n) break;
        }
        // If an id is in lowStockIds but missing in byId, we silently skip it.
    }
    return out;
};