#ifndef TIME_H
#define TIME_H
#include <string>


class Time {
private:
    int hours;
    int minutes;

public:
    Time();
    Time(int hours, int minutes);
    void setTime(int hours, int minutes);
    void setTime(Time& time);
    int getHours();
    int getMinutes();
    std::string getTime();
};

#endif // TIME_H
