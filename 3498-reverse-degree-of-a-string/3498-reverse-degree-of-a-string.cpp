class Solution {
public:
    int reverseDegree(string s) {
        int index=1;
        int sum=0;
        for(int i=0;i<s.size();i++){
            int value= 26-(s[i]-'a');
            sum+=value*index;
            index++;
        }
        return sum;
    }
};