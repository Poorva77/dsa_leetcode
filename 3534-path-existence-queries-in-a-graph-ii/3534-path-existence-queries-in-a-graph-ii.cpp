class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<pair<int,int>> a;
        for(int i=0;i<n;i++)
            a.push_back({nums[i],i});

        sort(a.begin(),a.end());

        vector<int> pos(n),comp(n);

        int cid=0;
        for(int i=0;i<n;i++){
            if(i&&a[i].first-a[i-1].first>maxDiff)
                cid++;
            pos[a[i].second]=i;
            comp[a[i].second]=cid;
        }

        vector<int> reach(n);
        int j=0;
        for(int i=0;i<n;i++){
            while(j+1<n && a[j+1].first-a[i].first<=maxDiff)
                j++;
            reach[i]=j;
        }

        const int LOG=18;
        vector<vector<int>> up(LOG,vector<int>(n));

        for(int i=0;i<n;i++)
            up[0][i]=reach[i];

        for(int k=1;k<LOG;k++)
            for(int i=0;i<n;i++)
                up[k][i]=up[k-1][up[k-1][i]];

        vector<int> ans;

        for(auto &q:queries){
            int u=q[0],v=q[1];

            if(u==v){
                ans.push_back(0);
                continue;
            }

            if(comp[u]!=comp[v]){
                ans.push_back(-1);
                continue;
            }

            int l=pos[u],r=pos[v];
            if(l>r) swap(l,r);

            int cur=l;
            int jumps=0;

            for(int k=LOG-1;k>=0;k--){
                if(up[k][cur]<r){
                    cur=up[k][cur];
                    jumps+=(1<<k);
                }
            }

            ans.push_back(jumps+1);
        }

        return ans;
    }
};
