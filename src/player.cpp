#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "map.h"
#include "utils.h"
#include "player.h"
#include <iostream>

Player::Player(sf::String str, Map map, int X, int Y, double W , double H, unsigned int  size_pixel_block) : w(W), h(H), x(X), y(Y), file(str), maps(map), p_size_pixel_block(size_pixel_block) {
    //image.loadFromFile(file);
    //texture.loadFromImage(image);
    //sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(w, h, w, h));
    sprite.setOrigin(w / 2, h / 2);
    corner = from_deg_to_rad(270);
}

void Player::action(sf::Time fps, Map map) {
    double moveSpeed = fps.asSeconds() * 90.0; //the constant value is in squares/second
    double rotSpeed = fps.asSeconds() * 3.0; //the cconstant value is in radians/second
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                        //both camera direction and camera plane must be rotated
                        double oldDirX = dirX;
                        dirX = dirX * cos(rotSpeed) - dirY * sin(rotSpeed);
                        dirY = oldDirX * sin(rotSpeed) + dirY * cos(rotSpeed);
                        double oldPlaneX = planeX;
                        planeX = planeX * cos(rotSpeed) - planeY * sin(rotSpeed);
                        planeY = oldPlaneX * sin(rotSpeed) + planeY * cos(rotSpeed);
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                        //both camera direction and camera plane must be rotated
                        double oldDirX = dirX;
                        dirX = dirX * cos(-rotSpeed) - dirY * sin(-rotSpeed);
                        dirY = oldDirX * sin(-rotSpeed) + dirY * cos(-rotSpeed);
                        double oldPlaneX = planeX;
                        planeX = planeX * cos(-rotSpeed) - planeY * sin(-rotSpeed);
                        planeY = oldPlaneX * sin(-rotSpeed) + planeY * cos(-rotSpeed);
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
                        if(map.stmap[int(posX/32 + dirX * moveSpeed)][int(posY/32)] == 0) {posX += dirX * moveSpeed; std::cout << posX << std::endl;}
                        if(map.stmap[int(posX/32)][int(posY/32 + dirY * moveSpeed)] == 0) {posY += dirY * moveSpeed; std::cout << posY << std::endl;}
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                        if(map.stmap[int(posX/32 - dirX * moveSpeed)][int(posY/32)] == 0) {posX -= dirX * moveSpeed; std::cout << posX << std::endl;}
                        if(map.stmap[int(posX/32)][int(posY/32 - dirY * moveSpeed)] == 0) {posY -= dirY * moveSpeed; std::cout << posY << std::endl;}
                }


}
    
//void Player::interact_with_map() {

    //for (int i = y / p_size_pixel_block; i < (y + h) / p_size_pixel_block; ++i) {
       //for (int j = x / p_size_pixel_block; j < (x + w) / p_size_pixel_block; ++j) {

            // std::cout << i << " " << j << " " << x << " " << char(stmap[i][j]) << std::endl;
            //if (maps.stmap[i - 1][j] == '0') {
                //if (y < i * p_size_pixel_block + h / 2) y = i * p_size_pixel_block + h / 2;
            //}
            //if (maps.stmap[i][j] == '0') {
                //if (y > i * p_size_pixel_block - h / 2) y = i * p_size_pixel_block - h / 2;
            //}

        //}
    //}
//}

