class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<char,string> mp={{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};
        vector<string> ans;
        if(digits.size()==1){
            for(char a:mp[digits[0]])
                ans.push_back(string(1,a));
        }
        else if(digits.size()==2){
            for(char a:mp[digits[0]]){
                for(char b:mp[digits[1]]){
                    ans.push_back(string(1,a)+b);
                }
            }
        }
        else if(digits.size()==3){
            for(char a:mp[digits[0]]){
                for(char b:mp[digits[1]]){
                    for(char c:mp[digits[2]]){
                        ans.push_back(string(1,a)+b+c);
                    }
                }
            }
        }
        else{
            for(char a:mp[digits[0]]){
                for(char b:mp[digits[1]]){
                    for(char c:mp[digits[2]]){
                        for(char d:mp[digits[3]]){
                            ans.push_back(string(1,a)+b+c+d);
                        }
                    }
                }
            }
        }
        return ans;
    }
};