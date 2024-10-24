//Vishal Wagh
#include <stack>
#include <bits/stdc++.h>
using namespace std;

// this function prints the chessboard with queens positions
void printGrid(const vector<vector<int>>& position, int N) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (position[i][j] != 1){
                cout <<"_";
            }else {
                cout << position[i][j] << " ";
            }
        }
        cout << endl; //Move to next line
    }
}

// Function to see if it's safe to place a queen at a perticular position
bool isValid(const vector<vector<int>>& position, int N, int row, int col) {
    // check if there's a queen in the column
    for (int i = 0; i < row; i++) {
        if (position[i][col] == 1) {
            return false;  //return false if there's a queen
        }
    }

    // check the left / diagonal
    int i = row;
    int j = col;
    while (i >= 0 && j >= 0) {
        if (position[i][j] == 1) {
            return false;  // return false if there's queen in the left digonal
        }
        i--;  // to move diagonaly
        j--;
    }

    // Check the right \ diagonal
    i = row;  // reset i to original row value
    j = col;  // reset j to the original coloumn value
    while (i >= 0 && j < N) {
        if (position[i][j] == 1) {
            return false;  // return false if there's a queen on the right diagonal
        }
        i--;  //move long the right digonal
        j++;
    }

    return true;  // if all checks out then you can place the queen.
}


// Recursive function to solve the N-Queens problem using backtracking
//// This function uses stacks to store the position of queens
bool N_Queens(stack<pair<int, int>>& queens, vector<vector<int>>& position, int row, int N){

    if (row>=N){ //base case
        return true;
    }
    for (int i = 0; i<N; i++){ //attempt to place the queen on each coloumn of the row
        if(isValid(position,N, row,i)){
            position[row][i] = 1;         //take a not on the board that there a queen at that position
            queens.push({row,i});          // store the position of the queen in stacks
            if(N_Queens(queens,position,row+1,N)){
                return true; //if the queen is successfully placed, return true
            }

            //backtrack if failed to place on the current row
            position[row][i] = 0; //remove the position
            queens.pop();

        }
    }

    return false; //return false if no solution found
}



int main(){
    int N;
    cout << "Enter the number of queens: ";
    cin >> N;           //user defined size of the board and number of queens
    if(N>60 || N < 1){
        cout<<"The time complexity of this program is O(N^3), this would take a whole lot of time to run. \nTry a smaller number but bigger than 1";
        return 0;
    }

    vector<vector<int>> position(N, vector<int>(N, 0));  //N*N chess board

    stack<pair<int, int>> queens; // stack to store positions of the queens

    if(N_Queens(queens, position, 0, N)){
        printGrid(position,N);
    }else{
        cout<<endl<<"No solution found for "<<N<<" Queens"<<endl;
    }


    return 0;
}
