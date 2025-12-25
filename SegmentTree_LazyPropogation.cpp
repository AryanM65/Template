#include <bits/stdc++.h>
using namespace std;
#define ll long long

class SegmentTree{
    vector<int> seg, lazy;
    public:
    SegmentTree(int n){
        seg.resize(4*n+1);
        lazy.resize(4*n+1, 0);
    }
    void build(int index, int low, int high, vector<int> &a){
        if(low == high){
            seg[index] = a[low];
            return;
        }
        int mid = (low + high)/2;
        build(2*index+1, low, mid, a);
        build(2*index+2, mid+1, high, a);
        seg[index] = seg[2*index+1] + seg[2*index+2];
    }
    void update(int index, int low, int high, int l, int r, int val){
        if(lazy[index] != 0){
            seg[index] += (high - low+1)* lazy[index];
            if(low != high){
                lazy[2*index+1] += lazy[index];
                lazy[2*index+2] += lazy[index];
            }
            lazy[index] = 0;
        }
        //no overlap -> simply return
        if(r < low || high < l){
            return;
        }
        //complete overlap
        if(l<= low && high <= r){
            //simply update and propogate the update downwards
            seg[index] += (high - low + 1)*val;
            if(low != high){
                lazy[2*index+1] += val;
                lazy[2*index+2] += val;
            }
            return;
        }
        int mid = (low + high) >> 1;
        update(2*index+1, low, mid, l, r, val);
        update(2*index+2, mid+1, high, l, r, val);
        seg[index] = seg[2*index+1] + seg[2*index+2];
    }

    int query(int index, int low, int high, int l, int r){
        if(lazy[index] != 0){
            seg[index] += (high - low + 1)*lazy[index];
            if(low != high){
                lazy[2*index+1] += lazy[index];
                lazy[2*index+2] += lazy[index]; 
            }
            lazy[index] = 0;
        }
        //no overlap
        if(low > r || l > high){
            return 0;
        }
        //complete overlap
        if(l <= low && high <= r){
            return seg[index];
        }
        int mid = (low + high)/2;
        int left = query(2*index+1, low, mid, l, r);
        int right = query(2*index+2, mid+1, high, l, r);
        return left + right;
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