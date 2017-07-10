#ifndef VIEWMODEL_H
#define VIEWMODEL_H

#include "../model/model.h"
#include "../common/parameter.h"
#include "../common/notification.h"
#include "../common/command.h"
#include <string>
#include <vector>
#include <memory>

class ViewModel;

class ChangeTextCmd : public Command
{
private:
    std::shared_ptr<TextParam> m_param;
    ViewModel *viewmodel;

public:
    ChangeTextCmd(ViewModel *viewmodel);
    void setParam(std::shared_ptr<Parameter> param);
    void exec();
};

class ChangePosCmd : public Command
{
private:
    std::shared_ptr<PosParam> m_param;
    ViewModel *viewmodel;

public:
    ChangePosCmd(ViewModel *viewmodel);
    void setParam(std::shared_ptr<Parameter> param);
    void exec();
};

class ChangeSizeCmd : public Command
{
private:
    std::shared_ptr<SizeParam> m_param;
    ViewModel *viewmodel;

public:
    ChangeSizeCmd(ViewModel *viewmodel);
    void setParam(std::shared_ptr<Parameter> param);
    void exec();
};

class ChangeParentCmd : public Command
{
private:
    std::shared_ptr<ParentParam> m_param;
    ViewModel *viewmodel;

public:
    ChangeParentCmd(ViewModel *viewmodel);
    void setParam(std::shared_ptr<Parameter> param);
    void exec();
};

class ChangeIDCmd : public Command
{
private:
    std::shared_ptr<IDParam> m_param;
    ViewModel *viewmodel;

public:
    ChangeIDCmd(ViewModel *viewmodel);
    void setParam(std::shared_ptr<Parameter> param);
    void exec();
};

class ChangeLevelCmd : public Command
{
private:
    std::shared_ptr<LevelParam> m_param;
    ViewModel *viewmodel;

public:
    ChangeLevelCmd(ViewModel *viewmodel);
    void setParam(std::shared_ptr<Parameter> param);
    void exec();
};

class ChangeSubObjectCmd : public Command
{
private:
    std::shared_ptr<SubObjectParam> m_param;
    ViewModel *viewmodel;

public:
    ChangeSubObjectCmd(ViewModel *viewmodel);
    void setParam(std::shared_ptr<Parameter> param);
    void exec();
};

/*class ChangeSubObjectCmd : public Command
{
private:
    std::shared_ptr<SubObjectParam> m_param;
    std::shared_ptr<int> level;
    ViewModel *viewmodel;
public:
    ChangeSubObjectCmd(ViewModel *viewmodel);
    void setParam(std::shared_ptr<Parameter> param);
    void exec();
};*/

class ViewModel
{
private:
    std::shared_ptr<Notification> changeTextNotify;
    std::shared_ptr<Notification> changeIDNotify;
    std::shared_ptr<Notification> changeLevelNotify;
    std::shared_ptr<Notification> changeParentNotify;
    std::shared_ptr<Notification> changePosNotify;
    std::shared_ptr<Notification> changeSizeNotify;
    std::shared_ptr<Notification> changeSubObjectNotify;

    std::shared_ptr<ChangeTextCmd> changeTextCmd;
    std::shared_ptr<ChangeIDCmd> changeIDCmd;
    std::shared_ptr<ChangeLevelCmd> changeLevelCmd;
    std::shared_ptr<ChangeParentCmd> changeParentCmd;
    std::shared_ptr<ChangePosCmd> changePosCmd;
    std::shared_ptr<ChangeSizeCmd> changeSizeCmd;
    std::shared_ptr<ChangeSubObjectCmd> changeSubObjectCmd;

    std::shared_ptr<QString> text;
    std::shared_ptr<int> x;
    std::shared_ptr<int> y;
    std::shared_ptr<int> height;
    std::shared_ptr<int> weight;
    std::shared_ptr<int> level;
    std::shared_ptr<int> id;
    std::shared_ptr<int> parent;
    std::vector<int> SubObject;

public:
    friend class ChangeTextCmd;
    friend class ChangeIDCmd;
    friend class ChangeLevelCmd;
    friend class ChangePosCmd;
    friend class ChangeSizeCmd;
    friend class ChangeSubObjectCmd;
    friend class ChangeParentCmd;

    ViewModel();
    ViewModel(std::shared_ptr<object> model);

    std::shared_ptr<object> model;
    std::shared_ptr<Command> getChangeTextCmd();
    std::shared_ptr<Command> getChangeIDCmd();
    std::shared_ptr<Command> getChangeLevelCmd();
    std::shared_ptr<Command> getChangePosCmd();
    std::shared_ptr<Command> getChangeSizeCmd();
    std::shared_ptr<Command> getChangeSubObjectCmd();
    std::shared_ptr<Command> getChangeParentCmd();

    void setChangeTextNotify(std::shared_ptr<Notification> notify);
    void setChangeIDNotify(std::shared_ptr<Notification> notify);
    void setChangeLevelNotify(std::shared_ptr<Notification> notify);
    void setChangePosNotify(std::shared_ptr<Notification> notify);
    void setChangeSizeNotify(std::shared_ptr<Notification> notify);
    void setChangeSubObjectNotify(std::shared_ptr<Notification> notify);
    void setChangeParentNotify(std::shared_ptr<Notification> notify);

    void setID(std::shared_ptr<int> id);
    std::shared_ptr<int> getID();
    void setLevel(std::shared_ptr<int> level);
    std::shared_ptr<int> getLevel();
    void setPos(std::pair<std::shared_ptr<int> , std::shared_ptr<int>>  xy);
    std::pair<std::shared_ptr<int>, std::shared_ptr<int>> getPos();
    void setSize(std::pair<std::shared_ptr<int>,std::shared_ptr<int>> hw);
    std::pair<std::shared_ptr<int>, std::shared_ptr<int>> getSize();
    void setParent(std::shared_ptr<int> parent);
    std::shared_ptr<int> getParent();
    void setText(std::shared_ptr<QString> text);
    std::shared_ptr<QString> getText();
    void setObject(std::shared_ptr<int> id);
    std::vector<int> getObject();
};

/*class viewmodel : public object
{
private:
    std::shared_ptr<Parameter> v_param;
public:
    void setParam(std::shared_ptr<Parameter> param);
    void exec();
    void setChanges();
    void onPropertyChanged();
};*/

#endif // VIEWMODEL_H
