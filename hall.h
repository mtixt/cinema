#ifndef HALL_H
#define HALL_H
// #include <vector>


class Hall {
private:
    int id;
    int rows;
    int seatNums;

public:
    Hall();
    Hall(int id, int rows, int seatNums);
    void setId(int id);
    int getId();
    int getRows();
    int getNums();
    void setSpace(int rows, int nums);
};

#endif // HALL_H
