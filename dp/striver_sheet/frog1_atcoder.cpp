#include<bits/stdc++.h> 
using namespace std; 
using ll=long long; 
 
int main(){ 
    ios::sync_with_stdio(false); 
    cin.tie(nullptr); 

    ll N,total_weight;
    cin>>N>>total_weight;
    vector<ll>values(N),weights(N);
    for(ll i=0;i<N;i++)cin>>weights[i]>>values[i];
    vector<vector<ll>>dp(N,vector<ll>(total_weight+1,0));

    //base case
    for(ll w=weights[0];w<=total_weight;w++){
        dp[0][w]=values[0];
    }

    //main logic
    for(ll i=1;i<N;i++){
        for(ll w=1;w<=total_weight;w++){
            ll not_take=dp[i-1][w];
            ll take=INT_MIN;
            if(weights[i]<=w)take=values[i]+dp[i-1][w-weights[i]];
            dp[i][w]=max(take,not_take);
        }
    }
    cout<<dp[N-1][total_weight];
}
