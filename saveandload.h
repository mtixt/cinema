#ifndef SAVEANDLOAD_H
#define SAVEANDLOAD_H
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QSqlRelationalTableModel>
#include <QSqlError>
#include "date.h"
#include "film.h"
#include "client.h"
#include "time.h"
#include "session.h"
#include "director.h"
#include "hall.h"
#include "ticket.h"


class SaveAndLoad {
private:
    SaveAndLoad() = default;
    ~SaveAndLoad() = default;
    SaveAndLoad(const SaveAndLoad&) = delete;
    SaveAndLoad& operator=(const SaveAndLoad&) = delete;
    void* operator new(std::size_t) = delete;
    void* operator new[](std::size_t) = delete;
    void operator delete(void*) = delete;
    void operator delete[](void*) = delete;

    QString databasePath;
    vector<Film> todayFilms;
    vector<Session> todaySessions;
    vector<Hall> halls;

    QSqlDatabase db;

    // id инкременты для каждого объекта
    int sessionid;
    int filmid;
    int ticketid;
    int clientid;
    int directorid;
    int actorid;
    int statisticid;
    int hallid;

public:
    static SaveAndLoad& init();
    bool setDatabase(QString path="./cinema.db");
    QSqlDatabase& getDB();
    bool dbOpened();
    Time getTime();
    Date getDate();
    Film getFilmByName(string name);
    vector<Film> getFilmsByDirector(string name);
    vector<Film> getFilmsByActor(string name);
    vector<Film> getAllFilms();
    vector<Session> getSessionByDate(Date date);
    vector<Session> getSessionByFilm(string name);
    vector<Session> getAllSessions();
    vector<Hall> getHalls();
    void addFilm(string name, string description, string picID, string genre, int duration, int rating);
    void addSession(Film* film, Date date, Time time);
    void addClient(string name, string lastname, Date bday);
    void addActor(string name, string lastname, Date bday);
    void addDirector(string name, string lastname, Date bday);
    void addHall(int rows, int seats);
    void removeHall(int id);
    void printTicket(Ticket ticket);
    vector<Client> getAllClients();
    Client getClientByName(string name, string lastname);
    vector<Director> getAllDirectors();
};

#endif // SAVEANDLOAD_H
