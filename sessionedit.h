#ifndef SESSIONEDIT_H
#define SESSIONEDIT_H

#include <QDialog>
#include "session.h"
#include "saveandload.h"

namespace Ui {
class SessionEdit;
}

class SessionEdit : public QDialog
{
    Q_OBJECT

public:
    explicit SessionEdit(Session* session, QWidget *parent = nullptr);
    ~SessionEdit();

private slots:
    void on_saveButton_clicked();

    void on_resetButton_clicked();

private:
    Session* session;
    SaveAndLoad& sal = SaveAndLoad::init();

    Ui::SessionEdit *ui;
};

#endif // SESSIONEDIT_H
