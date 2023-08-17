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

    /* Inıtialize map pointers */

    map_size = map_w * map_h;
    map_widht = map_w;
    map_height = map_h;
    map = new GameObject**[map_height];
    for (int i = 0; i < map_height; ++i) {
        map[i] = new GameObject*[map_widht];
        for (int j = 0; j < map_widht; ++j) {
            map[i][j] = nullptr;
        }
    }

    ball_num = eat_num = score = 0;
    int ghost_i = 0;
    QPixmap wallpix(":/game_objects/map_objects/wall.png");
    QPixmap ballpix(":/game_objects/map_objects/dot.png");
    QPixmap powerballpix(":/game_objects/map_objects/power_ball.png");
    QPixmap gatepix(":/game_objects/map_objects/gate.png");
    QPixmap blankpix;
    QFile blankpix;
    QFile mapfile(map_src);
    mapfile.open(QIODevice::ReadOnly|QIODevice::Text);

    pacman = new Pacman();

    for (int i = 0; i < map_h; ++i) {
        QByteArray line = mapfile.readLine();
        for (int j = 0; j < map_w; ++j) {
            int tmp_x = x + (j *W);
            int tmp_y = y + (i *W);
            switch (line[j]) {
            case '1':
                map[i][j] = new GameObject(GameObject::Wall, wallpix);
                map[i][j]->setPos(tmp_x,tmp_y);
                addItem(map[i][j]);
                break;
            case '0':
                break;
            case '4':
                break;
            case '3':
                break;
            case '2':
                break;
            case 'p':
                break;
            case 'g':
                break;
            default:
                break;
            }
        }
    }
}
