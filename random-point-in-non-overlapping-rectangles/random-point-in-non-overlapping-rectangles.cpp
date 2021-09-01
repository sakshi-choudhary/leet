class Solution {
public:
    // helper variables and functions
    vector<int> cumulativeAreas;
    vector<vector<int>> rs;

    int getArea(vector<int> &r) {
        return (r[3] - r[1] + 1) * (r[2] - r[0] + 1);
    }
    
    int randint(int a, int b) {
        // random number from a to b, both included
		return rand() % (b - a + 1) + a;
    }
    
    vector<int> getRandomPoint(vector<int> r) {
        return {randint(r[0], r[2]), randint(r[1], r[3])};
    }
    
    Solution(vector<vector<int>>& rects) {
        // sending rand
        srand(time(NULL));
        // storing rects and rects data
        rs = rects;
        // populating cumulativeAreas
        cumulativeAreas.resize(rs.size());
        cumulativeAreas[0] = getArea(rs[0]);
        for (int i = 1; i < rs.size(); i++) cumulativeAreas[i] = cumulativeAreas[i - 1] + getArea(rs[i]);
    }
    
    vector<int> pick() {
        int currRect = upper_bound(begin(cumulativeAreas), end(cumulativeAreas), rand() % cumulativeAreas.back()) - begin(cumulativeAreas);
        return getRandomPoint(rs[currRect]);
    }
};