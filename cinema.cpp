#include "cinema.h"
#include "./ui_cinema.h"
#include <QString>
#include <QButtonGroup>

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
}

Cinema::~Cinema()
{
    if (sal.saveData())
        qDebug("Data saved");

    delete ui;
}


void Cinema::on_filmsButton_clicked()
{
    ui->headerToolButtons->setEnabled(true);
    ui->bottomToolButtons->show();

    filmsPage = new FilmsPage(ui->pages);
    filmsPage->render_page();

    ui->pages->addWidget(filmsPage);
    ui->pages->setCurrentWidget(filmsPage);
}


void Cinema::on_actorsButton_clicked()
{
    ui->headerToolButtons->setEnabled(true);
    ui->bottomToolButtons->show();

    actorsPage = new ActorsPage(ui->pages);
    actorsPage->render_page();

    ui->pages->addWidget(actorsPage);
    ui->pages->setCurrentWidget(actorsPage);
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
    else if (ui->pages->currentWidget() == actorsPage) {
        int id = actorsPage->actorButtonsGroup->checkedId();

        if (id >= 0) {
            actorView = new ActorView(sal.getActorById(id));
            actorView->setModal(true);
            actorView->show();
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
}


void Cinema::on_deleteButton_clicked()
{
    if (ui->pages->currentWidget() == filmsPage) {
        int id = filmsPage->filmButtonsGroup->checkedId();

        if (id >= 0) {
            sal.delFilm(id);
        }

        filmsPage->render_page();
    }
}

