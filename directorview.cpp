#include "directorview.h"
#include "ui_directorview.h"
#include "filmspage.h"

DirectorView::DirectorView(Director* director, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DirectorView)
{
    ui->setupUi(this);

    ui->nameLabel->setText((director->getName() + " " + director->getLastname()).c_str());
    ui->birthdayLabel->setText(director->getBirthday().getDate().c_str());

    FilmsPage* filmsPage = new FilmsPage();
    filmsPage->render_page(director->getFilms());
    ui->filmsLayout->addWidget(filmsPage);
}

DirectorView::~DirectorView()
{
    delete ui;
}
