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
        int n;
        cin>>n;
        vi v;
        int x=0,y=0,z=0;
        int c1=0,c2=0,flag=0;
        REP(i,0,n-1){
            int a;
            cin>>a;
            v.push_back(a);
            int b=a%10;
            int c=(a/10)%10;
            if(b!=0 && b!=5){
                if(b==7 || b==9 || b==6 || b==3){
                    if(c%2==0){
                    y++;
                }
                else{
                    x++;
                }
                }
                else{
                if(c%2==0){
                    x++;
                }
                else{
                    y++;
                }
                }
            }
            else{
                c1++;
            }
        }
        // cout<<c1<<" "<<x<<y<<endl;
        if(c1==0){
            if(x==0 || y==0){
                cout<<"YES"<<endl;
            }
            else{cout<<"NO"<<endl;}
        }
        else{
            if(c1==n){
                set<int> s;
                REP(i,0,n-1){
                    s.insert(v[i]);
                }
                if(s.size()==2 || s.size()==1){
                    if(s.size()==2 && (*(s.begin())%10)==5){
                        cout<<"YES"<<endl;
                    }
                    else if(s.size()==2 && (*(s.begin())%10)!=5){cout<<"NO"<<endl;}
                    else if(s.size()==1){cout<<"YES"<<endl;}
                }
                else{cout<<"NO"<<endl;}
            }
            else{cout<<"NO"<<endl;}
        }

    }
}