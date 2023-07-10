class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        // int majo=nums.size()/2;
        // map<int ,int> freq;
        // for(int i=0;i<nums.size();i++){
        //     freq[nums[i]] ++;
        // }
        // for(auto it: freq){
        //     if(it.second>majo){
        //         return it.first;
        //     }
        // }
        // return -1;
        if(nums.size()==1){
            return nums[0];
        }

        sort(nums.begin(),nums.end());
        int i=0;
        int n=nums.size();
        int majo=n/2;
        
        while(i<n){
            int count=1;
            while(i+1<n && nums[i]==nums[i+1]){
                count++;
                if(count>majo){
                    return nums[i];
                }
                i++;
            }
            i++;


        }
        return -1;
    }
};