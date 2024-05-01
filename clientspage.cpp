#include "clientspage.h"

ClientsPage::ClientsPage(QWidget *parent)
    : QWidget{parent}
{}

void ClientsPage::render_page(const vector<Client*>& clients, QString title)
{
    // Очистка страницы
    for (auto child : this->children()) {
        delete child;
    }

    clientsPageLayout = new QVBoxLayout(this);

    // Заголовок если есть
    if (title != "") {
        clientsLabel = new QLabel(title, this);
        clientsLabel->setFont(QFont("Segoe UI", 20, QFont::Bold));
        clientsLabel->setAlignment(Qt::Alignment(Qt::AlignCenter));
        clientsPageLayout->addWidget(clientsLabel);
    }

    // Scroll Area
    clientsScrollArea = new QScrollArea(this);
    clientsScrollArea->setWidgetResizable(true);
    clientsScrollAreaWidget = new QWidget();
    clientsScrollArea->setWidget(clientsScrollAreaWidget);
    clientsPageLayout->addWidget(clientsScrollArea);

    // Layout для равномерного заполнения
    clientsScrollAreaLayout = new QVBoxLayout(clientsScrollAreaWidget);

    clientsButtonsGroup = new QButtonGroup(this);

    for (auto client : clients) {
        // Создание виджетов и добавление их в ScrollArea

        QPushButton *clientWidget = new QPushButton();
        clientWidget->setFixedHeight(75);
        clientWidget->setFlat(true);
        clientWidget->setCheckable(true);

        QGridLayout* clientLayout = new QGridLayout(clientWidget);

        // client name
        QLabel* clientNameLabel = new QLabel(QString::fromStdString(client->getName() + " " + client->getLastname()));
        clientNameLabel->setFont(QFont("Arial", 14, QFont::Bold));

        // Количество сыгранных фильмов
        QLabel* clientRatingLabel = new QLabel(QString("Скидка %1%").arg(client->getDiscount()));
        clientRatingLabel->setFont(QFont("Arial", 11, QFont::Bold));
        clientRatingLabel->setAlignment(Qt::Alignment(Qt::AlignRight));
        clientRatingLabel->setStyleSheet("QLabel { color : green; }");

        // Компановка
        clientLayout->addWidget(clientNameLabel, 1, 1, 1, 2);
        clientLayout->addWidget(clientRatingLabel, 1, 3);

        clientsScrollAreaLayout->addWidget(clientWidget);
        clientsButtonsGroup->addButton(clientWidget, client->getId());
    }

    // Spacer для заполнения нижней части, чтоб виджеты фильмов не растягивались на всю высоту
    clientsScrollSpaser = new QSpacerItem(100, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);
    clientsScrollAreaLayout->addItem(clientsScrollSpaser);
}
