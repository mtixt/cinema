#include "filmspage.h"
#include "film.h"


FilmsPage::FilmsPage(QWidget *parent)
    : QWidget{parent}
{}

void FilmsPage::render_page(const vector<Film*>& films, QString title)
{
    // Очистка страницы
    for (auto child : this->children()) {
        delete child;
    }

    filmsPageLayout = new QVBoxLayout(this);

    // Заголовок если есть
    if (title != "") {
        filmsLabel = new QLabel(title, this);
        filmsLabel->setFont(QFont("Segoe UI", 20, QFont::Bold));
        filmsLabel->setAlignment(Qt::Alignment(Qt::AlignCenter));

        filmsPageLayout->addWidget(filmsLabel);
    }

    // Scroll Area
    filmsScrollArea = new QScrollArea(this);
    filmsScrollArea->setWidgetResizable(true);
    filmsScrollAreaWidget = new QWidget();
    filmsScrollArea->setWidget(filmsScrollAreaWidget);
    filmsPageLayout->addWidget(filmsScrollArea);

    // Layout для равномерного заполнения
    filmsScrollAreaLayout = new QVBoxLayout(filmsScrollAreaWidget);

    filmButtonsGroup = new QButtonGroup(this);

    for (auto film : films) {
        // Создание виджетов и добавление их в ScrollArea

        // Film Widget
        // QFrame *filmWidget = new QFrame();
        QPushButton *filmWidget = new QPushButton();
        filmWidget->setFixedHeight(100);
        filmWidget->setFlat(true);
        filmWidget->setCheckable(true);

        // filmWidget->setFrameStyle(QFrame::Plain);
        // filmWidget->setFrameShape(QFrame::StyledPanel);


        QGridLayout* filmLayout = new QGridLayout(filmWidget);

        // Film name
        QLabel* filmNameLabel = new QLabel(QString::fromStdString(film->getName()));
        filmNameLabel->setFont(QFont("Arial", 16, QFont::Bold));

        // Film description
        QLabel* filmDescLabel = new QLabel(QString::fromStdString(film->getDescription()));
        filmDescLabel->setFont(QFont("Arial", 10));
        filmDescLabel->setMaximumWidth(860);
        filmDescLabel->setWordWrap(true);

        // Film rating
        QLabel* filmRatingLabel = new QLabel(QString("%1").arg(film->getRating()));
        filmRatingLabel->setFont(QFont("Arial", 11, QFont::Bold));
        filmRatingLabel->setAlignment(Qt::Alignment(Qt::AlignRight));
        filmRatingLabel->setStyleSheet("QLabel { color : green; }");

        // Компановка
        filmLayout->addWidget(filmNameLabel, 1, 1);
        filmLayout->addWidget(filmDescLabel, 2, 1, 2, 3);
        filmLayout->addWidget(filmRatingLabel, 1, 3);

        filmsScrollAreaLayout->addWidget(filmWidget);
        filmButtonsGroup->addButton(filmWidget, film->getId());
    }

    // Spacer для заполнения нижней части, чтоб виджеты фильмов не растягивались на всю высоту
    filmsScrollSpaser = new QSpacerItem(100, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);
    filmsScrollAreaLayout->addItem(filmsScrollSpaser);
}
