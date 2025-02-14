# Snake Game

## Created by:
Group **404**

1.Parth Agrawal\
2.Abhijeet Kujur\
3.Heer Bhanushali\
4.Harsh Asnani

## Introduction
The Snake Game is a classic arcade game where the player controls a snake that moves around the screen, consuming food and growing in length. The challenge is to navigate the snake without colliding with the walls or itself.This Snake game is made using basic C++ codes and some concepts of Object Oriented Programming.

## Objective
The goal of the game is to control the snake and eat as much food as possible to increase the score, all while avoiding collisions with the walls and the snake's own body.If snake collides with
itself or with walls then game will be over. 

## Installation

1. Clone the repository:
   ```sh
   git clone https://github.com/aprk/snake.git
   cd snake
   ```
2. Install dependencies (if any):
   ```sh
   `conio.h` library should be there
   `windows.h` library should be there
   ```
   
## Requirements
- Operating System: Windows as we have included ```windows.h``` library it would run in windows terminal
- Compiler: C++ Compiler (GCC MinGW or MSVC)

## Platform
- Windows

## Compiler
- GCC (MinGW) (for Windows)

## Libraries

- `windows.h` for 'cls' and sleep function
- `iostream.h` for basic commands
- `conio.h` for _kbhit and _getch
- `cstdlib` for rand and srand
- `ctime` for time
- `vector` for vector
- `fstream` for file handling

## How to Compile and Run

### On Windows
#### Using GCC (MinGW):
```
g++ snake_windows.cpp -o snake_windows
```
```
./snake_windows
```

## Display of the Game
-its a simple snake game with simple UI/UX pretty easy to understand and play.

## Key Features
- Classic snake movement mechanics
- Food consumption and snake growth
- Collision detection
- Score tracking/High Score Display
- Smooth animations

## How to Play

1. Use the following keys to control the snake:
   - `W` - Move Up
   - `S` - Move Down
   - `A` - Move Left
   - `D` - Move Right
   - `X` - Quit the game
2. The goal is to eat the fruit (`F`) to grow the snake and increase your score.
3. Avoid colliding with the walls or the snake's own body.

## Data Structures Used
### 1. Class: Snake

The `Snake` class is responsible for handling the snake's movement, growth, and collision detection.

#### Attributes:

- `int x, y;` - Stores the current position of the snake's head.
- `vector<int> tailX, tailY;` - Stores the positions of the snake's tail segments.
- `int nTail;` - Stores the current length of the snake's tail.
- `eDirection dir;` - Represents the current direction of movement.

#### Methods:

- **`Snake()`** - Constructor that initializes the snake in the center of the game area.
  
- **`void move();`**
  - Updates the snake's position based on its current direction.
  - Shifts the tail segments to follow the head's previous position.
  - Adjusts each tail segment to match the movement of the preceding segment.
  - Changes the `x` or `y` coordinate based on the movement direction (LEFT, RIGHT, UP, DOWN).
    
- **`bool checkCollision() const;`**
  - Checks if the snake's head position (`x`, `y`) is outside the game boundaries.
  - Iterates through the tail segments to determine if the head collides with any part of the tail.
  - Returns `true` if a collision is detected, indicating game over. if not game will continue
    
- **`void grow();`**
  - Appends a new segment at the current position of the snake's head.
  - Increases the tail length (`nTail`) to reflect the new segment.
  - Ensures the new segment follows the movement of the snake seamlessly.


### 2. Class: Fruit

The Fruit class is responsible for generating food for the snake at random positions within the game boundaries.

### Attributes:

-**`int x, y;`** - Stores the position of the fruit on the grid.

### Methods:

-**`Fruit()`;**\
   -Constructor that initializes the fruit at a random position within the game boundaries.\
   -Uses rand() % width and rand() % height to determine x and y coordinates.

-**`void reset()`;**\
   -Resets the fruit's position to a new random location after being consumed by the snake.\
   -Calls rand() % width and rand() % height again to update x and y.


### 3. Class: Game

The `Game` class handles the overall game logic, rendering, and user interaction.

#### Attributes:

- `Snake snake;` - An instance of the `Snake` class representing the player-controlled snake.
- `Fruit fruit;` - An instance of the `Fruit` class representing the food.
- `GameState state;` - Holds game-related state variables such as score and game-over status.

#### Methods:

- **`Game();`**
     - Constructor that initializes the game and sets up the random number generator using `srand(time(0))`.
      
- **`void draw() const;`**
   - Clears the screen and redraws the game grid.
   - Displays the snake, fruit, walls, and the current score.
     
- **`void input();`**
  - Captures user input from the keyboard and changes the snake's direction accordingly.
  - Pressing 'x' ends the game.
    
- **`void logic();`**
  - Updates the game state each frame.
  - Moves the snake, checks for collisions, and handles food consumption.
  - If the snake eats a fruit, the score increases, and the snake grows.
    
- **`void playAgain();`**
  - Prompts the player to restart the game or exit after game over.
  - If the player chooses to restart, a new `Game` instance is created.
    
- **`void start();`**
  - The main game loop that continuously runs:
    
    - Calls `draw()` to render the game state.
    - Calls `input()` to capture user input.
    - Calls `logic()` to update the game mechanics.
    - Uses `Sleep(100);` to control game speed.
    - Ends the game if the player loses and prompts for replay.

### 4. Class: GameState

The `GameState` class manages the state of the game, including tracking the score and determining if the game is over.

#### Attributes:

- `bool gameOver;` - A flag that indicates whether the game is over.
- `int score;` - Stores the player's current score.

#### Methods:

- **`GameState();`**
  - Constructor that initializes the game state.
  - Sets `gameOver` to `false` and `score` to `0` at the start of the game.


## Other Data Structures Used
- Data structures such as array, 2Darray for grid making,vectors for snake movement are used.for random value generator we have used ```rand``` and ```srand``` functions.
- functions like `_khbit` is used to ensure that if a key is pressed or not on keyboard
- `_getch` pauses output console until a key is pressed

## Future Enhancements

- Implementing different difficulty levels( this can be done by reducing sleep timer so to increase speed of snake)
- Adding sound effects and animations(can be done using a beep function)
  
## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.


