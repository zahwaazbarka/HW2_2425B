
#include "Pirate.h"


Pirate::Pirate(const string& name): name(name),bounty(0),devilFruit() {}
Pirate::Pirate():name(""),bounty(0),devilFruit() {}
Pirate::Pirate(const string& name, DEVIL_FRUIT devilFruit): name(name), devilFruit(devilFruit) {}
Pirate::Pirate(const string& name, const int& bounty,DEVIL_FRUIT devilFruit): name(name), bounty(bounty),devilFruit(devilFruit) {}

void Pirate::setName(const string& name){
    this->name = name;
}
void Pirate::setBounty(const int& bounty) {
    this->bounty = bounty;
}
int Pirate::getBounty(){
    return bounty;
}

void Pirate::setDevilFruit(DEVIL_FRUIT devilFruit){
    this->devilFruit = devilFruit;
}


std::string Pirate::getName(){
    return name;
}


DEVIL_FRUIT Pirate::getDevilFruit(){
    return devilFruit;
}


const char* const devilFruitNames[] = {
    "Gum Gum",
    "Smoke Smoke",
    "Flame Flame",
    "Rumble Rumble",
    "String String",
    "Ice Ice",
    "None"
};

std::ostream &operator<<(std::ostream &os, const Pirate &pirate){
    os << pirate.name << " " << pirate.bounty<< " (Devil Fruit: " << devilFruitNames[pirate.devilFruit] << ")";
    return os;
}
