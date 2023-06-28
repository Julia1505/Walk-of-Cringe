#include <SFML/Graphics.hpp>
#include "map.h"

bool Map::tst(int m[WIDTH_MAP][HEIGHT_MAP], const int row, int j) {
    int newRow;
    newRow = row - 1;
    //?????????? ??????, ??? ???????? ?????????? ?????
    if(m[newRow][j + 1] == 1 && m[newRow][j - 1] == 1 || m[newRow][j - 1] == 0 && m[newRow][j + 1] == 1)
    {
        return true;
    }
    else 
    {
        return false;
    }
}

Map::Map(int X, int Y, int Red_e, int Green_e, int Blue_e, int Red_f, int Green_f, int Blue_f, unsigned int  size_pixel_block) : p_size_pixel_block(size_pixel_block) {
for (int i = 0; i < WIDTH_MAP; i++) {
    stmap[0][i] = 1;
    stmap[i][0] = 1;
    stmap[WIDTH_MAP - 1][i] = 1;
    stmap[i][WIDTH_MAP - 1] = 1;
}
    enum STEP{YES, NO};
    srand(time(0));
    int i, j;
    for (int i = 0; i < WIDTH_MAP; i++ ){
        stmap[0][i] = 1;
        stmap[WIDTH_MAP - 1][i] = 1;
        stmap[i][0] = 1;
        stmap[i][WIDTH_MAP - 1] = 1;
    }

    for(i = 1; i < WIDTH_MAP - 1; i++)
    {
        if(i == 1 || i == WIDTH_MAP - 2)
        {
            for(j = 1; j < WIDTH_MAP - 1; j++)
            {
                stmap[i][j] = 1;
            }
        }
        //===================================
        else if(i == 2)
        {
            for(j = 1; j < HEIGHT_MAP - 1; j++)
            {
                if(j == 1 || j == HEIGHT_MAP - 2)
                {
                    stmap[i][j] = 1;
                    continue;
                }
                else if(j > 1 && j < HEIGHT_MAP - 2)
                {
                    if((rand() & 1) == YES)
                    {
                        stmap[i][j] = 1;
                        continue;
                    }
                    else 
                    {
                        stmap[i][j] = 0;
                        continue;
                    }
                }
            }
        }
        //========================================
        else if(i > 2 && i < WIDTH_MAP - 2)
        {   
            for(j = 1; j < HEIGHT_MAP - 1; j++)
            {
                if(j == 1 || j == HEIGHT_MAP - 2)
                {
                    stmap[i][j] = 1;
                    continue;
                }   
                else if(j > 1 && j < HEIGHT_MAP - 2)
                {   
                    if((rand() & 1) == YES)
                    {
                        if(tst(stmap, i, j))
                        {
                            stmap[i][j++] = 0;
                            stmap[i][j] = 1;
                            continue;
                        }
                        else 
                        {
                            stmap[i][j] = 1;
                            continue;
                        }
                    }
                    else 
                    {
                        stmap[i][j] = 0;
                        continue;
                    }
                }
            }
        }
    }
    for (int i = 1; i < HEIGHT_MAP - 1; i++) {
        for (int j = 1; j <HEIGHT_MAP - 1; j++) {
            if (stmap[i][j] != 0) {
                stmap[i][j] = rand()%6;
            }
        }
    }

    st_map = sf::RectangleShape(sf::Vector2f(X, Y));
    wall_color = sf::Color((sf::Color(Red_f, Green_f, Blue_f))); // Цвет стен
    empty_color = sf::Color((sf::Color(Red_e, Green_e, Blue_e))); // Цвет пола
}

