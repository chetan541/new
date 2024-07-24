#include <bits/stdc++.h>
using namespace std;
#define ll long long
// const int MAX_N = 1e5 + 5;
// const ll MOD = 1e9 + 7;
// const ll INF = 1e9;
// const ld EPS = 1e-9;



int main(){
    int t;
    cin>>t;
    while(t--){
        int n,x;
        cin>>n>>x;
        if(n%x!=0){
            cout<<"-1"<<endl;
        }
        else{
            int k=n/x;
            int c=0;int p=1;
            for(int i=2;i<k;i++){
                if(k%i==0){
                    p=i;
                    break;
                }
            }
            
            if(p==1){
                cout<<x<<" ";
                for(int i=2;i<n;i++){
                    if(i==x)
                        cout<<n<<" ";
                    else
                        cout<<i<<" ";
                }
                cout<<"1"<<endl;
            }
            else{
                


            cout<<x<<" ";
            for(int i=2;i<n;i++){
                if(i==x){
                    p=2;
                    while(k%p!=0){
                        p++;

                    }
                    k=k/p;

                    cout<<x*p<<" ";
                    x=x*p;
                    
                }
                
                else
                    cout<<i<<" ";

            }
            cout<<"1"<<endl;

        }

        }


    

    }       
}