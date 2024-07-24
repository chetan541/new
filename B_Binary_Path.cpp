#include<bits/stdc++.h>
using namespace std;
#define mod 998244353
#define int  long long
#define all(x) (x).begin(), (x).end()
void printDivisors(int n,set<int>&st); 
#define nl "\n"
typedef long long ll;
#define sz(v)   ((int)(v).size())
#define fill(a,x)   memset(a,x,sizeof(a))
int n;
int f(int i,int j,vector<int>a[],int sum,int k){

    if(i==n&&j==2){
        return sum+(a[2][n]<<k);
    }
    int a1=INT_MAX,a2=INT_MAX;
    if(i+1<=n)
       a1=f(i+1,j,a,sum+(a[j][i]<<k),k-1);
    if(j<=2)
      a2=f(i,j+1,a,sum+(a[j][i]<<k),k-1);
     return min(a1,a2);
}
int f1(int i,int j,vector<int>a[],int sum,int k,int sum1){

    if(i==n&&j==2){
        sum=sum+(a[2][n]<<k);
        if(sum==sum1) return 1;
        else return 0;
    }
    int a1=0,a2=0;
    if(i+1<=n)
       a1=f1(i+1,j,a,sum+(a[j][i]<<k),k-1,sum1);
    if(j<=2)
      a2=f1(i,j+1,a,sum+(a[j][i]<<k),k-1,sum1);
     return a1+a2;
}
std::string decimalToBinary(int decimal) {
    if (decimal == 0)
        return "0";
    
    std::string binary = "";
    while (decimal > 0) {
        binary = (char)((decimal & 1) + '0') + binary;
        decimal >>= 1;
    }
    return binary;
}

void solve(){
     cin>>n;
     string s1,s2;cin>>s1>>s2;
     vector<int>v1;
     vector<int>v2;
     for(int i=0;i<n;i++){
        if(s1[i]=='0') v1.push_back(i);
     }
     for(int i=0;i<n;i++){
        if(s2[i]=='0') v2.push_back(i);
     }
     int ans=1;
     string s="";
     int last=0;
    //  for(auto it:v1) cout<<it<<" ";cout<<endl;
    //  for(auto it:v2) cout<<it<<" ";cout<<endl;
     auto i=v2.begin();
     for(auto it:v1){
        if(i!=v2.end()){
             if(it==((*i)+1)){
               ans *=2;
             }
             if(it<((*i)+1)){
               last=it;
             }

        }
     }
    //  cout<<last<<endl;
     ans=0;
     for(int i=last+1;i<n;i++){
        if(s1[i]==s2[i-1]){
            ++ans;
        }
        else break;
     }
     for(int i=0;i<=last;i++){
         s +=s1[i];
     }
     for(int i=last;i<n;i++){
         s +=s2[i];
     }
     cout<<s<<endl;
     cout<<ans+1<<endl;



    //  vector<int>a[3];
    //  a[1].push_back(0);
    //  a[2].push_back(0);
    //  for(int i=0;i<n;i++) {
    //     // int x;cin>>x;
    //     a[1].push_back(s1[i]-48);
    //  }
    //   for(int i=0;i<n;i++) {
    //     // int x;cin>>x;
    //     a[2].push_back(s2[i]-48);
    //  } 
    // //  for(int i=1;i<=2;i++){
    // //     for(int j=1;j<=n;j++) cout<<a[i][j]<<" ";cout<<endl;
    // //  }
    // //  cout<<"h2";
    //   int sum1=f(1,1,a,0,n);
    //   string str=decimalToBinary(sum1);
    //   string temp="";
    //   for(int i=1;i<=(n+1-str.size());i++){
    //     temp +='0';
    //   }
    //   cout<<temp+str<<endl;
    //   cout<<f1(1,1,a,0,n,sum1)<<endl;





}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;
    // t=1;
    while(t--){
        solve();
    }
    return 0;
}
void printDivisors(int n,set<int>&st) 
{ 
    for (int i=1; i<=sqrt(n); i++) 
    { 
        if (n%i == 0) 
        { 
            if (n/i == i)   st.insert(i);
            else st.insert(i),st.insert(n/i);
        } 
    } 
}