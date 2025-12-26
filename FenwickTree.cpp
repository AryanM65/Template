#include <bits/stdc++.h>
using namespace std;
#define ll long long

class FenwickTree{
    vector<int> fen;
    public:
    FenwickTree(int n){
        fen.resize(n+1, 0);
    }
    void update(int i, int add){
        while(i < fen.size()){
            fen[i] += add;
            i += (i & (-i));
        }
    }

    int sum(int i){
        int s = 0;
        while(i > 0){
            s += fen[i];
            i -= (i & (-i));
        }
        return s;
    }

    int range(int l, int r){
        return sum(r) - sum(l-1);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
    }
    return 0;
}