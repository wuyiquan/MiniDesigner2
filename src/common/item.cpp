#include "item.h"

Item::Item(int id, int x, int y, int h, int w) :
    id(id), x(x), y(y), h(h), w(w)
{}

TextItem::TextItem(int id, int x, int y, int h, int w, QString text) :
    Item(id, x, y, h, w), text(text)
{}
