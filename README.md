# Snake Game

## Created by:
Group 404
Parth Agrawal
Abhijeet Kujur
Heer Bhanushali
Harsh Asnani

## Introduction
The Snake Game is a classic arcade game where the player controls a snake that moves around the screen, consuming food and growing in length. The challenge is to navigate the snake without colliding with the walls or itself.This Snake game is made using basic C++ codes and some concepts of Object Oriented Programming.

## Objective
The goal of the game is to control the snake and eat as much food as possible to increase the score, all while avoiding collisions with the walls and the snake's own body.If snake collides with
itself or with walls then game will be over. 

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

## Data Structures Used
### 1. Class: Snake

The `Snake` class is responsible for handling the snake's movement, growth, and collision detection.

#### Attributes:

- `int x, y;` - Stores the current position of the snake's head.
- `vector<int> tailX, tailY;` - Stores the positions of the snake's tail segments.
- `int nTail;` - Stores the current length of the snake's tail.
- `eDirection dir;` - Represents the current direction of movement.

#### Methods:

- `Snake()` - Constructor that initializes the snake in the center of the game area.
  
- `void move();`
  - Updates the snake's position based on its current direction.
  - Shifts the tail segments to follow the head's previous position.
  - Adjusts each tail segment to match the movement of the preceding segment.
  - Changes the `x` or `y` coordinate based on the movement direction (LEFT, RIGHT, UP, DOWN).
    
- `bool checkCollision() const;`
  - Checks if the snake's head position (`x`, `y`) is outside the game boundaries.
  - Iterates through the tail segments to determine if the head collides with any part of the tail.
  - Returns `true` if a collision is detected, indicating game over. if not game will continue
    
- `void grow();`
  - Appends a new segment at the current position of the snake's head.
  - Increases the tail length (`nTail`) to reflect the new segment.
  - Ensures the new segment follows the movement of the snake seamlessly.



### 2. Class: Fruit


### 3. Class: Game
(Explain the Game class and its attributes/methods)

## Other Data Structures Used
- Data structures such as array, 2Darray for grid making,vectors are used.for random value generator we have used ```rand``` and ```srand``` functions

## Future Enhancements
- Implementing different difficulty levels
- Adding sound effects and animations
- Multiplayer mode

## Credits
(Provide credits to contributors, if any)

## License
(Specify the open-source license if applicable)

