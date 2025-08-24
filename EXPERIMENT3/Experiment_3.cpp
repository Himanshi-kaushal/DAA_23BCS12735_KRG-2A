class Solution {
  public:
    vector<vector<int>> countFreq(vector<int>& arr) {
        
        map<int, int> freq;

        for (int num : arr) {
            freq[num]++;
        }

        vector<vector<int>> result;
        for (auto &p : freq) {
            result.push_back({p.first, p.second});
        }

        return result;
    }
};
