#pragma once
#include <string>
#include <utility>

using namespace std;

class Product {
    private:
    string id;
    string name;
    string category;
    double basePrice;

    public:
    Product();
    Product(string id, string name, string category, double basePrice);

    Product(const Product&) = default;
    Product(Product&&) noexcept = default;
    Product& operator=(const Product&) = default;
    Product& operator=(Product&&) noexcept = default;
    ~Product() = default;

    const string& getId() const noexcept;
    const string& getName() const noexcept;
    double getBasePrice() const noexcept;
    void setBasePrice(double newPrice) noexcept;

    bool operator==(const Product& other) const noexcept;
    bool operator<(const Product& other) const noexcept;
};