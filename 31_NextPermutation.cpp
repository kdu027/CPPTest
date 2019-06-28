class Solution {
public:
    void nextPermutation(vector<int> &num) {
        if(num.size()<2) return;
        int n = num.size(), j = n-2;
        while(j>=0 && num[j]>=num[j+1]) j--;
        
        if(j<0) {
            sort(num.begin(),num.end());
            return;
        } 
        
        int i=j+1;
        while(i<n && num[i]>num[j]) i++;
        i--;
        
        swap(num[i],num[j]);
        sort(num.begin()+j+1, num.end());
    }
};


//====================
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size()<2) return;
        int j = nums.size()-2;
        while(j>=0 && nums[j]>=nums[j+1]) --j;
        if (j<0){
            reverse(nums.begin(), nums.end());
            return;
        }
        int i = nums.size()-1;
        while(i>j && nums[j]>=nums[i]) i--; 
        
        swap(nums[j], nums[i]);
        reverse(nums.begin()+j+1, nums.end());
        return;
    }
};
/*
    1. track the array from right to left and check if it is in ascending order and find the first one violate the increasing trend 
    2. if it is always in the ascending order from right to left, reverse the array
    3. if we find the first violate element in the array, nums[i], find the first element in nums[i+1:end] (right to left) which is greater than nums[i], let's represent it as nums[j]
    4. swap(nums[i] and nums[j])
    5. reverse(nums[i+1], end)
*/