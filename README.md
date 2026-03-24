# Triversi: A Three-Player Othello Variant

This is My first ever project with C 

**Triversi** is a strategic command-line board game written in C. Inspired by the classic game *Reversi* (Othello), this version expands the competitive dynamic by supporting **three players**: Red (`r`), Yellow (`y`), and Blue (`b`).

---

## ## Game Rules

### 1. The Board
* The game is played on a square matrix of dimension $n \times n$.
* The user defines $n$ at the start, with a minimum size of 4 and a maximum of 23.
* The board is initialized with asterisks (`*`) representing empty slots.

### 2. The Opening Move
* **Red** always moves first.
* The first stone must be placed in the center of the grid:
    * **If $n$ is odd:** The stone must be at row $n/2+1$, column $n/2+1$.
    * **If $n$ is even:** The stone must be placed in one of the four central slots: $(n/2, n/2)$, $(n/2, n/2+1)$, $(n/2+1, n/2)$, or $(n/2+1, n/2+1)$.

### 3. Gameplay Mechanics
* **Turn Order:** Players rotate in the sequence Red $\rightarrow$ Yellow $\rightarrow$ Blue.
* **Adjacency Requirement:** After the first move, every stone must be placed in an empty slot that is adjacent (horizontally, vertically, or diagonally) to at least one existing stone.
* **Flipping Stones:** If a player traps an opponent's stones in a straight line between their new stone and an existing stone of their own color, the trapped stones "flip" to the current player's color.

### 4. Winning the Game
* The game ends once the board is completely full (no `*` remaining).
* The program counts the total stones for each color.
* The player with the highest count is declared the winner.
* If all players have an equal number of stones, the game ends in a tie.

---

## ## Technical Specifications

* **Language:** C
* **Data Structures:** * A 2D `char` array `board[max][max]` for grid management.
    * An $8 \times 2$ `directions` array to handle coordinate offsets for all 8 cardinal and ordinal directions.
* **Logic Flow:**
    * Input validation using `do-while` loops to ensure legal moves.
    * Directional scanning to identify and execute stone captures.

---

## ## Compilation and Execution

### Prerequisites
* A standard C compiler (such as `gcc`).

### Steps
1. **Compile the source code:**
   ```bash
   gcc Triversi.c -o triversi
