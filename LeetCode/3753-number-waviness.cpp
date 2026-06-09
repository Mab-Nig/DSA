#include <bits/stdc++.h>

#define MAX_NDIGIT 16

class Solution {
public:
  int64_t totalWaviness(int64_t num1, int64_t num2) {
    memset(save, -1, sizeof(save));

    m_num_digits = 0;
    while (num2) {
      m_digits[1][m_num_digits++] = num2 % 10;
      num2 /= 10;
    }
    int num_digits = 0;
    while (num1) {
      m_digits[0][num_digits++] = num1 % 10;
      num1 /= 10;
    }
    for (int i = num_digits; i < m_num_digits; ++i) {
      m_digits[0][i] = 0;
    }
    std::reverse(m_digits[0], m_digits[0] + m_num_digits);
    std::reverse(m_digits[1], m_digits[1] + m_num_digits);

    return dp(0, 0, 0, 1, 1, 0, PLATEAU);
  }

private:
  enum Trend { PLATEAU, RISING, FALLING };

  int64_t dp(
    int idx,
    int prev_digit,
    int num_waves,
    bool is_bottom,
    bool is_top,
    bool is_start,
    Trend trend
  ) {
    int64_t &result =
      save[idx][prev_digit][num_waves][is_bottom][is_top][is_start][trend];

    if (result >= 0) {
      return result;
    }
    if (idx >= m_num_digits) {
      return result = num_waves;
    }

    int low = (is_bottom ? m_digits[0][idx] : 0);
    int high = (is_top ? m_digits[1][idx] : 9);

    result = 0;
    for (int digit = low; digit <= high; ++digit) {
      Trend ntrend;
      if (!is_start) {
        ntrend = PLATEAU;
      } else {
        ntrend =
          (digit == prev_digit ? PLATEAU
                               : (digit < prev_digit ? FALLING : RISING));
      }

      bool nis_start = (is_start || digit > 0);
      bool nis_bottom = (is_bottom && digit == m_digits[0][idx]);
      bool nis_top = (is_top && digit == m_digits[1][idx]);
      bool is_wave =
        ((trend == RISING && ntrend == FALLING) ||
         (trend == FALLING && ntrend == RISING));

      m_num += '0' + digit;
      result += dp(
        idx + 1,
        digit,
        num_waves + is_wave,
        nis_bottom,
        nis_top,
        nis_start,
        ntrend
      );
      m_num.pop_back();
    }
    return result;
  }

private:
  static int64_t save[MAX_NDIGIT + 1][10][MAX_NDIGIT + 1][2][2][2][3];
  int m_num_digits, m_digits[2][MAX_NDIGIT];
  int m_wave_cnt = 0;
  std::string m_num;
};

int64_t Solution::save[MAX_NDIGIT + 1][10][MAX_NDIGIT + 1][2][2][2][3];

int main(void) {
  // clang-format off
  static const int64_t tests[] = {
    120, 130,
    198, 202,
    4848, 4848
  };
  // clang-format on
  Solution sol;
  for (int i = 0; i < sizeof(tests) / sizeof(tests[0]); i += 2) {
    std::cout << sol.totalWaviness(tests[i], tests[i + 1]) << '\n';
  }
}
