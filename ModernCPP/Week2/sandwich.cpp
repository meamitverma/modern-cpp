#include <iostream>
#include <vector>
#include<variant>
 
// Base class
class Ingredient {
public:
    virtual std::string name() = 0;
    virtual int calories() = 0;
    virtual int cost() = 0;
};
 
// Base class
class Bread : public Ingredient {
public:
    virtual std::string name() = 0;
    virtual int calories() = 0;
    virtual int cost() = 0;
};
 
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
 
// Base class
class Filling : public Ingredient {
public:
    virtual std::string name() = 0;
    virtual int calories() = 0;
    virtual int cost() = 0;
};
 
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
 
class SmokedSalmon : public Filling {
public:
    std::string name() override {
        return "Smoked Salmon";
    }
    int calories() override {
        return 150;
    }
    int cost() override {
        return 100;
    }
};
 
// IngredientProvider and DynamicIngredientProvider
class supplyIngredient {
public:
    virtual Ingredient* getBreadIngredient() = 0;
    virtual Ingredient* getFillingIngredient() = 0;
};
 
class DynamicIngredient : public supplyIngredient {
public:
    Ingredient* getBreadIngredient() override {
        std::cout << "Enter 1 for Bagel, 2 for Bun: ";
        int choice;
        std::cin >> choice;
 
        if (choice == 1) {
            return new Bagel();
        } else if (choice == 2) {
            return new Bun();
        } else {
            std::cout << "Please enter only specified choices. Providing Bagel..." << std::endl;
            return new Bagel();
        }
    }
 
    Ingredient* getFillingIngredient() override {
        std::cout << "Enter 1 for Cream Cheese, 2 for Smoked Salmon: ";
        int choice;
        std::cin >> choice;
 
        if (choice == 1) {
            return new CreamCheese();
        } else if (choice == 2) {
            return new SmokedSalmon();
        } else {
            std::cout << "Invalid choice. Returning default ingredient Cream Cheese." << std::endl;
            return new CreamCheese();
        }
    }
};
 
class Sandwich {
private:
    std::vector<Ingredient*> ingredients;
 
public:
    void addIngredients(Ingredient* ingredient) {
        ingredients.emplace_back(ingredient);
    }
 
    void getSandwich() {
        for (Ingredient* i : ingredients) {
            std::cout << i->name() << "; " << i->calories() << " ; " << i->cost() << " ." << std::endl;
        }
    }
 
    void getCalories() {
        int totalCalories = 0;
        for (Ingredient* i : ingredients) {
            totalCalories += i->calories();
        }
        std::cout << "Total calories: " << totalCalories << std::endl;
    }
};
 
class Sandwich_Builder {
private:
    supplyIngredient* ingredientProvider;
 
public:
    Sandwich_Builder(supplyIngredient* provider) : ingredientProvider(provider) {}
 
    Sandwich readyMade() {
        Sandwich sandwich;
        sandwich.addIngredients(ingredientProvider->getBreadIngredient());
        sandwich.addIngredients(ingredientProvider->getFillingIngredient());
        sandwich.addIngredients(ingredientProvider->getFillingIngredient());
 
        return sandwich;
    }
 
    Sandwich buildCustomSandwich(Sandwich& s) {
        s.addIngredients(ingredientProvider->getBreadIngredient());
        s.addIngredients(ingredientProvider->getFillingIngredient());
        s.addIngredients(ingredientProvider->getFillingIngredient());
 
        return s;
    }
};
 
//visitor --auditor code //dont give everything to auditor. just give what it needs.
//use proxy as a wrapper to sandwich to avoid giving access to unreqired member functions and private variables --proxy in turn will control
class AuditorSandwichVisitor{  //visiotrs aredouble dispatch but in modern cpp there is no double dispatch as it breaks it
    public:
    void operator ()(Sandwich sandwich){
        sandwich.getSandwich();
    }
};
 
int main() {
    std::cout << "Sandwich Builder" << std::endl;
 
    Sandwich_Builder builder(new DynamicIngredient);
 
    Sandwich custom;
    builder.buildCustomSandwich(custom);
 
    std::cout << std::endl;
    std::cout << "Customized Sandwich " << std::endl;
    // custom.getSandwich();
    // custom.getCalories();
 
    Sandwich offTheShelf = builder.readyMade();
    std::cout << "\nReady Made Sandwich " << std::endl;
    // offTheShelf.getSandwich();
    //offTheShelf.getCalories();
 
    using SandwichType = std::variant<Sandwich>;
    std::vector<SandwichType> mySandwiches{custom, offTheShelf};
    AuditorSandwichVisitor auditorsVisit;
    auto visitSandwich = [&](const auto& sandwichSeq){
        std::visit(auditorsVisit, sandwichSeq);
    };
 
    for(const auto sandwichSequence : mySandwiches){
        visitSandwich(sandwichSequence);
    }
 
    return 0;
}
 