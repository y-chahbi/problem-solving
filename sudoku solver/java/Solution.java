import java.util.Arrays;

public class Solution {
    private static final int BOX_WIDTH = 3;
    private static final int ROW_SIZE = BOX_WIDTH * BOX_WIDTH;
    private static final int COL_SIZE = BOX_WIDTH * BOX_WIDTH;

    private boolean isNumber(char c) {
        return c >= '1' && c <= '9';
    }

    private int toNumber(char c) {
        return c - '0';
    }

    private char toChar(int number) {
        return (char) (number + '0');
    }

    private boolean allowedInRow(char[][] board, int row, char number) {
        for (int i = 0; i < COL_SIZE; i++) {
            if (board[row][i] == number) {
                return false;
            }
        }
        return true;
    }

    private boolean allowedInCol(char[][] board, int col, char number) {
        for (int i = 0; i < ROW_SIZE; i++) {
            if (board[i][col] == number) {
                return false;
            }
        }
        return true;
    }

    private boolean allowedInBox(char[][] board, int row, int col, char number) {
        int boxRow = row - row % BOX_WIDTH;
        int boxCol = col - col % BOX_WIDTH;

        for (int i = 0; i < BOX_WIDTH; i++) {
            for (int j = 0; j < BOX_WIDTH; j++) {
                if (board[boxRow + i][boxCol + j] == number) {
                    return false;
                }
            }
        }
        return true;
    }

    private boolean isAllowed(char[][] board, int row, int col, char number) {
        return allowedInRow(board, row, number)
                && allowedInCol(board, col, number)
                && allowedInBox(board, row, col, number);
    }

    private boolean solve(char[][] board) {
        for (int row = 0; row < ROW_SIZE; row++) {
            for (int col = 0; col < COL_SIZE; col++) {
                if (board[row][col] == '.') {
                    for (int num = 1; num <= 9; num++) {
                        if (isAllowed(board, row, col, toChar(num))) {
                            board[row][col] = toChar(num);
                            if (solve(board)) {
                                return true;
                            }
                            board[row][col] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    public void solveSudoku(char[][] board) {
        solve(board);
    }

    public static void main(String[] args) {
        char[][] grid = {
            {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
            {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
            {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
            {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
            {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
            {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
            {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
            {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
            {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
        };

        Solution inst = new Solution();
        inst.solveSudoku(grid);

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                System.out.print(" " + grid[i][j] + " ");
            }
            System.out.println();
        }
    }
}
