#  Snake Game

## 1. About the Project
The **Snake Game** is a simple console-based implementation of the classic Snake game written in **C++**. The game involves maneuvering a snake around a grid to collect food while avoiding collisions with the walls and itself.

## 2. Features
- Classic Snake game mechanics
- Score tracking with a **high score saving** feature
- Simple **graphics**
- **Play again** option after game over
- Responsive controls using `W`, `A`, `S`, `D`

## 3. Screenshots

## 4. Installation
### Prerequisites
- C++ Compiler (GCC, MSVC, Clang, etc.)
- Windows OS (for `system("cls")` and `Sleep()` functions) or modify for cross-platform support

### 5. Steps to Install and Run
1. **Clone the repository**
   ```sh
   git clone https://github.com/aprk05/snake.git
   cd snake
   ```
2. **Compile the code**
   ```sh
   g++ snake_windows.cpp -o snake_windows
   ```
3. **Run the game**
   ```sh
   ./snake_game
   ```

## 6. How to Play
- **Move the snake**: `W` (Up), `A` (Left), `S` (Down), `D` (Right)
- **Eat food** (`F`) to grow longer and gain points
- **Avoid crashing** into walls or yourself
- **Press 'X'** to exit the game

## 7. File Structure
```
├── snake_game.cpp  # Main game source code
├── highscores.txt  # High score storage
├── README.md       # Project documentation
```



## 8. Future Improvements
- Cross-platform support (Linux/Mac) with including other libraries instead of windows library
- Game UI enhancements
- Add levels and speed variations
- save user data
  

