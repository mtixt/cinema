#include "filmview.h"
#include "ui_filmview.h"
#include "actorspage.h"

FilmView::FilmView(Film* film, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::FilmView)
{
    ui->setupUi(this);

    ui->filmNameLabel->setText(film->getName().c_str());
    ui->filmDescriptionLabel->setText(film->getDescription().c_str());
    ui->filmRatingLabel->setText(QString("%1").arg(film->getRating()));

    QString director = film->getDirector() ? (film->getDirector()->getName() + " " + film->getDirector()->getLastname()).c_str() : "неизвестно";

    QString filmInfo = QString("id: %1\n"
                               "Режиссер: %2\n"
                               "Жанр: %3\n"
                               "Длительность: %4\n").arg(film->getId()).arg(director, film->getGenre().c_str()).arg(film->getDuration());
    ui->filmInfoLabel->setText(filmInfo);

    ActorsPage* actorsPage = new ActorsPage();
    actorsPage->render_subpage(film);
    ui->actorsLayout->addWidget(actorsPage);

}

FilmView::~FilmView()
{
    delete ui;
}
