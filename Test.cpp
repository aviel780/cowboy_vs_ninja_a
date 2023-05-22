#include <iostream>

#include "sources/Point.hpp"
#include "sources/Character.hpp"
#include "sources/Team.hpp"
#include "sources/Team2.hpp"
#include "sources/SmartTeam.hpp"
#include "sources/Ninja.hpp"
#include "sources/YoungNinja.hpp"
#include "sources/TrainedNinja.hpp"
#include "sources/OldNinja.hpp"

using namespace ariel;

int main() {
    // Create points
    Point point1(3.5, 2.8);
    Point point2(-1.2, 5.6);

    // Test Point class
    std::cout << "Distance between point1 and point2: " << point1.distance(point2) << std::endl;
    point1.print();

    // Create characters
    Cowboy cowboy("John", point1);
    Ninja ninja("Ryu",120, point2,15);
    YoungNinja youngNinja("Ken", point1);
    TrainedNinja trainedNinja("Hanzo", point2);
    OldNinja oldNinja("Jubei", point1);

    // Test Character class
    std::cout << "Is cowboy alive? " << (cowboy.isAlive() ? "Yes" : "No") << std::endl;
    std::cout << "Distance between cowboy and ninja: " << cowboy.distance(ninja) << std::endl;
    cowboy.hit(20);
    std::cout << "Is cowboy alive after hit? " << (cowboy.isAlive() ? "Yes" : "No") << std::endl;
    std::cout << "Cowboy's name: " << cowboy.getName() << std::endl;
    std::cout << "Cowboy's location: ";
    cowboy.getLocation().print();
    cowboy.print();

    // Test Cowboy class
    cowboy.shoot(&ninja);
    std::cout << "Is ninja alive after being shot by cowboy? " << (ninja.isAlive() ? "Yes" : "No") << std::endl;
    std::cout << "Does cowboy have bullets? " << (cowboy.hasBullets() ? "Yes" : "No") << std::endl;
    cowboy.reload();
    std::cout << "Does cowboy have bullets after reloading? " << (cowboy.hasBullets() ? "Yes" : "No") << std::endl;

    // Test Ninja class
    ninja.move(&cowboy);
    ninja.slash(&cowboy);
    std::cout << "Is cowboy alive after being slashed by ninja? " << (cowboy.isAlive() ? "Yes" : "No") << std::endl;

    // Create teams
    Team team1(&cowboy);
    team1.add(&ninja);
    team1.add(&youngNinja);

    Team2 team2;
    team2.add(&cowboy);
    team2.add(&ninja);
    team2.add(&trainedNinja);

    SmartTeam smartTeam;
    smartTeam.add(&cowboy);
    smartTeam.add(&ninja);
    smartTeam.add(&oldNinja);

    // // Test Team class
    // std::cout << "Number of alive fighters in team1: " << team1.stillAlive() << std::endl;
    // std::cout << "Number of alive fighters in team2: " << team2.stillAlive() << std::endl;
    // team1.attack(&team2);
    // std::cout << "Number of alive fighters in team2 after attack: " << team2.stillAlive() << std::endl;
    // team1.print();

    // // Test Team2 class
    // team2.attack(&team1);
    // std::cout << "Number of alive fighters in team1 after attack: " << team1.stillAlive() << std::endl;
    // team2.print();

    // // Test SmartTeam class
    // smartTeam.attack(&team2);
    // std::cout << "Number of alive fighters in team2 after smart attack: " << team2.stillAlive() << std::endl;
    // smartTeam.print();

    return 0;
}
