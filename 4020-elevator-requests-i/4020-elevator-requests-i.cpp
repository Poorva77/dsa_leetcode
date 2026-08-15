class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
        int count=requests[0];
        for(int i=1;i<requests.size();i++){
            if(requests[i]>requests[i-1]){
                count+=requests[i]-requests[i-1];
            }
            else if(requests[i]<requests[i-1]){
                count+=requests[i-1]-requests[i];
            }
        }
        return count;
    }
};