#ifndef COMMAND_H
#define COMMAND_H
#include "../common/parameter.h"
#include <memory>

enum CmdType {
    CMD_CHANGE_TEXT,
    CMD_CHANGE_POS,
    CMD_CHANGE_SIZE,
    CMD_CHANGE_PARENT,
    CMD_CHANGE_ID,
    CMD_CHANGE_LEVEL,
    CMD_CHANGE_SUBOBJECTS,
    CMD_ADD,
    CMD_DELETE
};

class Command
{
private:
    std::shared_ptr<Parameter> m_param;

public:
    CmdType type;
    Command();
    virtual void setParam(std::shared_ptr<Parameter> param) = 0;
    virtual void exec() = 0;
    virtual ~Command() = default;
};

#endif // COMMAND_H
