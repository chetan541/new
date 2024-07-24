#include <iostream>
#include <vector>
using namespace std;

const int ROWS = 2;

vector<pair<int,int>> adj = {{0,1},{1,0} , {-1,0},{0,-1}};

bool dfs(vector<vector<int>>& arr, int x, int y, int n) {
    if (x == 1 && y == n - 1) 
        return true;

    for(auto direction : adj){ 
        int i = x + direction.first;
        int j = y + direction.second;

        if (i >= 0 && j >= 0 && i < ROWS && j < n && arr[i][j] != 0) { 
            j += arr[i][j]; 
            if (arr[i][j] != 0) {
                arr[x][y] = 0; 
                if (dfs(arr, i, j, n)) 
                    return true;
            }
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<vector<int>> arr(ROWS, vector<int>(n));

        for(int i = 0; i < ROWS; i++) {
            for(int j = 0; j < n; j++) {
                char ch;
                cin >> ch;
                arr[i][j] = (ch == '>') ? 1 : -1;
            }
        }

        if (dfs(arr, 0, 0, n))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}
