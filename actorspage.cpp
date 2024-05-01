#include "actorspage.h"

ActorsPage::ActorsPage(QWidget *parent)
    : QWidget{parent}
{

}

void ActorsPage::render_page(const vector<Actor*>& actors, QString title)
{
    // Очистка страницы
    for (auto child : this->children()) {
        delete child;
    }

    actorsPageLayout = new QVBoxLayout(this);

    // Заголовок если есть
    if (title != "") {
        actorsLabel = new QLabel("Актеры", this);
        actorsLabel->setFont(QFont("Segoe UI", 20, QFont::Bold));
        actorsLabel->setAlignment(Qt::Alignment(Qt::AlignCenter));
        actorsPageLayout->addWidget(actorsLabel);
    }

    // Scroll Area
    actorsScrollArea = new QScrollArea(this);
    actorsScrollArea->setWidgetResizable(true);
    actorsScrollAreaWidget = new QWidget();
    actorsScrollArea->setWidget(actorsScrollAreaWidget);
    actorsPageLayout->addWidget(actorsScrollArea);

    // Layout для равномерного заполнения
    actorsScrollAreaLayout = new QVBoxLayout(actorsScrollAreaWidget);

    actorsButtonsGroup = new QButtonGroup(this);

    for (auto actor : actors) {
        // Создание виджетов и добавление их в ScrollArea

        QPushButton *actorWidget = new QPushButton();
        actorWidget->setFixedHeight(75);
        actorWidget->setFlat(true);
        actorWidget->setCheckable(true);

        QGridLayout* actorLayout = new QGridLayout(actorWidget);

        // actor name
        QLabel* actorNameLabel = new QLabel(QString::fromStdString(actor->getName() + " " + actor->getLastname()));
        actorNameLabel->setFont(QFont("Arial", 14, QFont::Bold));

        // Количество сыгранных фильмов
        QLabel* actorRatingLabel = new QLabel(QString("%1 фильмов").arg(actor->getFilms().size()));
        actorRatingLabel->setFont(QFont("Arial", 11, QFont::Bold));
        actorRatingLabel->setAlignment(Qt::Alignment(Qt::AlignRight));
        actorRatingLabel->setStyleSheet("QLabel { color : green; }");

        // Компановка
        actorLayout->addWidget(actorNameLabel, 1, 1, 1, 2);
        actorLayout->addWidget(actorRatingLabel, 1, 3);

        actorsScrollAreaLayout->addWidget(actorWidget);
        actorsButtonsGroup->addButton(actorWidget, actor->getId());
    }

    // Spacer для заполнения нижней части, чтоб виджеты фильмов не растягивались на всю высоту
    actorsScrollSpaser = new QSpacerItem(100, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);
    actorsScrollAreaLayout->addItem(actorsScrollSpaser);
}
