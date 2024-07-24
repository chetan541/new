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
    ll t;
    cin>>t;
    
    while(t--){
        ll max=1e9 +7;
        ll n;
        cin>>n;
        ll count=0;
    ll count2=0;
    ll count3=0;
        vi v;
        REP(i,0,n-1){
            ll a;
            cin>>a;
            if(a==1){
                count++;
            }
            else if(a==2){
                count2++;
            }
            else if(a==3){
                count3++;
            }
            else{
                v.push_back(a);
            }
        }
        
        sort(v.begin(),v.end());
        if(count>count2)
        {
            count-=count2;
            count3+=count2;
            count2=0;


        }
        else {
            count3+=count;
            count=0;
            count2-=count;
        }
        ll temp=count/3;
        ll temp2=count%3;
        count3+=temp;
        if(temp2==2){
            if(count2!=0){
                if(count2==1){
                    count2++;
                    temp2=0;
                }
                else{
                    count3+=2;
                    count2-=2;
                }

            }
            else{
                count2++;
                count=0;
            }

        }
        if(temp2==1){
            if(count2!=0){
                count3++;
                count2--;

        }
        else{
            if(count3!=0)
           { count3--; v.push_back(4);}
            else
            {
                v[0]+=1;
            }
        }
        }
    
    ll sum=1;
    for(int i=0;i<v.size();i++)
    {
        sum*=v[i];
        sum=sum%max;
    }
    while(count2!=0){
    sum*=2;
    sum=sum%max;
    count2--;
   }
   while(count3!=0){
    sum*=3;
    sum=sum%max;
    count3--;
   }
   

cout<<sum<<endl;
}
}

           

        
    