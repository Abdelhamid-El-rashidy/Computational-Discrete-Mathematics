//
// Created by Abdelhamid on 11/28/2024.
// Transitive Closure (Roy–Warshall algorithm)
// ALGORITHM Warshall Algorithm:
// procedure Warshall (MR : n × n zero–one matrix)
// W:=MR
// for k := 1 to n
    // for i := 1 to n
        // for j := 1 to n
        // wij := wij ∨ (wik ∧ wkj)
// return W{W = [wij]isMR∗
// }
//
#include<bitset>
#include <iostream>
#include <vector>

using namespace std;

// R ={(1,3),(1,4),(2,1),(3,2)} on the set{1, 2, 3, 4}.

int main()
{
    int elements, pairs;
    cin >> elements >> pairs;
    vector<vector<int>> vec(elements, vector<int>(elements, 0));

    for (int i = 0; i < pairs; i++) {
        int j, k;
        cin >> j >> k;
        vec[j - 1][k - 1] = 1;
    }

    for (int k = 0; k < elements; k++) {
        for (int i = 0; i < elements; i++) {
            for (int j = 0; j < elements; j++) {
                vec[i][j] = vec[i][j] || (vec[i][k] && vec[k][j]);
            }
        }
    }

    for (int i = 0; i < elements; i++) {
        for (int j = 0; j < elements; j++) {
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}


