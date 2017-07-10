//#include "minidesigner.h"
#include <QApplication>
#include <memory>
#include "viewmodel/viewmodel.h"
#include "model/model.h"

int main(int argc, char *argv[])
{
    std::shared_ptr<Parameter> param = std::make_shared<IDParam>(3);
    std::shared_ptr<object> model = std::make_shared<object>();
    ViewModel viewmodel(model);
    std::shared_ptr<Command> cmd = viewmodel.getChangeIDCmd();
    cmd->setParam(param);
    cmd->exec();
    /*Application a(argc, argv);
    MiniDesigner w;
    w.show();
    return a.exec();*/
}
