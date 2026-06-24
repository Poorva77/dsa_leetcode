class Solution {
public:
    int solve(string &s, int &i) { //recurssion
        long long res = 0;
        long long num = 0;
        int sign = 1;
        while(i < s.size()) {
            char c = s[i];
            if(isdigit(c)) {
                num = num * 10 + (c - '0');
            }
            else if(c == '+') {
                res += sign * num;
                num = 0;
                sign = 1;
            }
            else if(c == '-') {
                res += sign * num;
                num = 0;
                sign = -1;
            }
            else if(c == '(') {
                i++;
                num = solve(s, i);
            }
            else if(c == ')') {
                res += sign * num;
                return res;
            }
            i++;
        }
        res += sign * num;
        return res;
    }
    int calculate(string s) {
        int i = 0;
        return solve(s, i);
    }
};