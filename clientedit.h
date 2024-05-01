#ifndef CLIENTEDIT_H
#define CLIENTEDIT_H

#include <QDialog>
#include "client.h"
#include "saveandload.h"

namespace Ui {
class ClientEdit;
}

class ClientEdit : public QDialog
{
    Q_OBJECT

public:
    explicit ClientEdit(Client* client, QWidget *parent = nullptr);
    ~ClientEdit();

private slots:
    void on_saveButton_clicked();

    void on_resetButton_clicked();

private:
    Client* client;
    SaveAndLoad& sal = SaveAndLoad::init();

    Ui::ClientEdit *ui;
};

#endif // CLIENTEDIT_H
