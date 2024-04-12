#ifndef CINEMA_H
#define CINEMA_H

#include <QMainWindow>
#include "saveandload.h"


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

private:
    Ui::Cinema *ui;
    SaveAndLoad& sal = SaveAndLoad::init();
};
#endif // CINEMA_H
