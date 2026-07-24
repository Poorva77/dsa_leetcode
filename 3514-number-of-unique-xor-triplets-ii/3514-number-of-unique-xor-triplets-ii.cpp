class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        // Step 1: Find all unique numbers in nums (1-element XORs)
        unordered_set<int> set1(nums.begin(), nums.end());
        // Step 2: Form all unique 2-element XOR values
        unordered_set<int> set2;
        for(int a:set1){
            for(int b:set1){
                set2.insert(a^b);
            }
        }
        // Step 3: Form all unique 3-element XOR values (triplets)
        unordered_set<int> set3;
        for(int ab:set2){
            for(int c:set1){
                set3.insert(ab^c);
            }
        }
        return set3.size();
    }
};