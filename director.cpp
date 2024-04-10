#include "director.h"

Director::Director(std::string name, std::string lastname, Date& birthday, int id) : Human(name, lastname, birthday) {
    this->id = id;
}

std::vector<Film*> Director::getFilms() {
    return this->films;
}

void Director::addFilm(Film* film) {
    this->films.push_back(film);
}

void Director::setSoldAtDay(Date date, int sold) {
    this->statistic.setSoldAtDay(date, sold);
}

void Director::addSoldAtDay(Date date, int amount) {
    this->statistic.addSoldAtDay(date, amount);
}

int Director::getSoldAtDay(Date date) {
    return this->statistic.getSoldAtDay(date);
}

int Director::getSoldTotal() {
    return this->statistic.getSoldTotal();
}

int Director::getId() {
    return this->id;
}

Statistic Director::getStatistic() {
    return this->statistic;
}
