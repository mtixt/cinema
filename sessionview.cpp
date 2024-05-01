#include "sessionview.h"
#include "ui_sessionview.h"
#include "QButtonGroup"
#include "QPushButton"

SessionView::SessionView(Session* session, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SessionView)
{
    ui->setupUi(this);

    ui->filmNameLabel->setText(session->getFilm()->getName().c_str());
    ui->filmRatingLabel->setText(QString("%1").arg(session->getFilm()->getRating()));
    ui->dateLabel->setText(QString("%1").arg(session->getDate().getDate().c_str()));
    ui->timeLabel->setText(QString("%1").arg(session->getTime().getTime().c_str()));

    render_space(session);
}

SessionView::~SessionView()
{
    delete ui;
}

void SessionView::render_space(Session* session)
{
    QWidget* spaceWidget = ui->spaceWidget;

    // Очистка страницы
    for (auto child : spaceWidget->children()) {
        delete child;
    }

    spaceWidget->setMinimumHeight(session->getSpace()->size() * 30);


    QGridLayout* spaceLayout = new QGridLayout(spaceWidget);
    QButtonGroup* spaceButtonGroup = new QButtonGroup(spaceWidget);

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
            // seatButton->setFlat(true);
            seatButton->setCheckable(true);

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
