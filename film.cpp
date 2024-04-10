#include "film.h"

Film::Film() {
    this->name = "";
    this->description = "";
    this->genre = "";
    this->duration = -1;
    this->rating = -1;
    this->id = -1;
    Director* director = nullptr;
}

Film::Film(string name, string description, string genre, int duration, int rating, Director* director, int id) {
    this->name = name;
    this->description = description;
    this->genre = genre;
    this->duration = duration;
    this->rating = rating;
    this->director = director;
    this->id = id;
}

int Film::getId() {
    return this->id;
}

int Film::getRating() {
    return this->rating;
}

void Film::setRating(int rate) {
    this->rating = rate;
}

string Film::getName() {
    return this->name;
}

string Film::getDescription() {
    return this->description;
}

string Film::getGenre() {
    return this->genre;
}

int Film::getDuration() {
    return this->duration;
}

void Film::setDescription(string description) {
    this->description = description;
}

void Film::setName(string name) {
    this->name = name;
}

vector<Actor*> Film::getActors() {
    return this->actors;
}

void Film::setDirector(Director* director) {
    this->director = director;
}

Director* Film::getDirector() {
    return this->director;
}

Statistic Film::getStatistic() {
    return this->statistic;
}

void Film::addActor(Actor* actor) {
    this->actors.push_back(actor);
}

void Film::delActor(Actor* actor) {
    vector<Actor*>::iterator f;
    f = std::find(this->actors.begin(), this->actors.end(), actor);

    if (f != this->actors.end()) {
        this->actors.erase(f);
    }
}

void Film::setSoldAtDay(Date date, int sold) {
    this->statistic.setSoldAtDay(date, sold);
    if (this->director) {
        this->director->addSoldAtDay(date, sold);
    }
}

void Film::addSoldAtDay(Date date, int amount) {
    this->statistic.addSoldAtDay(date, amount);
    if (this->director) {
        this->director->addSoldAtDay(date, amount);
    }
}

int Film::getSoldAtDay(Date date) {
    return this->statistic.getSoldAtDay(date);
}

int Film::getSoldTotal() {
    return this->statistic.getSoldTotal();
}
