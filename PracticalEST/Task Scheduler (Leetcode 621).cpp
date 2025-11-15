class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if (tasks.empty()) return 0;

        int counts[26] = {0};
        for (char c : tasks) {
            counts[c - 'A']++;
        }

        int maxCount = 0;
        for (int i = 0; i < 26; ++i) {
            if (counts[i] > maxCount) maxCount = counts[i];
        }

        int maxCountTasks = 0;
        for (int i = 0; i < 26; ++i) {
            if (counts[i] == maxCount) ++maxCountTasks;
        }

        // parts between the most frequent tasks
        int partCount = maxCount - 1;            // number of full parts
        int partLength = n + 1;                  // each part length (task + n slots)
        int minSlots = partCount * partLength + maxCountTasks;

        return max((int)tasks.size(), minSlots);
    }
};
