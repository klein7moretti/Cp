#include<bits/stdc++.h> 
using namespace std; 
using ll=long long; 
 
int main(){ 
    ios::sync_with_stdio(false); 
    cin.tie(nullptr); 

    ll N;
    cin>>N;
    vector<ll>heights(N);
    for(ll i=0;i<N;i++)cin>>heights[i];
    vector<ll>dp(N+1,0);

    //base case
    dp[0]=0;
    dp[1]=abs(heights[1]-heights[0]);
    //main logic
    for(ll i=2;i<N;i++){
        ll jump1=dp[i-1]+abs(heights[i]-heights[i-1]);
        ll jump2=dp[i-2]+abs(heights[i]-heights[i-2]);
        dp[i]=min(jump1,jump2);
    }
    cout<<dp[N-1];
}
