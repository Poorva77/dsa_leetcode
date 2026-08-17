class Solution {
public:
    int hammingWeight(int n) {
        int count=0;
        string num=bitset<32>(n).to_string();  //built-in
        for(int i=0;i<num.size();i++){
            if(num[i] =='1') count++;
        }
        return count;
    }
};