#include "raylib.h"
#include <math.h>
#include <string.h>
#include <stdio.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

typedef struct
{
    char display[50];
    double firstNumber;
    char operation;
    bool newInput;
    bool scientificMode;
} Calculator;

// Global variables
Calculator calc;              // Our main calculator ka object
Rectangle buttons[25];        // Stores positions of all buttons on screen
char buttonLabels[25][10] = { // Text on each button
    // Basic mode buttons
    "7", "8", "9", "/", "Mode",
    "4", "5", "6", "*", "sin",
    "1", "2", "3", "-", "cos",
    "0", ".", "=", "+", "tan",
    "C", "sqrt", "x^2", "ln", "pi"};
int totalButtons = 25;

//-----------------------------------------Initialize calculator
void InitCalculator()
{
    strcpy(calc.display, "0");
    calc.firstNumber = 0;
    calc.operation = ' ';
    calc.newInput = true;
    calc.scientificMode = false;

    // Create button positions
    float btnWidth = 100, btnHeight = 70; // Each button is 100x70 pixels
    float startX = 100, startY = 150;
    float spacing = 10;

    for (int i = 0; i < totalButtons; i++)
    {
        int row = i / 5;
        int col = i % 5;
        buttons[i].x = startX + col * (btnWidth + spacing);
        buttons[i].y = startY + row * (btnHeight + spacing);
        buttons[i].width = btnWidth;
        buttons[i].height = btnHeight;
    }
}

//---------------------------------------------------Handle button clicks
void HandleButtonClick(int buttonIndex)
{
    const char *label = buttonLabels[buttonIndex];

    // Mode switch button
    if (strcmp(label, "Mode") == 0)
    {
        calc.scientificMode = !calc.scientificMode;
        return;
    }

    //----------------------------------------------Number buttons (0-9)
    if (label[0] >= '0' && label[0] <= '9')
    {
        if (calc.newInput || strcmp(calc.display, "0") == 0)
        {
            strcpy(calc.display, label);
            calc.newInput = false;
        }
        else
        {
            strcat(calc.display, label);      //string ko modify ka lia
        }
    }
    //-------------------------------------------Clear button
    else if (strcmp(label, "C") == 0)
    {
        strcpy(calc.display, "0");
        calc.newInput = true;
    }
    //------------------------------------Operation buttons (+, -, *, /)
    else if (strchr("+-*/", label[0]) != NULL)
    {
        calc.firstNumber = atof(calc.display);   //atof int ko float ma convert kara ga 
        calc.operation = label[0];
        calc.newInput = true;
    }
    //-------------------------------------------Equals button
    else if (strcmp(label, "=") == 0)
    {
        double secondNumber = atof(calc.display);
        double result = 0;

        switch (calc.operation)
        {
        case '+':
            result = calc.firstNumber + secondNumber;
            break;
        case '-':
            result = calc.firstNumber - secondNumber;
            break;
        case '*':
            result = calc.firstNumber * secondNumber;
            break;
        case '/':
            if (secondNumber != 0)
                result = calc.firstNumber / secondNumber;
            else
                strcpy(calc.display, "Error");
            break;
        }

        if (strcmp(calc.display, "Error") != 0)
        {
            sprintf(calc.display, "%.6g", result);
        }
        calc.newInput = true;
    }
    //------------------------------------------Square root
    else if (strcmp(label, "sqrt") == 0)
    {
        double num = atof(calc.display);
        if (num >= 0)
        {
            sprintf(calc.display, "%.6g", sqrt(num));
        }
        else
        {
            strcpy(calc.display, "Error");
        }
        calc.newInput = true;
    }
    //-------------------------------------Square
    else if (strcmp(label, "x^2") == 0)
    {
        double num = atof(calc.display);
        sprintf(calc.display, "%.6g", num * num);
        calc.newInput = true;
    }
    //------------------------------Sine function
    else if (strcmp(label, "sin") == 0)
    {
        double num = atof(calc.display);
        sprintf(calc.display, "%.6g", sin(num));
        calc.newInput = true;
    }
    //------------------------------Cosine function
    else if (strcmp(label, "cos") == 0)
    {
        double num = atof(calc.display);
        sprintf(calc.display, "%.6g", cos(num));
        calc.newInput = true;
    }
    //-----------------------------Tangent function
    else if (strcmp(label, "tan") == 0)
    {
        double num = atof(calc.display);
        sprintf(calc.display, "%.6g", tan(num));
        calc.newInput = true;
    }
    //-----------------------------Natural logarithm
    else if (strcmp(label, "ln") == 0)
    {
        double num = atof(calc.display);
        if (num > 0)
        {
            sprintf(calc.display, "%.6g", log(num));
        }
        else
        {
            strcpy(calc.display, "Error");
        }
        calc.newInput = true;
    }
    //----------------------------Pi constant
    else if (strcmp(label, "pi") == 0)
    {
        sprintf(calc.display, "%.6g", 3.141592653589793);
        calc.newInput = true;
    }
}

//---------------------Draw everything
void DrawCalculator()
{
    // Draw display
    DrawRectangle(100, 50, 510, 80, DARKGRAY);
    DrawText(calc.display, 110, 70, 40, WHITE);

    //-------------------Draw mode indicator
    const char *modeText = calc.scientificMode ? "SCIENTIFIC MODE" : "BASIC MODE";
    DrawText(modeText, 100, 120, 20, YELLOW);

    //-------------------------Draw buttons
    for (int i = 0; i < totalButtons; i++)
    {
        Color btnColor = LIGHTGRAY;
        const char *label = buttonLabels[i];

        //-------------------------Color coding
        if (strchr("+-*/", label[0]) != NULL)
            btnColor = ORANGE;
        if (strcmp(label, "=") == 0)
            btnColor = GREEN;
        if (strcmp(label, "Mode") == 0)
            btnColor = BLUE;
        if (strcmp(label, "C") == 0)
            btnColor = RED;

        //----------------------------Scientific functions
        if (strcmp(label, "sin") == 0 || strcmp(label, "cos") == 0 ||
            strcmp(label, "tan") == 0 || strcmp(label, "ln") == 0 ||
            strcmp(label, "pi") == 0)
        {
            btnColor = PURPLE;
        }

        DrawRectangleRec(buttons[i], btnColor);

        //----------------Center text
        int textWidth = MeasureText(label, 20);
        DrawText(label,
                 buttons[i].x + (buttons[i].width - textWidth) / 2,
                 buttons[i].y + 25,
                 20, BLACK);
    }
}

int main()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Calculator with Trig Functions");
    SetTargetFPS(60);

    InitCalculator();

    while (!WindowShouldClose())
    {
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            Vector2 mousePos = GetMousePosition();
            for (int i = 0; i < totalButtons; i++)
            {
                if (CheckCollisionPointRec(mousePos, buttons[i]))
                {
                    HandleButtonClick(i);
                    break;
                }
            }
        }

        BeginDrawing();
        ClearBackground(BLACK);
        DrawCalculator();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}