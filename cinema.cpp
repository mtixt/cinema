#include "cinema.h"
#include "./ui_cinema.h"

Cinema::Cinema(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Cinema)
{
    ui->setupUi(this);

    SaveAndLoad& sal = SaveAndLoad::init();
    sal.setDatabase("C:\\Users\\gshtanchaev\\std\\oop\\Cinema\\cinemadb.db");

    if (sal.dbOpened()) {
        ui->statusbar->showMessage("DB opened");

        sal.loadData();

        for (auto film : sal.getAllFilms())
            qDebug() << film->getName();
    }
    else {
        ui->statusbar->showMessage("ERROR! Can't load DB");
    }
}

Cinema::~Cinema()
{
    delete ui;
}

void Cinema::on_addBtn_clicked()
{
    // model->insertRow(model->rowCount());
}
