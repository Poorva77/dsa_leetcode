class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> freq;
        for(char ch : text){
            freq[ch]++;
        }
        return min({freq['b'], freq['a'], freq['l']/2, freq['o']/2, freq['n']});
    }
};

//my previous code had this mistake - (When you form one "balloon", you are deleting all characters, including extra ones that could be used for the next "balloon").