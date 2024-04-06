#include "ticket.h"


Ticket::Ticket() {
    this->cost = -1;
    this->seat = nullptr;
    this->session = nullptr;
    this->client = nullptr;
}

Ticket::Ticket(int cost, Seat* seat, Session* session, Client* client, int id) {
    this->id = id;
    this->cost = cost;
    this->seat = seat;
    this->session = session;
    this->client = client;
}

int Ticket::getCost() {
    return this->cost;
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

void Ticket::setCost(int cost){
    this->cost = cost;
}

void Ticket::setSeat(Seat* seat){
    this->seat = seat;
}

void Ticket::setSession(Session* session){
    this->session = session;
}

