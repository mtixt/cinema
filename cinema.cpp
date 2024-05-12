#include "cinema.h"
#include "./ui_cinema.h"
#include <QString>
#include <QButtonGroup>
#include <QDate>

Cinema::Cinema(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Cinema)
{
    ui->setupUi(this);

    ui->pages->setCurrentWidget(ui->mainPage);
    ui->headerToolButtons->setDisabled(true);
    ui->bottomToolButtons->hide();

    sal.setDatabase("C:\\Users\\gshtanchaev\\std\\oop\\Cinema\\cinemadb.db");

    if (sal.dbOpened()) {
        ui->statusbar->showMessage("DB opened");

        if (sal.loadData())
            ui->statusbar->showMessage("Data loaded");

    }
    else {
        ui->statusbar->showMessage("ERROR! Can't load DB");
    }

    //
}

Cinema::~Cinema()
{
    if (sal.saveData())
        qDebug("Data saved");

    delete ui;
}


void Cinema::on_homeButton_clicked()
{
    // Удаляем элементы с предыдущей страницы
    for (auto child : ui->pages->currentWidget()->children())
        delete child;

    ui->pages->setCurrentWidget(ui->mainPage);
    ui->headerToolButtons->setDisabled(true);
    ui->bottomToolButtons->hide();
}


void Cinema::on_editButton_clicked()
{
    if (ui->pages->currentWidget() == filmsPage) {
        int id = filmsPage->filmButtonsGroup->checkedId();

        if (id >= 0) {
            filmEdit = new FilmEdit(sal.getFilmById(id));
            filmEdit->setModal(true);
            filmEdit->show();
        }
    }
    else if (ui->pages->currentWidget() == actorsPage) {
        int id = actorsPage->actorsButtonsGroup->checkedId();

        if (id >= 0) {
            actorEdit = new ActorEdit(sal.getActorById(id));
            actorEdit->setModal(true);
            actorEdit->show();
        }
    }
    else if (ui->pages->currentWidget() == hallsPage) {
        int id = hallsPage->hallsButtonsGroup->checkedId();

        if (id >= 0) {
            hallEdit = new HallEdit(sal.getHallById(id));
            hallEdit->setModal(true);
            hallEdit->show();
        }
    }
    else if (ui->pages->currentWidget() == directorsPage) {
        int id = directorsPage->directorsButtonsGroup->checkedId();

        if (id >= 0) {
            directorEdit = new DirectorEdit(sal.getDirectorById(id));
            directorEdit->setModal(true);
            directorEdit->show();
        }
    }
    else if (ui->pages->currentWidget() == clientsPage) {
        int id = clientsPage->clientsButtonsGroup->checkedId();

        if (id >= 0) {
            clientEdit = new ClientEdit(sal.getClientById(id));
            clientEdit->setModal(true);
            clientEdit->show();
        }
    }
    else if (ui->pages->currentWidget() == sessionsPage) {
        int id = sessionsPage->sessionsButtonsGroup->checkedId();

        if (id >= 0) {
            sessionEdit = new SessionEdit(sal.getSessionById(id));
            sessionEdit->setModal(true);
            sessionEdit->show();
        }
    }
}


void Cinema::on_viewButton_clicked()
{
    if (ui->pages->currentWidget() == filmsPage) {
        int id = filmsPage->filmButtonsGroup->checkedId();

        if (id >= 0) {
            filmView = new FilmView(sal.getFilmById(id));
            filmView->setModal(true);
            filmView->show();
        }
    }
    else if (ui->pages->currentWidget() == sessionsPage) {
        int id = sessionsPage->sessionsButtonsGroup->checkedId();

        if (id >= 0) {
            sessionView = new SessionView(sal.getSessionById(id));
            sessionView->setModal(true);
            sessionView->show();
        }
    }
    else if (ui->pages->currentWidget() == actorsPage) {
        int id = actorsPage->actorsButtonsGroup->checkedId();

        if (id >= 0) {
            actorView = new ActorView(sal.getActorById(id));
            actorView->setModal(true);
            actorView->show();
        }
    }
    else if (ui->pages->currentWidget() == hallsPage) {
        int id = hallsPage->hallsButtonsGroup->checkedId();

        if (id >= 0) {
            hallView = new HallView(sal.getHallById(id));
            hallView->setModal(true);
            hallView->show();
        }
    }
    else if (ui->pages->currentWidget() == directorsPage) {
        int id = directorsPage->directorsButtonsGroup->checkedId();

        if (id >= 0) {
            directorView = new DirectorView(sal.getDirectorById(id));
            directorView->setModal(true);
            directorView->show();
        }
    }
    else if (ui->pages->currentWidget() == clientsPage) {
        int id = clientsPage->clientsButtonsGroup->checkedId();

        if (id >= 0) {
            clientView = new ClientView(sal.getClientById(id));
            clientView->setModal(true);
            clientView->show();
        }
    }
}


void Cinema::on_addButton_clicked()
{
    if (ui->pages->currentWidget() == filmsPage) {

        Film* film = sal.addFilm("", "", "", 0, 0);
        filmEdit = new FilmEdit(film);
        filmEdit->setModal(true);
        filmEdit->show();
    }
    else if (ui->pages->currentWidget() == actorsPage) {
        Date bday = Date(0, 0, 0);
        Actor* actor = sal.addActor("", "", bday);
        actorEdit = new ActorEdit(actor);
        actorEdit->setModal(true);
        actorEdit->show();
    }
    else if (ui->pages->currentWidget() == hallsPage) {
        Hall* hall = sal.addHall(0, 0);
        hallEdit = new HallEdit(hall);
        hallEdit->setModal(true);
        hallEdit->show();
    }
    else if (ui->pages->currentWidget() == directorsPage) {
        Date bday = Date(0, 0, 0);
        Director* director = sal.addDirector("", "", bday);
        directorEdit = new DirectorEdit(director);
        directorEdit->setModal(true);
        directorEdit->show();
    }
    else if (ui->pages->currentWidget() == clientsPage) {
        Date bday = Date(0, 0, 0);
        Client* client = sal.addClient("", "", bday);
        clientEdit = new ClientEdit(client);
        clientEdit->setModal(true);
        clientEdit->show();
    }
    else if (ui->pages->currentWidget() == sessionsPage) {
        Date date = Date(0, 0, 0);
        Time time = Time(0, 0);

        Film* film = sal.getFilmById(1);
        Hall* hall = sal.getHallById(1);

        Session* session = sal.addSession(film, hall, time, date);
        sessionEdit = new SessionEdit(session);
        sessionEdit->setModal(true);
        sessionEdit->show();
    }
}


void Cinema::on_deleteButton_clicked()
{
    // Для фильмов
    if (ui->pages->currentWidget() == filmsPage) {
        int id = filmsPage->filmButtonsGroup->checkedId();

        if (id >= 0) {
            sal.delFilm(id);
        }

        filmsPage->render_page(sal.getAllFilms(), "Все фильмы");
    }
    // Для актеров
    else if (ui->pages->currentWidget() == actorsPage) {
        int id = actorsPage->actorsButtonsGroup->checkedId();

        if (id >= 0) {
            sal.delActor(id);
        }

        actorsPage->render_page(sal.getAllActors(), "Все актеры");
    }
    // Для сеансов
    else if (ui->pages->currentWidget() == sessionsPage) {
        int id = sessionsPage->sessionsButtonsGroup->checkedId();

        if (id >= 0) {
            sal.delSession(id);
        }

        sessionsPage->render_page(sal.getAllSessions(), "Все сеансы");
    }
    // Для кинозалов
    else if (ui->pages->currentWidget() == hallsPage) {
        int id = hallsPage->hallsButtonsGroup->checkedId();

        if (id >= 0) {
            sal.delHall(id);
        }

        hallsPage->render_page(sal.getHalls(), "Все кинозалы");
    }
    // Для режиссеров
    else if (ui->pages->currentWidget() == directorsPage) {
        int id = directorsPage->directorsButtonsGroup->checkedId();

        if (id >= 0) {
            sal.delDirector(id);
        }

        directorsPage->render_page(sal.getAllDirectors(), "Все режиссеры");
    }
    else if (ui->pages->currentWidget() == clientsPage) {
        int id = clientsPage->clientsButtonsGroup->checkedId();

        if (id >= 0) {
            sal.delClient(id);
        }

        clientsPage->render_page(sal.getAllClients(), "Все клиенты");
    }
}


void Cinema::on_refreshButton_clicked()
{
    if (ui->pages->currentWidget() == filmsPage) {
        filmsPage->render_page(sal.getAllFilms(), "Все фильмы");
    }
    else if (ui->pages->currentWidget() == sessionsPage) {
        sessionsPage->render_page(sal.getAllSessions(), "Все сеансы");
    }
    else if (ui->pages->currentWidget() == actorsPage) {
        actorsPage->render_page(sal.getAllActors(), "Все актеры");
    }
    else if (ui->pages->currentWidget() == hallsPage) {
        hallsPage->render_page(sal.getHalls(), "Все кинозалы");
    }
    else if (ui->pages->currentWidget() == directorsPage) {
        directorsPage->render_page(sal.getAllDirectors(), "Все режиссеры");
    }
    else if (ui->pages->currentWidget() == clientsPage) {
        clientsPage->render_page(sal.getAllClients(), "Все клиенты");
    }
}



void Cinema::on_filmsButton_clicked()
{
    ui->headerToolButtons->setEnabled(true);
    ui->bottomToolButtons->show();

    filmsPage = new FilmsPage(ui->pages);
    filmsPage->render_page(sal.getAllFilms(), "Все фильмы");

    ui->pages->addWidget(filmsPage);
    ui->pages->setCurrentWidget(filmsPage);
}


void Cinema::on_actorsButton_clicked()
{
    ui->headerToolButtons->setEnabled(true);
    ui->bottomToolButtons->show();

    actorsPage = new ActorsPage(ui->pages);
    actorsPage->render_page(sal.getAllActors(), "Все актеры");

    ui->pages->addWidget(actorsPage);
    ui->pages->setCurrentWidget(actorsPage);
}


void Cinema::on_sessionsButton_clicked()
{
    ui->headerToolButtons->setEnabled(true);
    ui->bottomToolButtons->show();

    sessionsPage = new SessionsPage(ui->pages);
    sessionsPage->render_page(sal.getAllSessions(), "Все сеансы");

    ui->pages->addWidget(sessionsPage);
    ui->pages->setCurrentWidget(sessionsPage);
}


void Cinema::on_hallsButton_clicked()
{
    ui->headerToolButtons->setEnabled(true);
    ui->bottomToolButtons->show();

    hallsPage = new HallsPage(ui->pages);
    hallsPage->render_page(sal.getHalls(), "Все кинозалы");

    ui->pages->addWidget(hallsPage);
    ui->pages->setCurrentWidget(hallsPage);
}


void Cinema::on_directorsButton_clicked()
{
    ui->headerToolButtons->setEnabled(true);
    ui->bottomToolButtons->show();

    directorsPage = new DirectorsPage(ui->pages);
    directorsPage->render_page(sal.getAllDirectors(), "Все режиссеры");

    ui->pages->addWidget(directorsPage);
    ui->pages->setCurrentWidget(directorsPage);
}


void Cinema::on_clientsButton_clicked()
{
    ui->headerToolButtons->setEnabled(true);
    ui->bottomToolButtons->show();

    clientsPage = new ClientsPage(ui->pages);
    clientsPage->render_page(sal.getAllClients(), "Все клиенты");

    ui->pages->addWidget(clientsPage);
    ui->pages->setCurrentWidget(clientsPage);
}


void Cinema::on_todaySessionsButton_clicked()
{
    QDate currentDate = QDate::currentDate();
    Date date(currentDate.day(), currentDate.month(), currentDate.year());

    auto sessions = sal.getSessionByDate(date);

    ui->headerToolButtons->setEnabled(true);
    ui->bottomToolButtons->show();

    sessionsPage = new SessionsPage(ui->pages);
    sessionsPage->render_page(sessions, "Сеансы на сегодня");

    ui->pages->addWidget(sessionsPage);
    ui->pages->setCurrentWidget(sessionsPage);
}


void Cinema::on_todayFilmsButton_clicked()
{
    QDate currentDate = QDate::currentDate();
    Date date(currentDate.day(), currentDate.month(), currentDate.year());

    auto films = sal.getFilmsByDate(date);

    ui->headerToolButtons->setEnabled(true);
    ui->bottomToolButtons->show();

    filmsPage = new FilmsPage(ui->pages);
    filmsPage->render_page(films, "Фильмы сегодня");

    ui->pages->addWidget(filmsPage);
    ui->pages->setCurrentWidget(filmsPage);
}

