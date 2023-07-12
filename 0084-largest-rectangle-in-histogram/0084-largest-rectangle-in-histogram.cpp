class Solution {
    private:
    vector<int> nextsmallerelements(vector<int> arr, int n){
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);
        for(int i=arr.size()-1;i>=0;i--){
            int current=arr[i];
            while(s.top()!=-1 && arr[s.top()]>=current){
                s.pop();
            }
            ans[i]=s.top();
            s.push(i);
        }
        return ans;
    }
    vector<int> previouselements(vector<int> arr, int n){
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);
        for(int i=0;i<arr.size();i++){
            int current=arr[i];
            while(s.top()!=-1 && arr[s.top()]>=current){
                s.pop();
            }
            ans[i]=s.top();
            s.push(i);
        }
        return ans;
    }

public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        if(n==1) return heights[0];
        vector<int>next(n);
        next=nextsmallerelements(heights,n);
        vector<int> prev(n);
        prev=previouselements(heights,n);
        int area=INT_MIN;
        for(int i=0;i<n;i++){
            int l=heights[i];
            if(next[i]==-1){
                next[i]=n;
            }
            int b=next[i]- prev[i]- 1;
            int newarea= l*b;
            area=max(area,newarea);


        }
        return area;
        
    }
};