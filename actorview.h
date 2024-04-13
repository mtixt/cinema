#ifndef ACTORVIEW_H
#define ACTORVIEW_H

#include <QDialog>
#include "actor.h"

namespace Ui {
class ActorView;
}

class ActorView : public QDialog
{
    Q_OBJECT

public:
    explicit ActorView(Actor* actor, QWidget *parent = nullptr);
    ~ActorView();

private:
    Ui::ActorView *ui;
};

#endif // ACTORVIEW_H
