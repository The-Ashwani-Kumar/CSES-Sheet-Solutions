#include<bits/stdc++.h>
#define ll long long
#define f(i,a,b) for(ll i=a;i<=b;i++)
#define rf(i,a,b) for(ll i=a;i>=b;i--)
#define fg(i,a,b,gap) for(ll i=a;i<=b;i+=gap)
#define v(dataType) vector<dataType>
#define vv(dataType) vector<vector<dataType>>
#define vp(dataType1,dataType2) vector<pair<dataType1,dataType2>>
#define sortV(s) sort(s.begin(),s.end())
#define sortR(s) sort(s.rbegin(),s.rend())
using namespace std;

bool isSafe(int row, int col, char chessBoard[8][8]){
    // Checking the upper left diagonal
    for(int r=row,c=col;r>=0 && c>=0;r--,c--){
        if(chessBoard[r][c] == 'Q'){
            return false;
        }
    }
    // Checking the upper right diagonal
    for(int r=row,c=col;r>=0 && c<8;r--,c++){
        if(chessBoard[r][c] == 'Q'){
            return false;
        }
    }
    // Checking the upper column
    for(int r=row;r>=0;r--){
        if(chessBoard[r][col] == 'Q'){
            return false;
        }
    }
    return true;
}

ll totalWaysToPlaceQueens(char chessBoard[8][8], int row){
    if(row == 8){
        return 1;
    }
    ll totalWays = 0;
    f(col,0,7){
        if(chessBoard[row][col] == '.' && isSafe(row,col,chessBoard)){
            chessBoard[row][col] = 'Q'; // Place the queen
            totalWays += totalWaysToPlaceQueens(chessBoard,row+1);
            chessBoard[row][col] = '.'; // Backtrack
        }
    }
    return totalWays;
}

int main(){
    char chessBoard[8][8];
    f(i,0,7){
        f(j,0,7){
            cin>>chessBoard[i][j];
        }
    }
    cout<<totalWaysToPlaceQueens(chessBoard,0)<<endl;
    return 0;
}