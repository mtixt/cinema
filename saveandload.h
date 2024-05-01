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
    SaveAndLoad(const SaveAndLoad&) = delete;

    SaveAndLoad&    operator =(const SaveAndLoad&)  = delete;
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

    bool saveData();
    bool saveFilms();
    bool saveActors();
    bool saveHalls();
    bool saveClients();
    bool saveSessions();
    bool saveTickets();
    bool saveDirectors();
    bool saveFilmsActors();


    Time                getTime();
    Date                getDate();
    Film*               getFilmByName(string name);

    vector<Film*>       getFilmsByDirector(string name);
    vector<Film*>       getFilmsByActor(string name);
    vector<Film*>       getFilmsByDate(Date date);
    vector<Film*>       getAllFilms();
    vector<Session*>    getSessionByDate(Date date);
    vector<Session*>    getSessionByFilm(string name);
    vector<Session*>    getSessionByFilm(Film* film);
    vector<Session*>    getAllSessions();
    vector<Hall*>       getHalls();
    vector<Client*>     getAllClients();
    vector<Ticket*>     getAllTickets();

    Client*             getClientByName(string name, string lastname);
    vector<Director*>   getAllDirectors();
    vector<Actor*>      getAllActors();
    Film*               getFilmById(int id);
    Session*            getSessionById(int id);
    Client*             getClientById(int id);
    Hall*               getHallById(int id);
    Ticket*             getTicketById(int id);
    Director*           getDirectorById(int id);
    Actor*              getActorById(int id);


    Film* addFilm(string name, string description, string genre, int duration, int rating, Director* director = nullptr, int id = -1);
    Session* addSession(Film* film, Hall* hall, Time time, Date date, int id = -1);
    Client* addClient(string name, string lastname, Date bday, int id = -1);
    Actor* addActor(string name, string lastname, Date bday, int id = -1);
    Director* addDirector(string name, string lastname, Date& bday, int id = -1);
    Hall* addHall(int rows, int seats, int id = -1);

    void delFilm(int id);
    void delSession(int id);
    void delActor(int id);
    void delClient(int id);
    void delDirector(int id);
    void delHall(int id);

    void filmAddActor(Film* film, Actor* actor);

    void printTicket(Ticket ticket);
};

#endif // SAVEANDLOAD_H
