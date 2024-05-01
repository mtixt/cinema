#ifndef ACTOREDIT_H
#define ACTOREDIT_H

#include <QDialog>
#include "actor.h"
#include "saveandload.h"

namespace Ui {
class actorEdit;
}

class ActorEdit : public QDialog
{
    Q_OBJECT

public:
    explicit ActorEdit(Actor* actor, QWidget *parent = nullptr);
    ~ActorEdit();

private slots:
    void on_resetButton_clicked();

    void on_saveButton_clicked();

private:
    Actor* actor;
    SaveAndLoad& sal = SaveAndLoad::init();

    Ui::actorEdit *ui;
};

#endif // ACTOREDIT_H
