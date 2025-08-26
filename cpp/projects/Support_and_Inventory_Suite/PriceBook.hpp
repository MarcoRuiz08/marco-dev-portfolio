#include <string>
#include <map>
#include <unordered_map>

using namespace std;

class PriceBook {
    private:
    map<string, double> priceByProduct;
    unordered_map<string,double> promoByProduct;

    public:
    PriceBook() = default;

    bool hasPrice(const string& productId) const noexcept;
    double getPrice(const string& productId) const;
    void setPrice(const string& productId, double price);
    void setPromo(const string& productId, double discountAmmount);
    void removePromo(const string& productId);
};