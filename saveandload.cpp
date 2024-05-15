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


bool SaveAndLoad::saveData() {
    //  Save data to DB and delete objects

    if (this->saveHalls()
            && this->saveClients()
            && this->saveDirectors()
            && this->saveFilms()
            && this->saveActors()
            && this->saveFilmsActors()
            && this->saveSessions()
            && this->saveTickets()
        ) {
        for (auto film : this->films) delete film;
        for (auto actor : this->actors) delete actor;
        for (auto director : this->directors) delete director;
        for (auto ticket : this->tickets) delete ticket;
        for (auto hall : this->halls) delete hall;
        for (auto session : this->sessions) delete session;

        return true;
    }

    return false;
}

bool SaveAndLoad::saveFilms() {
    QSqlQuery query = QSqlQuery(this->getDB());
    query.exec("DELETE FROM films");

    // query = QSqlQuery(this->getDB());
    query.prepare("INSERT INTO films (id, name, description, genre, duration, rating, director) "
               "VALUES (:id, :name, :description, :genre, :duration, :rating, :director)");

    for (auto film : this->films){
        query.bindValue(":id", film->getId());
        query.bindValue(":name", film->getName().c_str());
        query.bindValue(":description", film->getDescription().c_str());
        query.bindValue(":genre", film->getGenre().c_str());
        query.bindValue(":duration", film->getDuration());
        query.bindValue(":rating", film->getRating());

        if (film->getDirector())
            query.bindValue(":director", film->getDirector()->getId());

        query.exec();
    }

    return true;
}

bool SaveAndLoad::saveActors() {
    QSqlQuery query = QSqlQuery(this->getDB());
    query.exec("DELETE FROM actors");

    // query = QSqlQuery(this->getDB());
    query.prepare("INSERT INTO actors (id, name, lastname, birthday, birthmonth, birthyear) "
                  "VALUES (:id, :name, :lastname, :birthday, :birthmonth, :birthyear)");

    for (auto actor : this->actors){
        query.bindValue(":id", actor->getId());
        query.bindValue(":name", actor->getName().c_str());
        query.bindValue(":lastname", actor->getLastname().c_str());
        query.bindValue(":birthday", actor->getBirthday().getDay());
        query.bindValue(":birthmonth", actor->getBirthday().getMonth());
        query.bindValue(":birthyear", actor->getBirthday().getYear());
        query.exec();
    }

    return true;
}

bool SaveAndLoad::saveHalls() {
    QSqlQuery query = QSqlQuery(this->getDB());
    query.exec("DELETE FROM halls");

    query.prepare("INSERT INTO halls (id, rows, seatNums) "
                  "VALUES (:id, :rows, :seatNums)");

    for (auto hall : this->halls){
        query.bindValue(":id", hall->getId());
        query.bindValue(":rows", hall->getRows());
        query.bindValue(":seatNums", hall->getNums());
        query.exec();
    }

    return true;
}

bool SaveAndLoad::saveClients() {
    QSqlQuery query = QSqlQuery(this->getDB());
    query.exec("DELETE FROM clients");

    // query = QSqlQuery(this->getDB());
    query.prepare("INSERT INTO clients (id, name, lastname, discount, totalTicketPurchased, birthday, birthmonth, birthyear) "
                  "VALUES (:id, :name, :lastname, :discount, :totalTicketPurchased, :birthday, :birthmonth, :birthyear)");

    for (auto client : this->clients){
        query.bindValue(":id", client->getId());
        query.bindValue(":name", client->getName().c_str());
        query.bindValue(":lastname", client->getLastname().c_str());
        query.bindValue(":discount", client->getDiscount());
        query.bindValue(":totalTicketPurchased", client->getTotalTicketPurchased());
        query.bindValue(":birthday", client->getBirthday().getDay());
        query.bindValue(":birthmonth", client->getBirthday().getMonth());
        query.bindValue(":birthyear", client->getBirthday().getYear());
        query.exec();
    }

    return true;
}

bool SaveAndLoad::saveSessions() {
    QSqlQuery query = QSqlQuery(this->getDB());
    query.exec("DELETE FROM sessions");

    query.prepare("INSERT INTO sessions (id, film, hall, hours, minutes, day, month, year) "
                  "VALUES (:id, :film, :hall, :hours, :minutes, :day, :month, :year)");

    for (auto session : this->sessions){
        query.bindValue(":id", session->getId());
        query.bindValue(":film", session->getFilm()->getId());
        query.bindValue(":hall", session->getHall()->getId());
        query.bindValue(":hours", session->getTime().getHours());
        query.bindValue(":minutes", session->getTime().getMinutes());
        query.bindValue(":day", session->getDate().getDay());
        query.bindValue(":month", session->getDate().getMonth());
        query.bindValue(":year", session->getDate().getYear());
        query.exec();
    }

    return true;
}

bool SaveAndLoad::saveTickets() {
    QSqlQuery query = QSqlQuery(this->getDB());
    query.exec("DELETE FROM tickets");

    // query = QSqlQuery(this->getDB());
    query.prepare("INSERT INTO tickets (id, seatRow, seatNum, session, client) "
                  "VALUES (:id, :seatRow, :seatNum, :session, :client)");

    for (auto ticket : this->tickets){
        query.bindValue(":id", ticket->getId());
        query.bindValue(":seatRow", ticket->getSeat()->getRow());
        query.bindValue(":seatNum", ticket->getSeat()->getNum());
        query.bindValue(":session", ticket->getSession()->getId());

        if (ticket->getClient())
            query.bindValue(":client", ticket->getClient()->getId());

        query.exec();
    }

    return true;
}

bool SaveAndLoad::saveDirectors() {
    QSqlQuery query = QSqlQuery(this->getDB());
    query.exec("DELETE FROM directors");

    // query = QSqlQuery(this->getDB());
    query.prepare("INSERT INTO directors (id, name, lastname, birthday, birthmonth, birthyear) "
                  "VALUES (:id, :name, :lastname, :birthday, :birthmonth, :birthyear)");

    for (auto director : this->directors){
        query.bindValue(":id", director->getId());
        query.bindValue(":name", director->getName().c_str());
        query.bindValue(":lastname", director->getLastname().c_str());
        query.bindValue(":birthday", director->getBirthday().getDay());
        query.bindValue(":birthmonth", director->getBirthday().getMonth());
        query.bindValue(":birthyear", director->getBirthday().getYear());

        query.exec();
    }

    return true;
}

bool SaveAndLoad::saveFilmsActors() {
    QSqlQuery query = QSqlQuery(this->getDB());
    query.exec("DELETE FROM films_actors");

    query.prepare("INSERT INTO films_actors (fk_film, fk_actor) "
                  "VALUES (:fk_film, :fk_actor)");

    for (auto film : this->films){
        for (auto actor : film->getActors()) {
            query.bindValue(":fk_film", film->getId());
            query.bindValue(":fk_actor", actor->getId());
            query.exec();
        }
    }

    return true;
}

bool SaveAndLoad::loadData() {
    //  Load data from DB and create objects
    if (this->loadHalls()
            && this->loadClients()
            && this->loadDirectors()
            && this->loadFilms()
            && this->loadActors()
            && this->loadFilmsActors()
            && this->loadSessions()
            && this->loadTickets()
    ){
        return true;
    }

    return false;
}

bool SaveAndLoad::loadFilms() {
    // Load fimls from DB and create objects

    // this->films;

    QSqlQuery query = QSqlQuery(this->getDB());
    query.exec("SELECT * FROM films");

    while (query.next()) {
        int id              = query.record().field("id").value().toInt();
        string name         = query.record().field("name").value().toString().toStdString();
        string description  = query.record().field("description").value().toString().toStdString();
        string genre        = query.record().field("genre").value().toString().toStdString();
        int duration        = query.record().field("duration").value().toInt();
        int rating          = query.record().field("rating").value().toInt();
        int directorId      = query.record().field("director").value().toInt();

        Director* director = this->getDirectorById(directorId);

        this->addFilm(name, description, genre, duration, rating, director, id);
    }

    return true;
}

bool SaveAndLoad::loadHalls() {
    // Load halls from DB and create objects

    QSqlQuery query = QSqlQuery(this->getDB());
    query.exec("SELECT * FROM halls");

    while (query.next()) {
        int id          = query.record().field("id").value().toInt();
        int rows        = query.record().field("rows").value().toInt();
        int seatNums    = query.record().field("seatNums").value().toInt();

        this->addHall(rows, seatNums, id);
    }

    return true;
}

bool SaveAndLoad::loadClients() {
    // Load clients from DB and create objects

    QSqlQuery query = QSqlQuery(this->getDB());
    query.exec("SELECT * FROM clients");

    while (query.next()) {
        int id                      = query.record().field("id").value().toInt();
        int discount                = query.record().field("discount").value().toInt();
        int totalTicketPurchased    = query.record().field("totalTicketPurchased").value().toInt();
        int birthday                = query.record().field("birthday").value().toInt();
        int birthmonth              = query.record().field("birthmonth").value().toInt();
        int birthyear               = query.record().field("birthyear").value().toInt();
        string name                 = query.record().field("name").value().toString().toStdString();
        string lastname             = query.record().field("lastname").value().toString().toStdString();

        Date bdate(birthday, birthmonth, birthyear);
        this->_addClient(name, lastname, bdate, id, totalTicketPurchased, discount);
    }

    return true;
}

bool SaveAndLoad::loadDirectors() {
    // Load directors from DB and create objects

    QSqlQuery query = QSqlQuery(this->getDB());
    query.exec("SELECT * FROM directors");

    while (query.next()) {
        int id          = query.record().field("id").value().toInt();
        int birthday    = query.record().field("birthday").value().toInt();
        int birthmonth  = query.record().field("birthmonth").value().toInt();
        int birthyear   = query.record().field("birthyear").value().toInt();
        string name     = query.record().field("name").value().toString().toStdString();
        string lastname = query.record().field("lastname").value().toString().toStdString();

        Date bdate(birthday, birthmonth, birthyear);

        this->addDirector(name, lastname, bdate, id);
    }

    return true;
}

bool SaveAndLoad::loadActors() {
    // Load actors from DB and create objects

    QSqlQuery query = QSqlQuery(this->getDB());
    query.exec("SELECT * FROM actors");

    while (query.next()) {
        int id          = query.record().field("id").value().toInt();
        int birthday    = query.record().field("birthday").value().toInt();
        int birthmonth  = query.record().field("birthmonth").value().toInt();
        int birthyear   = query.record().field("birthyear").value().toInt();
        string name     = query.record().field("name").value().toString().toStdString();
        string lastname = query.record().field("lastname").value().toString().toStdString();

        Date bdate(birthday, birthmonth, birthyear);

        this->addActor(name, lastname, bdate, id);
    }

    return true;
}

bool SaveAndLoad::loadFilmsActors() {
    // load films to actors and actors to films

    for (auto actor : this->actors) {
        QSqlQuery query = QSqlQuery(this->getDB());
        query.exec(QString("SELECT * FROM films_actors WHERE fk_actor = %1").arg(actor->getId()));

        while (query.next()) {
            int filmId = query.record().field("fk_film").value().toInt();
            Film* film = this->getFilmById(filmId);
            actor->addFilm(film);
            film->addActor(actor);
        }
    }

    return true;
}

bool SaveAndLoad::loadTickets() {
    // Load tickets from DB and create objects

    // Перед билетом должны быть созданы:
    // - session
    // - client

    QSqlQuery query = QSqlQuery(this->getDB());
    query.exec("SELECT * FROM tickets");

    while (query.next()) {
        int id          = query.record().field("id").value().toInt();
        int seatrow     = query.record().field("seatrow").value().toInt();
        int seatnum     = query.record().field("seatnum").value().toInt();
        int sessionId   = query.record().field("session").value().toInt();
        int clientId    = query.record().field("client").value().toInt();

        Client* client = this->getClientById(clientId);
        Session* session = this->getSessionById(sessionId);

        this->sellTicket(session, seatrow, seatnum, client, id);
    }

    return true;
}

bool SaveAndLoad::loadSessions() {
    // Load sessions from DB and create objects

    // Перед сеансом должны быть созданы:
    // - film
    // - hall

    QSqlQuery query = QSqlQuery(this->getDB());
    query.exec("SELECT * FROM sessions");

    while (query.next()) {
        int id      = query.record().field("id").value().toInt();
        int filmId  = query.record().field("film").value().toInt();
        int hallId  = query.record().field("hall").value().toInt();
        int hours   = query.record().field("hours").value().toInt();
        int minutes = query.record().field("minutes").value().toInt();
        int day     = query.record().field("day").value().toInt();
        int month   = query.record().field("month").value().toInt();
        int year    = query.record().field("year").value().toInt();

        Film* film = this->getFilmById(filmId);
        Hall* hall = this->getHallById(hallId);

        Date date(day, month, year);
        Time time(hours, minutes);

        this->addSession(film, hall, time, date, id);
    }

    return true;
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

Film* SaveAndLoad::getFilmByName(string name) {
    for (auto film : this->getAllFilms()) {
        if (film->getName() == name)
            return film;
    }

    return nullptr;
}

vector<Film*> SaveAndLoad::getFilmsByDirector(string name) {
    vector<Film*> films;

    for (auto film : this->getAllFilms()) {
        if (film->getDirector()->getName() == name)
            films.push_back(film);
    }

    return films;
}

vector<Film*> SaveAndLoad::getFilmsByActor(string name) {
    vector<Film*> films;

    for (auto film : this->getAllFilms()) {
        for (auto actor : film->getActors()) {
            if (actor->getName() == name)
                films.push_back(film);
        }
    }

    return films;
}

vector<Film*> SaveAndLoad::getFilmsByDate(Date date) {
    vector<Film*> films;

    for (auto session : this->getAllSessions()) {
        if (session->getDate() == date
            && std::find(films.begin(), films.end(), session->getFilm()) == films.end())
        {
            films.push_back(session->getFilm());
        }
    }

    return films;
}

vector<Film*> SaveAndLoad::getAllFilms() {
    return this->films;
}

vector<Session*> SaveAndLoad::getSessionByDate(Date date) {
    vector<Session*> sessions;

    for (auto session : this->getAllSessions()) {
        if (session->getDate() == date)
            sessions.push_back(session);
    }

    return sessions;
}

vector<Session*> SaveAndLoad::getSessionByFilm(string name) {
    vector<Session*> sessions;

    for (auto session : this->getAllSessions()) {
        if (session->getFilm()->getName() == name)
            sessions.push_back(session);
    }

    return sessions;
}

vector<Session*> SaveAndLoad::getSessionByFilm(Film* film) {
    vector<Session*> sessions;

    for (auto session : this->getAllSessions()) {
        if (session->getFilm()->getId() == film->getId())
            sessions.push_back(session);
    }

    return sessions;
}

vector<Session*> SaveAndLoad::getAllSessions() {
    return this->sessions;
}

vector<Hall*> SaveAndLoad::getHalls() {
    return this->halls;
}

bool SaveAndLoad::_addFilm(string name, string description, string genre, int duration, int rating, string soldByDay, Director* director, int id) {

    if (id == -1) {
        id = this->films.size() + 1;
    }

    Film* newFilm = new Film(name, description, genre, duration, rating, director, id);

    this->films.push_back(newFilm);

    return true;
}

Film* SaveAndLoad::addFilm(string name, string description, string genre, int duration, int rating, Director* director, int id) {
    if (id == -1) {
        id = this->films.size() + 1;
    }

    Film* newFilm = new Film(name, description, genre, duration, rating, director, id);
    this->films.push_back(newFilm);

    return newFilm;
}

Session* SaveAndLoad::addSession(Film* film, Hall* hall, Time time, Date date, int id) {
    if (id == -1) {
        id = this->sessions.size() + 1;
    }

    Session* newSession = new Session(id, film, hall, time, date);
    this->sessions.push_back(newSession);

    return newSession;
}

Client* SaveAndLoad::addClient(string name, string lastname, Date bday, int id) {
    if (id == -1) {
        id = this->clients.size() + 1;
    }

    Client* newClient = new Client(name, lastname, bday, id);
    this->clients.push_back(newClient);

    return newClient;
}

bool SaveAndLoad::_addClient(string name, string lastname, Date bday, int id, int totalTicketPurchased, int discount) {
    Client* newClient = new Client(name, lastname, bday, id);
    newClient->setDiscount(discount);
    newClient->setTotalTicketPurchased(totalTicketPurchased);

    this->clients.push_back(newClient);

    return true;
}

Actor* SaveAndLoad::addActor(string name, string lastname, Date bday, int id) {
    if (id == -1) {
        id = this->actors.size() + 1;
    }

    Actor* newActor = new Actor(name, lastname, bday, id);
    this->actors.push_back(newActor);

    return newActor;
}

Director* SaveAndLoad::addDirector(string name, string lastname, Date& bday, int id) {
    if (id == -1) {
        id = this->directors.size() + 1;
    }

    Director* newDirector = new Director(name, lastname, bday, id);
    this->directors.push_back(newDirector);

    return newDirector;
}

bool SaveAndLoad::_addDirector(string name, string lastname, Date bday, int id, int soldTotal, string soldByDay) {
    Director* newDirector = new Director(name, lastname, bday, id);

    this->directors.push_back(newDirector);

    return true;
}

Hall* SaveAndLoad::addHall(int rows, int seats, int id) {
    if (id == -1) {
        id = this->halls.size() + 1;
    }

    Hall* newHall = new Hall(id, rows, seats);
    this->halls.push_back(newHall);

    return newHall;
}

void SaveAndLoad::delFilm(int id)
{
    Film* film = this->getFilmById(id);
    auto f = std::find(this->films.begin(), this->films.end(), film);

    if (f != this->films.end()) {
        this->films.erase(f);
        delete film;
    }
}

void SaveAndLoad::delSession(int id)
{
    Session* session = this->getSessionById(id);
    auto s = std::find(this->sessions.begin(), this->sessions.end(), session);

    if (s != this->sessions.end()) {
        this->sessions.erase(s);
        delete session;
    }
}

void SaveAndLoad::delActor(int id)
{
    Actor* actor = this->getActorById(id);
    auto a = std::find(this->actors.begin(), this->actors.end(), actor);

    if (a != this->actors.end()) {
        this->actors.erase(a);
        delete actor;
    }
}

void SaveAndLoad::delClient(int id)
{
    Client* client = this->getClientById(id);
    auto d = std::find(this->clients.begin(), this->clients.end(), client);

    if (d != this->clients.end()) {
        this->clients.erase(d);
        delete client;
    }
}

void SaveAndLoad::delDirector(int id)
{
    Director* director = this->getDirectorById(id);
    auto d = std::find(this->directors.begin(), this->directors.end(), director);

    if (d != this->directors.end()) {
        this->directors.erase(d);
        delete director;
    }
}

void SaveAndLoad::delHall(int id)
{
    Hall* hall = this->getHallById(id);
    auto h = std::find(this->halls.begin(), this->halls.end(), hall);

    if (h != this->halls.end()) {
        this->halls.erase(h);
        delete hall;
    }
}

void SaveAndLoad::filmAddActor(Film *film, Actor *actor)
{
    film->addActor(actor);
    actor->addFilm(film);
}

Ticket* SaveAndLoad::sellTicket(Session *session, int row, int num, Client *client, int id)
{
    if (id == -1)
        id = this->tickets.size() + 1;

    Ticket* ticket = new Ticket(session->getSeatByNum(row, num), session, client, id);

    this->tickets.push_back(ticket);
    session->bookSeat(row, num, ticket);

    if (client)
        client->addTicket(ticket);

    return ticket;
}

vector<Client*> SaveAndLoad::getAllClients() {
    return this->clients;
}

vector<Ticket*> SaveAndLoad::getAllTickets() {
    return this->tickets;
}

Client* SaveAndLoad::getClientByName(string name, string lastname) {
    for (auto client : this->getAllClients()) {
        if (client->getName() == name and client->getLastname() == lastname)
            return client;
    }

    return nullptr;
}

vector<Director*> SaveAndLoad::getAllDirectors() {
    return this->directors;
}

vector<Actor*> SaveAndLoad::getAllActors() {
    return this->actors;
}


Film* SaveAndLoad::getFilmById(int id) {
    for (auto film : this->getAllFilms()) {
        if (film->getId() == id) {
            return film;
        }
    }

    return nullptr;
}

Session* SaveAndLoad::getSessionById(int id) {
    for (auto session : this->getAllSessions()) {
        if (session->getId() == id) {
            return session;
        }
    }

    return nullptr;
}

Client* SaveAndLoad::getClientById(int id) {
    for (auto client : this->getAllClients()) {
        if (client->getId() == id) {
            return client;
        }
    }

    return nullptr;
}

Hall* SaveAndLoad::getHallById(int id) {
    for (auto hall : this->getHalls()) {
        if (hall->getId() == id) {
            return hall;
        }
    }

    return nullptr;
}

Ticket* SaveAndLoad::getTicketById(int id) {
    for (auto ticket : this->getAllTickets()) {
        if (ticket->getId() == id) {
            return ticket;
        }
    }

    return nullptr;
}

Director* SaveAndLoad::getDirectorById(int id) {
    for (auto director: this->getAllDirectors()) {
        if (director->getId() == id) {
            return director;
        }
    }

    return nullptr;
}

Actor* SaveAndLoad::getActorById(int id) {
    for (auto actor : this->getAllActors()) {
        if (actor->getId() == id) {
            return actor;
        }
    }

    return nullptr;
}


