class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n=word1.size(),m=word2.size();
        vector<int> suf(n+1,0);
        int j=m-1;
        // Find how many characters of word2's suffix can be matched
        for(int i=n-1;i>=0;i--){
            if(j>=0&& word1[i] == word2[j])
                j--;
            suf[i] = m-1-j;
        }
        vector<int> ans;
        j=0;
        bool used=false;
        for(int i=0;i<n && j<m;i++){
            // Exact match
            if(word1[i]==word2[j]){
                ans.push_back(i);
                j++;
            }
            // Use the one allowed mismatch
            else if(!used && suf[i+1]>=m-j-1){
                ans.push_back(i);
                j++;
                used=true;
            }
        }
        if(j==m)
            return ans;
        return {};
    }
};