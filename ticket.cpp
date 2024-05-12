#include "ticket.h"


Ticket::Ticket() {
    this->seat = nullptr;
    this->session = nullptr;
    this->client = nullptr;
}

Ticket::Ticket(Seat* seat, Session* session, Client* client, int id) {
    this->id = id;
    this->seat = seat;
    this->session = session;
    this->client = client;
}

int Ticket::getId() {
    return this->id;
}

Seat* Ticket::getSeat(){
    return this->seat;
}

Session* Ticket::getSession(){
    return this->session;
}

Client* Ticket::getClient(){
    return this->client;
}

void Ticket::setSeat(Seat* seat){
    this->seat = seat;
}

void Ticket::setSession(Session* session){
    this->session = session;
}

