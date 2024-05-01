#ifndef ACTORSPAGE_H
#define ACTORSPAGE_H

#include "saveandload.h"
#include <QWidget>
#include <QVBoxLayout>
#include <QButtonGroup>
#include <QPushButton>
#include <QScrollArea>
#include <QLabel>


class ActorsPage : public QWidget
{
    Q_OBJECT

private:
    SaveAndLoad& sal = SaveAndLoad::init();

    QVBoxLayout* actorsPageLayout;
    QLabel* actorsLabel;
    QScrollArea* actorsScrollArea;
    QWidget* actorsScrollAreaWidget;
    QVBoxLayout* actorsScrollAreaLayout;
    QSpacerItem* actorsScrollSpaser;

public:
    explicit ActorsPage(QWidget *parent = nullptr);
    QButtonGroup* actorsButtonsGroup;

public slots:
    void render_page(const vector<Actor*>& actors, QString title = "");

signals:
};

#endif // ACTORSPAGE_H
