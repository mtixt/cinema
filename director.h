#ifndef DIRECTOR_H
#define DIRECTOR_H
#include "human.h"
#include <vector>


class Film;

class Director : public Human {
private:
    int id;
    std::vector<Film*> films;

public:
    Director(std::string name, std::string lastname, Date& birthday, int id = -1);
    std::vector<Film*> getFilms();
    void addFilm(Film* film);
    int getId();
};

#endif // DIRECTOR_H
