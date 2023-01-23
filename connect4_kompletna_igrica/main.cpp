#include <iostream>
#include<Window.hpp>
#include<Graphics.hpp>
#include "Header.h"




int main() {

    // Declare and create a new render-window
    sf::RenderWindow window(sf::VideoMode(800, 700), "SFML window");
    // Limit the framerate to 60 frames per second (this step is optional)
    window.setFramerateLimit(60);

    sf::Texture board_texture;
    board_texture.loadFromFile("C:/mislav/connect4.png");
    sf::Texture red_texture;
    red_texture.loadFromFile("C:/mislav/red.png");
    sf::Texture yellow_texture;
    yellow_texture.loadFromFile("C:/mislav/yellow.png");
    sf::Texture win_texture;
    win_texture.loadFromFile("C:/mislav/win.png");
    sf::Texture play_again_texture;
    play_again_texture.loadFromFile("C:/mislav/playagain.png");


    sf::Sprite board_sprite;
    board_sprite.setTexture(board_texture);
    sf::Sprite red_sprite;
    red_sprite.setTexture(red_texture);
    sf::Sprite yellow_sprite;
    yellow_sprite.setTexture(yellow_texture);
   sf::Sprite win_sprite;
    win_sprite.setTexture(win_texture);
    win_sprite.setPosition(160, 150);
    win_sprite.setScale(0.5, 0.5);
    sf::Sprite play_again_sprite;
    play_again_sprite.setTexture(play_again_texture);
    play_again_sprite.setScale(0.2, 0.2);
    play_again_sprite.setPosition(290, 440);

    struct coordinate {
        int x;
        int y;
    };
    coordinate coordinate_model[6][7] = {
        {{66, 29},{158, 29},{249, 29},{340, 29},{433, 29}, {524, 29}, {616, 29}},
        {{66, 122},{158, 122},{249, 122},{340, 122},{433, 122}, {524, 122},{616, 122}},
        {{66, 215},{158, 215},{249, 215},{340, 215},{433, 215}, {524, 215},{616, 215}},
        {{66, 305},{158, 305},{249, 305},{340, 305},{433, 305}, {524, 305},{616, 305}},
        {{66, 397},{158, 397},{249, 397},{340, 397},{433, 397}, {524, 397},{616, 397}},
        {{66, 489},{158, 489},{249, 489},{340, 489},{433, 489}, {524, 489},{616, 489}}

    };

    int number_of_chips_in_the_column1 = 0;
    int number_of_chips_in_the_column2 = 0;
    int number_of_chips_in_the_column3 = 0;
    int number_of_chips_in_the_column4 = 0;
    int number_of_chips_in_the_column5 = 0;
    int number_of_chips_in_the_column6 = 0;
    int number_of_chips_in_the_column7 = 0;
    const auto offset_x = 70;
    const auto offset_y = 36;
    char current = 'R';
    char column[7] = { '1', '2', '3', '4', '5', '6', '7' };
    char board[6][7] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ',
                         ' ', ' ', ' ', ' ', ' ', ' ', ' ',
                         ' ', ' ', ' ', ' ', ' ', ' ', ' ',
                         ' ', ' ', ' ', ' ', ' ', ' ', ' ',
                         ' ', ' ', ' ', ' ', ' ', ' ', ' ',
                         ' ', ' ', ' ', ' ', ' ' ,' ', ' ' };

    // The main loop - ends as soon as the window is closed
    while (window.isOpen())
    {
        // Event processing
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Request for closing the window
            if (event.type == sf::Event::Closed)
                window.close();


            if (event.type == sf::Event::MouseButtonPressed) {

                if (event.mouseButton.button == sf::Mouse::Left) {
                    if (check_diagonal(board) == true || check_row(board) == true || check_reverse_diagonal(board) == true || check_column(board) == true) {
                        if ((event.mouseButton.x > 289 && event.mouseButton.x < 380) && (event.mouseButton.y > 441 && event.mouseButton.y < 532)) {
                            for (int i = 0; i < 6; i++) {
                                for (int j = 0; j < 7; j++) {
                                    board[i][j] = ' ';
                                }

                            }
                             number_of_chips_in_the_column1 = 0;
                             number_of_chips_in_the_column2 = 0;
                             number_of_chips_in_the_column3 = 0;
                             number_of_chips_in_the_column4 = 0;
                             number_of_chips_in_the_column5 = 0;
                             number_of_chips_in_the_column6 = 0;
                             number_of_chips_in_the_column7 = 0;
                        }
                    }
                    else {
                        int coordinate_x = (event.mouseButton.x - offset_x) / 90;
                        int coordinate_y = (event.mouseButton.y - offset_y) / 90;
                        int coordinate_on_board = coordinate_y + coordinate_x;
                        mouse_click(board, column, coordinate_on_board, current, number_of_chips_in_the_column1,
                            number_of_chips_in_the_column2,
                            number_of_chips_in_the_column3,
                            number_of_chips_in_the_column4,
                            number_of_chips_in_the_column5,
                            number_of_chips_in_the_column6,
                            number_of_chips_in_the_column7);

                    }
                }
            }
        }
    
        // Clear the whole window before rendering a new frame
        window.setActive();
        window.clear(sf::Color::White);
        // Draw some graphical entities
        window.draw(board_sprite);


        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 7; j++) {

                auto current_coordinate = coordinate_model[i][j];


                switch (board[i][j])
                {
                case'R':
                    red_sprite.setPosition(current_coordinate.x, current_coordinate.y);
                    window.draw(red_sprite);
                    break;

                case'Y':
                    yellow_sprite.setPosition(current_coordinate.x, current_coordinate.y);
                    window.draw(yellow_sprite);
                    break;
                default:
                    break;
                }
            }

        }

        if (check_diagonal(board) == true || check_row(board) == true || check_reverse_diagonal(board) == true || check_column(board) == true) {
            window.draw(win_sprite);
            window.draw(play_again_sprite);
        }


        // End the current frame and display its contents on screen
        window.display();
    }
}