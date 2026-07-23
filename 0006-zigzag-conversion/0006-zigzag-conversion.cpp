class Solution {
public:
    string convert(string s, int numRows) {
        int n=s.length();
        // Base cases
        if(numRows==1 || n<=numRows) return s;
        string ans="";
        int cycle=2*numRows-2; // Distance between main vertical characters
        // LOOP 1: Top Row (Row 0)
        for(int i=0;i<n;i+=cycle){
            ans.push_back(s[i]);
        }
        // LOOP 2: Middle Rows (Row 1 to Row numRows - 2)
        for(int row=1;row<numRows-1;row++){
            for(int i=row;i<n;i+=cycle){
                // Add vertical character
                ans.push_back(s[i]);
                // Add diagonal character (zigzag line character)
                int diagIndex=i+cycle-2*row;
                if(diagIndex<n){
                    ans.push_back(s[diagIndex]);
                }
            }
        }
        // LOOP 3: Bottom Row (Row numRows - 1)
        for (int i=numRows-1;i<n;i+=cycle){
            ans.push_back(s[i]);
        }
        return ans;
    }
};