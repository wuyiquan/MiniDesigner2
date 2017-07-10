#include "../model/model.h"
#include "../viewmodel/viewmodel.h"
#include <exception>
#include <QDebug>
#include <memory>

ViewModel::ViewModel()
{
    changeIDCmd = std::make_shared<ChangeIDCmd>(this);
    changeLevelCmd = std::make_shared<ChangeLevelCmd>(this);
    changeParentCmd = std::make_shared<ChangeParentCmd>(this);
    changePosCmd = std::make_shared<ChangePosCmd>(this);
    changeSizeCmd = std::make_shared<ChangeSizeCmd>(this);
    changeSubObjectCmd = std::make_shared<ChangeSubObjectCmd>(this);
    changeTextCmd = std::make_shared<ChangeTextCmd>(this);
    setID(this->model->getObjectId());
    setLevel(this->model->getObjectLevel());
    setParent(this->model->getObjectParent());
    setPos(this->model->getObjectPos());
    setSize(this->model->getObjectSize());
    setText(this->model->getObjectText());
}

ViewModel::ViewModel(std::shared_ptr<object> model) : model(model)
{
    changeIDCmd = std::make_shared<ChangeIDCmd>(this);
    changeLevelCmd = std::make_shared<ChangeLevelCmd>(this);
    changeParentCmd = std::make_shared<ChangeParentCmd>(this);
    changePosCmd = std::make_shared<ChangePosCmd>(this);
    changeSizeCmd = std::make_shared<ChangeSizeCmd>(this);
    changeSubObjectCmd = std::make_shared<ChangeSubObjectCmd>(this);
    changeTextCmd = std::make_shared<ChangeTextCmd>(this);
    setID(this->model->getObjectId());
    setLevel(this->model->getObjectLevel());
    setParent(this->model->getObjectParent());
    setPos(this->model->getObjectPos());
    setSize(this->model->getObjectSize());
    setText(this->model->getObjectText());
}

ChangeIDCmd::ChangeIDCmd(ViewModel *viewmodel) : viewmodel(viewmodel)
{

}

ChangeLevelCmd::ChangeLevelCmd(ViewModel *viewmodel) : viewmodel(viewmodel)
{

}

ChangeParentCmd::ChangeParentCmd(ViewModel *viewmodel) : viewmodel(viewmodel)
{

}

ChangePosCmd::ChangePosCmd(ViewModel *viewmodel) : viewmodel(viewmodel)
{

}

ChangeSizeCmd::ChangeSizeCmd(ViewModel *viewmodel) : viewmodel(viewmodel)
{

}

ChangeTextCmd::ChangeTextCmd(ViewModel *viewmodel) : viewmodel(viewmodel)
{

}

ChangeSubObjectCmd::ChangeSubObjectCmd(ViewModel *viewmodel) : viewmodel(viewmodel)
{

}

std::shared_ptr<Command> ViewModel::getChangeTextCmd()
{
    return changeTextCmd;
}

std::shared_ptr<Command> ViewModel::getChangeIDCmd()
{
    return changeIDCmd;
}

std::shared_ptr<Command> ViewModel::getChangeLevelCmd()
{
    return changeLevelCmd;
}

std::shared_ptr<Command> ViewModel::getChangePosCmd()
{
    return changePosCmd;
}

std::shared_ptr<Command> ViewModel::getChangeSizeCmd()
{
    return changeSizeCmd;
}

std::shared_ptr<Command> ViewModel::getChangeSubObjectCmd()
{
    return changeSubObjectCmd;
}

std::shared_ptr<Command> ViewModel::getChangeParentCmd()
{
    return changeParentCmd;
}

void ChangeTextCmd::setParam(std::shared_ptr<Parameter> param)
{
    try
    {
        m_param = std::dynamic_pointer_cast<TextParam>(param);
    }
    catch (std::exception e)
    {
        qDebug() << e.what();
    }
}

void ChangePosCmd::setParam(std::shared_ptr<Parameter> param)
{
    try
    {
        m_param = std::dynamic_pointer_cast<PosParam>(param);
    }
    catch (std::exception e)
    {
        qDebug() << e.what();
    }
}

void ChangeSizeCmd::setParam(std::shared_ptr<Parameter> param)
{
    try
    {
        m_param = std::dynamic_pointer_cast<SizeParam>(param);
    }
    catch (std::exception e)
    {
        qDebug() << e.what();
    }
}

void ChangeLevelCmd::setParam(std::shared_ptr<Parameter> param)
{
    try
    {
        m_param = std::dynamic_pointer_cast<LevelParam>(param);
    }
    catch (std::exception e)
    {
        qDebug() << e.what();
    }
}

void ChangeParentCmd::setParam(std::shared_ptr<Parameter> param)
{
    try
    {
        m_param = std::dynamic_pointer_cast<ParentParam>(param);
    }
    catch (std::exception e)
    {
        qDebug() << e.what();
    }
}

void ChangeIDCmd::setParam(std::shared_ptr<Parameter> param)
{
    try
    {
        m_param = std::dynamic_pointer_cast<IDParam>(param);
    }
    catch (std::exception e)
    {
        qDebug() << e.what();
    }
}

void ChangeSubObjectCmd::setParam(std::shared_ptr<Parameter> param)
{
    try
    {
        m_param = std::dynamic_pointer_cast<SubObjectParam>(param);
    }
    catch (std::exception e)
    {
        qDebug() << e.what();
    }
}

void ChangeIDCmd::exec()
{
    viewmodel->model->setObjectId(m_param->getId());
    this->viewmodel->changeIDNotify->onPropertyChanged();
}

void ChangeLevelCmd::exec()
{
    viewmodel->model->setObjectLevel(m_param->getLevel());
    this->viewmodel->changeLevelNotify->onPropertyChanged();
}

void ChangeParentCmd::exec()
{
    viewmodel->model->setObjectParent(m_param->getParent(),0);
    this->viewmodel->changeParentNotify->onPropertyChanged();
}

void ChangePosCmd::exec()
{
    viewmodel->model->setObjectPos(m_param->getPos());
    this->viewmodel->changePosNotify->onPropertyChanged();
}

void ChangeSizeCmd::exec()
{
    viewmodel->model->setObjectSize(m_param->getSize());
    this->viewmodel->changeSizeNotify->onPropertyChanged();
}

void ChangeSubObjectCmd::exec()
{
    viewmodel->model->setSubObject(m_param->getSubObject());
    this->viewmodel->changeTextNotify->onPropertyChanged();
}

void ChangeTextCmd::exec()
{
    viewmodel->model->setObjectText(m_param->getText());
    this->viewmodel->changeTextNotify->onPropertyChanged();
}

void ViewModel::setChangeTextNotify(std::shared_ptr<Notification> notify)
{
    changeTextNotify = notify;
}

void ViewModel::setChangeSubObjectNotify(std::shared_ptr<Notification> notify)
{
    changeSubObjectNotify = notify;
}

void ViewModel::setChangeIDNotify(std::shared_ptr<Notification> notify)
{
    changeIDNotify = notify;
}

void ViewModel::setChangeLevelNotify(std::shared_ptr<Notification> notify)
{
    changeLevelNotify = notify;
}

void ViewModel::setChangePosNotify(std::shared_ptr<Notification> notify)
{
    changePosNotify = notify;
}

void ViewModel::setChangeSizeNotify(std::shared_ptr<Notification> notify)
{
    changeSizeNotify = notify;
}

void ViewModel::setChangeParentNotify(std::shared_ptr<Notification> notify)
{
    changeParentNotify = notify;
}

void ViewModel::setID(std::shared_ptr<int> id)
{
    this->id = id;
}

std::shared_ptr<int> ViewModel::getID()
{
    return id;
}

void ViewModel::setLevel(std::shared_ptr<int> level)
{
    this->level = level;
}

std::shared_ptr<int> ViewModel::getLevel()
{
    return this->level;
}

void ViewModel::setPos(std::pair<std::shared_ptr<int>, std::shared_ptr<int>> xy)
{
    this->x = xy.first;
    this->y = xy.second;
}

std::pair<std::shared_ptr<int>, std::shared_ptr<int>> ViewModel::getPos()
{
    return std::make_pair(this->x, this->y);
}
void ViewModel::setSize(std::pair<std::shared_ptr<int>, std::shared_ptr<int>> hw)
{
    this->height = hw.first;
    this->weight = hw.second;
}

std::pair<std::shared_ptr<int>, std::shared_ptr<int>> ViewModel::getSize()
{
    return std::make_pair(this->height, this->weight);
}

void ViewModel::setParent(std::shared_ptr<int> parent)
{
    this->parent = parent;
}

std::shared_ptr<int> ViewModel::getParent()
{
    return this->parent;
}

void ViewModel::setText(std::shared_ptr<QString> text)
{
    this->text = text;
}

std::shared_ptr<QString> ViewModel::getText()
{
    return this->text;
}

/*void ViewModel::setObject(std::shared_ptr<int> id)
{
    SubObject.push_back(id);
}*/

std::vector<int> ViewModel::getObject()
{
    return SubObject;
}

/*void viewmodel::setParam(std::shared_ptr<Parameter> param)
{
    this->v_param = param;
}

void viewmodel::exec()
{
    switch(v_param->type)
    {
    case PARAM_TEXT:
        break;
    case PARAM_TEXT_ED:
        break;
    case PARAM_POS:
        setObjectPos(v_param->getX(), v_param->getY());
        break;
    case PARAM_SIZE:
        setObjectSize(v_param->getHeight(), v_param->getWeight());
        break;
    case PARAM_PARENT:
        setObjectParent(v_param->getParent(), v_param->getHeight()); // Height or Depth ?
        break;
    case PARAM_LEVEL:
        setObjectLevel(v_param->getLevel());
        break;
    case PARAM_SUBOBJECTS:
        setSubObject(v_param->getId());
        break;
    case PARAM_ID:
        setObjectId(v_param->getId());
        break;
    }
}

void viewmodel::setChanges()
{

}

void viewmodel::onPropertyChanged()
{

}*/
