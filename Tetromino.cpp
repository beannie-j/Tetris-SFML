#include "Tetromino.h"
#include <iostream>
#include <cstdlib>
#include <typeinfo>

Tetromino::Tetromino(TetrominoType type)
    : m_type(type)
{
    switch (m_type) {
    case TetrominoType::I:
        m_arr = { {
            {1,1,1,1}, {0,0,0,0}, {0,0,0,0}, {0,0,0,0} } };
        m_rotation_state = RotationState::cw0;
        m_color = sf::Color(59, 237, 237);
        break;
    case TetrominoType::O:
        m_arr = { { {1,1,0,0}, {1,1,0,0}, {0,0,0,0}, {0,0,0,0} } };
        m_rotation_state = RotationState::cw0;
        m_color = sf::Color(237, 234, 59);
        break;
    case TetrominoType::T:
        m_arr = { {{0,1,0,0}, {1,1,1,0}, {0,0,0,0}, {0,0,0,0}} };
        m_rotation_state = RotationState::cw0;
        m_color = sf::Color(138, 43, 226);
        break;
    case TetrominoType::S:
        m_arr = { {{0,1,1,0}, {1,1,0,0}, {0,0,0,0}, {0,0,0,0}} };
        m_rotation_state = RotationState::cw0;
        m_color = sf::Color(53, 232, 68);
        break;
    case TetrominoType::Z:
        m_arr = { {{1,1,0,0}, {0,1,1,0}, {0,0,0,0}, {0,0,0,0}} };
        m_rotation_state = RotationState::cw0;
        m_color = sf::Color(232, 70, 49);
        break;
    case TetrominoType::J:
        m_arr = { {{1,0,0,0}, {1,1,1,0}, {0,0,0,0}, {0,0,0,0}} };
        m_rotation_state = RotationState::cw0;
        m_color = sf::Color(54, 86, 227);
        break;
    case TetrominoType::L:
        m_arr = { {{0,0,1,0}, {1,1,1,0}, {0,0,0,0}, {0,0,0,0}} };
        m_rotation_state = RotationState::cw0;
        m_color = sf::Color(255, 165, 0);
        break;
    default:
        std::cout << "[ERROR] Tetrimino needs a shape\n";
        break;
    }
}

void Tetromino::Rotate_HardCoded(RotationState rotation_state)
{
    int intState = (int)rotation_state; // cw90
    intState = (intState + 1) % 4; // cw180
    m_rotation_state = (RotationState)intState;

    switch (m_type) {
    case TetrominoType::I:
        if (rotation_state == RotationState::cw0) {
            m_arr = { {
            {0,0,1,0},
            {0,0,1,0},
            {0,0,1,0},
            {0,0,1,0} } };

            m_rotation_state = RotationState::cw90;
        }
        if (rotation_state == RotationState::cw90) {
            m_arr = { {
            {0,0,0,0},
            {0,0,0,0},
            {1,1,1,1},
            {0,0,0,0} } };

            m_rotation_state = RotationState::cw180;
        }
        if (rotation_state == RotationState::cw180) {
            m_arr = { {
            {0,1,0,0},
            {0,1,0,0},
            {0,1,0,0},
            {0,1,0,0} } };

            m_rotation_state = RotationState::cw270;
        }
        if (rotation_state == RotationState::cw270) {
            m_arr = { {
            {0,0,0,0},
            {1,1,1,1},
            {0,0,0,0},
            {0,0,0,0} } };
            m_rotation_state = RotationState::cw0;
        }
        break;
    case TetrominoType::O:
        m_arr = { { 
            {1,1,0,0},
            {1,1,0,0},
            {0,0,0,0},
            {0,0,0,0} } };
        break;
    case TetrominoType::T:
        if (rotation_state == RotationState::cw0) {
            m_arr = { {
            {0,1,0,0},
            {0,1,1,0},
            {0,1,0,0},
            {0,0,0,0} } };
            m_rotation_state = RotationState::cw90;
        }
        if (rotation_state == RotationState::cw90) {
            m_arr = { {
            {0,0,0,0},
            {1,1,1,0},
            {0,1,0,0},
            {0,0,0,0} } };
            m_rotation_state = RotationState::cw270;
        }
        if (rotation_state == RotationState::cw270) {
            m_arr = { {
            {0,0,0,0},
            {0,1,0,0},
            {1,1,0,0},
            {0,1,0,0} } };
            m_rotation_state = RotationState::cw0;
        }
        break;

    case TetrominoType::S:
        if (rotation_state == RotationState::cw0) {
            m_arr = { {
            {0,0,0,0},
            {1,0,0,0},
            {1,1,0,0},
            {0,1,0,0} } };
            m_rotation_state = RotationState::cw90;
        }

        if (rotation_state == RotationState::cw90) {
            m_arr = { {
            {0,0,0,0},
            {0,0,0,0},
            {0,1,1,0},
            {1,1,0,0} } };
            m_rotation_state = RotationState::cw180;
        }

        if (rotation_state == RotationState::cw180) {
            m_arr = { {
            {0,0,0,0},
            {1,0,0,0},
            {1,1,0,0},
            {0,1,0,0} } };
            m_rotation_state = RotationState::cw270;
        }

        if (rotation_state == RotationState::cw270) {
            m_arr = { {
            {0,0,0,0},
            {0,0,0,0},
            {0,1,1,0},
            {1,1,0,0} } };
            m_rotation_state = RotationState::cw0;
        }
        break;
    case TetrominoType::Z:
        if (rotation_state == RotationState::cw0) {
            m_arr = { {
            {0,0,0,0},
            {0,1,0,0},
            {1,1,0,0},
            {1,0,0,0} } };
            m_rotation_state = RotationState::cw90;
        }
        if (rotation_state == RotationState::cw90) {
            m_arr = { {
            {0,0,0,0},
            {1,1,0,0},
            {0,1,1,0},
            {0,0,0,0} } };
            m_rotation_state = RotationState::cw180;
        }
        if (rotation_state == RotationState::cw180) {
            m_arr = { {
            {0,0,0,0},
            {0,1,0,0},
            {1,1,0,0},
            {1,0,0,0} } };
            m_rotation_state = RotationState::cw270;
        }
        if (rotation_state == RotationState::cw270) {
            m_arr = { {
            {0,0,0,0},
            {0,0,0,0},
            {1,1,0,0},
            {0,1,1,0} } };
            m_rotation_state = RotationState::cw0;
        }

        break;
    case TetrominoType::J:
        if (rotation_state == RotationState::cw0) {
            m_arr = { {
            {0,0,0,0},
            {1,1,0,0},
            {1,0,0,0},
            {1,0,0,0} } };
            m_rotation_state = RotationState::cw90;
        }
        if (rotation_state == RotationState::cw90) {
            m_arr = { {
            {0,0,0,0},
            {1,1,1,0},
            {0,0,1,0},
            {0,0,0,0} } };
            m_rotation_state = RotationState::cw180;
        }
        if (rotation_state == RotationState::cw180) {
            m_arr = { {
            {0,0,0,0},
            {0,0,1,0},
            {0,0,1,0},
            {0,1,1,0} } };
            m_rotation_state = RotationState::cw270;
        }
        if (rotation_state == RotationState::cw270) {
            m_arr = { {
            {0,0,0,0},
            {0,0,0,0},
            {1,0,0,0},
            {1,1,1,0} } };
            m_rotation_state = RotationState::cw0;
        }

        break;
    case TetrominoType::L:
        if (rotation_state == RotationState::cw0) {
            m_arr = { {
            {0,1,0,0},
            {0,1,0,0},
            {0,1,1,0},
            {0,0,0,0}} };
            m_rotation_state = RotationState::cw90;
        }
        if (rotation_state == RotationState::cw90) {
            m_arr = { {
            {0,0,0,0},
            {0,1,1,1},
            {0,1,0,0},
            {0,0,0,0}} };
            m_rotation_state = RotationState::cw180;
        }
        if (rotation_state == RotationState::cw180) {
            m_arr = { {
            {0,0,0,0},
            {0,1,1,0},
            {0,0,1,0},
            {0,0,1,0}} };
            m_rotation_state = RotationState::cw270;
        }
        if (rotation_state == RotationState::cw270) {
            m_arr = { {
            {0,0,0,0},
            {0,0,0,0},
            {0,0,1,0},
            {1,1,1,0}} };
            m_rotation_state = RotationState::cw0;
        }
        break;
    }
}

bool Tetromino::MoveDown(float dy)
{
    if (YBoundsCollision()) return false;
    if (CollisionWithBlocks(0, 1))
    {
        std::cout << " can you stop moving down??" << std::endl;
        posY -= dy;
        return false;
    }

    posY += dy;
    return true;

    /*
    if (!YBoundsCollision() && !CollisionWithBlocks())
    {
        std::cout << "moving down" << std::endl;
        posY += dy;
        return true;
    }
    std::cout << "move down stop" << std::endl;*/
    //return false;
}

bool Tetromino::YBoundsCollision()
{
    for (int y = 0; y < m_size; y++)
    {
        for (int x = 0; x < m_size; x++)
        {
            if (m_arr[y][x] == 0) continue;
            // checks for y bounds
            if ((y + posY) * block_size > ((GameBoard::Height - 2) * block_size))
            {
                std::cout << "Y bounds collision" << std::endl;
                return true;
            }
        }
    }
    return false;
}


bool Tetromino::XBoundsCollision()
{
    for (int y = 0; y < m_size; y++)
    {
        for (int x = 0; x < m_size; x++)
        {
            if (m_arr[y][x] == 0) continue;

            // checks for x bounds
            if ((posX + x) * block_size < 0 || (posX + x) * block_size >= ((GameBoard::Width) * block_size) - cell_size) return true;
        }
    }
    return false;
}

bool Tetromino::CollisionWithBlocks(float dx, float dy)
{
    /*for (int yc = 0; yc < m_size; yc++)
    {
        for (int xc = 0; xx < m_size; x++)
        {
            if (m_arr[yc][xc] == 0) continue;

            /*int potentialPosition = (x + posX) + (y + posY) * GameBoard::Width;
            if (GameBoard::PlayingArea[potentialPosition])
            {
                std::cout << "collision with other block" << std::endl;
                return true;
            }
        }
    }
    return false;*/

    {
        float x = posX + dx;
        float y = posY + dy;

        for (int yc = 0; yc < 4; yc++)
        {
            for (int xc = 0; xc < 4; xc++)
            {
                if (m_arr[yc][xc] != 0)
                {
                    float actualXPosition = xc + x;
                    float actualYPosition = yc + y;
                    if (GameBoard::PlayingArea[actualXPosition + actualYPosition * GameBoard::Width])
                    {
                        std::cout << "collision with other" << std::endl;
                        // how to slow down the collision

                        return true;
                    }
                }
            }
        }

        return false;
    }
}

void Tetromino::Draw(sf::RenderWindow& window)
{
    // dont delete, debugging purposes.
    //sf::Text text;
    //text.setFont(*s_Arcade_Font);
    //text.setFillColor(sf::Color(255, 255, 255));
    //text.setCharacterSize(14);

    sf::RectangleShape rect(sf::Vector2f(block_size, block_size));
    rect.setFillColor(m_color);
    for (int y = 0; y < m_size; y++)
    {
        for (int x = 0; x < m_size; x++)
        {
            if (m_arr[y][x])
            {
                float cx = (posX + x + s_shift) * block_size;
                float cy = (posY + y + s_shift) * block_size;

                rect.setPosition(sf::Vector2f(cx, cy));
                rect.setOutlineColor(sf::Color::White);
                rect.setOutlineThickness(1);
                window.draw(rect);

                // this is for debugging purposes - dont delete
                /*text.setPosition(sf::Vector2f(cx, cy));
                std::string string = std::to_string((int)(posX + x)) + ", " + std::to_string((int)(posY + y));
                text.setString(string);
                window.draw(text);*/
            }
        }
    }
}
