#include <QLabel>
#include <QLayout>
#include <algorithm>
#include "minidesigner.h"
#include "common/command.h"
#include "common/parameter.h"
#include "ui_minidesigner.h"

MiniDesigner::MiniDesigner(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MiniDesigner)
{
    ui->setupUi(this);
    QVBoxLayout *layout = new QVBoxLayout;
    QLabel *label = addLabel();
    label->setParent(this);
    items.push_back({
                        1,
                        TEXT,
                        label
                    });
    QLineEdit *inputBox = addInput();
    inputBox->setParent(this);
    items.push_back({
                        2,
                        TEXT,
                        inputBox
                    });
    layout->addWidget(label);
    layout->addWidget(inputBox);
    QWidget *textWidget = new QWidget(this);
    textWidget->setLayout(layout);
    setCentralWidget(textWidget);

    connect(inputBox, &QLineEdit::textChanged,this, &MiniDesigner::onTextChanged);
}

MiniDesigner::~MiniDesigner()
{
    delete ui;
}

QLabel *MiniDesigner::addLabel()
{
    QLabel *testLabel = new QLabel("test");
    return testLabel;
}

QLineEdit *MiniDesigner::addInput()
{
    QLineEdit *dialog = new QLineEdit();
    return dialog;
}

void MiniDesigner::onTextChanged(QString newText)
{
    for (auto item = items.begin(); item != items.end(); item++) {
        if (item->id == 1) {
            switch(item->type) {
                case TEXT:
                    QLabel *textLabel = (QLabel *)(item->widget);
                    std::shared_ptr<Parameter> textParam = std::make_shared<TextParam>();
                    changeTextCmd->setParam(textParam);
                    changeTextCmd->exec();
                break;
            }
        }
    }
}

void MiniDesigner::set_changeTextCmd(std::shared_ptr<Command> cmd)
{
    changeTextCmd = cmd;
}

