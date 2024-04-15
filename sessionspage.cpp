#include "sessionspage.h"
#include "session.h"


SessionsPage::SessionsPage(QWidget *parent)
    : QWidget{parent}
{}

void SessionsPage::render_page()
{
    // Очистка страницы
    for (auto child : this->children()) {
        delete child;
    }

    sessionsPageLayout = new QVBoxLayout(this);

    sessionsLabel = new QLabel("Сеансы", this);
    sessionsLabel->setFont(QFont("Segoe UI", 20, QFont::Bold));
    sessionsLabel->setAlignment(Qt::Alignment(Qt::AlignCenter));

    sessionsScrollArea = new QScrollArea(this);
    sessionsScrollArea->setWidgetResizable(true);

    sessionsScrollAreaWidget = new QWidget();
    sessionsScrollArea->setWidget(sessionsScrollAreaWidget);

    sessionsPageLayout->addWidget(sessionsLabel);
    sessionsPageLayout->addWidget(sessionsScrollArea);

    // Layout для равномерного заполнения
    sessionsScrollAreaLayout = new QVBoxLayout(sessionsScrollAreaWidget);
    // Spacer для заполнения нижней части, чтоб виджеты фильмов не растягивались на всю высоту
    sessionsScrollSpaser = new QSpacerItem(100, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

    sessionButtonsGroup = new QButtonGroup(this);

    for (auto session : sal.getAllSessions()) {
        // Создание виджетов и добавление их в ScrollArea

        // session Widget
        QPushButton *sessionWidget = new QPushButton();
        sessionWidget->setFixedHeight(100);
        sessionWidget->setFlat(true);
        sessionWidget->setCheckable(true);

        QGridLayout* sessionLayout = new QGridLayout(sessionWidget);

        // session name
        QLabel* sessionNameLabel = new QLabel(QString::fromStdString(session->getFilm()->getName()));
        sessionNameLabel->setFont(QFont("Arial", 16, QFont::Bold));

        // session description
        QLabel* sessionDescLabel = new QLabel(QString::fromStdString(session->getFilm()->getDescription()));
        sessionDescLabel->setFont(QFont("Arial", 10));
        sessionDescLabel->setMaximumWidth(860);
        sessionDescLabel->setWordWrap(true);

        // session rating
        QLabel* sessionRatingLabel = new QLabel(session->getDate().getDate().c_str());
        sessionRatingLabel->setFont(QFont("Arial", 13, QFont::Bold));
        sessionRatingLabel->setAlignment(Qt::Alignment(Qt::AlignRight));
        // sessionRatingLabel->setStyleSheet("QLabel { color : green; }");

        // Компановка
        sessionLayout->addWidget(sessionNameLabel, 1, 1);
        sessionLayout->addWidget(sessionDescLabel, 2, 1, 2, 3);
        sessionLayout->addWidget(sessionRatingLabel, 1, 3);

        sessionsScrollAreaLayout->addWidget(sessionWidget);
        sessionButtonsGroup->addButton(sessionWidget, session->getId());
    }

    sessionsScrollAreaLayout->addItem(sessionsScrollSpaser);
}
