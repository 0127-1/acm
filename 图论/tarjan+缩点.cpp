https://www.luogu.com.cn/problem/P3387
#include<bits/stdc++.h> 
using ll=long long;
using namespace std;
const int maxn=1e4+7;
const int mod=998244353;

int dp[maxn];
int sum[maxn];
int low[maxn];
int dfn[maxn];
int edg[maxn];
int is[maxn];
int out[maxn];
int in[maxn];
int cnt,p;
int mx,diff;
void solve(){
    int n,m;cin>>n>>m;
    vector<int>v(n+1);
    for(int i=1;i<=n;i++)cin>>v[i];
    memset(dp,-1,sizeof(dp));
    vector<vector<int>>d(n+1);
    vector<vector<int>>d1(n+1);
    for(int i=1;i<=m;i++){
        int a,b;cin>>a>>b;
        d[a].push_back(b);
    }
    deque<int>f;
    auto dfs=[&](auto&&dfs,int i)->void{
        dfn[i]=++cnt;
        low[i]=cnt;
        f.push_back(i);
        for(auto x:d[i]){
            if(!dfn[x]){
                dfs(dfs,x);
                low[i]=min(low[i],low[x]);
            }
            else{
                if(!is[x]){
                    low[i]=min(low[i],dfn[x]);
                }
            }
        }
        if(dfn[i]==low[i]){
            p++;
            while(f.back()!=i){
                edg[p]++;
                is[f.back()]=p;
                sum[p]+=v[f.back()];
                d1[p].push_back(f.back());
                f.pop_back();
            }
            is[f.back()]=p;
            edg[p]++;
            sum[p]+=v[f.back()];
            d1[p].push_back(f.back());
            f.pop_back();
        }
    };
    for(int i=1;i<=n;i++){
        if(!dfn[i])dfs(dfs,i);
    }
    vector<vector<int>>g(p+1);
    
    for(int i=1;i<=n;i++){
        for(auto x:d[i]){
            if(is[x]!=is[i]){
                in[is[x]]++,out[is[i]]++;
                g[is[i]].push_back(is[x]);
            }
        }
    }

    auto dfs1=[&](auto&&dfs1,int i)->void{
        if(dp[i]!=-1)return ;
        dp[i]=sum[i];
        for(auto x:g[i]){
            dfs1(dfs1,x);
            dp[i]=max(dp[i],dp[x]+sum[i]);
        }
    };


    int ans=0;
    for(int i=1;i<=p;i++){
        if(!in[i]){
            dfs1(dfs1,i);
            ans=max(ans,dp[i]);
        }
    }
    cout<<ans<<'\n';
    
    


}

signed main( ){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;//cin>>t;
    while(t--)
    solve();
    return 0;
}
