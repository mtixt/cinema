#include "human.h"

Human::Human(std::string name, std::string lastname, Date birthday) {
    setName(name);
    setLastname(lastname);
    setBirthday(birthday);
}

std::string Human::getName() {
    return this->name;
}

std::string Human::getLastname() {
    return this->lastname;
}
Date Human::getBirthday() {
    return this->birthday;
}

void Human::setName(std::string name) {
    this->name = name;
}

void Human::setLastname(std::string lastname) {
    this->lastname = lastname;
}

void Human::setBirthday(Date birthday) {
    this->birthday.setDate(birthday);
}
