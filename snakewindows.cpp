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

enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };


class Data {

    private:
    string name;
    long long ID;

    void set_name(string name);                      // using getter and setter fuctions for private entities so it can be accessed outside class also
    {
        this->name=name;
    }

    void set_ID(long long ID)
    {
        this->ID=ID;
    }

    string get_name()
    {
        return name;
    }

    long long get_ID()
    {
        return ID;
    }
};

class Snake {
public:
    int x, y;
    vector<int> tailX, tailY;
    int nTail;
    eDirection dir;

    Snake() {
        x = width / 2;
        y = height / 2;
        nTail = 0;
        dir = STOP;
    }

    void move() {
        int prevX = tailX.empty() ? x : tailX[0];
        int prevY = tailY.empty() ? y : tailY[0];
        int prev2X, prev2Y;
        if (!tailX.empty()) {
            tailX[0] = x;
            tailY[0] = y;
        }
        for (int i = 1; i < nTail; i++) {
            prev2X = tailX[i];
            prev2Y = tailY[i];
            tailX[i] = prevX;
            tailY[i] = prevY;
            prevX = prev2X;
            prevY = prev2Y;
        }
        switch (dir) {
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
    }

    bool checkCollision() const {
        if (x >= width || x < 0 || y >= height || y < 0)
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

    void reset() {                  // gives new fruit
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
    GameState state;

public:
    Game() {
        srand(time(0));
    }

    void draw() const {
        system("cls"); // Use "cls" on Windows to clear the console
        for (int i = 0; i < width + 2; i++)
            cout << "#";
        cout << endl;

        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (j == 0)
                    cout << "#";
                if (i == snake.y && j == snake.x)
                    cout << "O";
                else if (i == fruit.y && j == fruit.x)
                    cout << "F";
                else {
                    bool print = false;
                    for (int k = 0; k < snake.nTail; k++) {
                        if (snake.tailX[k] == j && snake.tailY[k] == i) {
                            cout << "o";
                            print = true;
                        }
                    }
                    if (!print)
                        cout << " ";
                }

                if (j == width - 1)
                    cout << "#";
            }
            cout << endl;
        }

        for (int i = 0; i < width + 2; i++)
            cout << "#";
        cout << endl;

        cout << "Score: " << state.score << " | High Score: " << highScore << endl;
    }

    void input() {
        if (_kbhit()) {                          // _khbit function used to check whether a key is pressed or not which is there in conio.h library
            char ch = _getch();
            switch (ch) {
            case 'a':
                if (snake.dir != RIGHT)
                    snake.dir = LEFT;
                break;
            case 'd':
                if (snake.dir != LEFT)
                    snake.dir = RIGHT;
                break;
            case 'w':
                if (snake.dir != DOWN)
                    snake.dir = UP;
                break;
            case 's':
                if (snake.dir != UP)
                    snake.dir = DOWN;
                break;
            case 'x':
                state.gameOver = true;
                break;
            }
        }
    }

    void logic() {
        snake.move();

        if (snake.checkCollision()) {
            state.gameOver = true;
        }

        if (snake.x == fruit.x && snake.y == fruit.y) {
            state.score += 10;
            if (state.score > highScore) highScore = state.score;
            fruit.reset();
            snake.grow();
        }
    }

    void playAgain() {
        char choice;
        cout << "Do you want to play again? (y/n): ";
        cin >> choice;

        if (choice == 'y' || choice == 'Y') {
            Game newGame;
            newGame.start();
        } else {
            exit(0);
        }
    }

    void start() {
        while (true) {
            draw();
            input();
            logic();
            Sleep(100); // Sleep for 0.1 seconds

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
    Game game;
    game.start();
    return 0;
}
