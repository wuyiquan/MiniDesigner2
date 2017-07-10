#ifndef MODEL_H
#define MODEL_H
#include <vector>
#include <string>
#include <memory>
#include "../common/command.h"
#include "../common/notification.h"
#include "../common/parameter.h"

class object
{
friend bool cmp(const object* x,const object* y);
friend class objectList;
protected:
     std::shared_ptr<int> x;
     std::shared_ptr<int> y;
     std::shared_ptr<int> height;
     std::shared_ptr<int> weight;
     std::shared_ptr<modelType> modeltype;
     std::shared_ptr<int> id;
     std::shared_ptr<int> level;
     std::shared_ptr<int> parent; //0就是没有父亲
     std::shared_ptr<int> depth; //该节点在树节点上的高度
     std::shared_ptr<bool> del; //标记该object是否被delete,1为已经被delete
     std::vector<int> subObject;
     std::shared_ptr<Notification> changeNoti;
     std::shared_ptr<QString> text;
public:
     object();
     virtual ~object()=default;
     std::pair<std::shared_ptr<int>,std::shared_ptr<int> > getObjectPos();
     std::pair<std::shared_ptr<int>,std::shared_ptr<int> > getObjectSize();
     std::shared_ptr<modelType> getObjectType();
     std::shared_ptr<int> getObjectParent();
     std::shared_ptr<int> getObjectLevel();
     std::shared_ptr<int> getObjectId();
     std::shared_ptr<int> getObjectDepth();
     void setObjectPos(std::pair<int, int>);
     void setObjectSize(std::pair<int, int>);
     void setObjectType(modelType type);
     void setObjectLevel(int level);
     void setObjectId(int id);
     void setChangeNoti(const std::shared_ptr<Notification> noti);
     //将该object标记为delete
     void setObjectDel();
     void setObjectText(QString text);
     std::shared_ptr<QString> getObjectText();
     std::shared_ptr<Notification> getChangeNoti();
     void setSubObject(int id);
     void setObjectParent(int parent,int parentDepth);
};

class objectList
{
private:
     std::shared_ptr<std::vector<object*> > listPtr;
     std::shared_ptr<Notification> changeNoti;
public:
     objectList();
     virtual ~objectList()=default;
     std::shared_ptr<std::vector<object*> > getListPtr();
     //对所有的元素进行排序，使其可以直接被painter顺序调用
     void sort();
     //通过偏移量来移动object和object的子树
     void setObjectPosOff(int id,int x,int y);
     //通过指定儿子和父亲的id,来设置某个元素的父亲
     void setObjectParent(int sonId,int parId);
     void setChangeNoti(const std::shared_ptr<Notification> noti);
     std::shared_ptr<Notification> getChangeNoti();
};
#endif // MODEL_H
