https://www.luogu.com.cn/problem/B4016

#include<bits/stdc++.h> 
using ll=long long;
using namespace std;
const int maxn=1e6+7;
const int mod=998244353;

void solve(){
    int n;cin>>n;
    vector<vector<int>>d(n+1);
    n--;
    while(n--){
        int a,b;cin>>a>>b;
        d[a].push_back(b);
        d[b].push_back(a);
    }
    int a=0,b=0,mx=-1;
    auto dfs=[&](auto&&dfs,int i,int fa,int k)->void{
        if(k>mx){
            a=i;
            mx=k;
        }
        for(auto x:d[i]){
            if(x==fa)continue;
            dfs(dfs,x,i,k+1);
        }
    };
    dfs(dfs,1,0,0);
    auto dfs1=[&](auto&&dfs1,int i,int fa,int k)->int{
        int ans=k;
        for(auto x:d[i]){
            if(x==fa)continue;
            ans=max(ans,dfs1(dfs1,x,i,k+1));
        }
        return ans;
    };
    cout<<dfs1(dfs1,a,0,0)<<'\n';
  
    
}

signed main( ){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;//cin>>t;
    while(t--)
    solve();
    return 0;
}
