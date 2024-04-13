#ifndef FILMSPAGE_H
#define FILMSPAGE_H

#include "saveandload.h"
#include <QWidget>
#include <QVBoxLayout>
#include <QButtonGroup>
#include <QPushButton>
#include <QScrollArea>
#include <QLabel>


class FilmsPage : public QWidget
{
    Q_OBJECT

private:
    SaveAndLoad& sal = SaveAndLoad::init();

    QVBoxLayout* filmsPageLayout;
    QLabel* filmsLabel;
    QScrollArea* filmsScrollArea;
    QWidget* filmsScrollAreaWidget;
    QVBoxLayout* filmsScrollAreaLayout;
    QSpacerItem* filmsScrollSpaser;

public:
    explicit FilmsPage(QWidget *parent = nullptr);
    QButtonGroup* filmButtonsGroup;

public slots:
    void render_page();

signals:
};

#endif // FILMSPAGE_H
