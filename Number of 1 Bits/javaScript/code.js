/**
 * @param {number} n
 * @return {number}
 */
var hammingWeight = function(n) {
    let counter = 0;
    let size = 32;

    for (let i = 0; i < size; i++) {
        if ((n & 1) === 1) {
            counter++;
        }
        n = n >> 1;
    }

return counter;    
};
