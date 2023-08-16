#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QTimer>
#include <QPair>
#include "gameobject.h"

#define BALL_SCORE      10          // score of balls
#define POWERBALL_SCORE 30          // score of powerballs
#define GHOST_SCORE     50          // score of ghosts
#define INTERVAL        10          // move interval of pacman
#define NORMAL_INTERVAL 10          // move interval of normal ghosts
#define PANNIC_INTERVAL 15          // move interval of pannic ghosts
#define RUNNING_INTERVAL 5          // move interval of running ghosts
#define PANNIC_TIME     1000        // interval number of pannic ghosts
#define FLASH_INTERVAL 200          // flash interval of powerballs


class Game : public QGraphicsScene
{
    Q_OBJECT
public:
    enum GameStatus {
        Playing, Win, Lose, Pause};
    Game(int, int, int, int, QString);
    ~Game();
    void start();
    void stop();
    void pacman_next_direction(GameObject::Dir);
    int get_score();

    GameObject ***map;
    GameObject *gate;
    Pacman *pacman;
    Ghost *ghost[Ghost::GhostNum];
    QVector<GameObject*> powweBall;

    friend class Pacman;
    friend class Ghost;

private slots:
    void pacman_Handler();
    void powerball_Flash();
    void ghost_Handler();

private:
    int map_height, map_widht;
    int map_size;
    int ball_num, eat_num, score;
    int geo_x, geo_y;

    QTimer *ghost_timer[Ghost::GhostNum];
    QTimer *pacman_timer;
    QTimer *powerball_flash_timer;
    bool flash_tick;
};

#endif // GAME_H
