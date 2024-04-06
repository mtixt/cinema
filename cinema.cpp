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

        QSqlQuery query = QSqlQuery(sal.getDB());
        query.exec("SELECT * FROM films");

        while (query.next()) {

            qDebug() << query.record().field("name").value().toString();
            qDebug() << query.record().field("description").value().toString();
            // qDebug() << query.record();
        }


        // model = new QSqlTableModel(this, sal.getDB());
        // model = new QSqlRelationalTableModel(this, sal.getDB());

        // model->setTable("films");
        // model->setRelation(6, QSqlRelation("actors", "id", "name"));
        // model->setRelation(7, QSqlRelation("directors", "id", "name"));
        // model->setRelation(8, QSqlRelation("statistics", "id", "soldTotal"));

        // model->select();

        // ui->tableView->setModel(model);
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
