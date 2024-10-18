class Solution {

/**
 * @param Integer $n
 * @return Integer
 */
function hammingWeight($n) {
    $counter = 0;
    $size = 32;
    
    for ($i = 0; $i < $size; $i++) {
        if (($n & 1) == 1) {
            $counter++;
        }
        $n = $n >> 1;
    }
    
    return $counter;
}
}
