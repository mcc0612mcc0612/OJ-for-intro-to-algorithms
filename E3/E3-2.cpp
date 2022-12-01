#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int shortest_path(int(*path)[200] ,int n,int m){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(i == 0){
                if(j != 0)
                    path[i][j] += path[i][j-1] ;
            }
            else{
                if(j == 0){
                    path[i][j] += path[i - 1][j];
                }
                else{
                    path[i][j] += min(path[i - 1][j],path[i][j - 1]);
                }
            }
        }
    }
    return path[n - 1][m - 1];
}

int main(){
    int n,m;
    int path[200][200];
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> path[i][j];
        }
    }
    cout << shortest_path(path,n,m);
}