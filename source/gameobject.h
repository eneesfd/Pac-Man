#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QTimer>
#include <QVector>

class Game;

class GameObject : public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    enum ObjetType {Ball, Wall, Gate, Pacman, Ghost, Blank, PowerBall};
    enum Dir { Up= 0, Down = 1, Left = 2, Right = 3, Stop = 4 };
    static const int Widgth = 20;

    GameObject (ObjetType, QPixmap);
    ~GameObject();
    ObjetType get_type();
    int get_x();
    int get_y();
    int get_score();
    void set_score(int);
    void set_dir(Dir);
    void set_next_dir(Dir);
    Dir get_dir();
    Dir get_next_dir();

    friend class Game;
    friend class Ghost;

protected:
    int _x, _y;
    Dir dir;
    Dir next_dir;
    ObjetType type;
    int score;

signals:

};

/* Pac-Man */
class Pacman : public GameObject
{
    Pacman();
    void move();
    Game *game;

    friend claas Game;

private:
    void moveUp();
    void modeDown();
    void moveLeft();
    void moveRight();
    void eat_ball(int,int);
    void overLapable(int,int);

    QVector<QPixmap> anim[4];
    int anim_index;
};

/* Ghost */

class Ghost : public GameObject
{
public:
    enum Color {Red = 0, Yellow = 1, Pink = 2, Green = 3};
    enum Status {Normal, Panic, Running};
    const static int GhostNum = 4;
    Game *game;

    friend class Game;
    friend class Pacman;

private:
    void moveup();
    void movedown();
    void moveleft();
    void moveright();

    void setDir_Ramdomly();
    void go_Out_Cage();
    void chase_Pacman();
    void dodge_Pacman();
    void go_To_Cage();
    QPair<int,int> (*chase_strategy)(Ghost*);
    bool overLapable(int,int);

    Color color;
    Status status;

    QVector<QPixmap> anim[4];
    QVector<QPixmap> panic_anim;
    QVector<QPixmap> running_anim;

    int anim_index;
    int release_time;
    bool is_released;
    int panic_time;
};

QPair<int, int> strategy1(Ghost*);
QPair<int, int> strategy2(Ghost*);
QPair<int, int> strategy3(Ghost*);
QPair<int, int> strategy4(Ghost*);

#endif // GAMEOBJECT_H
