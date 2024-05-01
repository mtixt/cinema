#include "sessionspage.h"
#include "session.h"


SessionsPage::SessionsPage(QWidget *parent)
    : QWidget{parent}
{}

void SessionsPage::render_page(const vector<Session*>& sessions, QString title)
{
    // Очистка страницы
    for (auto child : this->children()) {
        delete child;
    }

    sessionsPageLayout = new QVBoxLayout(this);

    // Заголовок если есть
    if (title != "") {
        sessionsLabel = new QLabel(title, this);
        sessionsLabel->setFont(QFont("Segoe UI", 20, QFont::Bold));
        sessionsLabel->setAlignment(Qt::Alignment(Qt::AlignCenter));
        sessionsPageLayout->addWidget(sessionsLabel);
    }

    // Scroll Area
    sessionsScrollArea = new QScrollArea(this);
    sessionsScrollArea->setWidgetResizable(true);
    sessionsScrollAreaWidget = new QWidget();
    sessionsScrollArea->setWidget(sessionsScrollAreaWidget);
    sessionsPageLayout->addWidget(sessionsScrollArea);

    // Layout для равномерного заполнения
    sessionsScrollAreaLayout = new QVBoxLayout(sessionsScrollAreaWidget);

    sessionsButtonsGroup = new QButtonGroup(this);

    for (auto session : sessions) {
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

        // session date and time
        QLabel* sessionDateTimeLabel = new QLabel((session->getTime().getTime() + "    " + session->getDate().getDate()).c_str());
        sessionDateTimeLabel->setFont(QFont("Arial", 13, QFont::Bold));
        sessionDateTimeLabel->setAlignment(Qt::Alignment(Qt::AlignRight));
        // sessionDateTimeLabel->setStyleSheet("QLabel { color : green; }");

        // Компановка
        sessionLayout->addWidget(sessionNameLabel, 1, 1);
        sessionLayout->addWidget(sessionDescLabel, 2, 1, 2, 3);
        sessionLayout->addWidget(sessionDateTimeLabel, 1, 3);

        sessionsScrollAreaLayout->addWidget(sessionWidget);
        sessionsButtonsGroup->addButton(sessionWidget, session->getId());
    }

    // Spacer для заполнения нижней части, чтоб виджеты фильмов не растягивались на всю высоту
    sessionsScrollSpaser = new QSpacerItem(100, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);
    sessionsScrollAreaLayout->addItem(sessionsScrollSpaser);
}
