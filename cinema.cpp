#include "cinema.h"
#include "./ui_cinema.h"
#include <QString>
#include <QButtonGroup>

Cinema::Cinema(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Cinema)
{
    ui->setupUi(this);

    ui->pages->setCurrentWidget(ui->mainPage);
    ui->headerToolButtons->setDisabled(true);
    ui->bottomToolButtons->hide();

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
    ui->headerToolButtons->setEnabled(true);
    ui->bottomToolButtons->show();

    QVBoxLayout* filmsPageLayout = new QVBoxLayout(ui->filmsPage);

    QLabel* filmsLabel = new QLabel("Фильмы", ui->filmsPage);
    filmsLabel->setFont(QFont("Segoe UI", 20, QFont::Bold));
    filmsLabel->setAlignment(Qt::Alignment(Qt::AlignCenter));

    QScrollArea* filmsScrollArea = new QScrollArea(ui->filmsPage);
    filmsScrollArea->setWidgetResizable(true);

    QWidget* filmsScrollAreaWidget = new QWidget();
    filmsScrollArea->setWidget(filmsScrollAreaWidget);

    filmsPageLayout->addWidget(filmsLabel);
    filmsPageLayout->addWidget(filmsScrollArea);

    // Layout для равномерного заполнения
    QVBoxLayout* filmsScrollAreaLayout = new QVBoxLayout(filmsScrollAreaWidget);
    // Spacer для заполнения нижней части, чтоб виджеты фильмов не растягивались на всю высоту
    QSpacerItem* filmsScrollSpaser = new QSpacerItem(100, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

    filmButtonsGroup = new QButtonGroup(ui->filmsPage);
    connect(filmButtonsGroup, SIGNAL(buttonClicked(int)), this, SLOT(on_film_clicked(int)));

    for (auto film : sal.getAllFilms()) {
        // Создание виджетов и добавление их в ScrollArea

        // Film Widget
        // QFrame *filmWidget = new QFrame();
        QPushButton *filmWidget = new QPushButton();
        filmWidget->setFixedHeight(100);
        filmWidget->setFlat(true);
        filmWidget->setCheckable(true);

        // filmWidget->setFrameStyle(QFrame::Plain);
        // filmWidget->setFrameShape(QFrame::StyledPanel);


        QGridLayout* filmLayout = new QGridLayout(filmWidget);

        // Film name
        QLabel* filmNameLabel = new QLabel(QString::fromStdString(film->getName()));
        filmNameLabel->setFont(QFont("Arial", 16, QFont::Bold));

        // Film description
        QLabel* filmDescLabel = new QLabel(QString::fromStdString(film->getDescription()));
        filmDescLabel->setFont(QFont("Arial", 10));
        filmDescLabel->setMaximumWidth(860);
        filmDescLabel->setWordWrap(true);

        // Film rating
        QLabel* filmRatingLabel = new QLabel(QString("%1").arg(film->getRating()));
        filmRatingLabel->setFont(QFont("Arial", 11, QFont::Bold));
        filmRatingLabel->setAlignment(Qt::Alignment(Qt::AlignRight));
        filmRatingLabel->setStyleSheet("QLabel { color : green; }");

        // Компановка
        filmLayout->addWidget(filmNameLabel, 1, 1);
        filmLayout->addWidget(filmDescLabel, 2, 1, 2, 3);
        filmLayout->addWidget(filmRatingLabel, 1, 3);

        filmsScrollAreaLayout->addWidget(filmWidget);
        filmButtonsGroup->addButton(filmWidget);
    }

    filmsScrollAreaLayout->addItem(filmsScrollSpaser);
}


void Cinema::on_actorsButton_clicked()
{
    ui->pages->setCurrentWidget(ui->actorsPage);
    ui->headerToolButtons->setEnabled(true);
    ui->bottomToolButtons->show();


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
    // Удаляем элементы с предыдущей страницы
    for (auto child : ui->pages->currentWidget()->children())
        delete child;

    ui->pages->setCurrentWidget(ui->mainPage);
    ui->headerToolButtons->setDisabled(true);
    ui->bottomToolButtons->hide();
}

void Cinema::on_film_clicked(int id)
{

    for(int buttonId = 0; buttonId < sal.getAllFilms().size(); ++buttonId) {
        if(buttonId != id)
            filmButtonsGroup->button(buttonId)->setChecked(false);
    }
}

void Cinema::on_edit_clicked(int id)
{

}

