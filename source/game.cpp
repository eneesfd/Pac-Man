#include "game.h"
#include <QString>
#include <QFile>
#include <QRandomGenerator>

#define W (GameObject::Widgth)


int GHOST_RELEASE_TIME[] = {0, 200, 400, 600};


Game::Game(int x, int y, int map_w, int map_h, QString map_src)
    : QGraphicsScene (x, y, W* map_w, W* map_h)
{
    stat = Playing;

    map_siz
}
