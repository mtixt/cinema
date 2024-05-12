#ifndef TICKET_H
#define TICKET_H
#include "seat.h"
#include "client.h"

class Session;

class Ticket {
private:
    int id;
    Client* client;
    Seat* seat;
    Session* session;

public:
    Ticket();
    Ticket(Seat* seat, Session* session, Client* client = nullptr, int id = -1);
    int getId();
    Seat* getSeat();
    Session* getSession();
    Client* getClient();
    void setSeat(Seat* seat);
    void setSession(Session* session);
};

#endif // TICKET_H
