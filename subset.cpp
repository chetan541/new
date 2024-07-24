#include<bits/stdc++.h>
bool canPartition(vector<int> &arr, int n)
{
	// Write your code here.
	// int n=arr.size();
	int sum=0;
	for(int i=0;i<=n-1;i++){
		sum+=arr[i];
	}
	int k=sum/2;
	if(sum%2!=0||n==1)return false;
	else{
	bool dp[n+1][k+1];
	memset(dp,0,sizeof(dp));
	// dp[0][0]=true;
	for(int i=0;i<=n;i++){
		dp[0][i]=true;
	}
	// for(int i=0;i<=n;i++){
	// 	dp[i][0]=true;
	// }
	for(int i=1;i<=n;i++){
		for(int j=0;j<=k;j++){
			bool flag=false;
			flag=dp[i-1][j];
			flag|=dp[i-1][j-arr[i-1]];
			dp[i][j]=flag;
		}
	}
	
	return dp[n][k];
}
}
