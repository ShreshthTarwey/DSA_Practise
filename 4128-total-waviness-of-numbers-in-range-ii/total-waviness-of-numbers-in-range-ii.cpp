class Solution {
public:
    string s;
    int n;
    long long dpTotalNumbers[16][10][10];
    long long dpTotalWaviness[16][10][10];
    pair<long long, long long> solve(int curr, int prevPrev, int prev,
                                     bool isLimitedWithActualNumber,
                                     bool isLeadingZero) {
        if (curr == n) {
            return {1, 0};
        }
        if (!isLeadingZero && !isLimitedWithActualNumber && prev >= 0 &&
            prevPrev >= 0) {
            if (dpTotalWaviness[curr][prevPrev][prev] != -1) {
                return {dpTotalNumbers[curr][prevPrev][prev], dpTotalWaviness[curr][prevPrev][prev]};
            }
        }
        long long totalNumbers = 0;
        long long totalWaveScore = 0;
        int limitDigit = isLimitedWithActualNumber ? s[curr] - '0' : 9;
        for (int digit = 0; digit <= limitDigit; digit++) {
            bool isNewLeadingZero = isLeadingZero && digit == 0;
            int newPrevPrev = prev;
            int newPrev = isNewLeadingZero ? -1 : digit;
            auto [remainingTotalNumbers, remainingTotalWaveScore] =
                solve(curr + 1, newPrevPrev, newPrev,
                      (isLimitedWithActualNumber && digit == limitDigit),
                      isNewLeadingZero);
            if (!isLeadingZero && prev >= 0 && prevPrev >= 0) {
                bool isPeak = (prev > prevPrev && prev > digit);
                bool isValley = (prev < prevPrev && prev < digit);

                if (isPeak || isValley) {
                    totalWaveScore += remainingTotalNumbers;
                }
            }
            totalWaveScore += remainingTotalWaveScore;
            totalNumbers += remainingTotalNumbers;
        }
        if (!isLeadingZero && !isLimitedWithActualNumber && prev >= 0 &&
            prevPrev >= 0) {
                dpTotalNumbers[curr][prevPrev][prev] = totalNumbers;
                dpTotalWaviness[curr][prevPrev][prev] = totalWaveScore;
        }
        return {totalNumbers, totalWaveScore};
    }
    long long func(long long num) {
        if (num < 100) {
            return 0;
        }
        memset(dpTotalNumbers, -1, sizeof(dpTotalNumbers));
        memset(dpTotalWaviness, -1, sizeof(dpTotalWaviness));
        s = to_string(num);
        n = s.length();
        auto [totalNumbers, totalWaveScore] = solve(0, -1, -1, true, true);
        return totalWaveScore;
    }
    long long totalWaviness(long long num1, long long num2) {
        return func(num2) - func(num1 - 1);
    }
};