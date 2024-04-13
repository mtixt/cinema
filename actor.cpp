#include "actor.h"

Actor::Actor(std::string name, std::string lastname, Date birthday, int id) : Human(name, lastname, birthday) {
    this->id = id;
}

std::vector<Film*> Actor::getFilms() {
    return this->films;
}

void Actor::addFilm(Film* film) {
    if (film)
        this->films.push_back(film);
}

int Actor::getId() {
    return this->id;
}
