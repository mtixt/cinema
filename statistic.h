#ifndef STATISTIC_H
#define STATISTIC_H
#include <map>
#include "date.h"
#include <string>


class Statistic {
private:
    int id;
    int soldTotal;
    std::map<Date, int> soldByDay;
    void _setSoldByDay(std::string soldByDay);

public:
    Statistic(int id = -1);
    void setSoldAtDay(Date date, int sold);
    void addSoldAtDay(Date date, int amount);
    int getSoldAtDay(Date date);
    int getSoldTotal();
    int getId();
};

#endif // STATISTIC_H
