#ifndef DIRECTORSPAGE_H
#define DIRECTORSPAGE_H

#include "saveandload.h"
#include <QWidget>
#include <QVBoxLayout>
#include <QButtonGroup>
#include <QPushButton>
#include <QScrollArea>
#include <QLabel>


class DirectorsPage : public QWidget
{
    Q_OBJECT
private:
    SaveAndLoad& sal = SaveAndLoad::init();

    QVBoxLayout* directorsPageLayout;
    QLabel* directorsLabel;
    QScrollArea* directorsScrollArea;
    QWidget* directorsScrollAreaWidget;
    QVBoxLayout* directorsScrollAreaLayout;
    QSpacerItem* directorsScrollSpaser;


public:
    explicit DirectorsPage(QWidget *parent = nullptr);
    QButtonGroup* directorsButtonsGroup;

public slots:
    void render_page(const vector<Director*>& directors, QString title = "");
};

#endif // DIRECTORSPAGE_H
