#include <iostream>

// q2

// base class
class Entity
{
private:
  std::string name;

public:
  Entity() = default;
  Entity(std::string _name) : name(_name) {}

  virtual void getName() = 0;
};

// using inheritance
class Player : public Entity
{
private:
  std::string name;

public:
  Player(std::string _name) : name(_name) {}
  void getName()
  {
    std::cout << "A player " << name << std::endl;
  }
};

class Enemy : public Entity
{
private:
  std::string name;

public:
  Enemy(std::string _name) : name(_name) {}
  void getName()
  {
    std::cout << "An enemy " << name << std::endl;
  }
};

int main()
{
  Entity *entity1 = new Player("amit");
  Entity *entity2 = new Enemy("dragon");
  entity1->getName();
  entity2->getName();

  return 0;
}
