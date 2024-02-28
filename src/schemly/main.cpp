#include <iostream>

#include "config/version.h"

#include "raylib.h"

int main() {

    std::cout << "Git sha: " << GS_GIT_SHA << "\n";
    std::cout << "Git branch: " << GS_GIT_BRANCH << "\n";
    std::cout << "Version: " << GS_PROJECT_VERSION << "\n";

    InitWindow(800, 450, "Schemly");

    while(!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}