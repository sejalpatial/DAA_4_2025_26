# Algorithm: Distinct Subsequences (Dynamic Programming)

## Problem
Given two strings `s` and `t`, return the number of distinct subsequences of `s` which equals `t`.

---

## Approach
We use **Dynamic Programming (DP)** to count the number of ways to form string `t` from string `s`.

---

## Steps

1. **Initialize Variables**
   - Let `m = length of s`
   - Let `n = length of t`

2. **Create DP Table**
   - Create a 2D array `dp` of size `(m + 1) × (n + 1)`
   - `dp[i][j]` represents the number of ways to form `t[0...j-1]` from `s[0...i-1]`

3. **Base Case**
   - For all `i`, set `dp[i][0] = 1`
     - (An empty string `t` can always be formed from any prefix of `s`)

4. **Fill DP Table**
   - Loop through `i` from `1` to `m`
   - Loop through `j` from `1` to `n`
   
   - If characters match:
     ```
     if s[i - 1] == t[j - 1]:
         dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j]
     ```
     - Include current character OR exclude it

   - If characters do not match:
     ```
     dp[i][j] = dp[i - 1][j]
     ```
     - Only exclude current character

5. **Final Answer**
   - Return `dp[m][n]`

---

## Time Complexity
- **O(m × n)**

## Space Complexity
- **O(m × n)**

---

## Key Insight
- At each step, we decide whether to:
  - Use the current character from `s`
  - Or skip it
- This forms overlapping subproblems → solved using DP