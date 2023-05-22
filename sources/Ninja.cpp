#include "Character.hpp"
#include "Ninja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include "OldNinja.hpp"
#include <iostream>
using namespace ariel;

Ninja::Ninja(const std::string& name, int hitPoints, const Point& location, int speed)
    : Character(name, hitPoints, location), speed(speed) {}

void Ninja::move(Character* enemy) {
    if (isAlive()) {
        double dist = distance(*enemy);
        if (dist > 1) {
            Point newLocation = location.moveTowards(location, enemy->getLocation(), speed);
            location = newLocation;
        }
    }
}


void Ninja::slash(Character* enemy) {
    if (isAlive()) {
        double dist = distance(*enemy);
        if (dist <= 1)
            enemy->hit(40);
    }
}
void Ninja::print() const {
    std::cout << "Ninja: ";
    if (!isAlive())
        std::cout << "(" << getName() << ")";
    else
        std::cout << getName() << " - HP: " << hitPoints;
    std::cout << " - Location: ";
    getLocation().print();
    std::cout << std::endl;
}




