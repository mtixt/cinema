#ifndef CINEMA_H
#define CINEMA_H

#include <QMainWindow>
#include <QButtonGroup>
#include "saveandload.h"
#include "sessionspage.h"
#include "sessionview.h"
#include "sessionedit.h"
#include "filmspage.h"
#include "filmview.h"
#include "filmedit.h"
#include "actorspage.h"
#include "actorview.h"
#include "actoredit.h"
#include "hallspage.h"
#include "hallview.h"
#include "halledit.h"
#include "directorspage.h"
#include "directorview.h"
#include "directoredit.h"
#include "clientspage.h"
#include "clientview.h"
#include "clientedit.h"


QT_BEGIN_NAMESPACE
namespace Ui { class Cinema; }
QT_END_NAMESPACE

class Cinema : public QMainWindow
{
    Q_OBJECT

public:
    Cinema(QWidget *parent = nullptr);
    ~Cinema();

private slots:
    void on_homeButton_clicked();
    void on_editButton_clicked();
    void on_viewButton_clicked();
    void on_addButton_clicked();
    void on_deleteButton_clicked();
    void on_refreshButton_clicked();

    void on_filmsButton_clicked();
    void on_actorsButton_clicked();
    void on_sessionsButton_clicked();
    void on_hallsButton_clicked();
    void on_directorsButton_clicked();
    void on_clientsButton_clicked();
    void on_todaySessionsButton_clicked();
    void on_todayFilmsButton_clicked();

private:
    Ui::Cinema *ui;

    FilmsPage* filmsPage;
    FilmView* filmView;
    FilmEdit* filmEdit;

    ActorsPage* actorsPage;
    ActorView* actorView;
    ActorEdit* actorEdit;

    SessionsPage* sessionsPage;
    SessionView* sessionView;
    SessionEdit* sessionEdit;

    HallsPage* hallsPage;
    HallView*  hallView;
    HallEdit*  hallEdit;

    DirectorsPage* directorsPage;
    DirectorView* directorView;
    DirectorEdit* directorEdit;

    ClientsPage* clientsPage;
    ClientView* clientView;
    ClientEdit* clientEdit;

    SaveAndLoad& sal = SaveAndLoad::init();
};
#endif // CINEMA_H
