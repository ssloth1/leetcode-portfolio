// Leetcode Problem: 1. Two Sum - https://leetcode.com/problems/two-sum/
// James Bebarski - Submission
// Easy Difficulty
// Array Tag

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    
    // Allocate memory for the twoSumArray.
    int* twoSumArray = (int*)malloc(2* sizeof(int));

    // Loop through all pairs of different elements in the given array.
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            // Check if the sum of the pair is equal to the given target.
            if (nums[i] + nums[j] == target) {
                // If the pair's sum is equal to the target, we store the indices of the pair.
                twoSumArray[0] = i;
                twoSumArray[1] = j;
                *returnSize = 2; // Our return size will be two.
                return twoSumArray; // Return the result array.
            }
        }
    }
    return 0;
}