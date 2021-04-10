#include "Unit.h"


bool Unit::existence() {
    return true;
}

Unit::Unit() = default;

Unit::~Unit() = default;

bool NonExistentUnit::existence() {
    return false;
}

uint16_t NonExistentUnit::hp() {
    return 0;
}

uint16_t NonExistentUnit::damage() {
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

NonExistentUnit::~NonExistentUnit() = default;

NonExistentUnit::NonExistentUnit() = default;

uint16_t Clubber::hp() {
    return hp_;
}

uint16_t Clubber::damage() {
    return damage_;
}

uint16_t Clubber::distance() {
    return distance_;
}

UnitImages Clubber::image() {
    return image_;
}

bool Clubber::allowed_to_move() {
    return true;
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
