#include "clientview.h"
#include "ui_clientview.h"
// #include "ticketspage.h"

ClientView::ClientView(Client* client, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ClientView)
{
    ui->setupUi(this);

    ui->nameLabel->setText((client->getName() + " " + client->getLastname()).c_str());
    ui->birthdayLabel->setText(client->getBirthday().getDate().c_str());

    ui->discountLabel->setText(QString("%1%").arg(client->getDiscount()));
    ui->totalTicketsLabel->setText(QString("%1").arg(client->getTotalTicketPurchased()));

    // TicketsPage* ticketsPage = new TicketsPage();
    // ticketsPage->render_subpage(client->getTickets());
    // ui->ticketsLayout->addWidget(ticketsPage);
}

ClientView::~ClientView()
{
    delete ui;
}
