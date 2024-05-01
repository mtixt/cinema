#ifndef CLIENTSPAGE_H
#define CLIENTSPAGE_H

#include "saveandload.h"
#include <QWidget>
#include <QVBoxLayout>
#include <QButtonGroup>
#include <QPushButton>
#include <QScrollArea>
#include <QLabel>

class ClientsPage : public QWidget
{
    Q_OBJECT

private:
    SaveAndLoad& sal = SaveAndLoad::init();

    QVBoxLayout* clientsPageLayout;
    QLabel* clientsLabel;
    QScrollArea* clientsScrollArea;
    QWidget* clientsScrollAreaWidget;
    QVBoxLayout* clientsScrollAreaLayout;
    QSpacerItem* clientsScrollSpaser;

public:
    explicit ClientsPage(QWidget *parent = nullptr);
    QButtonGroup* clientsButtonsGroup;

public slots:
    void render_page(const vector<Client*>& clients, QString title = "");

signals:
};

#endif // CLIENTSPAGE_H
