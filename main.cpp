#include <iostream>
#include <cstring>

using namespace std;

class Hero {
protected:
    string ime;
    float attack_damage;
    float attack_speed;
    float ability_power;
public:
    Hero(const string ime = "", float attack_damage = 0.0, float attack_speed = 0.0, float ability_power = 0.0) {
        this->ime = ime;
        this->attack_damage = attack_damage;
        this->attack_speed = attack_speed;
        this->ability_power = ability_power;
    }

    virtual void displayInfo() = 0;

    virtual float power() = 0;
};

class LegendaryHero : virtual public Hero {
protected:
    int hiddenPowers;
public:
    LegendaryHero(const string ime = "", float attack_damage = 0.0, float attack_speed = 0.0, float ability_power = 0.0,
                  int hiddenPowers = 0) :
            Hero(ime, attack_damage, attack_speed, ability_power) {
        this->hiddenPowers = hiddenPowers;
    }

    float power() override {
        return (0.4 * attack_damage * hiddenPowers) + (0.25 * attack_speed * hiddenPowers) +
               (0.35 * ability_power * hiddenPowers);
    }

    void displayInfo() {
        cout << "LegendaryHero: " << ime << endl;
        cout << "Number of hidden powers: " << hiddenPowers << endl;
        cout << "Attack damage: " << attack_damage << endl;
        cout << "Attack speed: " << attack_speed << endl;
        cout << "Ability power: " << ability_power << endl;
        cout << "Power: " << power();
    }
};

class SuperHero : virtual public Hero {
protected:
    bool isShapeshifter;
public:
    SuperHero(const string ime = "", float attack_damage = 0.0, float attack_speed = 0.0, float ability_power = 0.0,
              bool isShapeshifter = false)
            : Hero(ime, attack_damage, attack_speed, ability_power) {
        this->isShapeshifter = isShapeshifter;
    }

    float power() override {
        return attack_damage + attack_speed + ability_power;
    }

    void displayInfo() {
        cout << "SuperHero: " << ime << endl;
        cout << "Shapeshifter: " << isShapeshifter << endl;
        cout << "Attack damage: " << attack_damage << endl;
        cout << "Attack speed: " << attack_speed << endl;
        cout << "Ability power: " << ability_power << endl;
        cout << "Power: " << power() << endl;
    }
};

class LegendarySuperHero : public LegendaryHero, public SuperHero {
public:
    LegendarySuperHero(string ime = "", float attack_damage = 0.0, float attack_speed = 0.0, float ability_power = 0.0,
                       int hiddenPowers = 0, bool isShapeshifter = false)
            : Hero(ime, attack_damage, attack_speed, ability_power),
              LegendaryHero(ime, attack_damage, attack_speed, ability_power, hiddenPowers),
              SuperHero(ime, attack_damage, attack_speed, ability_power, isShapeshifter){}

    float power() {
        return (LegendaryHero::power() + SuperHero::power()) / 2;
    }

    void displayInfo() {
        cout << "LegendarySuperHero: " << ime << endl;
        cout << "Attack damage: " << attack_damage << endl;
        cout << "Attack speed: " << attack_speed << endl;
        cout << "Ability power: " << ability_power << endl;
        cout << "Power: " << LegendarySuperHero::power() << endl;
    }
};

Hero *mostPowerfulLegendaryHero(Hero **heroes, int n) {
    LegendaryHero *mostPowerful = nullptr;
    for (int i = 0; i < n; i++) {
        LegendaryHero *legendaryHero = dynamic_cast<LegendaryHero *>(heroes[i]);
        if (legendaryHero) {
            if (!mostPowerful || legendaryHero->power() > mostPowerful->power()) {
                mostPowerful = legendaryHero;
            }
        }

        LegendarySuperHero *legendarySuperHero = dynamic_cast<LegendarySuperHero *>(heroes[i]);
        if (legendarySuperHero) {
            if (!mostPowerful || legendarySuperHero->power() > mostPowerful->power()) {
                mostPowerful = legendarySuperHero;
            }
        }
    }
    return mostPowerful;
}


int main() {
    string name;
    double attackDamage;
    double attackSpeed;
    double abilityPower;
    int hiddenPowers;
    bool isShapeshifter;
    int n;
    int choice;

    cin>>choice;
    if(choice==1)
    {
        cin>>name;
        LegendarySuperHero legendarySuperHero(name, 55, 43, 70, 2, true);
        legendarySuperHero.displayInfo();
    }
    else {

        cin >> n;

        Hero **h = new Hero *[n];
        for (int i = 0; i < n; i++) {
            cin >> choice;
            if (choice == 1) {
                cin >> name >> attackDamage >> attackSpeed >> abilityPower >> hiddenPowers;

                h[i] = new LegendaryHero(name, attackDamage, attackSpeed, abilityPower, hiddenPowers);
            } else {
                cin >> name >> attackDamage >> attackSpeed >> abilityPower >> isShapeshifter;

                h[i] = new SuperHero(name, attackDamage, attackSpeed, abilityPower, isShapeshifter);
            }

        }

        mostPowerfulLegendaryHero(h,n)->displayInfo();

    }


    return 0;
}