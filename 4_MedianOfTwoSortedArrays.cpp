//myself
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size(), size2 = nums2.size(), total = nums1.size() + nums2.size();
        if (total & 0x01){ //odd number
            return find_kth(nums1.begin(), size1, nums2.begin(), size2, total/2+1);
        } else { //even number
            return (find_kth(nums1.begin(), size1, nums2.begin(), size2, total/2) + find_kth(nums1.begin(), size1, nums2.begin(), size2, (total/2+1)))/2.0;
        }    
    }
    
    int find_kth(std::vector<int>::const_iterator A, int size1, std::vector<int>::const_iterator B, int size2, int k){
        //assume size1 < size2
        if (size1 > size2) return find_kth(B, size2, A, size1, k);
        if (size1 == 0) return *(B+k-1);
        if (k == 1) return min(*A, *B);
        
        //divie the kth vector
        int ia = min(k/2, size1), ib = k-ia;
        if(*(A+ia-1) < *(B+ib-1)) return find_kth(A+ia, size1-ia, B, size2, k-ia);
        else if (*(A+ia-1) > *(B+ib-1)) return find_kth(A, size1, B+ib, size2-ib, k-ib);
        else return *(A+ia-1);
    }
};
//faster way
static auto x = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();
class Solution {
public:
    double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
      const int n1 = A.size(), n2 = B.size();
      
      if (n1 > n2) return findMedianSortedArrays(B, A);
      
      const int k = (n1 + n2 + 1) / 2;
      int l = 0, r = n1;
      while (l < r) {
        const int m1 = l + (r - l) / 2, m2 = k - m1;
        if (A[m1] < B[m2 - 1])
          l = m1 + 1;
        else
          r = m1;
      }
      
      const int m1 = l, m2 = k - l;
      const int c1 = max(m1 <= 0 ? INT_MIN : A[m1 - 1],
                         m2 <= 0 ? INT_MIN : B[m2 - 1]);
      if ((n1 + n2) & 1)
        return c1;
      
      const int c2 = min(m1 >= n1 ? INT_MAX : A[m1],
                         m2 >= n2 ? INT_MAX : B[m2]);
      
      return (c1 + c2) * 0.5;
    }
};