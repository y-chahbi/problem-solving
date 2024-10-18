/**
 * @param {number[]} nums
 * @return {number}
 */
var removeDuplicates = function(nums) {
    if (nums.length === 0) {
        return 0;
    }

    let co = 1; 
    for (let i = 1; i < nums.length; i++) {
        if (nums[i] !== nums[co - 1]) {
            nums[co] = nums[i];
            co++;
        }
    }

    return co;
};