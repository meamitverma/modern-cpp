// AMIT KUMAR VERMA
// 219379

#include <iostream>
#include <vector>

class Ingredient {
public:
    virtual std::string getName() const = 0;
    virtual int getCalories() const = 0;
    virtual int getCost() const = 0;
    virtual ~Ingredient() = default;
};

class Bread : public Ingredient {
public:
    virtual std::string getName() const = 0;
    virtual int getCalories() const = 0;
    virtual int getCost() const = 0;
};

class Bage1 : public Bread {
public:
    std::string getName() const override {
        return "Bage1";
    }
    int getCalories() const override {
        return 150;
    }
    int getCost() const override {
        return 80;
    }
};

class Bage2 : public Bread {
public:
    std::string getName() const override {
        return "Bage2";
    }
    int getCalories() const override {
        return 170;
    }
    int getCost() const override {
        return 100;
    }
};

class Filling : public Ingredient {
public:
    virtual std::string getName() const = 0;
    virtual int getCalories() const = 0;
    virtual int getCost() const = 0;
};

class Cheese : public Filling {
public:
    std::string getName() const override {
        return "Cheese";
    }
    int getCalories() const override {
        return 30;
    }
    int getCost() const override {
        return 10;
    }
};

class Salmon : public Filling {
public:
    std::string getName() const override {
        return "Salmon";
    }
    int getCalories() const override {
        return 60;
    }
    int getCost() const override {
        return 40;
    }
};

class Sandwich {
private:
    std::vector<Ingredient*> ingredients;

public:
    void addIngredient(Ingredient* ingredient) {
        ingredients.emplace_back(ingredient);
    }

    void displaySandwich() const {
        for (const Ingredient* item : ingredients) {
            std::cout << item->getName() << ": " << item->getCalories() << " calories, $" << item->getCost() << std::endl;
        }
        std::cout << std::endl;
    }

    void calculateTotalCalories() const {
        int totalCalories = 0;
        for (const Ingredient* item : ingredients) {
            totalCalories += item->getCalories();
        }
        std::cout << "Total Calories: " << totalCalories << std::endl;
    }
};

class IngredientProvider {
public:
    virtual Ingredient* getBreadIngredient() const = 0;
};

class DynamicIngredientProvider : public IngredientProvider {
public:
    Ingredient* getBreadIngredient() const override {
        std::cout << "Enter 1 for Bage1, 2 for Bage2: ";
        int choice;
        std::cin >> choice;

        if (choice == 1) {
            return new Bage1();
        } else if (choice == 2) {
            return new Bage2();
        } else {
            std::cout << "Invalid choice. Returning default ingredient Bage1." << std::endl;
            return new Bage1();
        }
    }
};

class SandwichBuilder {
private:
    IngredientProvider* ingredientProvider;

public:
    SandwichBuilder(IngredientProvider* provider) : ingredientProvider(provider) {}

    Sandwich prepareReadyMadeSandwich() const {
        Sandwich sandwich;
        sandwich.addIngredient(new Bage1());
        sandwich.addIngredient(new Cheese());
        sandwich.addIngredient(new Salmon());

        return sandwich;
    }

    Sandwich buildCustomSandwich(Sandwich& sandwich) const {
        Ingredient* breadIngredient = ingredientProvider->getBreadIngredient();
        sandwich.addIngredient(breadIngredient);
        return sandwich;
    }
};

int main() {
    std::cout << "Sandwich Builder" << std::endl;

    SandwichBuilder builder(new DynamicIngredientProvider);

    Sandwich customSandwich;
    builder.buildCustomSandwich(customSandwich);

    std::cout << std::endl;
    std::cout << "Customized Sandwich " << std::endl;
    customSandwich.displaySandwich();
    customSandwich.calculateTotalCalories();

    Sandwich readyMadeSandwich = builder.prepareReadyMadeSandwich();
    std::cout << "\nReady Made Sandwich " << std::endl;
    readyMadeSandwich.displaySandwich();
    readyMadeSandwich.calculateTotalCalories();

    return 0;
}
