class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        //PLA topic
        stack<int> st;
        int maxArea=0;
        for(int i=0;i<=heights.size();i++){
            int current=(i==heights.size())? 0:heights[i];
            while(!st.empty() && heights[st.top()]>current){
                int h= heights[st.top()];
                st.pop();
                int width= st.empty() ? i:i-st.top()-1;
                maxArea=max(maxArea, h*width);
            }
            st.push(i);
        }
        return maxArea;
    }
};