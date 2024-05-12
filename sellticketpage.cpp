#include "sellticketpage.h"
#include "ui_sellticketpage.h"
#include "client.h"

SellTicketPage::SellTicketPage(Session* session, int row, int num, int cost, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SellTicketPage)
{
    ui->setupUi(this);
    this->session = session;
    this->row = row;
    this->num = num;
    this->cost = cost;
}

SellTicketPage::~SellTicketPage()
{
    delete ui;
}

void SellTicketPage::on_sellButton_clicked()
{
    Client* client = nullptr;

    if  (!ui->clientEdit->text().isEmpty()) {
        int clientId = ui->clientEdit->text().toInt();
        client = sal.getClientById(clientId);
    }

    sal.sellTicket(session, row, num, client);
    emit sold();
    this->close();
}

