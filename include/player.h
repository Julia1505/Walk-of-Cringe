#ifndef WAR_OF_CRINGE_PLAYER_H
#define WAR_OF_CRINGE_PLAYER_H

#include <SFML/Graphics.hpp>
#include "map.h"
#include "utils.h"
#include <iostream>

class Player {

    public:

    Map maps;
    sf::String file; // Спрайт
    double x; // Положение по горизонтали 
    double y; // Положение по вертикали
    double w; // Ширина игрока
    double h; // Высота игрока
    double dx; // Скорость по горизонтали
    double dy; // Скорость по вертикали
    double d_corner; // Изменение угла
    double speed = 0; // Скорость игрока
    double speed_rotation; // Скорость вращения
    double corner; // Угол куда повернут персонаж
    unsigned int  p_size_pixel_block; // Размер блока в пикселях
    double dirX = -1, dirY = 0; //начальный вектор направления
    double planeX = 0, planeY = 0.66; //2d raycaster версия плоскости камеры
    double posX = 100, posY = 100;
    friend class Camera;

    public:

    sf::Image image;
    sf::Texture texture;
    sf::Sprite sprite;

    Player(sf::String str, Map map, int X, int Y, double W , double H, unsigned int  size_pixel_block);

    void action(sf::Time time, Map map);
    void update(sf::Time time);
    //void interact_with_map();
};

#endif //WAR_OF_CRINGE_PLAYER_H
