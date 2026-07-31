class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26, 0);
        for (char c : word) freq[c - 'a']++;
        // Sort descending so most frequent letters get index 0..7
        sort(freq.rbegin(), freq.rend()); //reverse begin, end
        int ans=0;
        for(int i=0;i<26 && freq[i]>0;i++){
            ans+=freq[i]*((i/8)+1); // Same (i/8)+1 formula!
        }
        return ans;
    }
};