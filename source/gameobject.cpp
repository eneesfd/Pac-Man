#include "gameobject.h"

GameObject::GameObject(ObjetType t, QPixmap pixmap)
    : QGraphicsPixmapItem(pixmap)
    , type(t)
{
}

