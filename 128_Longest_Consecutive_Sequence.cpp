//way1:
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //initialize the used map
        unordered_map<int, bool> used;
        int longest = 0;
        for (auto i : nums) used[i]=false;
        for (auto i:nums){
            int length = 1; //length 从1开始！
            if (used[i]) continue;
            used[i]=true; //不能忘了把当前iterator变成true！
            //从i向后找连续的下一个数,一个一个iterate
            //way 1:use for loop
          /*  for (int j=i+1; used.find(j)!=used.end();j++){ //注意条件是找到，如果没找到就return null pointer
                used[j]=true;
                length++;
            }
            //从i向前找连续的下一个数,一个一个iterate
            for (int j=i-1; used.find(j)!=used.end();j--){
                used[j]=true;
                length++;
            }
            */
            //way 2: use while loop
            auto j=i+1;
            while(used.find(j)!=used.end()){
                used[j]=true;
                length++;
                j++;
            }
            j=i-1;
            while(used.find(j)!=used.end()){
                used[j]=true;
                length++;
                j--;
            }
            longest = max(length, longest);
        }
        return longest;
    }
};
//way2:
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map <int, int> map;
        int l=1;
        for (int i=0; i<nums.size(); i++){
            if(map.find(nums[i]) != map.end()) continue;
            map[nums[i]]=1;
            if (map.find(nums[i]-1) != map.end()){
                l=max(l, mergeCluster(map, nums[i]-1, nums[i]));
            }
            if (map.find(nums[i]+1) != map.end()){
                l=max(l, mergeCluster(map,nums[i],nums[i]+1));
            }
        }
        return nums.size() == 0 ? 0:l;
    }
private: 
    int mergeCluster(unordered_map <int, int>& map,int left, int right){
        int upper = right + map[right] - 1;
        int lower = left - map[left] + 1;
        int length = upper - lower + 1;
        map[upper] = length;
        map[lower] = length;
        return length;
    }
};