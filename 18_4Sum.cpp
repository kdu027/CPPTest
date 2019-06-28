//myself: 
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        if (nums.size()<4) return result;
        sort(nums.begin(), nums.end());
        unordered_map<int, vector<pair<int, int>>> cache;
        
        for (int a = 0; a<nums.size()-1; ++a){
            for (int b = a+1; b<nums.size(); ++b){
                cache[nums[a]+nums[b]].push_back(pair<int,int>(a,b));
            }
        }
        for (int c = 0; c<nums.size()-1; ++c){
            for (int d = c+1; d<nums.size(); ++d){
                int key = target - nums[c] - nums[d];
                if (cache.find(key) == cache.end()) continue;
                // find the key, will push it
                const auto& vec = cache[key];
                for (int i = 0; i<vec.size(); ++i){
                    if(c>vec[i].second) result.push_back({nums[vec[i].first],nums[vec[i].second], nums[c], nums[d]});
                }
            }       
        }
        sort(result.begin(), result.end());
        result.erase(unique(result.begin(), result.end()), result.end());
        return result;
    }
};
/*
1. 判断size
	2. Sort
	3. create a cache for temperary storage 
	4. store all a+b to the cache as the key and pair<a,b> as the value vectors in the map 
	5. calculate the difference between target - sum(a,b) - c - d (d=c+1 to the end 夹逼法)
	6. 注意比较push back 到result的时候，a,b 必须必c小从而避免重叠，确保the result vector is in the increasing order
	7. erase()//Removes from the vector either a single element (position) or a range of elements ([first,last)).
*/
// faster method:
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (int i=0; i<nums.size(); i++) {
            if (i>0 && nums[i-1] == nums[i]) continue;
            for (int j=i+1; j<nums.size(); j++) {
                if (j>i+1 && nums[j-1] == nums[j]) continue;
                int left=j+1, right=nums.size()-1;
                while(left<right) {
                    int sum = nums[i] + nums[j] + nums[left] + nums[right];
                    if (sum == target) {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});
                        while(left<right && nums[left] == nums[left+1]) left++;
                        while(left<right && nums[right] == nums[right-1]) right--;
                        left++;
                        right--;
                    }
                    else if (sum < target) left++;
                    else right--;
                }
            }
        }
        return result;
    }
};
//method 2
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        if (nums.size() < 4) return res;
        
        std::sort(nums.begin(), nums.end());
        for (int k = 0; k < nums.size()-3; ++k){
            if (k-1 >= 0 && nums[k-1]==nums[k]) continue;
            
            for (int kk=k+1; kk < nums.size()-2; ++kk){
                if (kk-1 >= k+1 && nums[kk-1] == nums[kk]) continue;
                
                int i = kk+1;
                int j = nums.size()-1;
                
                int new_target = target - nums[k] - nums[kk];
                while(i < j){
                    if (nums[i]+nums[j] == new_target){
                        vector<int> solution{nums[k], nums[kk], nums[i], nums[j]};
                        res.push_back(solution);
                        while(i<j && i+1 <= j-1 && nums[i] == nums[i+1]) i++;   //去重时i+1的最大值为j-1
                        while(i<j && j-1 >= i+1 && nums[j-1] == nums[j]) j--;
                        
                        i++;
                        j--;
                        
                    } else if (nums[i]+nums[j] < new_target){
                        i++;
                    } else {
                        j--;
                    }
                }
            }
        }
        
        return res;
    }
};