#include<bits/stdc++.h> 
using namespace std; 
using ll=long long; 
 
int main(){ 
    ios::sync_with_stdio(false); 
    cin.tie(nullptr); 

    ll n,k;
    cin>>n>>k;
    vector<ll>heights(n);
    for(ll i=0;i<n;i++)cin>>heights[i];
    vector<ll>dp(n+1,INT_MAX);

    //base case
    dp[0]=0;
    dp[1]=abs(heights[1]-heights[0]);
    //main logic
    for(ll i=2;i<n;i++){
        for(ll j=1;j<=k;j++){
            ll jump=INT_MAX;
            if(i-j>=0)jump=dp[i-j]+abs(heights[i]-heights[i-j]);
            dp[i]=min(dp[i],jump);
        }
    }
    cout<<dp[n-1];
}
