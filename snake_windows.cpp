#include <iostream>
#include <windows.h>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

const int width = 20;
const int height = 20;
int highScore;

void loadHighScore() {
    ifstream file("highscores.txt");
    if (file.is_open()) {
        file >> highScore;
        file.close();
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

enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };

struct Node {
    int x;
    int y;
    Node* next;

    Node(int _x, int _y) {
        x = _x;
        y = _y;
        next = nullptr;
    }
};

class Snake {
public:
    Node* head;
    Node* tail;
    eDirection dir;

    Snake() {
        head = new Node(width / 2, height / 2);
        tail = head;
        dir = STOP;
    }

    ~Snake() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void move() {
        int prevX = head->x, prevY = head->y;
        switch (dir) {
        case LEFT: head->x--; break;
        case RIGHT: head->x++; break;
        case UP: head->y--; break;
        case DOWN: head->y++; break;
        default: break;
        }

        Node* current = head->next;
        int tempX, tempY;
        while (current) {
            tempX = current->x;
            tempY = current->y;
            current->x = prevX;
            current->y = prevY;
            prevX = tempX;
            prevY = tempY;
            current = current->next;
        }
    }

    bool checkCollision() {
        if (head->x >= width || head->x < 0 || head->y >= height || head->y < 0)
            return true;
        Node* current = head->next;
        while (current) {
            if (current->x == head->x && current->y == head->y)
                return true;
            current = current->next;
        }
        return false;
    }

    void grow() {
        Node* newTail = new Node(tail->x, tail->y);
        tail->next = newTail;
        tail = newTail;
    }
};

class Fruit {
public:
    int x, y;
    Fruit() { reset(); }
    void reset() {
        x = rand() % width;
        y = rand() % height;
    }
};

class GameState {
public:
    bool gameOver;
    int score;
    GameState() : gameOver(false), score(0) {}
};

class Game {
private:
    Snake snake;
    Fruit fruit;
    GameState state;

public:
    Game() { srand(time(0)); }

    void draw() const {
        system("cls");
        for (int i = 0; i < width + 2; i++) cout << "#";
        cout << endl;

        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (j == 0) cout << "#";
                if (i == snake.head->y && j == snake.head->x) cout << "O";
                else if (i == fruit.y && j == fruit.x) cout << "F";
                else {
                    bool print = false;
                    Node* current = snake.head->next;
                    while (current) {
                        if (current->x == j && current->y == i) {
                            cout << "o";
                            print = true;
                            break;
                        }
                        current = current->next;
                    }
                    if (!print) cout << " ";
                }
                if (j == width - 1) cout << "#";
            }
            cout << endl;
        }

        for (int i = 0; i < width + 2; i++) cout << "#";
        cout << endl;
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
        if (snake.head->x == fruit.x && snake.head->y == fruit.y) {
            state.score += 10;
            if (state.score > highScore) highScore = state.score;
            fruit.reset();
            snake.grow();
        }
    }

    void start() {
        while (!state.gameOver) {
            draw();
            input();
            logic();
            Sleep(100);
        }
        cout << "Game Over! Final Score: " << state.score << endl;
        if (state.score > highScore) {
            highScore = state.score;
            cout << "New High Score!" << endl;
        }
        saveHighScore();
    }
};

int main() {
    loadHighScore();
    Game game;
    game.start();
    return 0;
}
