#ifndef SEAT_H
#define SEAT_H


class Seat {
private:
    int row;
    int seatNum;
    bool booked;

public:
    Seat();
    Seat(int row, int seatNum, bool isBooked);
    int getRow();
    int getNum();
    bool isBooked();
    void setBooked(bool isBooked);
    void setPosition(int row, int num);
};

#endif // SEAT_H
