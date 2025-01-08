# Sudoku Solver
#### Video Demo:
#### Description:

The Sudoku Solver is a software tool designed to solve a 9x9 Sudoku puzzle. The puzzle is provided through command-line arguments, and the solver uses a backtracking algorithm to find the solution.

### Features:

1. **Input Method**:
    - The Sudoku grid is supplied through command-line arguments when running the program. Each argument corresponds to a row in the grid, where each character represents a cell value (use '.' for empty cells).

2. **Backtracking Algorithm**:
    - The core of the solver relies on a recursive backtracking technique. It tries each number (1-9) in each cell and checks if placing the number would violate Sudoku rules.
    - If the number placement is valid, it recurses to solve the rest of the grid.
    - If placing a number leads to an invalid configuration later in the grid, it backtracks by resetting the current cell to zero and tries the next number.

3. **Validation Functions**:
    - `missing_on_row`, `missing_on_column`, and `missing_on_block`:
        - These functions are used to check if a number is already present in the respective row, column, or 3x3 sub-grid.
    - `isValide`:
        - This function is the main backtracking solver which uses the above validation functions to ensure numbers are placed according to Sudoku rules.

4. **Memory Management**:
    - Dynamic memory allocation is used to create and manage the Sudoku grid. Specific functions clean up allocated memory to prevent leaks.

5. **Printing the Grid**:
    - The `print_grid` function is used to display the current state of the Sudoku grid at various stages of the solving process.

### Usage:

To run the Sudoku Solver, compile the code and provide the initial Sudoku grid via command-line arguments.

```sh
gcc main.c
./a.out "53..7...." "6..195..." ".98....6." "8...6...3" "4..8.3..1" "7...2...6" ".6....28." "...419..5" "....8..79"
```

### Known Issues:
- The program assumes valid input is provided. Input validation for 9x9 grid constraints and valid characters is limited.

### Future Enhancements:
1. **Input Validation**: Implement better validation for input to ensure it meets the 9x9 grid and valid character constraints.
2. **Graphical User Interface**: Develop a simple GUI to input Sudoku puzzles and display the solution visually.
3. **Performance Optimization**: Explore more efficient algorithms or heuristic methods to speed up the solving process.

### Conclusion:

This project demonstrates a practical application of algorithms and dynamic memory management in C. The Solver effectively uses recursive backtracking to solve given Sudoku puzzles and can be further enhanced with additional features and optimizations. The project compilation and execution steps make it accessible for anyone to test and solve their Sudoku puzzles.


This is CS50x !
