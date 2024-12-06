#pragma once
#include <raylib.h>

class Alien {
    public:
        Alien (int type, Vector2 position);
        void Draw();
        void Update(int dir);
        int GetType();
        Rectangle GetRect();
        static void UnloadImages();
        static Texture2D alienImages[3];
        int type;
        Vector2 position;
    private:
};