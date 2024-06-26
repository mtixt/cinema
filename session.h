#ifndef SESSION_H
#define SESSION_H
#include "film.h"
#include "time.h"
#include "date.h"
#include "hall.h"
#include "client.h"
#include "seat.h"
#include "ticket.h"
#include <vector>
// #include <algorithm>


class Session {
private:
    int id;
    Film* film;
    Hall* hall;
    Time time;
    Date date;
    std::vector<Ticket*> tickets;
    std::vector<std::vector<Seat*>> space;
    void _initSpace();

public:
    Session(int id, Film* film, Hall* hall, Time time, Date date);
    ~Session();
    int getId();
    void setId(int id);
    Film* getFilm();
    void setFilm(Film* film);
    Hall* getHall();
    void setHall(Hall* hall);
    Time getTime();
    void setTime(Time time);
    Date getDate();
    void setDate(Date date);
    Seat* getSeatByNum(int row, int num);
    void bookSeat(int row, int num, Ticket* ticket = nullptr);
    std::vector<Ticket*> getTickets();
    std::vector<std::vector<Seat*>>* getSpace();
};

#endif // SESSION_H
