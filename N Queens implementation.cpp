#include <iostream>
#include <vector>
using namespace std;

bool is_valid_position(vector<int> &queens, int row, int col) {
    for(int i = 0; i < row; i++)
        if(queens[i] == col || abs(queens[i] - col) == row - i)
            return false;
    return true;
}

void solve_n_queens(int n, int row, vector<int> &queens, vector<vector<int>> &solutions) {
    if(row == n) {
        solutions.push_back(queens);
        return;
    }
    for(int col = 0; col < n; col++)
        if(is_valid_position(queens, row, col)) {
            queens[row] = col;
            solve_n_queens(n, row+1, queens, solutions);
        }
}

void print_solution(vector<int> &queens) {
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
    vector<vector<int>> solutions;
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
