#ifndef NOTIFICATION_H
#define NOTIFICATION_H

#include <memory>
#include "../common/parameter.h"

enum NotifyType {
    NOTIFI_CHANGE_TEXT,
    NOTIFI_ATTR_CHANGE,
    NOTIFI_ATTR_CHANGED
};

class Notification
{
private:
    std::shared_ptr<Parameter> m_param;

public:
    Notification();
    virtual void setChange(std::shared_ptr<Parameter> param) = 0;
    virtual void onPropertyChanged() = 0;
    NotifyType type;
};

#endif // NOTIFICATION_H
