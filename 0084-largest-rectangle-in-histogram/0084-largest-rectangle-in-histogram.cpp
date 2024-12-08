class Solution {
public:
    void findPse(vector<int>& pse, vector<int>& heights) {
        stack<int> st;
        for (int i = 0; i < heights.size(); i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            pse.push_back(st.empty() ? -1 : st.top());
            st.push(i); // Push index instead of height
        }
    }

    void findNse(vector<int>& nse, vector<int>& heights) {
        stack<int> st;
        nse.resize(heights.size());
        for (int i = heights.size() - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            nse[i] = st.empty() ? heights.size() : st.top();
            st.push(i); // Push index instead of height
        }
    }

    int largestRectangleArea(vector<int>& heights) {
        vector<int> nse, pse;
        int maxi = 0;
        findNse(nse, heights);
        findPse(pse, heights);
        for (int i = 0; i < heights.size(); i++) {
            int width = nse[i] - pse[i] - 1;
            maxi = max(maxi, heights[i] * width);
        }
        return maxi;
    }
};
