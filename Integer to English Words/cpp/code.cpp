class Solution {

        std::array<std::array<string, 10>, 4> ZeroToTeen{{
            {
                "One",
                "Two",
                "Three",
                "Four",
                "Five",
                "Six",
                "Seven",
                "Eight",
                "Nine",
            },
            {
                "Ten",
                "Twenty",
                "Thirty",
                "Forty",
                "Fifty",
                "Sixty",
                "Seventy",
                "Eighty",
                "Ninety"
            },
            {
                "Eleven",
                "Twelve",
                "Thirteen",
                "Fourteen",
                "Fifteen",
                "Sixteen",
                "Seventeen",
                "Eighteen",
                "Nineteen"
            },
            {
                "Hundred",
                "Thousand",
                "Million",
                "Billion"
            }
        }};



        string HandelThreeNUmbers(int num, int DigitSize) {
            string nums;

            int index = 0;
            while (num) {
                if (index < 2)
                    nums = ZeroToTeen[index][num%10 - 1] + " " + nums;
                else
                    nums = ZeroToTeen[0][num%10 - 1] + " " + ZeroToTeen[index + 1][0] + " " + nums;
                num = num / 10;
                index++;
            }
            nums.erase(nums.begin() + (nums.size() - 1));
            return nums;
        };

        int getSize(int num) {
            int i = 0;

            while (num) {
                num = num / 10;
                i++;
            }
            return i;
        };
        
    public:
        string numberToWords(int num) {
            string Numbers;
            int DigitSize = getSize(num);

            if (DigitSize <= 3)
                Numbers = HandelThreeNUmbers(num, DigitSize);
            return Numbers;
        }
};