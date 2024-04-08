#ifndef SAVEANDLOAD_H
#define SAVEANDLOAD_H
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlField>
#include <QSqlError>
#include "date.h"
#include "film.h"
#include "actor.h"
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
    SaveAndLoad(const SaveAndLoad&)            = delete;
    SaveAndLoad&    operator=(const SaveAndLoad&)   = delete;
    void*           operator new(std::size_t)       = delete;
    void*           operator new[](std::size_t)     = delete;
    void            operator delete(void*)          = delete;
    void            operator delete[](void*)        = delete;

    QString databasePath;
    QSqlDatabase db;

    vector<Film*>       todayFilms;
    vector<Session*>    todaySessions;

    vector<Film*>       films;
    vector<Hall*>       halls;
    vector<Actor*>      actors;
    vector<Client*>     clients;
    vector<Ticket*>     tickets;
    vector<Session*>    sessions;
    vector<Director*>   directors;
    vector<Statistic*>  statistics;

    // id инкременты для каждого объекта
    int sessionid;
    int filmid;
    int ticketid;
    int clientid;
    int directorid;
    int actorid;
    int statisticid;
    int hallid;

    bool _addClient(string name, string lastname, Date bday, int id, int totalTicketPurchased, int discount);
    bool _addDirector(string name, string lastname, Date bday, int id, int soldTotal, string soldByDay);
    bool _addFilm(string name, string description, string genre, int duration, int rating, string soldByDay, Director* director = nullptr, int id = -1);

public:
    static SaveAndLoad& init();
    bool                setDatabase(QString path="./cinema.db");
    QSqlDatabase&       getDB();
    bool                dbOpened();

    bool loadData();
    bool loadFilms();
    bool loadActors();
    bool loadHalls();
    bool loadClients();
    bool loadSessions();
    bool loadTickets();
    bool loadDirectors();
    bool loadFilmsActors();

    Time                getTime();
    Date                getDate();
    Film                getFilmByName(string name);
    vector<Film*>       getFilmsByDirector(string name);
    vector<Film*>       getFilmsByActor(string name);
    vector<Film*>       getAllFilms();
    vector<Session*>    getSessionByDate(Date date);
    vector<Session*>    getSessionByFilm(string name);
    vector<Session*>    getAllSessions();
    vector<Hall*>       getHalls();
    vector<Client*>     getAllClients();
    vector<Ticket*>     getAllTickets();
    Client              getClientByName(string name, string lastname);
    vector<Director*>   getAllDirectors();
    vector<Actor*>      getAllActors();
    vector<Statistic*>  getAllStatistics();
    Film*               getFilmById(int id);
    Session*            getSessionById(int id);
    Client*             getClientById(int id);
    Hall*               getHallById(int id);
    Ticket*             getTicketById(int id);
    Director*           getDirectorById(int id);
    Actor*              getActorById(int id);
    Statistic*          getStatisticById(int id);

    void addFilm(string name, string description, string genre, int duration, int rating, Director* director = nullptr, int id = -1);
    void addSession(Film* film, Hall* hall, Time time, Date date, int id = -1);
    void addClient(string name, string lastname, Date bday, int id = -1);
    void addActor(string name, string lastname, Date bday, int id = -1);
    void addDirector(string name, string lastname, Date bday, int id = -1);
    void addHall(int rows, int seats, int id = -1);
    void removeHall(int id);
    void printTicket(Ticket ticket);
};

#endif // SAVEANDLOAD_H
