#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QWidget>
#include <QTimer>
#include <QSound>
#include "map.h"
#include "heroplane.h"
#include "bullet.h"
#include "enemyplane.h"
#include "bomb.h"

class MainScene : public QWidget
{
    Q_OBJECT

public:
    MainScene(QWidget *parent = nullptr);
    ~MainScene();

    //初始化场景
    void initScene();

    //启动游戏  用于启动定时器对象
    void playGame();
    //更新坐标
    void updatePosition();
    //绘图事件
    void paintEvent(QPaintEvent *event);

    //重写鼠标移动事件(函数声明不可更改)
    void mouseMoveEvent(QMouseEvent *event);

    //敌机出场
    void enemyToScene();

    //碰撞检测
    void collisionDetection();

    //地图对象
    Map m_map;

    //创建英雄飞机对象
    HeroPlane m_hero;

    //定时器对象
    QTimer m_Timer;

    //敌机数组
    EnemyPlane m_enemys[ENEMY_NUM];

    //敌机出场间隔记录
    int m_recorder;

    //爆炸数组
    Bomb m_bombs[BOMB_NUM];

    //测试子弹
//    Bullet temp_Bullet;

};
#endif // MAINSCENE_H
