class Solution {
public:
    string addBinary(string a, string b) {
        int size = max(a.size(), b.size());
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        string result;
        int carry=0;
        for (int i = 0; i<size; i++){
            int ia = (i<a.size())?a[i]-'0' : 0;
            int ib = (i<b.size())?b[i]-'0' : 0;
            const int val = (ia+ib+carry)%2;
            carry = (ia+ib+carry)/2;
            result.insert(result.begin(), val + '0');
        }
        if (carry == 1) result.insert(result.begin(), '1');
        return result;
    }
};