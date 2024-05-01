#include "clientedit.h"
#include "ui_clientedit.h"

ClientEdit::ClientEdit(Client* client, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ClientEdit)
{
    ui->setupUi(this);

    this->client = client;

    on_resetButton_clicked();
}

ClientEdit::~ClientEdit()
{
    delete ui;
}

void ClientEdit::on_saveButton_clicked()
{
    this->client->setName(ui->nameEdit->text().toStdString());
    this->client->setLastname(ui->lastnameEdit->text().toStdString());

    Date birthday = Date(
        ui->dayEdit->text().toInt(),
        ui->monthEdit->text().toInt(),
        ui->yearEdit->text().toInt()
    );

    this->client->setBirthday(birthday);

    this->client->setDiscount(ui->discountEdit->text().toInt());
    this->client->setTotalTicketPurchased(ui->totalTicketPurchasedEdit->text().toInt());

    QList<QString> tickets = ui->ticketsEdit->text().split(";");
    this->client->clearTickets();

    for (int i=0; i < tickets.size(); i++) {
        if (tickets[i].toInt())
            client->addTicket(sal.getTicketById(tickets[i].toInt()));
    }
}


void ClientEdit::on_resetButton_clicked()
{
    ui->nameEdit->setText(client->getName().c_str());
    ui->lastnameEdit->setText(client->getLastname().c_str());
    ui->dayEdit->setText(QString("%1").arg(client->getBirthday().getDay()));
    ui->monthEdit->setText(QString("%1").arg(client->getBirthday().getMonth()));
    ui->yearEdit->setText(QString("%1").arg(client->getBirthday().getYear()));
    ui->totalTicketPurchasedEdit->setText(QString("%1").arg(client->getTotalTicketPurchased()));
    ui->discountEdit->setText(QString("%1").arg(client->getDiscount()));

    QString tickets = "";
    for (auto ticket : client->getTickets()) {
        tickets += QString("%1;").arg(ticket->getId());
    }

    ui->ticketsEdit->setText(tickets);
}

