#include "cinema.h"
#include "./ui_cinema.h"
#include <QString>

Cinema::Cinema(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Cinema)
{
    ui->setupUi(this);

    ui->pages->setCurrentWidget(ui->mainPage);
    ui->toolButtons->setDisabled(true);

    sal.setDatabase("C:\\Users\\gshtanchaev\\std\\oop\\Cinema\\cinemadb.db");

    if (sal.dbOpened()) {
        ui->statusbar->showMessage("DB opened");

        if (sal.loadData())
            ui->statusbar->showMessage("Data loaded");

    }
    else {
        ui->statusbar->showMessage("ERROR! Can't load DB");
    }
}

Cinema::~Cinema()
{
    if (sal.saveData())
        qDebug("Data saved");

    delete ui;
}


void Cinema::on_filmsButton_clicked()
{
    ui->pages->setCurrentWidget(ui->filmsPage);
    ui->toolButtons->setEnabled(true);

    // Layout для равномерного заполнения
    QVBoxLayout* filmsScrollAreaLayout = new QVBoxLayout(ui->filmsScrollAreaWidget);
    // Spacer для заполнения нижней части, чтоб виджеты фильмов не растягивались на всю высоту
    QSpacerItem* filmsScrollSpaser = new QSpacerItem(100, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

    for (auto film : sal.getAllFilms()) {
        // Создание виджетов и добавление их в ScrollArea

        QFrame *filmWidget = new QFrame();
        filmWidget->setFixedHeight(80);
        filmWidget->setFrameStyle(QFrame::Plain);
        filmWidget->setFrameShape(QFrame::StyledPanel);

        // QVBoxLayout* filmLayout = new QVBoxLayout(filmWidget);
        QGridLayout* filmLayout = new QGridLayout(filmWidget);

        // Film name
        QLabel* filmNameLabel = new QLabel(QString::fromStdString(film->getName()));
        filmNameLabel->setFont(QFont("Arial", 16, QFont::Bold));

        // Film description
        QLabel* filmDescLabel = new QLabel(QString::fromStdString(film->getDescription()));
        filmDescLabel->setFont(QFont("Arial", 10));
        filmDescLabel->setMaximumWidth(860);
        filmDescLabel->setWordWrap(true);
        // filmDescLabel->setBaseSize(600, 40);

        // Film rating
        QLabel* filmRatingLabel = new QLabel(QString("%1").arg(film->getRating()));
        filmRatingLabel->setFont(QFont("Arial", 11, QFont::Bold));
        filmRatingLabel->setAlignment(Qt::Alignment(Qt::AlignRight));
        filmRatingLabel->setStyleSheet("QLabel { color : green; }");


        filmLayout->addWidget(filmNameLabel, 1, 1);
        filmLayout->addWidget(filmDescLabel, 2, 1, 2, 3);
        filmLayout->addWidget(filmRatingLabel, 1, 3);

        filmsScrollAreaLayout->addWidget(filmWidget);
    }

    filmsScrollAreaLayout->addItem(filmsScrollSpaser);
}


void Cinema::on_actorsButton_clicked()
{
    ui->pages->setCurrentWidget(ui->actorsPage);
    ui->toolButtons->setEnabled(true);

    // Layout для равномерного заполнения
    QVBoxLayout* actorsScrollAreaLayout = new QVBoxLayout(ui->actorsScrollAreaWidget);
    // Spacer для заполнения нижней части, чтоб виджеты актеров не растягивались на всю высоту
    QSpacerItem* actorsScrollSpaser = new QSpacerItem(100, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

    for (auto actor : sal.getAllActors()) {
        // Создание виджетов и добавление их в ScrollArea

        QWidget* actorWidget = new QWidget();
        actorWidget->setFixedHeight(80);
        QVBoxLayout* actorLayout = new QVBoxLayout(actorWidget);

        QLabel* actorNameLabel = new QLabel(QString::fromStdString(actor->getName() + " " + actor->getLastname()));
        actorNameLabel->setFont(QFont("Arial", 16, QFont::Bold));

        actorLayout->addWidget(actorNameLabel);

        actorsScrollAreaLayout->addWidget(actorWidget);
    }

    actorsScrollAreaLayout->addItem(actorsScrollSpaser);
}


void Cinema::on_homeButton_clicked()
{
    ui->pages->setCurrentWidget(ui->mainPage);
    ui->toolButtons->setDisabled(true);
}

