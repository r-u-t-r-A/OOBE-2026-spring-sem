#include "player.h"
#include <iostream>

int main(void) {
    Player newplayer;
    
    std::string nameCopy = newplayer.getName();
    uint32_t idCopy = newplayer.getId();
    uint8_t levelCopy = newplayer.getLevel();

    std::cout << "--- Printing Values ---\n";
    std::cout << "Name (Getter):   " << nameCopy << "\n";
    std::cout << "Name (DebugRef): " << newplayer.debugReference<PlayerField::Name>() << "\n";
    std::cout << "Name (DebugPtr): " << *newplayer.debugPointer<PlayerField::Name>() << "\n\n";

    std::cout << "ID (Getter):     " << idCopy << "\n";
    std::cout << "ID (DebugRef):   " << newplayer.debugReference<PlayerField::Id>() << "\n";
    std::cout << "ID (DebugPtr):   " << *newplayer.debugPointer<PlayerField::Id>() << "\n\n";

    std::cout << "--- Printing Memory Addresses ---\n";
    
    std::cout << "[Name]\n";
    std::cout << "Getter Copy Addr: " << (void*)&nameCopy << "\n";
    std::cout << "Debug Ref Addr:   " << (void*)&newplayer.debugReference<PlayerField::Name>() << "\n";
    std::cout << "Debug Ptr Addr:   " << (void*)newplayer.debugPointer<PlayerField::Name>() << "\n\n";

    std::cout << "[ID]\n";
    std::cout << "Getter Copy Addr: " << (void*)&idCopy << "\n";
    std::cout << "Debug Ref Addr:   " << (void*)&newplayer.debugReference<PlayerField::Id>() << "\n";
    std::cout << "Debug Ptr Addr:   " << (void*)newplayer.debugPointer<PlayerField::Id>() << "\n";

    return 0;
}