#include <iostream>
#include <vector>
using namespace std;

const int INF = 1000000; 

void printMatrix(int n, vector<vector<int>> &mat) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == INF)
                cout << "INF ";
            else
                cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}
int main() {
    int n = 4; 
    vector<vector<int>> mat = {
        {7, 5, INF, INF},   
        {7, INF, INF, 2},   
        {INF, 3, INF, INF}, 
        {4, INF, 1, INF} 
    };

    cout << "Initial adjacency matrix:\n";
    printMatrix(n, mat);
    n++;
    for (auto &row : mat) row.push_back(INF); 
    mat.push_back(vector<int>(n, INF));       
    mat[n-1][n-1] = 0; 
    mat[4][0] = 5; 
    mat[0][4] = 6; 
    mat[1][4]= 4;
    cout << "\nAdjacency matrix after adding new node and edges:\n";
    printMatrix(n, mat);

    int maxWeight = -1, maxI = -1, maxJ = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] != INF && mat[i][j] > maxWeight) {
                maxWeight = mat[i][j];
                maxI = i;
                maxJ = j;
            }
        }
    }
    if (maxI != -1 && maxJ != -1) {
        mat[maxI][maxJ] = INF;
    }

    cout << "\nAdjacency matrix after removing max weight edge:\n";
    printMatrix(n, mat);

    return 0;
}
