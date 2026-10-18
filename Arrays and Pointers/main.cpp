#include <windows.h>
#include <cstdlib>
#include <ctime>

// ============================================================
// GAME SETTINGS
// ============================================================

const int WIDTH = 30;          // Number of cells horizontally
const int HEIGHT = 20;         // Number of cells vertically
const int CELL_SIZE = 20;      // Size of each cell in pixels
const int MAX_TAIL = 100;      // Maximum snake body length

// ============================================================
// GAME VARIABLES
// ============================================================

bool gameOver = false;         // Stores whether the game has ended

int x, y;                      // Snake head position

int fruitX, fruitY;            // Food position

int score;                     // Player score

int tailX[MAX_TAIL];           // X positions of snake body

int tailY[MAX_TAIL];           // Y positions of snake body

int tailLength;                // Current snake body length

// ============================================================
// DIRECTION
// ============================================================

enum Direction
{
    STOP = 0,
    LEFT,
    RIGHT,
    UP,
    DOWN
};

Direction direction;


// ============================================================
// FUNCTION: IsPositionOnSnake
// Checks whether a position is already occupied by the snake.
// ============================================================

bool IsPositionOnSnake(int checkX, int checkY)
{
    // Check the snake head
    if (x == checkX && y == checkY)
    {
        return true;
    }

    // Check every body segment
    for (int i = 0; i < tailLength; i++)
    {
        if (tailX[i] == checkX && tailY[i] == checkY)
        {
            return true;
        }
    }

    return false;
}


// ============================================================
// FUNCTION: GenerateFood
// Generates food at a position not occupied by the snake.
// ============================================================

void GenerateFood()
{
    do
    {
        fruitX = rand() % WIDTH;
        fruitY = rand() % HEIGHT;

    } while (IsPositionOnSnake(fruitX, fruitY));
}


// ============================================================
// FUNCTION: Setup
// Initializes the game.
// ============================================================

void Setup()
{
    gameOver = false;

    direction = RIGHT;

    // Put the snake head in the middle
    x = WIDTH / 2;
    y = HEIGHT / 2;

    score = 0;

    tailLength = 0;

    // Generate the first food
    GenerateFood();
}


// ============================================================
// FUNCTION: Logic
// Handles movement, collision and eating.
// ============================================================

void Logic(HWND hwnd)
{
    // Store the old head position
    int previousX = x;
    int previousY = y;


    // ========================================================
    // MOVE THE HEAD
    // ========================================================

    switch (direction)
    {
        case LEFT:
            x--;
            break;

        case RIGHT:
            x++;
            break;

        case UP:
            y--;
            break;

        case DOWN:
            y++;
            break;

        default:
            break;
    }


    // ========================================================
    // MOVE THE BODY
    // ========================================================

    for (int i = 0; i < tailLength; i++)
    {
        // Save the current body position
        int tempX = tailX[i];
        int tempY = tailY[i];

        // Current body segment follows previous segment
        tailX[i] = previousX;
        tailY[i] = previousY;

        // Save old position for next body segment
        previousX = tempX;
        previousY = tempY;
    }


    // ========================================================
    // WALL COLLISION
    // ========================================================

    if (x < 0 ||
        x >= WIDTH ||
        y < 0 ||
        y >= HEIGHT)
    {
        gameOver = true;
    }


    // ========================================================
    // SELF COLLISION
    // ========================================================

    for (int i = 0; i < tailLength; i++)
    {
        if (tailX[i] == x && tailY[i] == y)
        {
            gameOver = true;
        }
    }


    // ========================================================
    // FOOD COLLISION
    // ========================================================

    if (x == fruitX && y == fruitY)
    {
        score += 10;

        // Increase snake length
        if (tailLength < MAX_TAIL)
        {
            tailLength++;
        }

        // Generate new food
        GenerateFood();
    }


    // ========================================================
    // STOP TIMER WHEN GAME IS OVER
    // ========================================================

    if (gameOver)
    {
        KillTimer(hwnd, 1);
    }

    // Ask Windows to redraw the window
    InvalidateRect(hwnd, NULL, FALSE);
}


// ============================================================
// FUNCTION: DrawGame
// Draws the entire game using Windows GDI.
// ============================================================

void DrawGame(HDC hdc)
{
    // ========================================================
    // CREATE BACKGROUND BRUSH
    // ========================================================

    HBRUSH backgroundBrush = CreateSolidBrush(RGB(20, 20, 20));

    RECT background;

    background.left = 0;
    background.top = 0;
    background.right = WIDTH * CELL_SIZE;
    background.bottom = HEIGHT * CELL_SIZE;

    FillRect(hdc, &background, backgroundBrush);

    DeleteObject(backgroundBrush);


    // ========================================================
    // DRAW FOOD
    // ========================================================

    HBRUSH foodBrush = CreateSolidBrush(RGB(255, 50, 50));

    HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, foodBrush);

    Ellipse(
        hdc,
        fruitX * CELL_SIZE + 2,
        fruitY * CELL_SIZE + 2,
        (fruitX + 1) * CELL_SIZE - 2,
        (fruitY + 1) * CELL_SIZE - 2
    );

    SelectObject(hdc, oldBrush);

    DeleteObject(foodBrush);


    // ========================================================
    // DRAW SNAKE HEAD
    // ========================================================

    HBRUSH headBrush = CreateSolidBrush(RGB(50, 255, 80));

    oldBrush = (HBRUSH)SelectObject(hdc, headBrush);

    Rectangle(
        hdc,
        x * CELL_SIZE + 1,
        y * CELL_SIZE + 1,
        (x + 1) * CELL_SIZE - 1,
        (y + 1) * CELL_SIZE - 1
    );

    SelectObject(hdc, oldBrush);

    DeleteObject(headBrush);


    // ========================================================
    // DRAW SNAKE BODY
    // ========================================================

    HBRUSH bodyBrush = CreateSolidBrush(RGB(30, 180, 60));

    oldBrush = (HBRUSH)SelectObject(hdc, bodyBrush);

    for (int i = 0; i < tailLength; i++)
    {
        Rectangle(
            hdc,
            tailX[i] * CELL_SIZE + 2,
            tailY[i] * CELL_SIZE + 2,
            (tailX[i] + 1) * CELL_SIZE - 2,
            (tailY[i] + 1) * CELL_SIZE - 2
        );
    }

    SelectObject(hdc, oldBrush);

    DeleteObject(bodyBrush);


    // ========================================================
    // DRAW GAME BORDER
    // ========================================================

    HPEN borderPen = CreatePen(
        PS_SOLID,
        2,
        RGB(100, 100, 100)
    );

    HPEN oldPen = (HPEN)SelectObject(hdc, borderPen);

    Rectangle(
        hdc,
        0,
        0,
        WIDTH * CELL_SIZE,
        HEIGHT * CELL_SIZE
    );

    SelectObject(hdc, oldPen);

    DeleteObject(borderPen);
}


// ============================================================
// FUNCTION: DrawTextInformation
// Draws score and controls.
// ============================================================

void DrawTextInformation(HDC hdc)
{
    char scoreText[100];

    wsprintf(
        scoreText,
        "Score: %d    Controls: Arrow Keys / WASD    Restart: R",
        score
    );

    SetTextColor(hdc, RGB(255, 255, 255));

    SetBkMode(hdc, TRANSPARENT);

    TextOut(
        hdc,
        10,
        HEIGHT * CELL_SIZE + 10,
        scoreText,
        lstrlen(scoreText)
    );


    // ========================================================
    // GAME OVER MESSAGE
    // ========================================================

    if (gameOver)
    {
        const char* message =
            "GAME OVER! Press R to restart";

        SetTextColor(
            hdc,
            RGB(255, 80, 80)
        );

        TextOut(
            hdc,
            170,
            HEIGHT * CELL_SIZE + 40,
            message,
            lstrlen(message)
        );
    }
}


// ============================================================
// WINDOW PROCEDURE
// ============================================================

LRESULT CALLBACK WndProc(
    HWND hwnd,
    UINT Message,
    WPARAM wParam,
    LPARAM lParam
)
{
    switch (Message)
    {
        // ====================================================
        // WINDOW CREATED
        // ====================================================

        case WM_CREATE:
        {
            Setup();

            // Call Logic every 100 milliseconds
            SetTimer(hwnd, 1, 100, NULL);

            break;
        }


        // ====================================================
        // TIMER
        // ====================================================

        case WM_TIMER:
        {
            if (!gameOver)
            {
                Logic(hwnd);
            }

            break;
        }


        // ====================================================
        // KEYBOARD INPUT
        // ====================================================

        case WM_KEYDOWN:
        {
            switch (wParam)
            {
                // --------------------------------------------
                // LEFT
                // --------------------------------------------

                case VK_LEFT:
                case 'A':

                    // Don't allow immediate reverse
                    if (direction != RIGHT)
                    {
                        direction = LEFT;
                    }

                    break;


                // --------------------------------------------
                // RIGHT
                // --------------------------------------------

                case VK_RIGHT:
                case 'D':

                    if (direction != LEFT)
                    {
                        direction = RIGHT;
                    }

                    break;


                // --------------------------------------------
                // UP
                // --------------------------------------------

                case VK_UP:
                case 'W':

                    if (direction != DOWN)
                    {
                        direction = UP;
                    }

                    break;


                // --------------------------------------------
                // DOWN
                // --------------------------------------------

                case VK_DOWN:
                case 'S':

                    if (direction != UP)
                    {
                        direction = DOWN;
                    }

                    break;


                // --------------------------------------------
                // RESTART
                // --------------------------------------------

                case 'R':

                    if (gameOver)
                    {
                        Setup();

                        SetTimer(hwnd, 1, 100, NULL);

                        InvalidateRect(
                            hwnd,
                            NULL,
                            FALSE
                        );
                    }

                    break;
            }

            break;
        }


        // ====================================================
        // DRAW WINDOW
        // ====================================================

        case WM_PAINT:
        {
            PAINTSTRUCT ps;

            HDC hdc = BeginPaint(hwnd, &ps);

            DrawGame(hdc);

            DrawTextInformation(hdc);

            EndPaint(hwnd, &ps);

            break;
        }


        // ====================================================
        // WINDOW DESTROYED
        // ====================================================

        case WM_DESTROY:
        {
            KillTimer(hwnd, 1);

            PostQuitMessage(0);

            break;
        }


        // ====================================================
        // DEFAULT WINDOWS MESSAGE
        // ====================================================

        default:
        {
            return DefWindowProc(
                hwnd,
                Message,
                wParam,
                lParam
            );
        }
    }

    return 0;
}


// ============================================================
// WINDOWS GUI MAIN FUNCTION
// ============================================================

int WINAPI WinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR lpCmdLine,
    int nCmdShow
)
{
    // Initialize random number generator
    srand((unsigned int)time(0));


    // ========================================================
    // CREATE WINDOW CLASS
    // ========================================================

    WNDCLASSEX wc;

    memset(&wc, 0, sizeof(wc));

    wc.cbSize = sizeof(WNDCLASSEX);

    wc.lpfnWndProc = WndProc;

    wc.hInstance = hInstance;

    wc.hCursor = LoadCursor(
        NULL,
        IDC_ARROW
    );

    wc.hbrBackground =
        (HBRUSH)(COLOR_WINDOW + 1);

    wc.lpszClassName = "SnakeGame";

    wc.hIcon = LoadIcon(
        NULL,
        IDI_APPLICATION
    );

    wc.hIconSm = LoadIcon(
        NULL,
        IDI_APPLICATION
    );


    // ========================================================
    // REGISTER WINDOW
    // ========================================================

    if (!RegisterClassEx(&wc))
    {
        MessageBox(
            NULL,
            "Window Registration Failed!",
            "Error",
            MB_ICONERROR | MB_OK
        );

        return 0;
    }


    // ========================================================
    // CREATE WINDOW
    // ========================================================

    int windowWidth =
        WIDTH * CELL_SIZE + 20;

    int windowHeight =
        HEIGHT * CELL_SIZE + 100;


    HWND hwnd = CreateWindowEx(
        0,
        "SnakeGame",
        "C++ Snake Game",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        windowWidth,
        windowHeight,
        NULL,
        NULL,
        hInstance,
        NULL
    );


    // Check if window was created
    if (hwnd == NULL)
    {
        MessageBox(
            NULL,
            "Window Creation Failed!",
            "Error",
            MB_ICONERROR | MB_OK
        );

        return 0;
    }


    // ========================================================
    // SHOW WINDOW
    // ========================================================

    ShowWindow(
        hwnd,
        nCmdShow
    );

    UpdateWindow(hwnd);


    // ========================================================
    // WINDOWS MESSAGE LOOP
    // ========================================================

    MSG msg;

    while (GetMessage(
        &msg,
        NULL,
        0,
        0
    ) > 0)
    {
        TranslateMessage(&msg);

        DispatchMessage(&msg);
    }


    return (int)msg.wParam;
}
