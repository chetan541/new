#include <bits/stdc++.h>
using namespace std;  
// Shortcuts for "common" data types in contests
typedef long long ll;
typedef vector<int> vi;
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
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,x,y;
        cin>>n>>x>>y;
        int diff=y-x;
        int num=diff/(n);
        
        int fact;
        REP(i,num+1,diff){
            if(diff%i==0){
                fact=i;
                break;
            }
        }
        int temp=diff/fact+1;
        int rem=n-temp;
        int start=x-rem*fact;
        if(start<=0){
           start=x%fact;
           if(start==0){start=fact;}

        }

        // int start=x%fact;
        // cout<<" "<<num<<" "<<fact<<" "<<start<<endl;
        
        REP(i,1,n){
            cout<<start<<" ";
            start=start+fact;
        }
        cout<<endl;
    }
}