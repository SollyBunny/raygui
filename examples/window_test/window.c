/*******************************************************************************************
*
*   window - tool description
*
*   LICENSE: zlib/libpng
*
*   Copyright (c) 2018 raylib technologies
*
**********************************************************************************************/

#include "raylib.h"

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

//----------------------------------------------------------------------------------
// Controls Functions Declaration
//----------------------------------------------------------------------------------

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main()
{
    // Initialization
    //---------------------------------------------------------------------------------------
    int screenWidth = 800;
    int screenHeight = 600;
    
    SetConfigFlags(FLAG_WINDOW_UNDECORATED);

    InitWindow(screenWidth, screenHeight, "window");

    // window: controls initialization
    //----------------------------------------------------------------------------------
    bool exitWindow = false;
    //----------------------------------------------------------------------------------
    
    // General variables
    Vector2 mousePos = { 0 };
    Vector2 position = { 500, 200 };
    Vector2 prevPosition = position;
    Vector2 panOffset = mousePos;
    bool dragWindow = false;

    SetTargetFPS(120);
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!exitWindow && !WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Implement required update logic
        //----------------------------------------------------------------------------------
        mousePos = GetMousePosition();
        
        if ((CheckCollisionPointRec(mousePos, (Rectangle){ 0, 0, screenWidth, 20 })) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            dragWindow = true;
            panOffset = mousePos;
        }
            
        if (dragWindow)
        {
            if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
            {
                position.x = prevPosition.x + (mousePos.x - panOffset.x),
                position.y = prevPosition.y + (mousePos.y - panOffset.y);
            }

            if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) 
            {
                prevPosition = position;
                dragWindow = false;
            }
        }
        
        SetWindowPosition(position.x, position.y);
        // printf("mouse: %f, %f\n", mousePos.x, mousePos.y);
        // printf("panOffset: %f, %f\n", panOffset.x, panOffset.y);
        // printf("prevPosition: %f, %f\n", prevPosition.x, prevPosition.y);
        // printf("position: %f, %f\n\n", position.x, position.y);

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(GetColor(style[DEFAULT_BORDER_COLOR_NORMAL]));

            // raygui: controls drawing
            //----------------------------------------------------------------------------------
            
            exitWindow = GuiWindowBox((Rectangle){ 1, 0, screenWidth - 2, screenHeight - 1 }, "EXAMPLE WINDOW");
            
            //----------------------------------------------------------------------------------

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

//------------------------------------------------------------------------------------
// Controls Functions Definitions (local)
//------------------------------------------------------------------------------------
