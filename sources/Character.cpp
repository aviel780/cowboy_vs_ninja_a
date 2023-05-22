#include "Character.hpp"
#include <iostream>
using namespace ariel;

Character::Character(const std::string& name, int hitPoints, const Point& location)
    : name(name), hitPoints(hitPoints), location(location) {}

bool Character::isAlive() const {
    return hitPoints > 0;
}

double Character::distance(const Character& other) const {
    return location.distance(other.location);
}

void Character::hit(int damage) {
    hitPoints -= damage;
    if (hitPoints < 0)
        hitPoints = 0;
}

std::string Character::getName() const {
    return name;
}

Point Character::getLocation() const {
    return location;
}

Cowboy::Cowboy(const std::string& name, const Point& location)
    : Character(name, 110, location), bullets(6) {}

void Cowboy::shoot(Character* enemy) {
    if (isAlive() && hasBullets()) {
        enemy->hit(10);
        bullets--;
    }
}

bool Cowboy::hasBullets() const {
    return bullets > 0;
}

void Cowboy::reload() {
    bullets = 6;
}

std::string Cowboy::print() const {
    // std::cout << "C - Name: " << name << ", HP: " << hitPoints << ", Location: ";
    // location.print();
    // std::cout << ", Bullets: " << bullets << std::endl;
    return " ";

}

