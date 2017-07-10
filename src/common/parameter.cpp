#include "../common/parameter.h"

Parameter::Parameter()
{

}

/*void Parameter::setParent(int parent)
{
    this->parent = parent;
}

void Parameter::setId(int id)
{
    this->id = id;
}

void Parameter::setLevel(int level)
{
    this->level = level;
}

void Parameter::setX(int x)
{
    this->attribute.x = x;
}

void Parameter::setY(int y)
{
    this->attribute.y = y;
}

void Parameter::setHeight(int height)
{
    this->attribute.height = height;
}

void Parameter::setWeight(int weight)
{
    this->attribute.weight = weight;
}

int Parameter::getParent()
{
    return this->parent;
}

int Parameter::getId()
{
    return this->id;
}

int Parameter::getLevel()
{
    return this->level;
}

int Parameter::getX()
{
    return this->attribute.x;
}

int Parameter::getY()
{
    return this->attribute.y;
}

int Parameter::getHeight()
{
    return this->attribute.height;
}

int Parameter::getWeight()
{
    return this->attribute.weight;
}*/

TextParam::TextParam(QString text) : type(PARAM_TEXT), text(text)
{

}

IDParam::IDParam(int id) : type(PARAM_ID)
{

}

ParentParam::ParentParam(int parent) : type(PARAM_PARENT)
{

}

LevelParam::LevelParam(int level) : type(PARAM_LEVEL)
{

}

SizeParam::SizeParam(int height, int weight) : type(PARAM_SIZE)
{

}

PosParam::PosParam(int x, int y) : type(PARAM_POS)
{

}

SubObjectParam::SubObjectParam(int id) : type(PARAM_SUBOBJECTS)
{

}

TextParamEd::TextParamEd(QString text) : type(PARAM_TEXT_ED), text(text)
{

}

QString TextParam::getText()
{
    return this->text;
}

std::pair<int, int> PosParam::getPos()
{
    return std::make_pair(this->x, this->y);
}

std::pair<int, int> SizeParam::getSize()
{
    return std::make_pair(this->height, this->weight);
}

int IDParam::getId()
{
    return this->id;
}

int LevelParam::getLevel()
{
    return this->level;
}

int ParentParam::getParent()
{
    return this->parent;
}

int SubObjectParam::getSubObject()
{
    return this->id;
}

QString TextParamEd::getText()
{
    return text;
}
