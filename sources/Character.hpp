#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>
#include "Point.hpp"


 
namespace ariel {
class Character {
protected:
    std::string name;
    int hitPoints;
    Point location;

public:
    Character(const std::string& name, int hitPoints, const Point& location);
    bool isAlive() const;
    double distance(const Character& other) const;
    void hit(int damage);
    std::string getName() const;
    Point getLocation() const;
    virtual std::string print() const = 0;
};

class Cowboy : public Character {
private:
    int bullets;

public:
    Cowboy(const std::string& name, const Point& location);
    void shoot(Character* enemy);
    bool hasBullets() const;
    void reload();
     std::string print() const override;
};

 }

// class Ninja : public Character {
// protected:
//     int speed;

// public:
//     Ninja(const std::string& name, int hitPoints, const Point& location, int speed);
//     void move(Character* enemy);
//     void slash(Character* enemy);
// };

// class YoungNinja : public Ninja {
// public:
//     YoungNinja(const std::string& name, const Point& location);
//     void print() const override;
// };

// class TrainedNinja : public Ninja {
// public:
//     TrainedNinja(const std::string& name, const Point& location);
//     void print() const override;
// };

// class OldNinja : public Ninja {
// public:
//     OldNinja(const std::string& name, const Point& location);
//     void print() const override;
// };

#endif  // CHARACTER_HPP
