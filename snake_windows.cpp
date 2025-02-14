#include <iostream>
#include <windows.h>  // For Sleep and system("cls")
#include <conio.h>    // For _kbhit and _getch
#include <cstdlib>    // For rand and srand
#include <ctime>      // For time
#include <vector>     // For vector
#include <fstream>

using namespace std;

const int width = 20;
const int height = 20;
int highScore;

void loadHighScore() {
    ifstream file("highscores.txt");
    if (file.is_open()) {
        file >> highScore;
        file.close();    // file closes
    } else {
        highScore = 0;
    }
}

void saveHighScore() {
    ofstream file("highscores.txt");
    if (file.is_open()) {
        file << highScore;
        file.close();
    }
}

void instructions()
{
    cout << "Steps and instructions to play the game" << endl;
    cout << "Cursor keys -" << endl;
    cout << "1. W - UP" << endl;
    cout << "2. A - LEFT" << endl;
    cout << "3. D - RIGHT" << endl;
    cout << "4. S - DOWN" << endl;
    cout << "5. X - Quit the game" << endl;
    cout << "Select difficulty level:" << endl;
    cout << "1. Easy" << endl;
    cout << "2. Medium" << endl;
    cout << "3. Hard" << endl;
}

enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };

class Snake {
public:
    int x, y;
    vector<int> tailX, tailY;
    int nTail;
    eDirection dir;

    Snake() {                                    //constructor called
        x = width / 2;
        y = height / 2;
        nTail = 2;
        dir = RIGHT;

        tailX.resize(2);                       // if not resized then game does not run
        tailY.resize(2);

        for(int i = 0; i < nTail; i++)
        {
            tailX[i] = x - (i + 1);
            tailY[i] = y;
        }
    }

    void move() {
        int prevX = tailX[0];
        int prevY = tailY[0];
        int prev2X, prev2Y;

        tailX[0] = x;
        tailY[0] = y;

        for (int i = 1; i < nTail; i++) {
            prev2X = tailX[i];
            prev2Y = tailY[i];
            tailX[i] = prevX;
            tailY[i] = prevY;
            prevX = prev2X;
            prevY = prev2Y;
        }
        switch (dir) {
        case LEFT: x--; break;
        case RIGHT: x++; break;
        case UP: y--; break;
        case DOWN: y++; break;
        default: break;
        }
    }

    bool checkCollision() const {
        if (x >= width || x < 0 || y >= height || y < 0)                      // if snake goes out of box then game overs
            return true;
        for (int i = 0; i < nTail; i++) {
            if (tailX[i] == x && tailY[i] == y)
                return true;
        }
        return false;
    }

    void grow() {
        tailX.push_back(x);
        tailY.push_back(y);
        nTail++;
    }
};

class Fruit {
public:
    int x, y;
    Fruit() {
        x = rand() % width;
        y = rand() % height;
    }
    void reset() {
        x = rand() % width;
        y = rand() % height;
    }
};

class GameState {
public:
    bool gameOver;
    int score;
    GameState() {
        gameOver = false;
        score = 0;
    }
};

class Game {
private:
    Snake snake;
    Fruit fruit;
    int difficulty;

public:
    GameState state;
    Game() {
        srand(time(0));
        difficulty = 1; // Default to easy
    }

    void setDifficulty(int level) {
        difficulty = level;
    }

    void draw() const {
        system("cls");
        for (int i = 0; i < width + 2; i++) {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11); // Light Blue for grid
            cout << "#";
        }
        cout << endl;
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (j == 0) {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11); // Light Blue for grid
                    cout << "#";
                }
                if (i == snake.y && j == snake.x) {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); // Light Green for snake
                    cout << "O";
                } else if (i == fruit.y && j == fruit.x) {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); // Light Red for fruit
                    cout << "F";
                } else {
                    bool print = false;
                    for (int k = 0; k < snake.nTail; k++) {
                        if (snake.tailX[k] == j && snake.tailY[k] == i) {
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); // Light Green for snake
                            cout << "o";
                            print = true;
                        }
                    }
                    if (!print) {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // Default color for empty space
                        cout << " ";
                    }
                }
                if (j == width - 1) {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11); // Light Blue for grid
                    cout << "#";
                }
            }
            cout << endl;
        }
        for (int i = 0; i < width + 2; i++) {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11); // Light Blue for grid
            cout << "#";
        }
        cout << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // Default color for text
        cout << "Score: " << state.score << " | High Score: " << highScore << endl;
    }

    void input() {
        if (_kbhit()) {
            char ch = _getch();
            switch (ch) {
            case 'a': if (snake.dir != RIGHT) snake.dir = LEFT; break;
            case 'd': if (snake.dir != LEFT) snake.dir = RIGHT; break;
            case 'w': if (snake.dir != DOWN) snake.dir = UP; break;
            case 's': if (snake.dir != UP) snake.dir = DOWN; break;
            case 'x': state.gameOver = true; break;
            }
        }
    }

    void logic() {
        snake.move();
        if (snake.checkCollision()) state.gameOver = true;
        if (snake.x == fruit.x && snake.y == fruit.y) {
            state.score += 10;
            if (state.score > highScore) highScore = state.score;
            fruit.reset();    //new fruit appears
            snake.grow();     //length of snake increases
        }
    }

    void playAgain() {
        char key;
        cout << "Do you want to play again? (y/n): ";
        cin >> key;
        if (key == 'y' || key == 'Y') {
            Game newGame;
            newGame.setDifficulty(difficulty);
            newGame.start();
        } else {
            saveHighScore();
            exit(0);
        }
    }

    void start() {
        while (true) {
            draw();           // for construction of box or grid
            input();          // takes input from user
            logic();          // fruit mechanism and check collision of snake
            Sleep(300 / difficulty);       // to run program automatically after sometime
            if (state.gameOver) {
                cout << "Game Over! Final Score: " << state.score << endl;
                if (state.score > highScore) {
                    highScore = state.score;
                    cout << "New High Score!" << endl;
                }
                playAgain();
            }
        }
    }
};

int main() {
    instructions();
    loadHighScore();

    int difficulty;
    cout << "Enter difficulty level (1-Easy, 2-Medium, 3-Hard): ";
    cin >> difficulty;

    Game game;
    game.setDifficulty(difficulty);
    game.start();

    return 0;
}
