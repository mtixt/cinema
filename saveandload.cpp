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
    return time;
}

Date SaveAndLoad::getData() {
    Date date;
    return date;
}

Film SaveAndLoad::getFilmByName(string name) {
    Film film;
    return film;
}

vector<Film> SaveAndLoad::getFilmsByDirector(string name) {
    vector<Film> films;
    return films;
}

vector<Film> SaveAndLoad::getFilmsByActor(string name) {
    vector<Film> films;
    return films;
}

vector<Film> SaveAndLoad::getAllFilms() {
    vector<Film> films;
    return films;
}

vector<Session> SaveAndLoad::getSessionByDate(Date date) {
    vector<Session> sessions;
    return sessions;
}

vector<Session> SaveAndLoad::getSessionByFilm(string name) {
    vector<Session> sessions;
    return sessions;
}

vector<Session> SaveAndLoad::getAllSessions() {
    vector<Session> sessions;
    return sessions;
}

vector<Hall> SaveAndLoad::getHalls() {
    vector<Hall> halls;
    return halls;
}

void SaveAndLoad::addFilm(string name, string description, string picID, string genre, int duration, int rating) {

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

