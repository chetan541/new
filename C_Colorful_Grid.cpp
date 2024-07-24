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
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n, m, k;
        cin >> n >> m >> k;
        int cnt = n - 1 + m - 1;
        int flag = (k - cnt) % 4;
        // cout<<flag<<endl;
        if(k-cnt < 0 || flag % 2 != 0)
            cout << "NO" << endl;
        else{
            vector<vector<char>> arr1(n, vector<char>(m - 1, 'R'));
            vector<vector<char>> arr2(n - 1, vector<char>(m, 'R'));
            REP(i, 0, n - 2){
                if(i % 2 == 0)
                    arr2[i][0] = 'R';
                else 
                    arr2[i][0] = 'B';
            }
            REP(i, 0, m - 2){
                if(i % 2 == 0)
                    arr1[n - 1][i] = arr2[n-3][0];
                else 
                    arr1[n - 1][i] = arr2[n-2][0];
            }
            
            
            
            arr1[n - 2][m - 2] = arr1[n - 1][m - 2];
            if(arr1[n - 1][m - 2] == 'R'){
                arr2[n - 2][m - 1] = 'B';
                arr2[n - 2][m - 2] = 'B';
            } else {
                arr2[n - 2][m - 1] = 'R';
                arr2[n - 2][m - 2] = 'R';
            }

            if(flag == 2)
                arr2[0][1] = 'B';

            cout << "YES" << endl;
            REP(i, 0, n - 1){
                REP(j, 0, m - 2)
                    cout << arr1[i][j] << " ";
                cout << endl;
            }
            REP(i, 0, n - 2){
                REP(j, 0, m - 1)
                    cout << arr2[i][j] << " ";
                cout << endl;
            }
        }
    }
    return 0;
}
