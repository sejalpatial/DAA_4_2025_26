# Minimum Subset Sum Difference

## Step 1: Calculate Total Sum
Traverse the array and compute the sum of all elements. Let this be `totalSum`.

## Step 2: Define Target
To minimize the difference between two subsets, we aim to find a subset whose sum is as close as possible to `totalSum / 2`.  
Let this value be `target`.

## Step 3: Define Recursive Function
Create a function:
helper(index, target)

This function returns the minimum remaining value of the target after considering elements from the current index onward.

## Step 4: Base Case
If the index reaches the size of the array, return the current `target` value.  
This represents the leftover sum that could not be formed.

## Step 5: Memoization
Use a 2D array:


dp[index][target]


to store results of subproblems.  
If a value is already computed, return it directly to avoid recomputation.

## Step 6: Recursive Choices
For each element, there are two choices:

- **Include the current element**  
  If `arr[index] <= target`, recursively call:

helper(index + 1, target - arr[index])


- **Exclude the current element**  

helper(index + 1, target)


## Step 7: Store Result
Store the minimum of the two choices:


dp[index][target] = min(pick, notPick)


## Step 8: Compute Final Answer
After the recursion completes:

- Remaining value:

remaining = helper(0, target)


- First subset sum:

subset1 = target - remaining


- Second subset sum:

subset2 = totalSum - subset1


- Minimum difference:

subset2 - subset1


## Time Complexity

O(n × target)


## Space Complexity

O(n × target) (DP table)
O(n) (recursion stack)