#ifndef ACTOR_H
#define ACTOR_H
#include "human.h"
#include "film.h"
#include <vector>


class Actor : public Human {
private:
    int id;
    std::vector<Film*> films;

public:
    Actor(std::string name, std::string lastname, Date birthday, int id = -1);
    std::vector<Film*> getFilms();
    void addFilm(Film* film);
};


#endif // ACTOR_H
