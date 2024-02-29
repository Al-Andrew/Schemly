#include <iostream>

#include "config/version.h"

#include "raylib.h"


namespace Schemely::imGUI {

    struct Theme {
        Color primary_color;
        Color accent_color;
        Color accent_hover_color;
        Color text_primary_color;

        float window_header_height;
        float font_size;
    };

    Theme g_Theme{
        .primary_color = Color{0x17, 0x17, 0x17, 0xff},
        .accent_color = Color{0x21, 0x4a, 0xb0, 0xff},
        .accent_hover_color = Color{0x1f, 0x21, 0xa1, 0xff},
        .text_primary_color = Color{0xf0, 0xf0, 0xf0, 0xff},
        .window_header_height = 25.0f,
        .font_size = 15.0f,
    };

    static bool IsHovered(Rectangle bounds) {
        bool result = CheckCollisionPointRec(GetMousePosition(), bounds);

        //TODO(AAL): set the mouse cursor
        
        return result;
    }
    
    bool BeginWindow(char const* const title, int const flags, Rectangle* const bounds, bool* const is_open) {
        if(!bounds) { return false; }
        if(!is_open) { return false; }

        Rectangle header_bounds = Rectangle{bounds->x, bounds->y, bounds->width, g_Theme.window_header_height};
        Color header_color = IsHovered(header_bounds)? g_Theme.accent_hover_color : g_Theme.accent_color; 
        
        // base panel
        DrawRectangleRec(*bounds, g_Theme.primary_color);
        // outline
        DrawRectangleLinesEx(*bounds, 1, header_color);
        // header
        DrawRectangleRec(header_bounds, header_color);
        // title
        // TODO(AAL): check if title fits in window
        if(title) {
            DrawText(title, header_bounds.x + 5, header_bounds.y + 5, (int)g_Theme.font_size, g_Theme.text_primary_color);
        }

        return true;
    }


    void EndWindow() {
        
    }
};

int main() {

    std::cout << "Git sha: " << GS_GIT_SHA << "\n";
    std::cout << "Git branch: " << GS_GIT_BRANCH << "\n";
    std::cout << "Version: " << GS_PROJECT_VERSION << "\n";

    namespace sg = Schemely::imGUI;
    using sg::g_Theme;

    InitWindow(1280, 720, "Schemly");

    while(!WindowShouldClose()) {
        BeginDrawing();
            ClearBackground(Color{0x28,0x28,0x28,255});

            Rectangle bounds = {50, 50, 400, 500};
            bool is_open = true;

            if(sg::BeginWindow("Test", 0, &bounds, &is_open)) {

                sg::EndWindow();
            }


            Rectangle bounds2 = {700, 50, 400, 500};
            bool is_open2 = true;

            if(sg::BeginWindow("Test2", 0, &bounds2, &is_open2)) {

                sg::EndWindow();
            }
        
        EndDrawing();
    }

    CloseWindow();

    return 0;
}