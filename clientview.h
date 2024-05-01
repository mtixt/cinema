#ifndef CLIENTVIEW_H
#define CLIENTVIEW_H

#include <QDialog>
#include "client.h"

namespace Ui {
class ClientView;
}

class ClientView : public QDialog
{
    Q_OBJECT

public:
    explicit ClientView(Client* client, QWidget *parent = nullptr);
    ~ClientView();

private:
    Ui::ClientView *ui;
};

#endif // CLIENTVIEW_H
