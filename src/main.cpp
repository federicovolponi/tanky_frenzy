#include "player.h"
#include "globals.h"
#include "arena.h"

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    Vector2 playerPos = { SCREENWIDTH/2, SCREENHEIGHT/2 };
    Player player(playerPos);
    Arena* arenaPtr = Arena::Instance();
    InitWindow(SCREENWIDTH, SCREENHEIGHT, "Tanky Frenzy");

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
