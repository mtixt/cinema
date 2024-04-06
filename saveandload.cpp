#include "saveandload.h"

SaveAndLoad& SaveAndLoad::init() {
    static SaveAndLoad obj;
    return obj;
}

bool SaveAndLoad::setDatabase(QString path) {
    if (this->db.isOpen()) {
        return false;
    }

    this->databasePath = path;
    this->db = QSqlDatabase::addDatabase("QSQLITE");
    this->db.setDatabaseName(path);

    return true;
}

bool SaveAndLoad::dbOpened() {
    return this->db.open();
}

QSqlDatabase& SaveAndLoad::getDB() {
    return this->db;
}

Time SaveAndLoad::getTime() {
    Time time;

    /*
        получить системное время
    */

    return time;
}

Date SaveAndLoad::getDate() {
    Date date;

    /*
        получить системную дату
    */

    return date;
}

Film SaveAndLoad::getFilmByName(string name) {
    Film film;

    /*
        - film = БД.Films.Where(@film => @film.Name == name).Select().FirstOrDefault();
    */

    return film;
}

vector<Film*> SaveAndLoad::getFilmsByDirector(string name) {
    vector<Film*> films;

    // QSqlQuery query = QSqlQuery(this->getDB());
    // query.exec("SELECT * FROM films");


    // QSqlQuery query = QSqlQuery(this->getDB());
    // query.exec("SELECT * FROM films");

    // while (query.next()) {

    //     qDebug() << query.record().field("name").value().toString();
    //     qDebug() << query.record().field("description").value().toString();
    //     // qDebug() << query.record();
    // }


    /*
        - film = БД.Films.Where(@film => @film.Director == name).Select();
    */

    return films;
}

vector<Film*> SaveAndLoad::getFilmsByActor(string name) {
    vector<Film*> films;

    /*
        - film = БД.Films.Where(@film => @film.Actor == name).Select();
    */

    return films;
}

vector<Film*> SaveAndLoad::getAllFilms() {
    vector<Film*> films;

    /*
        - film = БД.Films.Select();
    */

    return films;
}

vector<Session*> SaveAndLoad::getSessionByDate(Date date) {
    vector<Session*> sessions;

    /*
        - sessions = БД.Sessions.Where(@session => @session.Date == date).Select();
    */

    return sessions;
}

vector<Session*> SaveAndLoad::getSessionByFilm(string name) {
    vector<Session*> sessions;

    /*
        - sessions = БД.Sessions.Where(@sessions => @session.Film == name).Select();
    */

    return sessions;
}

vector<Session*> SaveAndLoad::getAllSessions() {
    vector<Session*> sessions;

    /*
        - sessions = БД.Sessions.Select();
    */

    return sessions;
}

vector<Hall*> SaveAndLoad::getHalls() {
    vector<Hall*> halls;

    /*
        - halls = БД.Halls.Select();
    */

    return halls;
}

void SaveAndLoad::addFilm(string name, string description, string picID, string genre, int duration, int rating) {
    /*
       БД.Films.Insert(@name = name, @description = description, @picID = picID, @genre = genre, @duration = duration, @rating = rating);
    */
}

void SaveAndLoad::addSession(Film* film, Date date, Time time) {

}

void SaveAndLoad::addClient(string name, string lastname, Date bday) {

}

void SaveAndLoad::addActor(string name, string lastname, Date bday) {

}

void SaveAndLoad::addDirector(string name, string lastname, Date bday) {

}

void SaveAndLoad::addHall(int rows, int seats) {

}

void SaveAndLoad::removeHall(int id) {

}

void SaveAndLoad::printTicket(Ticket ticket) {
    // echo "ваш билетик"
}

vector<Client*> SaveAndLoad::getAllClients() {
    vector<Client*> clients;


    return clients;
}

vector<Ticket*> SaveAndLoad::getAllTickets() {
    vector<Ticket*> tickets;


    return tickets;
}

Client SaveAndLoad::getClientByName(string name, string lastname) {
    Date bday;
    Client client("", "", bday);
    return client;
}

vector<Director*> SaveAndLoad::getAllDirectors() {
    vector<Director*> directors;


    return directors;
}

vector<Actor*> SaveAndLoad::getAllActors() {
    vector<Actor*> actors;


    return actors;
}

vector<Statistic*> SaveAndLoad::getAllStatistics() {
    vector<Statistic*> statistics;


    return statistics;
}


Film* SaveAndLoad::getFilmById(int id) {
    Film* result = nullptr;
    auto films = this->getAllFilms();

    for (auto film: films) {
        if (film->getId() == id) {
            result = film;
            break;
        }
    }

    return result;
}

Session* SaveAndLoad::getSessionById(int id) {
    Session* result = nullptr;
    auto sessions = this->getAllSessions();

    for (auto session: sessions) {
        if (session->getId() == id) {
            result = session;
            break;
        }
    }

    return result;
}

Client* SaveAndLoad::getClientById(int id) {
    Client* result = nullptr;
    auto clients = this->getAllClients();

    for (auto client: clients) {
        if (client->getId() == id) {
            result = client;
            break;
        }
    }

    return result;
}

Hall* SaveAndLoad::getHallById(int id) {
    Hall* result = nullptr;
    auto halls = this->getHalls();

    for (auto hall: halls) {
        if (hall->getId() == id) {
            result = hall;
            break;
        }
    }

    return result;
}

Ticket* SaveAndLoad::getTicketById(int id) {
    Ticket* result = nullptr;
    auto tickets = this->getAllTickets();

    for (auto ticket: tickets) {
        if (ticket->getId() == id) {
            result = ticket;
            break;
        }
    }

    return result;
}

Director* SaveAndLoad::getDirectorById(int id) {
    Director* result = nullptr;
    auto directors = this->getAllDirectors();

    for (auto director: directors) {
        if (director->getId() == id) {
            result = director;
            break;
        }
    }

    return result;
}

Actor* SaveAndLoad::getActorById(int id) {
    Actor* result = nullptr;
    auto actors = this->getAllActors();

    for (auto actor: actors) {
        if (actor->getId() == id) {
            result = actor;
            break;
        }
    }

    return result;
}

Statistic* SaveAndLoad::getStatisticById(int id) {
    Statistic* result = nullptr;
    auto statistics = this->getAllStatistics();

    for (auto statistic: statistics) {
        if (statistic->getId() == id) {
            result = statistic;
            break;
        }
    }

    return result;
}

