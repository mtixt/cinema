#include "hallspage.h"

HallsPage::HallsPage(QWidget *parent)
    : QWidget{parent}
{

}

void HallsPage::render_page(const vector <Hall*>& halls, QString title)
{
    // Очистка страницы
    for (auto child : this->children()) {
        delete child;
    }

    hallsPageLayout = new QVBoxLayout(this);

    // Заголовок если есть
    if (title != "") {
        hallsLabel = new QLabel(title, this);
        hallsLabel->setFont(QFont("Segoe UI", 20, QFont::Bold));
        hallsLabel->setAlignment(Qt::Alignment(Qt::AlignCenter));
        hallsPageLayout->addWidget(hallsLabel);
    }

    // Scroll Area
    hallsScrollArea = new QScrollArea(this);
    hallsScrollArea->setWidgetResizable(true);
    hallsScrollAreaWidget = new QWidget();
    hallsScrollArea->setWidget(hallsScrollAreaWidget);
    hallsPageLayout->addWidget(hallsScrollArea);

    // Layout для равномерного заполнения
    hallsScrollAreaLayout = new QVBoxLayout(hallsScrollAreaWidget);

    hallsButtonsGroup = new QButtonGroup(this);

    for (auto hall : sal.getHalls()) {
        // Создание виджетов и добавление их в ScrollArea

        QPushButton *hallWidget = new QPushButton();
        hallWidget->setFixedHeight(75);
        hallWidget->setFlat(true);
        hallWidget->setCheckable(true);

        QGridLayout* hallLayout = new QGridLayout(hallWidget);

        // hall name
        QLabel* hallIdLabel = new QLabel(QString("%1").arg(hall->getId()));
        hallIdLabel->setFont(QFont("Arial", 14, QFont::Bold));

        // Размер
        QLabel* hallSpaceLabel = new QLabel(QString("%1 мест").arg(hall->getNums() * hall->getRows()));
        hallSpaceLabel->setFont(QFont("Arial", 11, QFont::Bold));
        hallSpaceLabel->setAlignment(Qt::Alignment(Qt::AlignRight));
        hallSpaceLabel->setStyleSheet("QLabel { color : green; }");

        // Компановка
        hallLayout->addWidget(hallIdLabel, 1, 1, 1, 2);
        hallLayout->addWidget(hallSpaceLabel, 1, 3);

        hallsScrollAreaLayout->addWidget(hallWidget);
        hallsButtonsGroup->addButton(hallWidget, hall->getId());
    }

    // Spacer для заполнения нижней части, чтоб виджеты фильмов не растягивались на всю высоту
    hallsScrollSpaser = new QSpacerItem(100, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);
    hallsScrollAreaLayout->addItem(hallsScrollSpaser);
}
