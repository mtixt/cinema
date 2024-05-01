#include "actoredit.h"
#include "film.h"
#include "ui_actoredit.h"

ActorEdit::ActorEdit(Actor* actor, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::actorEdit)
{
    ui->setupUi(this);

    this->actor = actor;

    on_resetButton_clicked();
}

ActorEdit::~ActorEdit()
{
    delete ui;
}

void ActorEdit::on_resetButton_clicked()
{
    ui->nameEdit->setText(actor->getName().c_str());
    ui->lastnameEdit->setText(actor->getLastname().c_str());
    ui->dayEdit->setText(QString("%1").arg(actor->getBirthday().getDay()));
    ui->monthEdit->setText(QString("%1").arg(actor->getBirthday().getMonth()));
    ui->yearEdit->setText(QString("%1").arg(actor->getBirthday().getYear()));

    QString films = "";
    for (auto film : actor->getFilms()) {
        films += QString("%1;").arg(film->getId());
    }

    ui->filmsEdit->setText(films);
}


void ActorEdit::on_saveButton_clicked()
{
    this->actor->setName(ui->nameEdit->text().toStdString());
    this->actor->setLastname(ui->lastnameEdit->text().toStdString());

    Date birthday = Date(
        ui->dayEdit->text().toInt(),
        ui->monthEdit->text().toInt(),
        ui->yearEdit->text().toInt()
    );

    this->actor->setBirthday(birthday);

    QList<QString> films = ui->filmsEdit->text().split(";");

    this->actor->clearFilms();

    for (int i=0; i < films.size(); i++) {
        if (films[i].toInt())
            sal.filmAddActor(sal.getFilmById(films[i].toInt()), actor);
    }
}

