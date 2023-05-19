#include <iostream>
#include <vector>
using namespace std;

bool is_valid_position(vector<int> &queens, int row, int col) {
    for(int i = 0; i < row; i++)
        if(queens[i] == col || abs(queens[i] - col) == row - i) //if queens attack each other
            return false;
    return true;
}

void solve_n_queens(int n, int row, vector<int> &queens, vector<vector<int>> &solutions) {
    if(row == n) {
        solutions.push_back(queens); //queens is the solution array Ex:[2,4,1,3] where q1 is in the 2nd col of row 1 and q2 is in the 4th col of row 2 ans so on....
        return;
    }
    for(int col = 0; col < n; col++)
        if(is_valid_position(queens, row, col)) {
            queens[row] = col; //updating the col position in the queens array
            solve_n_queens(n, row+1, queens, solutions);
        }
}

void print_solution(vector<int> &queens) { //representation of the queens array in the board format
    int n = queens.size();
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(queens[i] == j) {
                cout << "Q ";
            } else {
                cout << "- ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the size of the board: ";
    cin >> n;
    vector<vector<int>> solutions; //2d array containing all the solutions stored in queens array
    vector<int> queens(n);
    solve_n_queens(n, 0, queens, solutions);
    int num_solutions = solutions.size();
    if(num_solutions == 0) {
        cout << "No solutions found." << endl;
    } else {
        cout << "Found " << num_solutions << " solutions:" << endl;
        for(int i = 0; i < num_solutions; i++) {
            cout << "Solution " << i+1 << ":" << endl;
            print_solution(solutions[i]);
        }
    }
    return 0;
}
