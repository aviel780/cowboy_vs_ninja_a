#ifndef Ninja_HPP
#define Ninja_HPP
#include <string>
#include "Point.hpp"
#include "Character.hpp"


 
namespace ariel {
class Ninja : public Character {
protected:
    int speed;

public:
    Ninja(const std::string& name, int hitPoints, const Point& location, int speed);
    void move(Character* enemy);
    void slash(Character* enemy);
    std::string print() const override;
};

 }

#endif  // Ninja_HPP