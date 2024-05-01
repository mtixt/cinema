#ifndef HALLSPAGE_H
#define HALLSPAGE_H

#include "saveandload.h"
#include <QWidget>
#include <QVBoxLayout>
#include <QButtonGroup>
#include <QPushButton>
#include <QScrollArea>
#include <QLabel>


class HallsPage : public QWidget
{
    Q_OBJECT

private:
    SaveAndLoad& sal = SaveAndLoad::init();

    QVBoxLayout* hallsPageLayout;
    QLabel* hallsLabel;
    QScrollArea* hallsScrollArea;
    QWidget* hallsScrollAreaWidget;
    QVBoxLayout* hallsScrollAreaLayout;
    QSpacerItem* hallsScrollSpaser;

public:
    explicit HallsPage(QWidget *parent = nullptr);
    QButtonGroup* hallsButtonsGroup;

public slots:
    void render_page(const vector <Hall*>& halls, QString title = "");

signals:
};

#endif // HALLSPAGE_H
