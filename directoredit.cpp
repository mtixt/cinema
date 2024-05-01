#include "directoredit.h"
#include "ui_directoredit.h"

DirectorEdit::DirectorEdit(Director* director, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DirectorEdit)
{
    ui->setupUi(this);

    this->director = director;

    on_resetButton_clicked();
}

DirectorEdit::~DirectorEdit()
{
    delete ui;
}

void DirectorEdit::on_saveButton_clicked()
{
    this->director->setName(ui->nameEdit->text().toStdString());
    this->director->setLastname(ui->lastnameEdit->text().toStdString());

    Date birthday = Date(
        ui->dayEdit->text().toInt(),
        ui->monthEdit->text().toInt(),
        ui->yearEdit->text().toInt()
        );

    this->director->setBirthday(birthday);

    QList<QString> films = ui->filmsEdit->text().split(";");

    this->director->clearFilms();

    for (int i=0; i < films.size(); i++) {
        if (films[i].toInt())
            director->addFilm(sal.getFilmById(films[i].toInt()));
    }
}


void DirectorEdit::on_resetButton_clicked()
{
    ui->nameEdit->setText(director->getName().c_str());
    ui->lastnameEdit->setText(director->getLastname().c_str());
    ui->dayEdit->setText(QString("%1").arg(director->getBirthday().getDay()));
    ui->monthEdit->setText(QString("%1").arg(director->getBirthday().getMonth()));
    ui->yearEdit->setText(QString("%1").arg(director->getBirthday().getYear()));

    QString films = "";
    for (auto film : director->getFilms()) {
        films += QString("%1;").arg(film->getId());
    }

    ui->filmsEdit->setText(films);
}

