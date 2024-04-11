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


    SaveAndLoad& sal = SaveAndLoad::init();
    sal.setDatabase("C:\\Users\\gshtanchaev\\std\\oop\\Cinema\\cinemadb.db");

    if (sal.dbOpened()) {
        ui->statusbar->showMessage("DB opened");

        // sal.loadData();


        // sal.saveData();
    }
    else {
        ui->statusbar->showMessage("ERROR! Can't load DB");
    }
}

Cinema::~Cinema()
{
    delete ui;
}

void Cinema::on_filmsButton_clicked()
{
    ui->pages->setCurrentWidget(ui->filmsPage);
    ui->toolButtons->setEnabled(true);
}


void Cinema::on_actorsButton_clicked()
{
    ui->pages->setCurrentWidget(ui->actorsPage);
    ui->toolButtons->setEnabled(true);
}


void Cinema::on_homeButton_clicked()
{
    ui->pages->setCurrentWidget(ui->mainPage);
    ui->toolButtons->setDisabled(true);
}

