class Solution {
public:
    typedef pair<double, pair<int, int>> P;

    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();

        priority_queue<P> pq;

        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {

                pq.push({1.0 * arr[i] / arr[j], {arr[i], arr[j]}});

                if (pq.size() > k) {
                    pq.pop();
                }
            }
        }

        auto top = pq.top();

        int x = top.second.first;
        int y = top.second.second;

        return {x, y};
    }
};