#include<bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
typedef long double ld;
typedef unsigned long long int ull;
typedef vector<pair<ll,ll>> vi;
typedef vector<vector<int> > vvi;
typedef vector<long long int> vll;
typedef pair<int,int> pii;
typedef pair<long long int,long long int> pll;
typedef vector<pair<ll,ll> > vpll;
int minNumber(int a, int b) {return (a < b) ? a : b;}
bool sortbyCond(const pair<int, int>& a,
                const pair<int, int>& b)
{
    if (a.first != b.first)
        return (a.first > b.first);
    else
       return (a.second < b.second);
}
int main(){
    int t;
    cin>>t;
    while(t--){
        ll n,l,h;
        cin>>n>>l>>h;
       vector< multiset<ll>> v;
       for (int i = 0; i < n; i++)
       {
        /* code */
        multiset<ll> m;
        for (ll i = 0;  i<l; i++)
        {
            /* code */
            int a;
            cin>>a;
            m.insert(a);
        }
        v.push_back(m);
        
       }
    //    cout<<v.size()<<endl;
       vi vec;
       for (int i = 0; i < n; i++){
        ll ti=0,pi=0,c=0,prev=0;
        for (auto it:v[i])
        {
            /* code */
            c++;
            prev+=it;
            if(prev>h){
                break;
            }
            else{
                pi++;
                ti= ti+prev;
            }
            
            // prev=ti;
            // cout<<ti<<endl;
            
            // if(prev<=h && c<l){
            // pi++;}
            // else if(c==l && prev<=h){
            //     pi++;
            //     vec.push_back({pi,ti});
            //     break;}

            //     else{
            //     ti=ti-prev;
            //     vec.push_back({pi,ti});
            //     break;
            // }


        }
        vec.push_back({pi,ti});
       }
       ll r1=vec[0].first;
       ll r2=vec[0].second;
    //    cout<<r1<<" "<<r2<<endl;
       sort(vec.begin(),vec.end(),sortbyCond);
       int ans=0;
       for(auto it:vec){
        ans++;
        // cout<<it.first<<" "<<it.second<<endl;
        if(it.first==r1 && it.second==r2){
            break;

        }
       }
       cout<<ans<<endl;
    // cout<<endl<<endl;    
    }
}