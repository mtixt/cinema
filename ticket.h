#ifndef TICKET_H
#define TICKET_H
#include "seat.h"
#include "client.h"

class Session;

class Ticket {
private:
    int id;
    int cost;
    Client* client;
    Seat* seat;
    Session* session;

public:
    Ticket();
    Ticket(int cost, Seat* seat, Session* session, Client* client = nullptr, int id = -1);
    int getCost();
    int getId();
    Seat* getSeat();
    Session* getSession();
    void setCost(int cost);
    void setSeat(Seat* seat);
    void setSession(Session* session);
};

#endif // TICKET_H
