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
double calculateDistance(double x1, double y1, double x2, double y2) {
    double dx = x2 - x1;
    double dy = y2 - y1;
    double distance = sqrt(dx * dx + dy * dy);
    return distance;
}
// If you need to recall how to use memset:
#define MEMSET_INF 127 // about 2B
#define MEMSET_HALF_INF 63 // about 1B
int main(){
    int t;
    cin>>t;
    while(t--){
        pair<int ,int> p,a,b;
        cin>>p.first>>p.second;
        cin>>a.first>>a.second;
        cin>>b.first>>b.second;
        double disa,disb,disab,disoa,disob;
        disa=calculateDistance(a.first,a.second,p.first,p.second);
        disb=calculateDistance(b.first,b.second,p.first,p.second);
        disab=calculateDistance(a.first,a.second,b.first,b.second);
        disoa=calculateDistance(0,0,a.first,a.second);
        disob=calculateDistance(0,0,b.first,b.second);
        int l,m,n;
        
        double ans;
        if(disa<disb){l=1;}
        else{l=2;}

        if(disoa<disob){m=1;}
        else{m=2;}
        if(l==m){
            if(l==1){
                ans=max(disa,disoa);
            }
            else{
                ans=max(disob,disb);
            }
        }
        else{
            double temp1,temp2,temp3;
            if(l==1){
                temp1=disa;
            }
            else{temp1=disb;}
            if(m==1){
                temp2=disoa;
            }
            else{temp2=disob;}
            temp3=max(temp1,temp2);
            if(temp3>=(disab)/2){
                ans=temp3;
            }
            else{
                ans=disab/2;
            }
        }
        cout<<setprecision(11);
        cout<<ans<<endl;

    }
}