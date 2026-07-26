class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if (str1 + str2 != str2 + str1)  //BRAIN
            return "";
        int n=gcd((int)str1.size(), (int)str2.size());  //gcd(a,b) ->returns gcd of 2 integers
        return str1.substr(0,n);   //substr(start, length) ->returns substring starting at index 'start'
    }
};