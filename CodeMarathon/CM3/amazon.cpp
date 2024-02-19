#include <iostream>
#include <string>
#include <vector>
#include <map>

enum class CategoryType {
    FASHION,
    ELECTRONICS,
    BOOKS,
    ENTERTAINMENT
};

class Product {
public:
    std::string productName;
    std::string productID;
    float productCost;
    CategoryType category;

    Product(std::string name, float cost, CategoryType category)
        : productName(name), productCost(cost), category(category) {}
};

template <typename T>
void print(const T& t) {
    std::cout << t << std::endl;
}

template <typename T>
float calculateTotalCost(const T& products) {
    float total_cost = 0.0f;
    for (const auto& prod : products) {
        total_cost += prod.productCost;
    }
    return total_cost;
}

template <typename T>
void bill(const T& products) {
    std::cout << "----------Amazon Receipt----------" << std::endl;

    for (const auto& prod : products) {
        std::cout << prod.productName << " : Rs." << prod.productCost << std::endl;
    }

    std::cout << "-----------------------------------" << std::endl;
    std::cout << "Total : Rs." << std::to_string(calculateTotalCost(products)) << std::endl;
    std::cout << "-----------------------------------" << std::endl;
}

class AmazonStore {
public:
    
    std::map<CategoryType, std::vector<Product>> category_list;

    Product searchProduct(const std::string& name) {
        for (const auto& [category, products] : category_list) {
            for (const auto& prod : products) {
                if (prod.productName == name) {
                    print("Product found:");
                    print("Product name: " + name);
                    print("Product Cost: Rs." + std::to_string(prod.productCost));
                    return prod;
                }
            }
        }

        print("Product not found");
        // return a default-constructed Product or throw an exception
        return Product("", 0.0f, CategoryType::BOOKS);
    }

    void addProduct(Product&& prod) {
        category_list[prod.category].emplace_back(std::move(prod));
    }

    void deliverProducts() {
        print("Products delivered");
    }
};

class Vendor {
public:
    Vendor(AmazonStore& amazon) : amazonStore(amazon) {}

    void sendProduct(std::vector<Product>&& products) {
        for (auto&& p : products) {
            amazonStore.addProduct(std::move(p));
        }
    }

private:
    AmazonStore& amazonStore;
};

class Customer : public AmazonStore {
public:
    std::string name;
    std::string address;

    Customer(std::string name, std::string address) : name(name), address(address) {}

    void addToCart(Product&& product) {
        cart.emplace_back(std::move(product));
    }

    void purchase() {
        print("Total amount of Rs." + std::to_string(calculateTotalCost(cart)) + " received.");
        bill(cart);
        deliverProducts();
    }

private:
    std::vector<Product> cart;
};

int main() {
    AmazonStore amazon;
    Vendor vendor(amazon);

    Product prod1("Airdope", 54000.1, CategoryType::ELECTRONICS);
    Product prod2("Laptop", 74000.5, CategoryType::ELECTRONICS);
    Product prod3("Shoes", 5003.2, CategoryType::FASHION);

    vendor.sendProduct({std::move(prod1), std::move(prod2), std::move(prod3)});

    print("Welcome to Amazon!");

    Customer customer1("Amit", "Bangalore");
    customer1.addToCart(Product("Airdope", 54000.1, CategoryType::ELECTRONICS));
    customer1.addToCart(Product("Laptop", 74000.5, CategoryType::ELECTRONICS));
    customer1.purchase();

    return 0;
}
