// C++ program to demonstrate iterators

#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        const int m = nums1.size();
        const int n = nums2.size();
        int total = m+n;
        if (total & 0X1) //if it is odd
        {
            return findKthValue(nums1.begin(), m, nums2.begin(), n, (total+1)/2);
        } else { //if it is even
            return (findKthValue(nums1.begin(), m, nums2.begin(), n, total/2)+findKthValue(nums1.begin(), m, nums2.begin(), n, (total/2)+1))/2.0;
        }
    }
private:
    static int findKthValue(std::vector<int>::const_iterator A,int m, std::vector<int>::const_iterator B, int n, int k){
        if (m > n) findKthValue(B,n,A,m,k);
        if (m == 0) return *(B+k-1);
        if (k == 1) return std::min (*A, *B);
        int ia = std::min (k/2, m), ib = k-ia;
        if (*(A+ia-1) < *(B+ib-1)){
            return findKthValue((A+ia),m-ia,B,n,k-ia);
        } else if (*(A+ia-1) > *(B+ib-1)){
            return findKthValue(A,m,(B+ib),n-ib,k-ib);
        } else {
            return *(A+ia-1);
        }
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums1 = stringToIntegerVector(line);
        getline(cin, line);
        vector<int> nums2 = stringToIntegerVector(line);
        
        double ret = Solution().findMedianSortedArrays(nums1, nums2);
        
        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
