#include <iostream>
#include <string>

using namespace std;

class FinalForm {
private:
  int health;
  string weapon, shield, galaxyBoots;

public:
  FinalForm(int h, string w, string s, string gb)
      : health(h), weapon(w), shield(s), galaxyBoots(gb) {}
  ~FinalForm() {};
  void attack() { cout << "Attacking with a sword\n"; }
  void defend() { cout << "Defended a blow\n"; }
  void run() { cout << "Sprinting\n"; }
};

class Tools {
public:
  string shield = "Iron";
  string galaxyBoots = "Galaxy";
};

class legacyHero {
private:
  int health;
  string weapon;

public:
  legacyHero(int h, string w) : health(h), weapon(w) {}
  ~legacyHero() {};
  void attack() { cout << "Attacking with a sword\n"; }
  FinalForm operator+(Tools &t) {
    return FinalForm(this->health, this->weapon, t.shield, t.galaxyBoots);
  }
};

int main() {
  int level = 10;
  legacyHero hero(100, "sword");
  if (level >= 10) {
    cout << "You got an upgrade!!!\n";
    Tools t;
    FinalForm finalHero = hero + t;
    finalHero.attack();
    finalHero.defend();
    finalHero.run();
  }
}
