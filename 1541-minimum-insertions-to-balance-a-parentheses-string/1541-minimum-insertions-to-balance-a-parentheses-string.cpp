//my initial thinking - correct code taken from ai
class Solution {
public:
    int minInsertions(string s) {
        int ans = 0;
        int open = 0;
        int close = 0;

        for (char ch : s) {
            if (ch == '(') {
                if (close == 1) {
                    ans++; // Insert one ')' to make "))"
                    if (open > 0) {
                        open--; // Matches with an earlier '('
                    } else {
                        ans++; // No '(' available, so we also needed to insert a '('
                    }
                    close = 0;
                }
                open++;
            } 
            else { // ch == ')'
                close++;
                if (close == 2) {
                    if (open > 0) {
                        open--;
                    } else {
                        ans++; // Need to insert '('
                    }
                    close = 0;
                }
            }
        }

        // Clean up remaining state after the loop
        if (close == 1) {
            ans++; // Need 1 more ')' to complete "))"
            if (open > 0) {
                open--;
            } else {
                ans++; // Need a '(' to match the "))"
            }
        }

        return ans + 2 * open; // Each remaining '(' needs "))" (2 insertions)
    }
};