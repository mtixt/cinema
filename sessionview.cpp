#include "sessionview.h"
#include "ui_sessionview.h"
#include <QLineEdit>
#include <QCheckBox>

SessionView::SessionView(Session* session, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SessionView)
{
    ui->setupUi(this);

    this->session = session;

    ui->filmNameLabel->setText(session->getFilm()->getName().c_str());
    ui->filmRatingLabel->setText(QString("%1").arg(session->getFilm()->getRating()));
    ui->dateLabel->setText(QString("%1").arg(session->getDate().getDate().c_str()));
    ui->timeLabel->setText(QString("%1").arg(session->getTime().getTime().c_str()));

    render_space();
}

SessionView::~SessionView()
{
    delete ui;
}

void SessionView::render_space()
{
    spaceWidget = ui->spaceWidget;

    // Очистка страницы
    for (auto child : spaceWidget->children()) {
        delete child;
    }

    spaceWidget->setMinimumHeight(session->getSpace()->size() * 40);

    spaceLayout = new QGridLayout(spaceWidget);
    spaceButtonGroup = new QButtonGroup(spaceWidget);

    int row_i = 1;
    for (auto row : *session->getSpace()) {
        QLabel* rowLabel = new QLabel(QString("%1").arg(row_i));
        rowLabel->setAlignment(Qt::Alignment(Qt::AlignVCenter));
        rowLabel->setAlignment(Qt::Alignment(Qt::AlignRight));
        rowLabel->setFixedSize(30, 30);

        spaceLayout->addWidget(rowLabel, row_i, 1);
        row_i++;

        for (auto seat : row) {
            QPushButton* seatButton = new QPushButton();
            seatButton->setFixedSize(30, 30);
            seatButton->setCheckable(true);
            seatButton->setFlat(true);

            // free - blue, booked - gray
            QPalette palette = seatButton->palette();
            palette.setColor(seatButton->backgroundRole(), qRgb(30, 144, 255));
            if (seat->isBooked()) {
                palette.setColor(seatButton->backgroundRole(), Qt::gray);
                seatButton->setDisabled(true);
            }
            seatButton->setAutoFillBackground(true);
            seatButton->setPalette(palette);

            QVBoxLayout* seatButtonLayout = new QVBoxLayout(seatButton);

            QLabel* seatButtonLabel = new QLabel(QString("%1").arg(seat->getNum()));
            seatButtonLabel->setFont(QFont("Arial", 9, QFont::Bold));
            seatButtonLabel->setAlignment(Qt::Alignment(Qt::AlignCenter));

            seatButtonLayout->addWidget(seatButtonLabel);
            seatButtonLayout->setContentsMargins(0,0,0,0);

            spaceLayout->addWidget(seatButton, seat->getRow(), seat->getNum()+1);
            spaceButtonGroup->addButton(seatButton);
        }
    }
}

void SessionView::on_bookButton_clicked()
{
    // calc row and num from index
    int index = -spaceButtonGroup->checkedId() - 1;
    if (index > 0) {
        int row = (index - 1) / session->getHall()->getNums() + 1;
        int num = index - (row - 1) * session->getHall()->getNums();

        sellTicketPage = new SellTicketPage(session, row, num);
        connect(sellTicketPage, SIGNAL(sold()), this,  SLOT(render_space()));

        sellTicketPage->setModal(true);
        sellTicketPage->show();

        this->render_space();
    }
}


