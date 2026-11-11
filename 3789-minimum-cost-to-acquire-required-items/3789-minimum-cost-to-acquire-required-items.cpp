
class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long mini = min(need1, need2);
        long long maxi = max(need1, need2);
        long long bothType = (long long)cost1*need1 + (long long)cost2*need2;
        long long type3 = (long long)costBoth*maxi;
        long long oneType = (long long)mini*costBoth;
        if(need1 > need2)
            oneType += (long long)(maxi-mini)*min(cost1,costBoth);
        else
            oneType += (long long)(maxi-mini)*min(cost2,costBoth);
        return min({bothType,type3,oneType});
    }
};
