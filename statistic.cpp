#include "statistic.h"

Statistic::Statistic(int id) {
    this->id = id;
    this->soldTotal = 0;
}

void Statistic::setSoldAtDay(Date date, int sold) {
    this->soldByDay[date] = sold;
}

void Statistic::addSoldAtDay(Date date, int amount) {
    this->soldByDay[date] += amount;
}

int Statistic::getSoldAtDay(Date date) {
    return this->soldByDay[date];
}

int Statistic::getSoldTotal() {
    return soldTotal;
}
