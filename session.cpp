#include "session.h"

Session::Session(int id, Film* film, Hall* hall, Time time, Date date) {
    this->id = id;
    this->film = film;
    this->hall = hall;
    this->time.setTime(time);
    this->date.setDate(date);
    this->_initSpace();
}

Session::~Session() {
    for (auto&& ticket : this->tickets) {
        delete ticket;
    }

    for (auto&& row : this->space) {
        for (auto&& num : row) {
            delete num;
        }
    }
}

void Session::_initSpace() {
    for (int row = 1; row <= hall->getRows(); row++) {
        std::vector<Seat*> r;

        for (int num = 1; num <= hall->getNums(); num++) {
            Seat *seat = new Seat(row, num, false);
            r.push_back(seat);
        }

        this->space.push_back(r);
    }
}

int Session::getId() {
    return this->id;
}

void Session::setId(int id) {
    this->id = id;
}

Film* Session::getFilm() {
    return this->film;
}

void Session::setFilm(Film* film) {
    this->film = film;
}

Hall* Session::getHall() {
    return this->hall;
}

void Session::setHall(Hall* hall) {
    this->hall = hall;
}

Time Session::getTime() {
    return this->time;
}

void Session::setTime(Time time) {
    this->time.setTime(time);
}

Date Session::getDate() {
    return this->date;
}

void Session::setDate(Date date) {
    this->date.setDate(date);
}

Seat* Session::getSeatByNum(int row, int num) {
    return this->getSpace()->at(row).at(num);
}

Ticket* Session::sellTicket(int cost, int row, int num, Client* client) {
    Seat* seat = this->getSeatByNum(row, num);
    Ticket* ticket = new Ticket(cost, seat, this);
    this->tickets.push_back(ticket);
    seat->setBooked(true);

    if (client)
        client->addTicket(ticket);

    return ticket;
}

std::vector<Ticket*> Session::getTickets() {
    return this->tickets;
}

std::vector<std::vector<Seat*>>* Session::getSpace() {
    return &this->space;
}
