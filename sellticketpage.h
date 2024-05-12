#ifndef SELLTICKETPAGE_H
#define SELLTICKETPAGE_H

#include <QDialog>
#include "session.h"
#include "saveandload.h"

namespace Ui {
class SellTicketPage;
}

class SellTicketPage : public QDialog
{
    Q_OBJECT

public:
    explicit SellTicketPage(Session* session, int row, int num, int cost = 0, QWidget *parent = nullptr);
    ~SellTicketPage();

private slots:
    void on_sellButton_clicked();

private:
    Ui::SellTicketPage *ui;
    SaveAndLoad& sal = SaveAndLoad::init();
    Session* session;
    int row, num, cost;

signals:
    void sold();
};

#endif // SELLTICKETPAGE_H
