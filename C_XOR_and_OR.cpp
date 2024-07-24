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
    string a,b;
    cin>>a>>b;
    if(a.size()!=b.size()){
        cout<<"NO"<<endl;
    }
    else{
        ll count1=0,count2=0,count3=0,count4=0;
        for(int i=0;i<a.size();i++){
            if(a[i]=='1'){
                count1++;
                
            }
            else{
                count2++;
            }

            if(b[i]=='1'){
                count3++;
                
            }
            else{
                count4++;
            }
        }
            if(count1!=0 && count4==a.size()){
                cout<<"NO"<<endl;
            }
            else if(count2==a.size() && count4!=a.size()){
                cout<<"NO"<<endl;
            }
            else{
                cout<<"YES"<<endl;
            }
        
    }
}