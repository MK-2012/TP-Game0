#include "BasicUnits.h"


bool Unit::existence() {
    return true;
}

Unit::Unit(PlayerEnum player) : player_(player) {}

bool Unit::canConstruct() {
    return false;
}

const std::string NonExistentUnit::name_ = "nothing";

bool NonExistentUnit::existence() {
    return false;
}

uint16_t NonExistentUnit::hp() {
    return 0;
}

uint16_t NonExistentUnit::damage(PlayerEnum player) {
    return 0;
}

uint16_t NonExistentUnit::distance() {
    return 0;
}

UnitImages NonExistentUnit::image() {
    return image_;
}

bool NonExistentUnit::allowed_to_move() {
    return true;
}

bool NonExistentUnit::allowedToMoveAim(int delta_x, int delta_y) {
    return false;
}

bool NonExistentUnit::get_damage(uint16_t damage) {
    return false;
}

NonExistentUnit::NonExistentUnit(PlayerEnum player) : Unit(player) {}

int NonExistentUnit::cost() {
    return 0;
}

std::string NonExistentUnit::name() {
    return name_;
}

void NonExistentUnit::clearMotions() {}

uint16_t Clubber::hp() {
    return hp_;
}

uint16_t Clubber::damage(PlayerEnum player) {
    if(player == player_) {
        return 0;
    }
    return damage_;
}

uint16_t Clubber::distance() {
    return distance_;
}

UnitImages Clubber::image() {
    return image_;
}

bool Clubber::allowed_to_move() {
    if (num_of_motions < max_motions) {
        ++ num_of_motions;
        return true;
    } else {
        return false;
    }
}

bool Clubber::allowedToMoveAim(int delta_x, int delta_y) {
    return std::abs(delta_x) <= distance_ && std::abs(delta_y) <= distance_;
}

bool Clubber::get_damage(uint16_t damage) {
    if (hp_ < damage) {
        return true;
    } else {
        hp_ -= damage;
        return false;
    }
}

Clubber::Clubber(PlayerEnum player) : Unit(player) {}

int Clubber::cost() {
    return cost_;
}
const std::string Clubber::name_ = "Clubber";

std::string Clubber::name() {
    return name_;
}

void Clubber::clearMotions() {
    num_of_motions = 0;
}

uint16_t Worker::hp() {
    return hp_;
}

uint16_t Worker::damage(PlayerEnum player) {
    if(player == player_) {
        return 0;
    }
    return damage_;
}

uint16_t Worker::distance() {
    return distance_;
}

UnitImages Worker::image() {
    return image_;
}

bool Worker::allowed_to_move() {
    if (num_of_motions < max_motions) {
        ++ num_of_motions;
        return true;
    } else {
        return false;
    }
}

bool Worker::allowedToMoveAim(int delta_x, int delta_y) {
    return std::abs(delta_x) <= distance_ && std::abs(delta_y) <= distance_;
}

bool Worker::get_damage(uint16_t damage) {
    if (hp_ < damage) {
        return true;
    } else {
        hp_ -= damage;
        return false;
    }
}

Worker::Worker(PlayerEnum player) : Unit(player) {}

int Worker::cost() {
    return cost_;
}
const std::string Worker::name_ = "Worker";

std::string Worker::name() {
    return name_;
}

void Worker::clearMotions() {
    num_of_motions = 0;
}

bool Worker::canConstruct() {
    return true;
}


