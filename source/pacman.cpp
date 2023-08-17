#include "Game.h"

#define W (GameObject::Widgth)

Pacman::Pacman() : GameObject (
        GameObject::Pacman, QPixmap(":/game_objects/pacman/a3.png"))
{
    dir = Stop;
    next_dir = Stop;
    anim_index = 2;
    anim[Right].push_back(QPixmap(":/game_objects/pacman/a1.png"));
    anim[Right].push_back(QPixmap(":/game_objects/pacman/a2.png"));
    anim[Right].push_back(QPixmap(":/game_objects/pacman/a3.png"));
    anim[Right].push_back(QPixmap(":/game_objects/pacman/a4.png"));
    anim[Right].push_back(QPixmap(":/game_objects/pacman/a5.png"));
    anim[Right].push_back(QPixmap(":/game_objects/pacman/a6.png"));
    anim[Right].push_back(QPixmap(":/game_objects/pacman/a5.png"));
    anim[Right].push_back(QPixmap(":/game_objects/pacman/a4.png"));
    anim[Right].push_back(QPixmap(":/game_objects/pacman/a3.png"));
    anim[Right].push_back(QPixmap(":/game_objects/pacman/a2.png"));

    anim[Up].push_back(QPixmap(":/game_objects/pacman/a1.png"));
    anim[Up].push_back(QPixmap(":/game_objects/pacman/b2.png"));
    anim[Up].push_back(QPixmap(":/game_objects/pacman/b3.png"));
    anim[Up].push_back(QPixmap(":/game_objects/pacman/b4.png"));
    anim[Up].push_back(QPixmap(":/game_objects/pacman/b5.png"));
    anim[Up].push_back(QPixmap(":/game_objects/pacman/b6.png"));
    anim[Up].push_back(QPixmap(":/game_objects/pacman/b5.png"));
    anim[Up].push_back(QPixmap(":/game_objects/pacman/b4.png"));
    anim[Up].push_back(QPixmap(":/game_objects/pacman/b3.png"));
    anim[Up].push_back(QPixmap(":/game_objects/pacman/b2.png"));

    anim[Left].push_back(QPixmap(":/game_objects/pacman/a1.png"));
    anim[Left].push_back(QPixmap(":/game_objects/pacman/c2.png"));
    anim[Left].push_back(QPixmap(":/game_objects/pacman/c3.png"));
    anim[Left].push_back(QPixmap(":/game_objects/pacman/c4.png"));
    anim[Left].push_back(QPixmap(":/game_objects/pacman/c5.png"));
    anim[Left].push_back(QPixmap(":/game_objects/pacman/c6.png"));
    anim[Left].push_back(QPixmap(":/game_objects/pacman/c5.png"));
    anim[Left].push_back(QPixmap(":/game_objects/pacman/c4.png"));
    anim[Left].push_back(QPixmap(":/game_objects/pacman/c3.png"));
    anim[Left].push_back(QPixmap(":/game_objects/pacman/c2.png"));

    anim[Down].push_back(QPixmap(":/game_objects/pacman/a1.png"));
    anim[Down].push_back(QPixmap(":/game_objects/pacman/d2.png"));
    anim[Down].push_back(QPixmap(":/game_objects/pacman/d3.png"));
    anim[Down].push_back(QPixmap(":/game_objects/pacman/d4.png"));
    anim[Down].push_back(QPixmap(":/game_objects/pacman/d5.png"));
    anim[Down].push_back(QPixmap(":/game_objects/pacman/d6.png"));
    anim[Down].push_back(QPixmap(":/game_objects/pacman/d5.png"));
    anim[Down].push_back(QPixmap(":/game_objects/pacman/d4.png"));
    anim[Down].push_back(QPixmap(":/game_objects/pacman/d3.png"));
    anim[Down].push_back(QPixmap(":/game_objects/pacman/d2.png"));
}
