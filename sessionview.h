#ifndef SESSIONVIEW_H
#define SESSIONVIEW_H

#include <QDialog>
#include "session.h"
#include "saveandload.h"


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

public slots:
    void render_space(Session* session);
};

#endif // SESSIONVIEW_H
