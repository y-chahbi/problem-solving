
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> returnn;

        vector<int>::iterator it = nums.begin();
        int indexOne = 0;
        int indexTow = 0;

        while (it != nums.end()) {
            vector<int>::iterator its = it + 1;
            indexTow = indexOne + 1;
            while (its != nums.end()) {
                if (*it + *its == target)
                {
                    returnn.push_back(indexOne);
                    returnn.push_back(indexTow);
                    return returnn;
                }
                its++;
                indexTow++;
            }
            it++;
            indexOne++;
        }
        return returnn;
    }
};