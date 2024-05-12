#include "sessionedit.h"
#include "ui_sessionedit.h"

SessionEdit::SessionEdit(Session* session, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SessionEdit)
{
    ui->setupUi(this);

    this->session = session;
    on_resetButton_clicked();
}

SessionEdit::~SessionEdit()
{
    delete ui;
}

void SessionEdit::on_saveButton_clicked()
{
    this->session->setHall(sal.getHallById(ui->hallEdit->text().toInt()));
    this->session->setFilm(sal.getFilmById(ui->filmEdit->text().toInt()));
    this->session->setDate(Date(ui->dayEdit->text().toInt(),
                                ui->monthEdit->text().toInt(),
                                ui->yearEdit->text().toInt()));
    this->session->setTime(Time(ui->hoursEdit->text().toInt(),
                                ui->minutesEdit->text().toInt()));
}

void SessionEdit::on_resetButton_clicked()
{
    if (session->getFilm() != nullptr)
        ui->filmEdit->setText(QString("%1").arg(session->getFilm()->getId()));
    else
        ui->filmEdit->setText("set film id");

    if (session->getHall() != nullptr)
        ui->hallEdit->setText(QString("%1").arg(session->getHall()->getId()));
    else
        ui->hallEdit->setText("set hall id");

    ui->dayEdit->setText(QString("%1").arg(session->getDate().getDay()));
    ui->monthEdit->setText(QString("%1").arg(session->getDate().getMonth()));
    ui->yearEdit->setText(QString("%1").arg(session->getDate().getYear()));

    ui->hoursEdit->setText(QString("%1").arg(session->getTime().getHours()));
    ui->minutesEdit->setText(QString("%1").arg(session->getTime().getMinutes()));
}
