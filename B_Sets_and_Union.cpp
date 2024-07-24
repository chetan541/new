#include <bits/stdc++.h>
using namespace std;  
// Shortcuts for "common" data types in contests
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<int, int> msi;
  
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
void ans(){
    
    int n;
    cin >> n;
    unordered_set<int> elements;
    vector<unordered_set<int>> arr;
    for (int i = 0; i < n; i++)
    {
        unordered_set<int> temp;
        int s;
        cin >> s;
        for (int j = 0; j < s; j++)
        {
            int r;
            cin >> r;
            temp.insert(r);
            elements.insert(r);
        }
        arr.push_back(temp);
    }

    int res = INT_MIN;
    for (auto i : elements)
    {
        unordered_set<int> temp;
        for (int j = 0; j < n; j++)
        {
            if (arr[j].count(i) != 0)
            {
                continue;
            }
            else
            {
                for (auto it : arr[j])
                {
                    temp.insert(it);
                }
            }
        }
        int a = temp.size();
        res = max(res, a);
    }

    cout << res << endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        ans();
    }
}