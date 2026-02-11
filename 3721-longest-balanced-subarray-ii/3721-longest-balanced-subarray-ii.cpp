class Solution {
public:
    struct Smart{
        int n;
        vector<int> arr;
        Smart(int _n){
            n = _n;
            arr  = vector<int>(n, 0);
        }
        void update(int pos, int newval){
            arr[pos] = newval;
        }
        int query(int x){
            if(x == 0) return -1;
            int sum = 0;
            for(int i = 0; i < n; i ++){
                sum += arr[i];
                if(sum == x){
                    return i;
                }
            }
            return n;
        }
    };
    
    int longestBalanced(vector<int>& nums) {
        int n = (int)nums.size();
        int m = 0;
        for(auto x : nums) m = max(m, x);
        m += 1;
        
        vector<int> lastPos(m, -1);
        Smart S(n);
        int sum = 0;
        int ans = 0;
        for(int i = 0; i < n; i ++){
            if(lastPos[nums[i]] != -1){
                S.update(lastPos[nums[i]], 0);
            }
            else{
                if(nums[i] % 2){
                    sum += 1;
                }
                else{
                    sum -= 1;
                }
            }
            lastPos[nums[i]] = i;
            if(nums[i] % 2){
                S.update(i, +1);
            }
            else{
                S.update(i, -1);
            }
            
            int p = S.query(sum);
            
            ans = max(ans, i - p);
        }
        return ans;
    }
};