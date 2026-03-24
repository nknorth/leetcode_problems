class Solution {
public:
    vector<vector<int>> subsets(vector<int>& arr) {
         int n = arr.size();
    vector<vector<int>> result;
    for (int j = 0; j < (1 << n); j++) {
        vector<int> subset;

        for (int i = 0; i < n; i++) {
            if (j & (1 << i)) {
                subset.push_back(arr[i]);
            }
        }

        result.push_back(subset);
    }

    return result;
    }
};