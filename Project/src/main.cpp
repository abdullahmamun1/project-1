#include "raylib.h"
#include "game.hpp"
#include <string>

std::string FormatWithLeadingZeros(int number, int width){
    std::string numberText = std::to_string(number);
    int leadingZeros = width - numberText.length();
    return numberText = std::string(leadingZeros, '0') + numberText;
}
 
int main()
{
    Color grey = {29, 29, 27, 255};
    Color green = {67, 226, 63, 255};
    int offset = 50;
    int windowWidth = 750;
    int windowHeight = 700;

    InitWindow(windowWidth + offset, windowHeight + 2* offset, "C++ Space Invaders Clone Game");

    Font font = LoadFontEx("Font/monogram.ttf", 64, 0, 0);
    Texture2D SpaceshipImage = LoadTexture("Graphics/spaceship.png");

    SetTargetFPS(60);

    Game game;

    while(WindowShouldClose() == false) {
        
        game.HandleInput();
        game.Update();
        BeginDrawing();
        ClearBackground(grey);
        DrawRectangleRoundedLines({10,10,780,780}, 0.18f, 20, 2, green);
        DrawLineEx({25, 730},  {775, 730}, 3, green);
         if(game.run){
            DrawTextEx(font, "LEVEL 01", {570, 740}, 34, 2, green);
        } else {
            DrawTextEx(font, "GAME OVER", {570, 740}, 34, 2, green);
        }

        float x = 70.0;
        for(int i = 0; i<game.lives;i++){
                DrawTextureV(SpaceshipImage, {x, 735}, WHITE);
                x += 70;
        }

        DrawTextEx(font, "SCORE", {50,15}, 34, 2, green);
        std::string scoreText = FormatWithLeadingZeros(game.score,5);
        DrawTextEx(font, scoreText.c_str(), {50,40}, 34, 2, green);

        DrawTextEx(font, "HIGH-SCORE", {570,15}, 34, 2, green);
        std::string highScoreText = FormatWithLeadingZeros(game.highScore,5);
        DrawTextEx(font, highScoreText.c_str(), {655,40}, 34, 2, green);
        

        game.Draw();
        EndDrawing();

    }

    CloseWindow();
}