#pragma once
#include <unordered_map>
#include <set>
#include <string>
#include <vector>

#include "InventoryItem.hpp"

using namespace std;

class Inventory {
    private:
    static constexpr int LOW_STOCK_THRESHOLD = 10;
    std::unordered_map<std::string, InventoryItem> byId;
    set<string> lowStockIds;

    public:
    Inventory() = default;

    bool exists(const string& productId) const;
    InventoryItem* findProduct(const string& productId) ;
    const InventoryItem* findProduct(const string& productId) const;
    void upsertItem(const InventoryItem& item);
    void reserve(const string& productId, int qty);
    void commitSale(const string& productId, int qty);
    vector<InventoryItem> topLowStock(size_t n) const;
};
