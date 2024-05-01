#include "directorspage.h"

DirectorsPage::DirectorsPage(QWidget *parent)
    : QWidget{parent}
{

}

void DirectorsPage::render_page(const vector<Director*>& directors, QString title)
{
    // Очистка страницы
    for (auto child : this->children()) {
        delete child;
    }

    directorsPageLayout = new QVBoxLayout(this);

    // Заголовок если есть
    if (title != "") {
        directorsLabel = new QLabel(title, this);
        directorsLabel->setFont(QFont("Segoe UI", 20, QFont::Bold));
        directorsLabel->setAlignment(Qt::Alignment(Qt::AlignCenter));
        directorsPageLayout->addWidget(directorsLabel);
    }

    // Scroll Area
    directorsScrollArea = new QScrollArea(this);
    directorsScrollArea->setWidgetResizable(true);
    directorsScrollAreaWidget = new QWidget();
    directorsScrollArea->setWidget(directorsScrollAreaWidget);
    directorsPageLayout->addWidget(directorsScrollArea);

    // Layout для равномерного заполнения
    directorsScrollAreaLayout = new QVBoxLayout(directorsScrollAreaWidget);

    directorsButtonsGroup = new QButtonGroup(this);

    for (auto director : directors) {
        // Создание виджетов и добавление их в ScrollArea

        QPushButton *directorWidget = new QPushButton();
        directorWidget->setFixedHeight(75);
        directorWidget->setFlat(true);
        directorWidget->setCheckable(true);

        QGridLayout* directorLayout = new QGridLayout(directorWidget);

        // director name
        QLabel* directorNameLabel = new QLabel(QString::fromStdString(director->getName() + " " + director->getLastname()));
        directorNameLabel->setFont(QFont("Arial", 14, QFont::Bold));

        // Количество снятых фильмов
        QLabel* directorRatingLabel = new QLabel(QString("%1 фильмов").arg(director->getFilms().size()));
        directorRatingLabel->setFont(QFont("Arial", 11, QFont::Bold));
        directorRatingLabel->setAlignment(Qt::Alignment(Qt::AlignRight));
        directorRatingLabel->setStyleSheet("QLabel { color : green; }");

        // Компановка
        directorLayout->addWidget(directorNameLabel, 1, 1, 1, 2);
        directorLayout->addWidget(directorRatingLabel, 1, 3);

        directorsScrollAreaLayout->addWidget(directorWidget);
        directorsButtonsGroup->addButton(directorWidget, director->getId());
    }

    // Spacer для заполнения нижней части, чтоб виджеты фильмов не растягивались на всю высоту
    directorsScrollSpaser = new QSpacerItem(100, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);
    directorsScrollAreaLayout->addItem(directorsScrollSpaser);
}
