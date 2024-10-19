class Solution {
    std::array<std::array<std::string, 10>, 4> Numbers{{
        {
            "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"
        },
        {
            "", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"
        },
        {
            "", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"
        },
        {
            "Hundred", "Thousand", "Million", "Billion"
        }
    }};
    
    std::string handleThreeNumbers(int num) {
        std::string result;

        int hundreds = num / 100;
        int remainder = num % 100;
        int tens = remainder / 10;
        int ones = remainder % 10;

        if (hundreds) {
            result += Numbers[0][hundreds] + " " + Numbers[3][0] + " ";
        }

        if (remainder >= 11 && remainder <= 19) {
            result += Numbers[2][remainder - 10] + " ";
        } else {
            if (tens > 1) {
                result += Numbers[1][tens] + " ";
            }

            if (ones == 0 && tens == 1)
                result += "Ten";
            if (ones > 0 || tens == 1) {
                result += Numbers[0][ones] + " ";
            }
        }

        return result;
    }

public:
    std::string numberToWords(int num) {
        if (num == 0) return "Zero";

        std::string result;

        int billion = num / 1000000000;
        int million = (num / 1000000) % 1000;
        int thousand = (num / 1000) % 1000;
        int remainder = num % 1000;

        if (billion) {
            result += handleThreeNumbers(billion) + "Billion ";
        }
        if (million) {
            result += handleThreeNumbers(million) + "Million ";
        }
        if (thousand) {
            result += handleThreeNumbers(thousand) + "Thousand ";
        }
        if (remainder) {
            result += handleThreeNumbers(remainder);
        }

        if (!result.empty() && result.back() == ' ') {
            result.pop_back();
        }

        return result;
    }
};
