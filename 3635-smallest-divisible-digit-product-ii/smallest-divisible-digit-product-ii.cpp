class Solution {
public:
    string smallestNumber(string num, long long t) {

        // Check whether t can be represented using digits 2..9
        long long x = t;

        for (int d = 2; d <= 9; ++d) {
            while (x % d == 0) {
                x /= d;
            }
        }

        if (x != 1) {
            return "-1";
        }

        int len = num.size();

        vector<long long> remaining(len + 1);
        remaining[0] = t;

        int start = len - 1;

        for (int i = 0; i < len; ++i) {

            if (num[i] == '0') {
                start = i;
                break;
            }

            long long digit = num[i] - '0';
            remaining[i + 1] =
                remaining[i] / gcd(remaining[i], digit);
        }

        // The given number already satisfies the condition
        if (remaining[len] == 1) {
            return num;
        }

        // Try increasing the number from right to left
        for (int i = start; i >= 0; --i) {

            while (++num[i] <= '9') {

                long long need =
                    remaining[i] /
                    gcd(remaining[i], num[i] - '0');

                int digit = 9;

                for (int j = len - 1; j > i; --j) {

                    while (need % digit != 0) {
                        --digit;
                    }

                    need /= digit;
                    num[j] = char('0' + digit);
                }

                if (need == 1) {
                    return num;
                }
            }
        }

        // Construct the smallest number from the prime factors of t
        string result;

        for (int digit = 9; digit >= 2; --digit) {
            while (t % digit == 0) {
                result.push_back(char('0' + digit));
                t /= digit;
            }
        }

        result += string(
            max(len + 1 - (int)result.size(), 0),
            '1'
        );

        ranges::reverse(result);

        return result;
    }
};