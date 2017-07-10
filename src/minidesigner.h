#ifndef MINIDESIGNER_H
#define MINIDESIGNER_H

#include <QMainWindow>
#include <QInputDialog>
#include <vector>
#include <QLabel>
#include "common/command.h"

#define TEST 1

namespace Ui {
class MiniDesigner;
}

class MiniDesigner : public QMainWindow
{
    Q_OBJECT

public:
    explicit MiniDesigner(QWidget *parent = 0);
    ~MiniDesigner();
    void set_changeTextCmd(std::shared_ptr<Command> cmd);

private:
    enum ItemType {
        TEXT,
        BUTTON
    };

    struct Item{
        int id;
        ItemType type;
        QWidget *widget;
    };
    Ui::MiniDesigner *ui;
    std::vector<Item> items;
    std::shared_ptr<Command> changeTextCmd;
#if TEST
    QLabel *addLabel();
    QLineEdit *addInput();
    void onTextChanged(QString newText);
#endif
};

#endif // MINIDESIGNER_H
