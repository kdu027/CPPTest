//self-write
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
       vector<vector<int>> result;
        // confirm the size
        if (nums.size() < 3) return result;
        sort(nums.begin(), nums.end());
        const int target = 0;
        
        for (auto i=nums.begin(); i!= nums.end(); ++i){
            if(i>nums.begin() && *(i-1) == *i) continue;
            auto j = i+1, k = nums.end()-1;
            while (j<k){
                if(*i + *j + *k < target){
                    do{
                        ++j;
                    }while(*j == *(j-1) && j<k);
                } else if (*i + *j + *k >target){
                    do{
                        --k;
                    }while(*k == *(k+1) && j<k);
                } else{
                        result.push_back({*i, *j, *k});
                    do{
                        ++j;
                        --k;
                    }while(*j == *(j-1) && *k == *(k+1) && j<k);
                }
            }
        }
        return result;
    }
};
//better way+++++++++++++++
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int size = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int i1 = 0; i1 < size; i1++) {
            if (i1 > 0 && nums[i1] == nums[i1 - 1]) continue;
            int i2 = i1 + 1, i3 = size - 1;
            while(i2 < i3) {
                int target = nums[i1] + nums[i2] + nums[i3];
                if (target == 0) {
                    res.push_back(vector<int>{nums[i1], nums[i2], nums[i3]});
                    i2++;
                    i3--;
                    while (i2 < i3 && nums[i2-1] == nums[i2]) i2++;
                    while (i2 < i3 && nums[i3+1] == nums[i3]) i3--;
                } else if (target < 0) {
                    i2++;
                } else { // target > 0
                     i3--;
                }  
            }
        }
        return res;
    }
};
//original method+++++++++++++++++++++++++++++++
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