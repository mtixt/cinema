#include "client.h"

Client::Client(std::string name, std::string lastname, Date birthday, int id) : Human(name, lastname, birthday) {
    this->discount = 0;
    this->totalTicketPurchased = 0;
    this->id = id;
}

void Client::autoDiscount() {
    if (this->totalTicketPurchased >= 10)   setDiscount(5);
    if (this->totalTicketPurchased >= 20)   setDiscount(10);
    if (this->totalTicketPurchased >= 50)   setDiscount(15);
    if (this->totalTicketPurchased >= 100)  setDiscount(20);
    if (this->totalTicketPurchased >= 250)  setDiscount(30);
    if (this->totalTicketPurchased >= 500)  setDiscount(40);
    if (this->totalTicketPurchased >= 1000) setDiscount(50);
}

std::vector<Ticket*> Client::getTickets() {
    return this->tickets;
}

int Client::getDiscount() {
    return this->discount;
}

int Client::getTotalTicketPurchased() {
    return this->totalTicketPurchased;
}

void Client::setDiscount(int discount) {
    this->discount = discount;
}

void Client::setTotalTicketPurchased(int totalTicketPurchased) {
    this->totalTicketPurchased = totalTicketPurchased;
}

void Client::addTicket(Ticket* ticket) {
    this->tickets.push_back(ticket);
    totalTicketPurchased++;
}

int Client::getId() {
    return this->id;
}
