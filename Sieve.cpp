#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<bool> sieve(1e5 + 1, false);
    sieve[2] = false;
    for(int i = 2; i*i <= 1e5; i++){
        if(!sieve[i]){
            for(int j = i*i; j <= 1e5; j += i){
                sieve[j] = true;
            }
        }
    }
    //sieve generated
    return 0;
}