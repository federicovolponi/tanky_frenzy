#include "player.h"
#include "globals.h"

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1800;
    const int screenHeight = 950;
    Vector2 playerPos = { (float)screenWidth/2, (float)screenHeight/2 };
    Player player(playerPos);
    InitWindow(screenWidth, screenHeight, "Tanky Frenzy");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second

    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        for (auto it = gameObjects.begin(); it != gameObjects.end();) {
            (*it)->update();
            // Remove deleted gameObjects
            if ((*it)->getToDelete()) {
                (*it)->destroy();
                it = gameObjects.erase(it);
            }
            else {
                ++it;
            }
        }
        // Draw
        BeginDrawing();

            ClearBackground(RAYWHITE);
            for (GameObject* gameObject : gameObjects) {
                gameObject->render();
            }

        EndDrawing();
    }

    // De-Initialization
    CloseWindow();        // Close window and OpenGL context

    return 0;
}
