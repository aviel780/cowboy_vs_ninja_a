#ifndef OldNinja_HPP
#define OldNinja_HPP
#include <string>
#include "Point.hpp"
#include "Character.hpp"
#include "Ninja.hpp"


namespace ariel {
class OldNinja : public Ninja {
public:
    OldNinja(const std::string& name, const Point& location);
    void print() const override;
};

 }
#endif  // OldNinja_HPP