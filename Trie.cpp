#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Node{
    Node* links[26];
    bool flag = false;
    public:
    bool checknext(char x){
        return links[x - 'a'] != nullptr;
    }
    Node* next(char x){
        return links[x - 'a'];
    }
    void insert(char x, Node* ptr){
        links[x - 'a'] = ptr;
    }
    bool checkend(){
        return flag;
    }
    void setend(){
        flag = true;
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