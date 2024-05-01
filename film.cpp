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

void Film::setDuration(int duration)
{
    this->duration = duration;
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

void Film::setGenre(string genre)
{
    this->genre = genre;
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

void Film::addActor(Actor* actor) {
    if (actor) {
        this->actors.push_back(actor);
    }
}

void Film::clearActors() {
    this->actors.clear();
}

void Film::delActor(Actor* actor) {
    vector<Actor*>::iterator f;
    f = std::find(this->actors.begin(), this->actors.end(), actor);

    if (f != this->actors.end()) {
        this->actors.erase(f);
    }
}
