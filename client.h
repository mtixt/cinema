#ifndef CLIENT_H
#define CLIENT_H
#include <vector>
#include "human.h"


class Ticket;

class Client : public Human {
private:
    int id;
    int discount;                   // in percent
    int totalTicketPurchased;
    std::vector<Ticket*> tickets;

public:
    Client(std::string name, std::string lastname, Date birthday, int id = -1);
    void autoDiscount();
    std::vector<Ticket*> getTickets();
    void setDiscount(int discount);
    int getDiscount();
    int getTotalTicketPurchased();
    void setTotalTicketPurchased(int totalTicketPurchased);
    void addTicket(Ticket* ticket);
    int getId();
};

#endif // CLIENT_H
