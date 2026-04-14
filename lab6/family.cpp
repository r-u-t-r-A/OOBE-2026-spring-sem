#include "family.h"

Mother::Mother() {
}

void Mother::setNameOfChild(Child& child, const std::string& name) {
    child.setName(name);
}

Child::Child(const std::string& name) {
    setName(name);
}


std::string Child::getName() const {
    return name;
}

void Child::setName(const std::string& name) {
    this->name = name;
}

const std::string FriendFromSchool::play(Child& child) {
    return child.getName() + " is playing";
}


Father::Father() {
}
