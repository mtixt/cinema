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

    QSqlRelationalTableModel* model;
    QSqlDatabase db;


private slots:
    void on_addBtn_clicked();

private:
    Ui::Cinema *ui;
};
#endif // CINEMA_H
