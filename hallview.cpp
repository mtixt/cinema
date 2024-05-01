#include "hallview.h"
#include "ui_hallview.h"

HallView::HallView(Hall* hall,  QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::HallView)
{
    ui->setupUi(this);

    ui->idLabel->setText(QString("Зал №%1").arg(hall->getId()));
    ui->rowsLabel->setText(QString("%1").arg(hall->getRows()));
    ui->numsLabel->setText(QString("%1").arg(hall->getNums()));
}

HallView::~HallView()
{
    delete ui;
}
