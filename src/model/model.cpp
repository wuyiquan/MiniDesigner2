#include "../model/model.h"
object::object()
{
    x = std::make_shared<int>(0);
    y = std::make_shared<int>(0);
    height = std::make_shared<int>(0);
    weight = std::make_shared<int>(0);
    modeltype = std::make_shared<modelType>();
    id = std::make_shared<int>(0);
    level = std::make_shared<int>(0);
    parent = std::make_shared<int>(0);
    depth = std::make_shared<int>(0);
    del = std::make_shared<bool>(0);
    subObject.clear();
    text = std::make_shared<QString>("");
}

objectList::objectList()
{
    listPtr = std::make_shared<std::vector<std::shared_ptr<object> > >();
    (*listPtr).clear();
}

std::pair<std::shared_ptr<int>,std::shared_ptr<int> > object::getObjectPos()
{
    return std::make_pair(this->x,this->y);
}

std::pair<std::shared_ptr<int>,std::shared_ptr<int> > object::getObjectSize()
{
    return std::make_pair(this->height,this->weight);
}

std::shared_ptr<modelType> object::getObjectType()
{
    return this->modeltype;
}

std::shared_ptr<int> object::getObjectLevel()
{
    return level;
}

std::shared_ptr<int> object::getObjectId()
{
    return id;
}

std::shared_ptr<int> object::getObjectParent()
{
    return parent;
}

std::shared_ptr<int> object::getObjectDepth()
{
    return depth;
}

void object::setObjectDel()
{
    (*del) = 1;
    changeNoti->type = NOTIFI_ATTR_CHANGED;
}

void object::setChangeNoti(const std::shared_ptr<Notification> noti)
{
    changeNoti = noti;
}

void object::setObjectPos(std::pair<int,int> xy)
{
    *(this->x) = xy.first;
    *(this->y) = xy.second;
    changeNoti->type = NOTIFI_ATTR_CHANGED;
}

void object::setObjectSize(std::pair<int,int> hw)
{
    *(this->height) = hw.first;
    *(this->weight) = hw.second;
    changeNoti->type = NOTIFI_ATTR_CHANGED;
}

void object::setObjectId(int id)
{
    *(this->id) = id;
    changeNoti->type = NOTIFI_ATTR_CHANGED;
    qDebug("s");
}

void object::setObjectLevel(int level)
{
    *(this->level) = level;
    changeNoti->type = NOTIFI_ATTR_CHANGED;
}

void object::setObjectParent(int parent,int parentDepth)
{
    *(this->parent) = parent;
    *depth = parentDepth + 1;
    changeNoti->type = NOTIFI_ATTR_CHANGED;
}

void object::setObjectType(modelType type)
{
    *(this->modeltype) = type;
    changeNoti->type = NOTIFI_ATTR_CHANGED;
}

void object::setSubObject(int id)
{
    subObject.push_back(id);
    changeNoti->type = NOTIFI_ATTR_CHANGED;
}

std::shared_ptr<Notification> object::getChangeNoti()
{
    return changeNoti;
}

void object::setObjectText(QString text)
{
    *(this->text) = text;
}

std::shared_ptr<QString> object::getObjectText()
{
    return text;
}

bool cmp(const std::shared_ptr<object> x,const std::shared_ptr<object> y)
{
    if(*(x->level) != *(y->level)) return *(x->level) < *(y->level);
    if(*(x->depth) != *(y->depth)) return *(x->depth) < *(y->depth);
    return *(x->id) < *(y->id);
}

void objectList::sort()
{
    std::sort((*listPtr).begin(),(*listPtr).end(),cmp);
}

void objectList::setObjectPosOff(int id,int x,int y)
{
    for(auto &i:*listPtr)
    {
        if(*(i->id)==id)
        {
            *(i->x)+=x;
            *(i->y)+=y;
            for(auto &j:i->subObject)
            {
                this->setObjectPosOff(j,x,y);
            }
        }
    }
    changeNoti->type=NOTIFI_ATTR_CHANGED;
}

void objectList::setChangeNoti(const std::shared_ptr<Notification> noti)
{
    changeNoti=noti;
}

std::shared_ptr<Notification> objectList::getChangeNoti()
{
    return changeNoti;
}

void objectList::setObjectParent(int sonId,int parId)
{
    int faHeight;
    for(auto &i:*listPtr)
    {
        if(*(i->id)==parId)
        {
            i->setSubObject(sonId);
            faHeight=*(i->getObjectDepth());
        }
    }
    for(auto &i:*listPtr)
    {
        if(*(i->id)==sonId)
        {
            i->setObjectParent(parId,faHeight);
        }
    }
    changeNoti->type=NOTIFI_ATTR_CHANGED;
}

void objectList::setNewObject(int id)
{
    std::shared_ptr<object> newObject=std::make_shared<object>();
    *(newObject->id)=id;
}

std::shared_ptr<std::vector<std::shared_ptr<object> > > objectList::getListPtr()
{
    return listPtr;
}
