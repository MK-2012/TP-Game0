#include "Cursor.h"



void Cursor::move(int delta_x, int delta_y) {
    if (!unit_attached) {
        if ((delta_x + x) >= 0 && (delta_y + y) >= 0 && (delta_x + x) < field_.x_size &&
            (delta_y + y) < field_.y_size) {
            x += delta_x;
            y += delta_y;
        }
    } else {
        if (field_.cellIsFree(static_cast<int>(x) + delta_x, static_cast<int>(y)  + delta_y)) {
            if (field_[x][y]->located_unit->allowed_to_move()) {
                Cell* next_place = field_[static_cast<int>(x) + delta_x][static_cast<int>(y) + delta_y];
                std::swap(field_[x][y]->located_unit, next_place->located_unit);
                x += delta_x;
                y += delta_y;
            }
        }
    }
}

Cursor::Cursor(Field& field, PlayerEnum player, size_t x, size_t y): field_(field), x(x), y(y), unit_attached(false), player_(player) {}
Cursor::Cursor(const Cursor& other) = default;
Cursor::~Cursor() = default;

CursorImages Cursor::image() const {
    if (unit_attached){
        return CursorWithUnitImage;
    } else {
        return CursorWithoutUnitImage;
    }
}
void Cursor::move_up() {
    move(0, -1);
};
void Cursor::move_down() {
    move(0, 1);
};
void Cursor::move_left() {
    move(-1, 0);
};
void Cursor::move_right() {
    move(1, 0);
};
void Cursor::attachUnit() {
    if (unit_attached) {
        throw UnitAttachingException("unit already attached");
    } else if (!(field_[x][y]->located_unit-> existence())){
        throw UnitAttachingException("You can't attach non existent unit");
    } else if (player_ != field_[x][y]->located_unit->player_){
        throw UnitAttachingException("It's not your unit");
    } else {
        unit_attached = true;
    }
}
void Cursor::detachUnit() {
    if (!unit_attached) {
        throw UnitAttachingException("there is no attached units");
    } else {
        unit_attached = false;
    }
}

Cell *Cursor::get_cell() {
    return field_[x][y];
}


Aim::Aim(const Cursor& cursor): Cursor(cursor), creator(cursor) {};
void Aim::move(int delta_x, int delta_y) {
    int x_new = static_cast<int>(x) + delta_x;
    int y_new = static_cast<int>(y) + delta_y;
    if((x_new) >= 0 && (y_new) >= 0 && (x_new) < field_.x_size && (y_new) < field_.y_size) {
        if (field_[creator.x][creator.y]->located_unit->allowedToMoveAim(x_new - static_cast<int>(creator.x), y_new - static_cast<int>(creator.y))) {
            x += delta_x;
            y += delta_y;
        }
    }
}
CursorImages Aim::image() const {
    return AimImage;
}
void Aim::attack() {
    if (field_[x][y] -> located_unit != field_[creator.x][creator.y]->located_unit) {
        if (field_[x][y]->located_unit->get_damage(field_[creator.x][creator.y]->located_unit->damage(field_[x][y]->located_unit->player_))) {
            delete field_[x][y]->located_unit;
            field_[x][y]->located_unit = new NonExistentUnit(Nobody);
        }
    }
}
Aim::~Aim() = default;
