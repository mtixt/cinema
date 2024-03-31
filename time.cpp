#include "time.h"

Time::Time(int hours, int minutes) {
    this->setTime(hours, minutes);
}

Time::Time() {
    this->setTime(-1, -1);
}

void Time::setTime(int hours, int minutes) {
    this->hours = hours;
    this->minutes = minutes;
}

void Time::setTime(Time& time) {
    this->hours = time.getHours();
    this->minutes = time.getMinutes();
}

int Time::getHours() {
    return this->hours;
}

int Time::getMinutes() {
    return this->minutes;
}

std::string Time::getTime() {
    std::string strTime;
    strTime = std::to_string(hours) + ":" + std::to_string(minutes);
    return strTime;
}
