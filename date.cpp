#include "date.h"

Date::Date(int day, int month, int year) {
    setDate(day, month, year);
}

Date::Date() {
    setDate(0, 0, 0);
}

void Date::setDate(int day, int month, int year) {
    this->day = day;
    this->month = month;
    this->year = year;
}

void Date::setDate(Date& date) {
    this->day = date.getDay();
    this->month = date.getMonth();
    this->year = date.getYear();
}

int Date::getDay() {
    return this->day;
}

int Date::getMonth() {
    return this->month;
}

int Date::getYear() {
    return this->year;
}

std::string Date::getDate() const {
    std::string strDate;
    strDate = std::to_string(day) + "." + std::to_string(month) + "." + std::to_string(year);
    return strDate;
}

bool Date::operator==(Date& date) {
    return this->getDay() == date.getDay()
           and this->getMonth() == date.getMonth()
           and this->getYear() == date.getYear();
}
