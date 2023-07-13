class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;

        int n = matrix.size();
        int m = matrix[0].size();
        int area = 0;

        vector<int> heights(m, 0);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '1')
                    heights[j] += 1;
                else
                    heights[j] = 0;
            }

            int currArea = largestRectangleArea(heights);
            area = max(area, currArea);
        }

        return area;
    }

    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        s.push(-1);
        int n = heights.size();
        int maxArea = 0;

        for (int i = 0; i < n; i++) {
            while (s.top() != -1 && heights[s.top()] >= heights[i]) {
                int height = heights[s.top()];
                s.pop();
                int width = i - s.top() - 1;
                maxArea = max(maxArea, height * width);
            }
            s.push(i);
        }

        while (s.top() != -1) {
            int height = heights[s.top()];
            s.pop();
            int width = n - s.top() - 1;
            maxArea = max(maxArea, height * width);
        }

        return maxArea;
    }
};
