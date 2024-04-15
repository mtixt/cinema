#include "filmedit.h"
#include "actor.h"
#include "ui_filmedit.h"
#include <QDebug>

FilmEdit::FilmEdit(Film* film, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::FilmEdit)
{
    ui->setupUi(this);

    this->film = film;

    on_resetButton_clicked();
}

FilmEdit::~FilmEdit()
{
    delete ui;
}

void FilmEdit::on_saveButton_clicked()
{
    this->film->setName(ui->nameEdit->text().toStdString());
    this->film->setDescription(ui->descriptionEdit->toPlainText().toStdString());
    this->film->setDirector(sal.getDirectorById(ui->directorEdit->text().toInt()));
    this->film->setRating(ui->ratingEdit->text().toInt());
    this->film->setDuration(ui->durationEdit->text().toInt());
    this->film->setGenre(ui->genreEdit->text().toStdString());

    QList<QString> actors = ui->actorsEdit->text().split(";");

    this->film->clearActors();

    for (int i=0; i < actors.size(); i++) {
        if (actors[i].toInt())
            this->film->addActor(sal.getActorById(actors[i].toInt()));
    }

}


void FilmEdit::on_resetButton_clicked()
{
    ui->nameEdit->setText(film->getName().c_str());
    ui->descriptionEdit->setText(film->getDescription().c_str());
    ui->genreEdit->setText(film->getGenre().c_str());
    ui->ratingEdit->setText(QString("%1").arg(film->getRating()));
    ui->durationEdit->setText(QString("%1").arg(film->getDuration()));

    QString director = film->getDirector() ? QString("%1").arg(film->getDirector()->getId()) : "";
    QString actors = "";
    for (auto actor : film->getActors()) {
        actors += QString("%1;").arg(actor->getId());
    }

    ui->actorsEdit->setText(actors);
    ui->directorEdit->setText(director);
}

