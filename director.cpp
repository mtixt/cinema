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

void Director::clearFilms()
{
    this->films.clear();
}

int Director::getId() {
    return this->id;
}
