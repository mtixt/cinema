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
#include <algorithm>


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
    int getID();
    void setID(int id);
    Film* getFilm();
    void setFilm(Film* film);
    Hall* getHall();
    void setHall(Hall* hall);
    Time getTime();
    void setTime(Time time);
    Date getDate();
    void setDate(Date date);
    Ticket* sellTicket(int cost, int row, int num, Client* client=nullptr);
    Seat* getSeatByNum(int row, int num);
    std::vector<Ticket*> getTickets();
    std::vector<std::vector<Seat*>>* getSpace();
};

#endif // SESSION_H
