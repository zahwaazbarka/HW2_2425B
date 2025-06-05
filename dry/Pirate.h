
#pragma once

#include <iostream>

using std::string;

enum DEVIL_FRUIT {
    GUM_GUM_FRUIT,
    SMOKE_SMOKE_FRUIT,
    FLAME_FLAME_FRUIT,
    RUMBLE_RUMBLE_FRUIT,
    STRING_STRING_FRUIT,
    ICE_ICE_FRUIT,
    NONE
};

class Pirate {
private:
    string name;
    int bounty;
public:
    DEVIL_FRUIT devilFruit;
    Pirate(const string& name);
    Pirate();
    Pirate(const string& name, DEVIL_FRUIT devilFruit = DEVIL_FRUIT::NONE);
    Pirate(const string& name,const int& bounty ,DEVIL_FRUIT devilFruit = DEVIL_FRUIT::NONE);


    ~Pirate() = default;
    void setName(const string& name);
    void setBounty(const int& bounty);
    int getBounty();
    void setDevilFruit(DEVIL_FRUIT devilFruit);
    string getName();
    DEVIL_FRUIT getDevilFruit();

    friend std::ostream &operator<<(std::ostream &os, const Pirate &pirate);
};
