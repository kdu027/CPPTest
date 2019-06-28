class Solution {
public:
    string getPermutation(int n, int k) {
        string result;
        string num = "123456789";
        vector<int> f(n,1);
        //calculate factorials
        for(int i = 1; i<n; ++i){
            f[i] = i * f[i-1];
        }
        // change k to become index
        k--;
        
        //calculate the highest index
        for(int i = n; i>0; i--){
            int index = k/f[i-1];
            k = k%f[i-1];
            result.push_back(num[index]);
            num.erase(index,1);
        }
        return result;
    }
};