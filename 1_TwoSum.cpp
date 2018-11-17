class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int, int> map;
        vector<int> result;
        //create a hash table [value, index]
        for (int i=0; i<nums.size(); i++) map[nums[i]]=i;
        for (int i=0; i<nums.size(); i++) {
            int gap = target - nums[i];
            if (map.find(gap) != map.end() && map[gap] > i){
                result.push_back(i);
                result.push_back(map[gap]);
                break;
            }
        }
        return result;
    }
};