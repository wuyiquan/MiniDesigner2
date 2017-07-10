#ifndef ITEM_H
#define ITEM_H
#include <QString>
enum ItemType {
    PICTURE,
    MOSAIC,
    BOARD
};

struct Item
{
    Item();
    Item(int id, int x, int y, int h, int w);
    int id;
    int x;
    int y;
    int h;
    int w;
    ItemType type;
};

struct TextItem : Item {
    TextItem();
    TextItem(int id, int x, int y, int h, int w, QString text);
    QString text;
};

#endif // ITEM_H
