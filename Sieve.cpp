#include<bits/stdc++.h>
using namespace std;

vector<bool> generate_sieve(int n){
    vector<bool> sieve(n+1, false);
    if(n > 1)sieve[2] = false;
    for(int i = 2; i*i <= n; i++){
        if(!sieve[i]){
            for(int j = i*i; j<=n; j += i){
                sieve[j] = true;
            }
        }
    }
    return sieve;
}
int main(){
    int n;
    cin>>n;
    vector<bool> sieve = generate_sieve(n);
    //sieve generated
    return 0;
}