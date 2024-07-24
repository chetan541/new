#include <bits/stdc++.h>
using namespace std;  

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pi;
typedef vector<pi> vii;
typedef set<int> si;
typedef map<string, int> msi;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define F first 
#define S second
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, greater<int>, rb_tree_tag, tree_order_statistics_node_update>ordered_set;
#define multi_ordered_set tree<ll, null_type,greater_equal<ll>, rb_tree_tag,tree_order_statistics_node_update>
  
#define REP(i, a, b) \
for(int i = int(a); i <= int(b); i++) 
#define TRvi(c, it) \
for(vi::iterator it = (c).begin(); it != (c).end(); it++)
#define TRvii(c, it) \
for(vii::iterator it = (c).begin(); it != (c).end(); it++)
#define TRmsi(c, it) \
for(msi::iterator it = (c).begin(); it != (c).end(); it++)
  
#define INF 2000000000 

int main(){
    ios::sync_with_stdio(false), cin.tie(0);
    int t; cin >> t;
    while(t--){
        string s1, s2; cin >> s1 >> s2;
        int n = s1.size(), ind = -1;
        
        for(int i = 0; i <n; i++){
            if(s1[i] != s2[i]){
                if(s1[i] < s2[i]){
                    char x;
                    x=s1[i];
                    s1[i]=s2[i];
                    s2[i]=x;
                    
                }
                ind = i;
                break;
            }
        }
        
        if(ind != -1){
            for(int i = ind+1; i <n; i++){
                // cout<<i<<endl;
                if( s1[i] > s2[i]){
                    char x;
                    x=s1[i];
                    s1[i]=s2[i];
                    s2[i]=x;
                    // cout<<s2[i]<<endl;
                }
            }
        }
        
        cout << s1 << endl;
        cout << s2 << endl;
    }
}
