class Solution {
    //tc= O(n3 log n) and sc= O(n3)
public:
    int totalNumbers(vector<int>& digits) {
        set<int> s;
        for(int i=0; i<digits.size(); i++){
            for(int j=0; j<digits.size(); j++){
                for(int k=0; k<digits.size(); k++){
                    if(i!=j && j!=k && i!=k){
                        int num = digits[i]*100 + digits[j]*10 + digits[k];
                        if(digits[i]!=0 && digits[k]%2==0){
                            s.insert(num);
                        }
                    }
                }
            }
        }
        return s.size();
    }
};