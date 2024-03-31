#ifndef HALL_H
#define HALL_H
#include <vector>


class Hall {
private:
    int id;
    int rows;
    int seatNums;

public:
    Hall();
    Hall(int id, int rows, int seatNums);
    void setID(int id);
    int getID();
    int getRows();
    int getNums();
    void setSpace(int rows, int nums);
};

#endif // HALL_H
