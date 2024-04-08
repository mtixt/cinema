#ifndef FILM_H
#define FILM_H
#include "statistic.h"
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
    Statistic statistic;

public:
    Film();
    Film(string name, string description, string genre, int duration, int rating, Director* director, int id);
    int getId();
    int getRating();
    void setRating(int rate);
    string getName();
    string getDescription();
    void setDescription(string description);
    void setName(string name);
    vector<Actor*> getActors();
    void setDirector(Director* director);
    Director* getDirector();
    void addActor(Actor* actor);
    void delActor(Actor* actor);
    void setSoldAtDay(Date date, int sold);
    void addSoldAtDay(Date date, int amount);
    int getSoldAtDay(Date date);
    int getSoldTotal();
};


#endif // FILM_H
