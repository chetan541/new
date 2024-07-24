#include <bits/stdc++.h>
using namespace std;
// void func(vector<int> &v,int ind,int size,long long &a,vector<long long> &ans){
//     if(ind==size-1){ans.push_back(a);return;}
//     a+=1LL<<v[ind];
//     func(v,ind+1,size,a,ans);
//     a-=1LL<<v[ind];
//     func(v,ind+1,size,a,ans);
// }

int main() {
	// your code goes here
	int t;cin>>t;
	while(t--){
	    int x;cin>>x;
	    int cnt=0;
	    long long a=0,b=0;
        int flag=0;
        vector<int> v;
	    for(int i=0;i<=32;i++){
	        if(((1LL<<i)^x)<x){
	            // cnt++;
                v.push_back(i);

	        }
	    }
        int size=v.size();

        a=1LL<<v[size-1];
        b=x-a;
	    int l=min(a,b);
	    int r=max(a,b);
        long long z=abs(l-r);
	    // cout<<l<<" "<<r<<endl;
        if(size==1)cout<<1<<endl;
        else cout<<pow(2,v[size-2]-(size-2))<<endl;
	}

}
