#include <iostream>
#include <string>
#include <algorithm>

class Character {
private:
    std::string name;
    int health;
    int attack;
    int defense;
    int maxHealth;

public:
    Character(const std::string& n, int h, int a, int d)
        : name(n), health(h), attack(a), defense(d), maxHealth(100) {
    }

    int getHealth() const {
        return health;
    }

    void displayInfo() const {
        std::cout << "Name: " << name << ", HP: " << health
            << ", Attack: " << attack << ", Defense: " << defense << std::endl;
    }

    void attackEnemy(Character& enemy) {
        int damage = attack - enemy.defense;
        if (damage > 0) {
            enemy.takeDamage(damage);
            std::cout << name << " attacks " << enemy.name << " for " << damage << " damage!" << std::endl;
        }
        else {
            std::cout << name << " attacks " << enemy.name << ", but it has no effect!" << std::endl;
        }
    }

    void heal(int amount) {
        if (amount > 0) {
            health = std::min(maxHealth, health + amount);
            std::cout << name << " heals for " << amount << " HP." << std::endl;
        }
        else {
            std::cout << "Cannot heal for a non-positive amount." << std::endl;
        }
    }

    void takeDamage(int amount) {
        if (amount > 0) {
            health = std::max(0, health - amount);
            std::cout << name << " takes " << amount << " damage." << std::endl;
            if (health == 0) {
                std::cout << name << " has been defeated!" << std::endl;
            }
        }
        else {
            std::cout << "Cannot take a non-positive amount of damage." << std::endl;
        }
    }
};

int main() {
    Character hero("Hero", 100, 20, 10);
    Character monster("Goblin", 50, 15, 5);

    hero.displayInfo();
    monster.displayInfo();

    hero.attackEnemy(monster);
    monster.displayInfo();

    monster.attackEnemy(hero);
    hero.displayInfo();

    std::cout << "\n--- Testing new methods ---\n";

    monster.heal(10);
    monster.displayInfo();

    hero.takeDamage(15);
    hero.displayInfo();

    hero.heal(20);
    hero.displayInfo();

    monster.takeDamage(60);
    monster.displayInfo();

    return 0;
}