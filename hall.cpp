#include "hall.h"

Hall::Hall() {
    this->id = -1;
    this->rows = -1;
    this->seatNums = -1;
}

Hall::Hall(int id, int rows, int seatNums) {
    this->id = id;
    this->rows = rows;
    this->seatNums = seatNums;
}

void Hall::setID(int id) {
    this->id = id;
}

int Hall::getID() {
    return this->id;
}

int Hall::getRows() {
    return this->rows;
}

int Hall::getNums() {
    return this->seatNums;
}

void Hall::setSpace(int rows, int nums) {
    this->rows = rows;
    this->seatNums = nums;
}

