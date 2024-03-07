# Sudoku Generator and Solver

## Table of Contents

- [Overview](#overview)
- [Sudoku Generator](#sudoku-generator)
- [Sudoku Solver](#sudoku-solver)
- [Compilation and Execution](#compilation-and-execution)
- [Files](#files)
- [License](#license)

## Overview

This project consists of a Sudoku Generator written in C++ that creates Sudoku puzzles and a Sudoku Solver that solves the generated puzzles. Both programs are designed to work together seamlessly.

## Sudoku Generator

The Sudoku Generator uses a backtracking algorithm to fill the Sudoku grid. It first fills the diagonal blocks and then completes the rest of the grid while ensuring the generated puzzle has a unique solution. You can specify the number of elements to be removed from each row, creating puzzles with varying difficulty levels.

### Usage

1. **Compile the Sudoku Generator:**

    ```bash
    g++ -o sudoku_generator sudoku_generator.cpp
    ```

2. **Run the Sudoku Generator:**

    ```bash
    sudoku_generator.exe
    ```

3. Follow the prompts to specify the number of elements to be removed from each row.

4. The generated puzzle will be displayed on the console and saved to a `Puzzle.txt` file.

## Sudoku Solver

The Sudoku Solver reads a Sudoku puzzle from the `Puzzle.txt` file and uses a recursive backtracking algorithm to find the solution. If a solution exists, it prints the solved Sudoku grid; otherwise, it indicates that no solution exists.

### Usage

1. **Compile the Sudoku Solver:**

    ```bash
    g++ -o sudoku_solver sudoku_solver.cpp
    ```
    
![Generated unsolved SUDOKU puzzle](https://user-images.githubusercontent.com/95247831/200465729-0d7e6e0a-1c19-444c-aa06-db67251ec8dc.png)

2. **Run the Sudoku Solver:**

    ```bash
    sudoku_solver.exe
    ```

    ![Generated unsolved SUDOKU puzzle in a text](https://user-images.githubusercontent.com/95247831/200465859-770ec5b8-5e51-4e92-a377-1e07830de47d.png)

3. The solved Sudoku grid will be displayed on the console.
   ![Generated SUDOKU puzzle after solved](https://user-images.githubusercontent.com/95247831/200465864-d1eb442b-0ebe-4e6f-abbd-a70ca0669abc.png)

## Compilation and Execution

The provided batch file (`run_sudoku.bat`) automates the compilation and execution process for both the Generator and Solver. Simply run the batch file:

```bash
./run_sudoku.bat







