//Binary search (fastest one)
static int _ = []() {
    cout.sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
private:
    int skip_inc(vector<int> &nums, int i, int end) {
        while (i + 1 < end && nums[i] == nums[i+1]) ++i;
        return i + 1;
    }
    
    int skip_dec(vector<int> &nums, int i, int end) {
        while (end < i - 1 && nums[i] == nums[i-1]) --i;
        return i - 1;
    }
    
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), prev = INT_MAX;
        int ans = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < n; ++i) {
            if (prev == nums[i])
                continue;
            prev = nums[i];
            int lo = i + 1, hi = n - 1;
            while (lo < hi) {
                int sum = nums[i] + nums[lo] + nums[hi];
                if (sum == target)
                    return target;
                
                if (abs(sum - target) < abs(ans - target))
                    ans = sum;
                
                if (sum < target)
                    lo = skip_inc(nums, lo, hi);
                else
                    hi = skip_dec(nums, hi, lo);
            }
        }
        return ans;
    }
};
// myself 
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int result = 0;
        int min_gap = INT_MAX;
        if (nums.size()<3) return result;
        sort(nums.begin(), nums.end());
        for (auto i = nums.begin(); i!= nums.end()-2; ++i){
            auto j = i+1, k = nums.end()-1;
            while(j<k){
                int sum = *i + *j + *k;
                int gap = abs(target - sum);
                if (gap == 0){
                    return target;
                } 
                if(gap < min_gap){
                    min_gap = gap;
                    result = sum;     
                } 
                if (sum < target){
                    ++j;
                }else{
                    --k;
                }
            }
        }
        return result;
    }
};