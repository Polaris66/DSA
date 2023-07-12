#include <bits/stdc++.h>

int main(){
    int n = 4;

    int arr[n][n];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            arr[i][j] = 0;
        }
    }

    for(int i = n-1; i > -1; i--){
        for(int j = 0; j < n; j++){
            if(i>j){
                arr[i][j] = max(min(arr[i + 2][j] + markers[i+1], arr[i + 1][j - 1] + markers[j]), min(arr[i + 2][j], arr[i + 1][j - 1]));
            }
        }
    }
}

// a[i][j] = max(min(a[i+2][j], a[i+1][j-1]),min(a[i+1][j-1], a[i][j-2]) )