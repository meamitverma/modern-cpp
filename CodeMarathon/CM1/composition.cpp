#include <iostream>

class Entity
{
private:
    std::string name;

public:
    Entity() = default;
    Entity(std::string _name) : name(_name) {}

    std::string getName() {
        return name;
    }
};

class Asset
{
private:
    std::string name;
    Entity entity;

public:
    Asset(std::string _name) {
        name = _name;
        entity = Entity(_name);
    }
    void interact()
    {
        std::cout << "An asset " << entity.getName() << " is interacting" << std::endl;
    }
};

class Enemy
{
private:
    std::string name;
    Entity entity;

public:
    Enemy(std::string _name) {
        name = _name;
        entity = Entity(_name);
    }
    void attack()
    {
        std::cout << "An enemy " << entity.getName() << " is attacking."  << std::endl;
    }
};

class Person
{
private:
    std::string name;
    Entity entity;

public:
    Person(std::string _name) {
        name = _name;
        entity = Entity(_name);
    }

    void talk()
    {
        std::cout << "An person " << entity.getName() << " is talking." << std::endl;
    }
};

int main()
{
    Person p("Amit");
    Asset grass("Grass");
    Enemy enemy("Enemy");

    p.talk();
    grass.interact();
    enemy.attack();


    return 0;
}