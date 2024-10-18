class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int size = matrix.size();


        vector<vector<int>>::iterator it = matrix.begin();

        while (it != matrix.end()) {

            vector<int>::iterator it2 = (*it).begin();
            
            while (it2 != (*it).end()) {
                if ((*it2) == target)
                    return true;
                it2++;
            }
            it++;
        }

        return false;
    }
};