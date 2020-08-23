#include <SFML/Graphics.hpp>
#include <array>
#include <iostream>
#include <cstdlib>
#include <typeinfo>

#include "Tetromino.h"
#include "Button.h"
#include "Menu.h"

int GetColorInt(Tetromino tetromino)
{
    if (tetromino.m_type == TetrominoType::I) return 2;
    if (tetromino.m_type == TetrominoType::O) return 3;
    if (tetromino.m_type == TetrominoType::T) return 4;
    if (tetromino.m_type == TetrominoType::S) return 5;
    if (tetromino.m_type == TetrominoType::Z) return 6;
    if (tetromino.m_type == TetrominoType::J) return 7;
    if (tetromino.m_type == TetrominoType::L) return 8;

}

TetrominoType GetTypeFromNumeration(int number)
{
    switch (number) {
    case 0: return TetrominoType::I;
    case 1: return TetrominoType::O;
    case 2: return TetrominoType::T;
    case 3: return TetrominoType::S;
    case 4: return TetrominoType::Z;
    case 5: return TetrominoType::J;
    case 6: return TetrominoType::L;
    }
}

static bool CheckGameOver(Tetromino curr)
{
    for (int y = 0; y < curr.m_size; y++)
    {
        for (int x = 0; x < curr.m_size; x++)
        {
            if (curr.m_arr[y][x] == 0) continue;
            int pos = (x + curr.posX) + (y + curr.posY) * GameBoard::Width;
            if (GameBoard::PlayingArea[pos] && curr.m_landed)
            {
                s_GameOver = true;
            }
        }
    }
    return true;
}

static Tetromino CreateTetromino()
{
    std::cout << "Creating new" << std::endl;
    int random = rand() % 7;
    TetrominoType type = GetTypeFromNumeration(random);
    Tetromino tetromino(type);
    return tetromino;
}

static void CommitBlock(const Tetromino& tetromino)
{
    int txc = tetromino.posX;
    int tyc = tetromino.posY + 1;


    for (int y = 0; y < tetromino.m_size; y++)
    {
        for (int x = 0; x < tetromino.m_size; x++)
        {
            if (tetromino.m_arr[y][x])
            {

                int xc = txc + x;
                int yc = tyc + y;
                int pos = xc + yc  * GameBoard::Width;

                if (yc + 1 > GameBoard::Height)
                {
                    std::cout << "[WARNING] : gameborad height out of bounds" << std::endl;
                    continue;
                }
          
                GameBoard::PlayingArea[pos] = GetColorInt(tetromino);
                
            }
        }
    }

}

static void ClearRow(sf::RenderWindow& window)
{
    for (int y = 0; y < GameBoard::Height; y++)
    {
        int count = 0;
        for (int x = 0; x < GameBoard::Width; x++)
        {
            int block = GameBoard::PlayingArea[x + y * GameBoard::Width];
            if (block) count += 1;
            if (count == GameBoard::Width)
            {
                std::cout << " y "<< y << std::endl;
                for (int x = 0; x < GameBoard::Width; x++) {
                    int i = y;
                    int j = 0;
                    while (j < i)
                    {
                        GameBoard::PlayingArea[x + (y - j) * GameBoard::Width] = GameBoard::PlayingArea[x + (y -j -1) * GameBoard::Width];
                        j++;

                    }
                }    
            }
        }
    }
}

static void DrawGameBoard(sf::RenderWindow& window)
{
    sf::RectangleShape rect(sf::Vector2f(Tetromino::block_size, Tetromino::block_size));

    sf::Text text;
    text.setFont(s_Font);
    text.setFillColor(sf::Color(255, 255, 255));
    text.setCharacterSize(14);

    for (int y = 0; y < GameBoard::Height; y++)
    {
        for (int x = 0; x < GameBoard::Width; x++)
        {
            float cx = x * Tetromino::block_size;
            float cy = y * Tetromino::block_size;
            int block = GameBoard::PlayingArea[x + y * GameBoard::Width];
            if (block >= 2)
            {
                //colours if the s_PlayingArea == 2
                rect.setPosition(sf::Vector2f(cx, cy));
                rect.setOutlineThickness(3);
                rect.setFillColor(s_Colors[block]);
                rect.setOutlineColor(sf::Color(250, 150, 100));
                window.draw(rect);
            }
            else
            {
                rect.setPosition(sf::Vector2f(cx, cy));
                rect.setOutlineThickness(3);
                rect.setFillColor(sf::Color::Black);
                rect.setOutlineColor(sf::Color::White);

                window.draw(rect);

                text.setPosition(sf::Vector2f(cx, cy));
                std::string string = std::to_string(x) + ", " + std::to_string(y);
                text.setString(string);
                window.draw(text);
            }
        }
    }
}

static void DrawPoints(sf::RenderWindow& window, int points)
{
    sf::Text text;
    text.setFont(s_Font);
    text.setFillColor(sf::Color::White);
    text.setCharacterSize(30);
    text.setPosition(900, 50);
    std::string string = "POINTS : " + std::to_string(points);
    text.setString(string);
    window.draw(text);
}


int main()
{
    srand((unsigned int)time(NULL));

    s_Font.loadFromFile("C:\\Windows\\Fonts\\Arial.ttf");

    int Window_Width = 30 * Tetromino::block_size;
    int Window_Height = 30 * Tetromino::block_size;

    sf::RenderWindow menu_window(sf::VideoMode(Window_Width/2, Window_Height/2), "Menu");

    Button play_tetris_button((Window_Width/4), (Window_Height/4), 200.f, 50.f, s_Font, "Play Tetris", 30, sf::Color::Blue, sf::Color::Green);


    // Menu menu(menu_window.getSize().x, menu_window.getSize().y, s_Font);
    //menu.DrawMenu(menu_window);
    

    while (menu_window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (menu_window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                menu_window.close();
        }

        // clear the window with black color
        menu_window.clear(sf::Color::Black);

        // draw everything here...
        play_tetris_button.DrawButton(menu_window);


        // end the current frame

        menu_window.display();
    }

    


    /*

    sf::RenderWindow window(sf::VideoMode(Window_Width, Window_Height), "Tetris");

    memset(GameBoard::PlayingArea.data(), 0, sizeof(GameBoard::PlayingArea));

    Tetromino current_tetromino = CreateTetromino();

    sf::Clock clock;

    float last_time = clock.getElapsedTime().asSeconds();

    int points = 0;

    sf::Vector2i mouse_position;

    Button play_again_button(450.f, 400.f, 200.f, 50.f, s_Font, "Play again", 30, sf::Color::Blue, sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Left)
                {
                    current_tetromino.posX -= cell_size;

                    if (!current_tetromino.CheckBounds()) current_tetromino.posX += cell_size;
                }

                if (event.key.code == sf::Keyboard::Right)
                {
                    current_tetromino.posX += cell_size;

                    if (!current_tetromino.CheckBounds()) current_tetromino.posX -= cell_size;
                }

                if (event.key.code == sf::Keyboard::Down)
                {
                    current_tetromino.MoveDown(cell_size);
                }

                if (event.key.code == sf::Keyboard::Up)
                {
                    current_tetromino.Rotate_HardCoded(current_tetromino.m_rotation_state);
                }

                if (event.key.code == sf::Keyboard::Space)
                {
                    
                }
            }
        }

        window.clear(sf::Color::Black);

        DrawGameBoard(window);
        current_tetromino.Draw(window);
        ClearRow(window);
        DrawPoints(window, points); 
        CheckGameOver(current_tetromino);

        mouse_position = sf::Mouse::getPosition(window);
        play_again_button.DrawButton(window);
        play_again_button.GetPressed(mouse_position);

        float now = clock.getElapsedTime().asSeconds();
        if (now - last_time >= 0.7f)
        {
            current_tetromino.MoveDown(cell_size);
            last_time = now;
        } 

        if (current_tetromino.m_landed && !s_GameOver)
        {
            ++points;
            CommitBlock(current_tetromino);
            if (current_tetromino.posY <= 0 && current_tetromino.m_landed) s_GameOver = true;
            if (!s_GameOver) current_tetromino = CreateTetromino();
        }

        if (s_GameOver)
        {
            sf::Text text;
            text.setFont(s_Font);
            text.setFillColor(sf::Color::Red);
            text.setCharacterSize(70);
            text.setPosition(450, 50);
            std::string string = "Game Over";
            text.setString(string);
            window.draw(text);
            current_tetromino.m_color = sf::Color::Transparent;
        }
        window.display();

    }
    */
    
    return 0;
}