class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word;
        vector<string> words;
        // Extract words separated by whitespace automatically
        while (ss>>word){  //IMP
            words.push_back(word);
        }
        // Build the result in reverse order
        string result = "";
        for (int i=words.size()-1; i>=0;i--){
            result += words[i];
            if(i>0){
                result+=" ";
            }
        }
        return result;
    }
};