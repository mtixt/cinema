#ifndef DATE_H
#define DATE_H
#include <string>


class Date {
private:
    int day;
    int month;
    int year;

public:
    Date();
    Date(int day, int month, int year);
    void setDate(int day, int month, int year);
    void setDate(Date& date);
    int getDay();
    int getMonth();
    int getYear();
    std::string getDate() const;

    bool operator==(Date& date);
};

#endif // DATE_H
