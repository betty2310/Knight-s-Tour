#include<iostream>
#include<stdio.h>

using namespace std;

#define max 1000

int n, x, y;
int a[max][max] = {0};
int h[9] = {0, -2, -1, 1, 2, 2, 1, -1, -2}; //mang move hang
int c[9] = {0, 1, 2, 2, 1, - 1, -2, -2, -1}; //mang move cot
int d = 0;

void printResult() {
    ++d;
    cout << "Case #" << d << " :\n";
    for (int i = 1; i <= n ;++i) {
        for (int j = 1; j <= n;++j) {
            cout << a[i][j] << " ";
        }
    }
    cout << "\n";
}

void trySolve(int i, int x, int y) {

    a[x][y] = i;
    for (int j = 1; j <= 8;++j) {
        if(i == n*n) {
            printResult();
        }
        int u = x + h[j]; //vi tri hang moi
        int v = y + c[j]; //vi tri cot moi
        if((u>0) && (v>0) && (u<=n) &&( v<=n) && (a[u][v] == 0)) {//kiem tra vi tri thoa man trong bang n*n
            trySolve(i+1, u, v);
            a[u][v] = 0; //dat lai vi tri lai thoa man
        }

    }
    
}

int main() {

    freopen("inp.txt", "r", stdin);
    cin >> n >> x >> y;
    fclose(stdin);
    freopen("out.txt", "w", stdout);
    trySolve(1, x, y);
    cout << "Khong co cach di thoa man";

    return 0;
}