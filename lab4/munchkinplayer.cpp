#include "munchkinplayer.h"
#include <random>
#define number_of_classes 6
#define number_of_races 5

MunchkinPlayer::MunchkinPlayer() : Player(), armour(0), weapon(0) {
    setLevel(1);
    auto randominteger = [](int max) -> int {
        std::random_device rd;  
        std::mt19937 gen(rd()); 
        std::uniform_int_distribution<int> dist(1, max); 
        return dist(gen);
    };
    playerClass = static_cast<munchkinClass>(randominteger(number_of_classes) - 1);
    playerRace = static_cast<munchkinRace>(randominteger(number_of_races) - 1);
};

const void MunchkinPlayer::setPlayerClass(munchkinClass inputClass) {
    playerClass = inputClass;
}

MunchkinPlayer::munchkinClass MunchkinPlayer::getPlayerClass() {
    return playerClass;
}

const void MunchkinPlayer::setPlayerRace(munchkinRace inputRace) {
    playerRace = inputRace;
}

MunchkinPlayer::munchkinRace MunchkinPlayer::getPlayerRace() {
    return playerRace;
}
const void MunchkinPlayer::setArmour(uint8_t inputArmour) {
    armour = inputArmour; 
}

uint8_t MunchkinPlayer::getArmour() { 
    return armour; 
}

const void MunchkinPlayer::setWeapon(uint8_t inputWeapon) { 
    weapon = inputWeapon; 
}

uint8_t MunchkinPlayer::getWeapon() { 
    return weapon; 
}

const void MunchkinPlayer::levelUp() {
    Player::setLevel(getLevel() + 2);
}