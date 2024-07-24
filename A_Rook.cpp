#include <bits/stdc++.h>
using namespace std;  
// Shortcuts for "common" data types in contests
typedef long long ll;
typedef vector<char> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;
  
// To simplify repetitions/loops, Note: define your
// loop style and stick with it!
#define REP(i, a, b) \
for(int i = int(a); i <= int(b); i++) // a to b, and variable i is local!
#define TRvi(c, it) \
for(vi::iterator it = (c).begin(); it != (c).end(); it++)
#define TRvii(c, it) \
for(vii::iterator it = (c).begin(); it != (c).end(); it++)
#define TRmsi(c, it) \
for(msi::iterator it = (c).begin(); it != (c).end(); it++)
  
#define INF 2000000000 // 2 billion
  
// If you need to recall how to use memset:
#define MEMSET_INF 127 // about 2B
#define MEMSET_HALF_INF 63 // about 1B

vi subsets;
vector<vector<char>> ans;

void sub(vi & vec,int i){
    if(i==vec.size()){ans.push_back(subsets);}
    else{
    sub(vec,i+1);
    subsets.push_back(vec[i]);
    sub(vec,i+1);
    subsets.pop_back();}
    
}
int main(){
    vi vec;
    int n;cin>>n;
    REP(i,0,n){
        char a;cin>>a;
        vec.push_back(a);
    }
    sub(vec,0);
    for(auto it:ans){
        for(auto vt:it){
            cout<<vt<<" ";
        }
        cout<<endl;
    }
}