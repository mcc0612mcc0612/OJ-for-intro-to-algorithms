#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
long int max_continious_array(int* addr,int n){
    long int temp_sum = 0;
    long int max_sum = 0;
    for(int i =0; i < n;i++) {
        if(addr[i] >= 0){
            temp_sum += addr[i];
            if(temp_sum > max_sum){
                max_sum = temp_sum;
            }
        }
        else{
            if(temp_sum + addr[i] < 0){
                temp_sum = 0;
            }
            else{
                temp_sum += addr[i];
            }
        }
    }
    return max_sum;
}

int main(){
    int n;
    cin >> n;
    int *num = new int[n];
    int* _num = num;
    for (int i = 0; i < n;i++) {
        cin >> *_num; 
        _num++;
    }
    cout << max_continious_array(num,n);
}