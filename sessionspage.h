#ifndef SESSIONSPAGE_H
#define SESSIONSPAGE_H

#include "saveandload.h"
#include <QWidget>
#include <QVBoxLayout>
#include <QButtonGroup>
#include <QPushButton>
#include <QScrollArea>
#include <QLabel>


class SessionsPage : public QWidget
{
    Q_OBJECT

private:
    SaveAndLoad& sal = SaveAndLoad::init();

    QVBoxLayout* sessionsPageLayout;
    QLabel* sessionsLabel;
    QScrollArea* sessionsScrollArea;
    QWidget* sessionsScrollAreaWidget;
    QVBoxLayout* sessionsScrollAreaLayout;
    QSpacerItem* sessionsScrollSpaser;

public:
    explicit SessionsPage(QWidget *parent = nullptr);
    QButtonGroup* sessionsButtonsGroup;

public slots:
    void render_page(const vector<Session*>& sessions, QString title = "");

signals:
};

#endif // SESSIONSPAGE_H
