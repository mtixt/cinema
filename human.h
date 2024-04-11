#ifndef HUMAN_H
#define HUMAN_H
#include <string>
#include "date.h"


class Human {
private:
    std::string name;
    std::string lastname;
    Date birthday;

public:
    Human(std::string name, std::string lastname, Date& birthday);
    std::string getName();
    std::string getLastname();
    Date getBirthday();
    void setName(std::string name);
    void setLastname(std::string lastname);
    void setBirthday(Date& date);
};

#endif // HUMAN_H
