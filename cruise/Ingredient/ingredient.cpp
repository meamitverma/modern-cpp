#include<iostream>
#include<vector>

class Ingredient {
    public:
    virtual std::string name() = 0;
    virtual int calories() = 0;
    virtual int cost() = 0;
};

// Base Bread
class Bread : public Ingredient {
    public:
    virtual std::string name() = 0;
    virtual int calories() = 0;
    virtual int cost() = 0;
};
// types of bread inheriting from Bread
class Bagel : public Bread {
    public:
    std::string name() override {
        return "Bagel";
    }
    int calories() override {
        return 250;
    }
    int cost() override {
        return 20;
    }
};
class Bun : public Bread {
    public:
    std::string name() override {
        return "Bun";
    }
    int calories() override {
        return 150;
    }
    int cost() override {
        return 10;
    }
};

// filling
// meat, patty, caramol, onions etc.
class Filling : public Ingredient {
    public:
    virtual std::string name() = 0;
    virtual int calories() = 0;
    virtual int cost() = 0;
};
//types of filling
class CreamCheese : public Filling {
    public:
    std::string name() override {
        return "Cream Cheese";
    }
    int calories() override {
        return 250;
    }
    int cost() override {
        return 50;
    }
};

class Salamon : public Filling {
    public:
    std::string name() override {
        return "Salamon";
    }
    int calories() override {
        return 450;
    }
    int cost() override {
        return 120;
    }
};

// sandwich
class Sandwich {
    private:
    std::vector< Ingredient* > ingredients;

    public:
    void addIngredients( Ingredient *ingredient) {
        ingredients.emplace_back(ingredient);
    }
    void getSandwich() {
        for (Ingredient *i : ingredients) {
            std:: cout << i->name() << ":" << i->calories() << "kcal : Cost = " << i->cost() << std::endl;
        }
    }
    void getCalories() {
        int totalCalories = 0;
        for (Ingredient *i : ingredients) {
            totalCalories += i->calories();
        }

        std::cout << "Total Calories: " << totalCalories << std::endl;
    }

};

class SandwichBuilder {
    public:
    // not an acceptable way to write a code
    // it is hardcoded
    static Sandwich readyMade() {
        Sandwich sandwich;
        sandwich.addIngredients( new Bagel());
        sandwich.addIngredients( new Salamon());
        sandwich.addIngredients( new CreamCheese());

        return sandwich;
    }

    static Sandwich build( Sandwich &s, Ingredient *ingredient) {
        s.addIngredients(ingredient);
        return s;
    }

};


int main (int argc, char *argv[]) {

    std::cout << "Sandwich builder\n" << std::endl;
    Sandwich custom;
    SandwichBuilder::build(custom, new Bun());
    SandwichBuilder::build(custom, new CreamCheese());

    std::cout << "Customised Sandwich" << std::endl;
    custom.getSandwich();
    custom.getCalories();

    Sandwich offTheShelf = SandwichBuilder::readyMade();;
    std::cout << "Ready made sandwich" << std::endl;
    offTheShelf.getSandwich();
    offTheShelf.getCalories();

    return 0;
}