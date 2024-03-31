#include "seat.h"

Seat::Seat() {
    this->row = -1;
    this->seatNum = -1;
    this->booked = false;
}

Seat::Seat(int row, int seatNum, bool isBooked) {
    this->row = row;
    this->seatNum = seatNum;
    this->booked = isBooked;
}

int Seat::getRow() {
    return this->row;
}

int Seat::getNum() {
    return this->seatNum;
}

bool Seat::isBooked() {
    return this->booked;
}

void Seat::setBooked(bool isBooked) {
    this->booked = isBooked;
}

void Seat::setPosition(int row, int num) {
    this->row = row;
    this->seatNum = num;
}


