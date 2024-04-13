#ifndef FILM_H
#define FILM_H
#include "director.h"
#include <string>
#include <vector>
// #include <algorithm>


using std::string;
using std::vector;


class Actor;

class Film {
private:
    int id;
    string name;
    string description;
    string genre;
    int duration;
    int rating;
    vector<Actor*> actors;
    Director* director;

public:
    Film();
    Film(string name, string description, string genre, int duration, int rating, Director* director, int id);
    int getId();
    int getRating();
    void setRating(int rate);
    void setDuration(int duration);
    string getName();
    string getDescription();
    string getGenre();
    int getDuration();
    void setDescription(string description);
    void setName(string name);
    void setGenre(string genre);
    vector<Actor*> getActors();
    void setDirector(Director* director);
    Director* getDirector();
    void addActor(Actor* actor);
    void delActor(Actor* actor);
    void clearActors();
};


#endif // FILM_H
