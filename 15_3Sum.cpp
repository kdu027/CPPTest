class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
      vector<vector<int>> result;
        int target = 0;
        if (nums.size() < 3) return result;
        sort (nums.begin(), nums.end());
        auto last = nums.size();
        for (int i=0; i<last-2; i++){
            int j = i+1;
            if (i>0 && nums[i] == nums[i-1]) continue; //don't forgot compare if *i == *(i+1), if there is repeat elements, no need to rerun.
            int k = last-1;
            while(j<k){ //don't forget, it will scan all possible combinations with the same nums[i]
                if (nums[i]+nums[j]+nums[k]<target){
                    do{
                        ++j;
                    }while(nums[j]==nums[j-1] && j<k);
                } else if(nums[i]+nums[j]+nums[k]>target){
                    do{
                        --k;
                    }while(nums[k]==nums[k+1] && j<k);
                } else { //sum == target
                    result.push_back({nums[i], nums[j], nums[k]});
                    --k;
                    do{
                        ++j;
                    }while(nums[j]==nums[j-1] && nums[k]==nums[k+1] &&j<k); //if 下一个*j && 前一个*k 值不变 && j<k，j++
                }
            }
        }
        return result;
    }
};