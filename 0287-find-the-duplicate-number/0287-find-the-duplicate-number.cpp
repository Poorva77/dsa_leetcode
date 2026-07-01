class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //floyd cycle dtection(also k/a linkedlist cycle or  tortoise and Hare algo.)
        int slow=nums[0];
        int fast=nums[0];

        do{
            slow=nums[slow];
            fast=nums[nums[fast]]; //it will move 2 step 
        }while(slow!=fast);

        fast=nums[0];
        while(slow!=fast){
            slow=nums[slow];
            fast=nums[fast]; //now 1 step
        }
        return slow;
    }
};