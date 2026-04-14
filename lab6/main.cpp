#include "family.h"
#include <iostream>
#include <string>

int main(void) {

    Child child("Ala");
    Mother mother;
    Father father;
    FriendFromSchool friendFromSchool;
    father.combatAssignment(child, "a toy");
    father.combatAssignment(child, 2137);
    father.combatAssignment(child, 3.14);

    return 0;
}