#include <SFML/Graphics.hpp>
#include "map.h"
#include "player.h"
#include "camera.h"
#include <iostream>
#include <cassert>

Camera::Camera(sf::RenderWindow &window, Player c_person, Map c_maps, unsigned int width_screen, unsigned int height_screen, unsigned int  size_pixel_block)
: person(c_person), maps(c_maps), dirY(c_person.dirY), dirX(c_person.dirX) {
    // const float fov = acos(-1)/3; // Поверхность взгляда
    // camera.reset(sf::FloatRect(0, 0, 1280, 1024)); //Устанавливаем размер камеры
    // camera.setCenter(person.x, person.y);
    // window.setView(camera);
    for (int t = 0; t < width_screen; ++t) {
        double cameraX = 2 * t / double(width_screen) - 1; //x-координата в пространстве камеры
        ////* double cx = person.x + t * cos(person.corner);
        ///double cy = person.y + t * sin(person.corner);*/
        double rayPosX = c_person.posX;
        double rayPosY = c_person.posY;
        double rayDirX = dirX + c_person.planeX * cameraX;
        double rayDirY = dirY + c_person.planeY * cameraX;
        // в каком направлении двигаться в направлении x или y (+1 или -1)
        int stepX;
        int stepY;

        //в каком поле карты мы находимся
        int mapX = int(rayPosX) / 32;
        int mapY = int(rayPosY) / 32;

        // длина луча от текущего положения до следующей стороны x или y
        double sideDistX;
        double sideDistY;

        //длина луча от одной стороны x или y до следующей x или y-стороны
        double deltaDistX = sqrt(1 + (rayDirY * rayDirY) / (rayDirX * rayDirX));
        double deltaDistY = sqrt(1 + (rayDirX * rayDirX) / (rayDirY * rayDirY));
        double perpWallDist;

        int hit = 0; //was there a wall hit?
        int side; //was a NS or a EW wall hit?

        // рассчитать шаг и начальную сторонуDist
        if (rayDirX < 0) {
            stepX = -1;
            sideDistX = (rayPosX / 32 - mapX) * deltaDistX;
        } else {
            stepX = 1;
            sideDistX = (mapX + 1.0 - rayPosX / 32) * deltaDistX;
        }
        if (rayDirY < 0) {
            stepY = -1;
            sideDistY = (rayPosY / 32 - mapY) * deltaDistY;
        } else {
            stepY = 1;
            sideDistY = (mapY + 1.0 - rayPosY / 32) * deltaDistY;
        }

        // выполнение DDA
        while (hit == 0) {
            //перейти к следующему квадрату карты, ИЛИ в направлении X, ИЛИ в направлении Y
            if (sideDistX < sideDistY) {
                sideDistX += deltaDistX;
                mapX += stepX;
                side = 0;
            } else {
                sideDistY += deltaDistY;
                mapY += stepY;
                side = 1;
            }
            // Проверьте, не ударился ли луч о стену
            if (maps.stmap[mapX][mapY] > 0) {
                hit = 1;
            }
        }
        if (side == 0)
            perpWallDist = fabs((mapX - rayPosX / 32 + (1 - stepX) / 2) / rayDirX);
        else
            perpWallDist = fabs((mapY - rayPosY / 32 + (1 - stepY) / 2) / rayDirY);
        //Вычисление высоты линии для рисования на экране
        int lineHeight = abs(int(height_screen / perpWallDist));

        //рассчитать самый низкий и самый высокий пиксель для заполнения текущей полосы
        int drawStart = -lineHeight / 2 + height_screen / 2;
        if(drawStart < 0) drawStart = 0;
        int drawEnd = lineHeight / 2 + height_screen / 2;
        if(drawEnd >= height_screen) drawEnd = height_screen - 1;
        //выберите цвет стены
        sf::Color color;
        switch(maps.stmap[mapX][mapY]) {
            case 1:  color = sf::Color::Red;  break; //red
            case 2:  color = sf::Color::Green;  break; //green
            case 3:  color = sf::Color::Blue;   break; //blue
            case 4:  color = sf::Color::White;  break; //white
            default: color = sf::Color::Yellow; break; //yellow
        }

        //придают сторонам x и y разную яркость
        if (side == 1) {
            color = sf::Color(color.r/2, color.g/2, color.b/2);
        }

        //нарисовать пиксели полосы в виде вертикальной линии
        // sf::VerLine(cx, drawStart, drawEnd, color);
        // Линия с нулевой толщиной. Создаём её в качестве массива вершин типа Vertex
        sf::Vertex line[2] = {
            sf::Vertex(sf::Vector2f(t, drawStart), color),
            sf::Vertex(sf::Vector2f(t, drawEnd), color)
        };
        // Отрисовка линии
        window.draw(line, 2, sf::Lines);
    }
}


