# Snake Game (C++ Console Application)

This is a simple console-based Snake game implemented in C++  using the Windows console. The game features a moving snake that grows when it eats a randomly placed fruit, and the game ends if the snake collides with the walls or itself. The game keeps track of the high score and saves it between sessions.

# Requirements

## Installation
1. Clone the repository:
```bash
 git clone https://github.com/aprk05/snake.git
```

2. Install dependencies:
```bash
 npm install
 ```

**Features**
- Snake moves using WASD keys.
- Fruits are randomly generated across the board which :
  + Increases the length of snake.
  + Increases the score by 10.
- Game over when snake collides with walls or itself.
- Simple console-based rendering.

**Controls**
- W - Move Up
- A - Move Down
- S - Move Left
- D - Move Right
- X - To exit the game
- Y - Continue the game
- N - Quit the game

    
**Requirements**
- Windows OS
- C++ Compiler

## How to Run

Compile the program using a C++ compiler:

```
g++ -o snakegame snakewindows.cpp
```

Run the compiled executable:
```
snakegame.exe
```

**Authors**

Group Allknighters
- 202401006
- 202401010
- 202401062
- 202401066
