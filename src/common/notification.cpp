#include "../common/notification.h"

Notification::Notification()
{

}

void Notification::setChange(std::shared_ptr<Parameter> param)
{
    this->type = NOTIFI_ATTR_CHANGE;
    this->m_param = param;
}

void Notification::onPropertyChanged()
{

}
