#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

void printBoard(const vector<int>& queens) {
    int N = queens.size();
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (queens[i] == j) {
                cout << "1 ";
            } else {
                cout << "0 ";
            }
        }
        cout << endl;
    }
}

bool isSolution(const vector<int>& queens) {
    int N = queens.size();
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            if (queens[i] == queens[j] || abs(i - j) == abs(queens[i] - queens[j])) {
                return false;
            }
        }
    }
    return true;
}

vector<int> findBetterNeighbor(const vector<int>& current) {
    int N = current.size();
    vector<int> neighbor = current;
    int randRow = rand() % N;
    int randCol = rand() % N;
    neighbor[randRow] = randCol;

    return neighbor;
}

vector<int> hillClimbing(int N) {
    srand(time(0));
    vector<int> current(N);

    for (int i = 0; i < N; ++i) {
        current[i] = rand() % N;
    }

    while (!isSolution(current)) {
        vector<int> neighbor = findBetterNeighbor(current);

        if (isSolution(neighbor)) {
            current = neighbor;
        } else {
            for (int i = 0; i < N; ++i) {
                current[i] = rand() % N;
            }
        }
    }

    return current;
}

int main() {
    int N;
    cout << "Enter N (less than 10): ";
    cin >> N;

    if (N >= 10) {
        cout << "Please enter N less than 10." << endl;
        return 1;
    }

    vector<int> solution = hillClimbing(N);
    cout << N << endl;
    printBoard(solution);

    return 0;
}
// nqueens.cpp
// Displaying 22074009.cpp.