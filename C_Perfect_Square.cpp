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
int maxof(int a, int b, int c, int d) {
    int max1 = std::max(a, b); // Compare the first pair
    int max2 = std::max(c, d); // Compare the second pair
    return std::max(max1, max2); // Compare the results from the first and second pair
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<char>> v;
        REP(i,0,n-1){
            vi vec;
            REP(j,0,n-1){
                char a;cin>>a;
                vec.push_back(a);
            }
            v.push_back(vec);
        }
        int count=0;
        REP(i,0,n-1){
            REP(j,0,n-1){
                // cout<<v[n-1-j][i];
                // char x=maxof(v[i][j],v[n-1-j][i],v[i][n-1-j])
                
                count+=abs(v[i][j]-v[n-1-j][i]);
            }
            cout<<endl;
        }
        cout<<count<<endl;
    }
}