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

vector<Film> SaveAndLoad::getFilmsByDirector(string name) {
    vector<Film> films;

    /*
        - film = БД.Films.Where(@film => @film.Director == name).Select();
    */

    return films;
}

vector<Film> SaveAndLoad::getFilmsByActor(string name) {
    vector<Film> films;

    /*
        - film = БД.Films.Where(@film => @film.Actor == name).Select();
    */

    return films;
}

vector<Film> SaveAndLoad::getAllFilms() {
    vector<Film> films;

    /*
        - film = БД.Films.Select();
    */

    return films;
}

vector<Session> SaveAndLoad::getSessionByDate(Date date) {
    vector<Session> sessions;

    /*
        - sessions = БД.Sessions.Where(@session => @session.Date == date).Select();
    */

    return sessions;
}

vector<Session> SaveAndLoad::getSessionByFilm(string name) {
    vector<Session> sessions;

    /*
        - sessions = БД.Sessions.Where(@sessions => @session.Film == name).Select();
    */

    return sessions;
}

vector<Session> SaveAndLoad::getAllSessions() {
    vector<Session> sessions;

    /*
        - sessions = БД.Sessions.Select();
    */

    return sessions;
}

vector<Hall> SaveAndLoad::getHalls() {
    vector<Hall> halls;

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

vector<Client> SaveAndLoad::getAllClients() {
    vector<Client> clients;
    return clients;
}

Client SaveAndLoad::getClientByName(string name, string lastname) {
    Date bday;
    Client client("", "", bday);
    return client;
}

vector<Director> SaveAndLoad::getAllDirectors() {
    vector<Director> directors;
    return directors;
}

