#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve(int N, int K) {
    vector<vector<int>> arr;
    int root = sqrt(N);
    int row = 0, col = 0;
    
    // Build initial blocks
    vector<int> vec;
    for (int i = 1; i <= N; i++) {
        if (vec.size() > root) {
            arr.push_back(vec);
            vec.clear();
        }
        vec.push_back(i);
    }
    if (!vec.empty()) 
        arr.push_back(vec);
    
    // Process removals
    for (int i = 0; i < N; i++) {
        int j = K % (N - i);
        
        while (j) {
            if (col + j < arr[row].size()) {
                col += j;
                j = 0;
            } else {
                j -= arr[row].size() - col;
                col = 0;
                row++;
            }
            if (row >= arr.size()) 
                row = 0;
        }
        
        while (arr[row].size() <= col) {
            col = 0;
            row++;
            if (row >= arr.size())
                row = 0;
        }
        
        cout << arr[row][col] << " ";
        if (i != N - 1) {
            arr[row].erase(arr[row].begin() + col);
            while (arr[row].size() <= col) {
                col = 0;
                row++;
                if (row >= arr.size())
                    row = 0;
            }
        }
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    solve(n, k);
    return 0;
}