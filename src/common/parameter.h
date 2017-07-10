#ifndef PARAMETER_H
#define PARAMETER_H
#include <QString>
#include <vector>

enum modelType{
    PICTURE,
    MOSAIC,
    BOARD
};

enum ParamType {
    PARAM_TEXT,
    PARAM_TEXT_ED,
    PARAM_POS,
    PARAM_SIZE,
    PARAM_PARENT,
    PARAM_LEVEL,
    PARAM_SUBOBJECTS,
    PARAM_ID
};

class Parameter
{
/*protected:
    int x;
    int y;
    int height;
    int weight;
    int parent;
    int id;
    int level;
    std::vector<int> subObject;*/
    modelType modeltype;
public:
    Parameter();
    ParamType type;
    /*void setParent(int parent);
    void setId(int id);
    void setLevel(int level);
    void setX(int x);
    void setY(int y);
    void setHeight(int height);
    void setWeight(int weight);
    int getParent();
    int getId();
    int getLevel();
    int getX();
    int getY();
    int getHeight();
    int getWeight();*/
    virtual ~Parameter() = default;
};

class SubObjectParam : public Parameter
{
private:
    int id;
public:
    SubObjectParam() = default;
    SubObjectParam(int id);
    int getSubObject();
    ParamType type;
};

class TextParam : public Parameter
{
private:
    QString text;
public:
    TextParam() = default;
    TextParam(QString text);
    QString getText();
    ParamType type;
};

class ParentParam : public Parameter
{
private:
    int parent;
public:
    ParentParam() = default;
    ParentParam(int parent);
    int getParent();
    ParamType type;
};

class IDParam : public Parameter
{
private:
    int id;
public:
    IDParam() = default;
    IDParam(int id);
    int getId();
    ParamType type;
};

class LevelParam : public Parameter
{
private:
    int level;
public:
    LevelParam() = default;
    LevelParam(int level);
    int getLevel();
    ParamType type;
};

class SizeParam : public Parameter
{
private:
    int height;
    int weight;
public:
    SizeParam() = default;
    SizeParam(int height, int weight);
    std::pair<int, int> getSize();
    ParamType type;
};

class PosParam : public Parameter
{
private:
    int x;
    int y;
public:
    PosParam() = default;
    PosParam(int x, int y);
    std::pair<int, int> getPos();
    ParamType type;
};

class TextParamEd : public Parameter
{
private:
    QString text;
public:
    TextParamEd() = default;
    TextParamEd(QString text);
    QString getText();
    ParamType type;
};

#endif // PARAMETER_H
