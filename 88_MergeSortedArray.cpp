class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // find the size of two array
        int size = m + n;
        int a = m-1; 
        int b = n-1;
        for (int i = size-1; i>=0; i--){
            if(a >=0 && b >=0){
                if (nums1[a] <= nums2[b]){
                    nums1[i] = nums2[b];
                    b--;
                }else {
                    nums1[i] = nums1[a];
                    a--;
                }
            } else if(a>=0 && b<0){
                nums1[i] = nums1[a];
                a--;
            } else if(a<0 && b>=0){
                nums1[i] = nums2[b];
                b--;
            } else {
                break;
            }
        }
        return;
    }
};