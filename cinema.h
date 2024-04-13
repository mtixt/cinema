#ifndef CINEMA_H
#define CINEMA_H

#include <QMainWindow>
#include <QButtonGroup>
#include "saveandload.h"
#include "filmspage.h"
#include "filmview.h"
#include "filmedit.h"
#include "actorspage.h"
#include "actorview.h"


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
    void on_filmsButton_clicked();

    void on_actorsButton_clicked();

    void on_homeButton_clicked();

    void on_editButton_clicked();

    void on_viewButton_clicked();

    void on_addButton_clicked();

    void on_deleteButton_clicked();

private:
    Ui::Cinema *ui;

    FilmsPage* filmsPage;
    FilmView* filmView;
    FilmEdit* filmEdit;

    ActorsPage* actorsPage;
    ActorView* actorView;

    SaveAndLoad& sal = SaveAndLoad::init();
};
#endif // CINEMA_H
