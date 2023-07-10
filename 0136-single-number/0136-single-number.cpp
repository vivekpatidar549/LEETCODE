// class Solution {
// public:
//     int singleNumber(vector<int>& nums) {
        // sort(nums.begin(), nums.end());
        // int n=nums.size();
        // if (n==1){
        //     return nums[0];
        // }
        // int i=0;
        // int ans;
        // while(i+1<=n &&i<n){
        //     if(nums[i]==nums[i+1]){
        //         i=i+2;
        //     }
        //     if(i+1 <=n && nums[i]!=nums[i+1]){
        //         ans=nums[i];
        //         i=i+1;
        //     }

        // }
        // return ans;
//     }
// };


// with O(N) extra space solution 
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if (nums.size()==1){
            return nums[0];
        }
        unordered_map<int, int> freq;
        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
        }
        for(auto it : freq){
            cout<<it.first<<" "<<it.second<<endl;
            if(it.second==1){
                return it.first;
            }
            
        }
        return -1;
        
    }
};