https://www.luogu.com.cn/problem/U224391
#include<bits/stdc++.h> 
using ll=long long;
using namespace std;
const int maxn=5e4+7;
const int mod=998244353;

int low[maxn];
int dfn[maxn];
int edg[maxn];
int is[maxn];
int cnt,p;

void solve(){
    int n,m;cin>>n>>m;
    vector<vector<int>>d(n+1);
    vector<vector<int>>d1(n+1);
    for(int i=0;i<m;i++){
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
                d1[p].push_back(f.back());
                f.pop_back();
            }
            is[f.back()]=p;
            edg[p]++;
            d1[p].push_back(f.back());
            f.pop_back();
        }
    };
    for(int i=1;i<=n;i++){
        if(!dfn[i])dfs(dfs,i);
    }
    // for(int i=1;i<=p;i++){
    //     sort(d1[i].begin(),d1[i].end());
    // }
    // sort(d1.begin()+1,d1.begin()+1+p);
    cout<<p<<'\n';
    for(int i=1;i<=p;i++){
        cout<<edg[i]<<' ';
        for(auto x:d1[i]){
            cout<<x<<' ';
        }
        cout<<'\n';
    }

}

signed main( ){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;//cin>>t;
    while(t--)
    solve();
    return 0;
}
