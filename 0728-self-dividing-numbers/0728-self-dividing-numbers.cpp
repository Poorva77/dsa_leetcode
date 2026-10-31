class Solution {
public:
    bool selfd(int n){
        int temp=n;
        while(temp>0){
            int rem=temp%10;
            if(rem==0) return false;
            if(n%rem!=0) return false;
            temp=temp/10;
        }
        return true;
    }
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> arr;
        for(int i=left;i<=right;i++){
            if(selfd(i)){
                arr.push_back(i);
            }
        }
        return arr;
    }
};