#include "actorview.h"
#include "ui_actorview.h"
#include "filmspage.h"

ActorView::ActorView(Actor *actor, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ActorView)
{
    ui->setupUi(this);

    ui->actorNameLabel->setText((actor->getName() + " " + actor->getLastname()).c_str());
    ui->birthdayLabel->setText(actor->getBirthday().getDate().c_str());

    FilmsPage* filmsPage = new FilmsPage();
    filmsPage->render_page(actor->getFilms());
    ui->filmsLayout->addWidget(filmsPage);
}

ActorView::~ActorView()
{
    delete ui;
}
