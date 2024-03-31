#include "cinema.h"
#include "./ui_cinema.h"

Cinema::Cinema(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Cinema)
{
    ui->setupUi(this);

    SaveAndLoad& sal = SaveAndLoad::init();
    sal.setDatabase("C:\\Users\\qp\\Desktop\\std\\oop\\Cinema\\cinemadb.db");

    if (sal.dbOpened()) {
        ui->statusbar->showMessage("DB opened");

        model = new QSqlTableModel(this, sal.getDB());
        model->setTable("films");
        model->select();

        ui->tableView->setModel(model);

    }
    else {
        ui->statusbar->showMessage("error loading DB");
    }

}

Cinema::~Cinema()
{
    delete ui;
}



void Cinema::on_addBtn_clicked()
{
    model->insertRow(model->rowCount());
}

