#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle(tr("pac-man"));

    ui->graphicsView->setStyleSheet("QGraphicsView {border: none;}");
    ui->graphicsView->setBackgroundBrush(Qt::black);
    ui->graphicsView->setFocusPolicy(Qt::NoFocus);

    int map_height = 20, map_width = 29;
    int x = 50, y = 50;
    int w = (map_width * GameObject::Widgth);
    int h = (map_height * GameObject::Widgth);

    ui->graphicsView->setGeometry(x, y, w, h);
    game = new Game (x,y,map_width, map_height, ":/game_objects/map_objects/map.txt");
}

MainWindow::~MainWindow()
{
    delete ui;
}

