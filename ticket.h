#ifndef TICKET_H
#define TICKET_H
#include "seat.h"

class Session;

class Ticket {
private:
    int id;
    int cost;
    Seat* seat;
    Session* session;

public:
    Ticket();
    Ticket(int cost, Seat* seat, Session* session, int id = -1);
    int getCost();
    Seat* getSeat();
    Session* getSession();
    void setCost(int cost);
    void setSeat(Seat* seat);
    void setSession(Session* session);
};

#endif // TICKET_H
