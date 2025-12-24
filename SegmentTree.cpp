#include <bits/stdc++.h>
using namespace std;
#define ll long long

class SegmentTree{
    vector<int> seg;
    public: 

    SegmentTree(int n){
        seg.resize(4*n + 1);
    }

    void build(int index, int low, int high, vector<int> &a){
        if(low == high){
            seg[index] = a[low];
            return;
        }
        int mid = (low + high)/2;
        build(2*index+1, low, mid, a);
        build(2*index+2, mid+1, high, a);
        seg[index] = min(seg[2*index+1], seg[2*index+2]);
    }

    int query(int index, int low, int high, int l, int r){
        if(high < l || r < low )return INT_MAX; //no overlap
        if(l <= low && r >= high)return seg[index]; //complete overlap
        
        //partial overlap
        int mid = (low + high)/2;
        int left = query(2*index+1, low, mid, l, r);
        int right = query(2*index+2, mid+1, high, l, r);

        return min(left, right);
    }

    void update(int index, int low, int high, int i, int val, vector<int> &a){
        if(low == high){
            seg[index] = val;
            // a[i] = val;
            return;
        }
        int mid = (low + high)/2;
        if(i <= mid){
            update(2*index+1, low, mid, i, val, a);
        }
        else{
            update(2*index+2, mid+1, high, i, val, a);
        }
        seg[index] = min(seg[2*index+1], seg[2*index+2]);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
    }
    return 0;
}