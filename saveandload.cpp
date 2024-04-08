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
        int statisticId     = query.record().field("statistic").value().toInt();

        Director* director = this->getDirectorById(directorId);

        QSqlQuery query2 = QSqlQuery(this->getDB());
        query2.exec(QString("SELECT * FROM statistics WHERE id = %1").arg(statisticId));

        if (query2.next()) {
            string soldByDay = query.record().field("soldByDay").value().toString().toStdString();

            this->_addFilm(name, description, genre, duration, rating, soldByDay, director, id);
        }
        else {
            this->addFilm(name, description, genre, duration, rating, director, id);
        }
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
        int statId      = query.record().field("statistic").value().toInt();

        Date bdate(birthday, birthmonth, birthyear);

        QSqlQuery query2 = QSqlQuery(this->getDB());
        query2.exec(QString("SELECT * FROM statistics WHERE id = %1").arg(statId));

        if (query2.next()) {
            int soldTotal = query.record().field("soldTotal").value().toInt();
            string soldByDay = query.record().field("soldByDay").value().toString().toStdString();

            this->_addDirector(name, lastname, bdate, id, soldTotal, soldByDay);
        }
        else {
            this->addDirector(name, lastname, bdate, id);
        }
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
        int cost        = query.record().field("cost").value().toInt();
        int seatrow     = query.record().field("seatrow").value().toInt();
        int seatnum     = query.record().field("seatnum").value().toInt();
        int sessionId   = query.record().field("sessionId").value().toInt();
        int clientId    = query.record().field("clientId").value().toInt();

        Client* client = this->getClientById(clientId);
        Session* session = this->getSessionById(sessionId);

        session->sellTicket(cost, seatrow, seatnum, client);
    }

    return true;
}

bool SaveAndLoad::loadSessions() {
    // Load sessions from DB and create objects

    // Перед сеансом должны быть созданы:
    // - film

    QSqlQuery query = QSqlQuery(this->getDB());
    query.exec("SELECT * FROM tickets");

    while (query.next()) {
        int id      = query.record().field("id").value().toInt();
        int filmId  = query.record().field("filmId").value().toInt();
        int hallId  = query.record().field("hallId").value().toInt();
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

Film SaveAndLoad::getFilmByName(string name) {
    Film film;

    /*
        - film = БД.Films.Where(@film => @film.Name == name).Select().FirstOrDefault();
    */

    return film;
}

vector<Film*> SaveAndLoad::getFilmsByDirector(string name) {
    vector<Film*> films;

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
    return this->films;
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
    return this->sessions;
}

vector<Hall*> SaveAndLoad::getHalls() {
    return this->halls;
}

bool SaveAndLoad::_addFilm(string name, string description, string genre, int duration, int rating, string soldByDay, Director* director, int id) {

    if (id == -1) {
        id = this->films.size();
    }

    Film* newFilm = new Film(name, description, genre, duration, rating, director, id);

    // parsing soldByDay
    // newFilm.setSoldAtDay() loop

    this->films.push_back(newFilm);

    return true;
}

void SaveAndLoad::addFilm(string name, string description, string genre, int duration, int rating, Director* director, int id) {
    if (id == -1) {
        id = this->films.size();
    }

    Film* newFilm = new Film(name, description, genre, duration, rating, director, id);

    this->films.push_back(newFilm);
}

void SaveAndLoad::addSession(Film* film, Hall* hall, Time time, Date date, int id) {
    if (id == -1) {
        id = this->sessions.size();
    }

    Session* newSession = new Session(id, film, hall, time, date);
    this->sessions.push_back(newSession);
}

void SaveAndLoad::addClient(string name, string lastname, Date bday, int id) {
    if (id == -1) {
        id = this->clients.size();
    }

    Client* newClient = new Client(name, lastname, bday, id);
    this->clients.push_back(newClient);
}

bool SaveAndLoad::_addClient(string name, string lastname, Date bday, int id, int totalTicketPurchased, int discount) {
    Client* newClient = new Client(name, lastname, bday, id);
    newClient->setDiscount(discount);
    newClient->setTotalTicketPurchased(totalTicketPurchased);

    this->clients.push_back(newClient);

    return true;
}

void SaveAndLoad::addActor(string name, string lastname, Date bday, int id) {
    if (id == -1) {
        id = this->actors.size();
    }

    Actor* newActor = new Actor(name, lastname, bday, id);
    this->actors.push_back(newActor);
}

void SaveAndLoad::addDirector(string name, string lastname, Date bday, int id) {
    if (id == -1) {
        id = this->directors.size();
    }

    Director* newDirector = new Director(name, lastname, bday, id);
    this->directors.push_back(newDirector);
}

bool SaveAndLoad::_addDirector(string name, string lastname, Date bday, int id, int soldTotal, string soldByDay) {
    Director* newDirector = new Director(name, lastname, bday, id);

    // parse soldByDay
    // newDirector.setSoldAtDay() loop


    this->directors.push_back(newDirector);

    return true;
}

void SaveAndLoad::addHall(int rows, int seats, int id) {
    if (id == -1) {
        id = this->halls.size();
    }

    Hall* newHall = new Hall(id, rows, seats);
    this->halls.push_back(newHall);
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

