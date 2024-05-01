#include "halledit.h"
#include "ui_halledit.h"

HallEdit::HallEdit(Hall* hall, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::HallEdit)
{
    ui->setupUi(this);

    this->hall = hall;

    on_resetButton_clicked();
}

HallEdit::~HallEdit()
{
    delete ui;
}

void HallEdit::on_saveButton_clicked()
{
    this->hall->setSpace(ui->rowsEdit->text().toInt(), ui->numsEdit->text().toInt());
}


void HallEdit::on_resetButton_clicked()
{
    ui->idEdit->setText(QString("%1").arg(this->hall->getId()));
    ui->rowsEdit->setText(QString("%1").arg(this->hall->getRows()));
    ui->numsEdit->setText(QString("%1").arg(this->hall->getNums()));
}

