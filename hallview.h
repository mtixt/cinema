#ifndef HALLVIEW_H
#define HALLVIEW_H

#include <QDialog>
#include "hall.h"

namespace Ui {
class HallView;
}

class HallView : public QDialog
{
    Q_OBJECT

public:
    explicit HallView(Hall* hall, QWidget *parent = nullptr);
    ~HallView();

private:
    Ui::HallView *ui;
};

#endif // HALLVIEW_H
