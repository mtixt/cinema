#ifndef DIRECTOR_H
#define DIRECTOR_H
#include "human.h"
#include "statistic.h"
#include <vector>


class Film;

class Director : public Human {
private:
    int id;
    Statistic statistic;
    std::vector<Film*> films;

public:
    Director(std::string name, std::string lastname, Date birthday, int id = -1);
    std::vector<Film*> getFilms();
    void addFilm(Film* film);
    void setSoldAtDay(Date date, int sold);
    void addSoldAtDay(Date date, int amount);
    int getSoldAtDay(Date date);
    int getSoldTotal();
    int getId();
};

#endif // DIRECTOR_H
