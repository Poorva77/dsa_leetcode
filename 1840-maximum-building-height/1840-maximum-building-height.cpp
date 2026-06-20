class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        restrictions.push_back({1,0}); // add start boundary
        restrictions.push_back({n,n-1}); // add end boundary
        sort(restrictions.begin(),restrictions.end()); // sort by index

        int m=restrictions.size();

        for(int i=1;i<m;i++){
            int d=restrictions[i][0]-restrictions[i-1][0]; // gap between two restricted buildings
            restrictions[i][1]=min(restrictions[i][1],restrictions[i-1][1]+d); // left to right limit
        }

        for(int i=m-2;i>=0;i--){
            int d=restrictions[i+1][0]-restrictions[i][0]; // gap to next restriction
            restrictions[i][1]=min(restrictions[i][1],restrictions[i+1][1]+d); // right to left limit
        }

        int ans=0;

        for(int i=1;i<m;i++){
            int x=restrictions[i-1][1]; // left height
            int y=restrictions[i][1]; // right height
            int d=restrictions[i][0]-restrictions[i-1][0]; // distance between them

            ans=max(ans,(x+y+d)/2); // peak height formula
        }

        return ans;
    }
};