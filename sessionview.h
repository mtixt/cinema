#ifndef SESSIONVIEW_H
#define SESSIONVIEW_H

#include <QDialog>
#include "session.h"
#include "saveandload.h"
#include "QButtonGroup"
#include "QPushButton"
#include "QGridLayout"
#include "sellticketpage.h"


namespace Ui {
class SessionView;
}

class SessionView : public QDialog
{
    Q_OBJECT

public:
    explicit SessionView(Session* session, QWidget *parent = nullptr);
    ~SessionView();

private:
    Ui::SessionView *ui;
    SaveAndLoad& sal = SaveAndLoad::init();

    Session* session;

    QWidget* spaceWidget;
    QGridLayout* spaceLayout;
    QButtonGroup* spaceButtonGroup;
    SellTicketPage* sellTicketPage;

public slots:
    void render_space();
private slots:
    void on_bookButton_clicked();
};

#endif // SESSIONVIEW_H
