// Leetcode Problem: 26. Remove Duplicates from Sorted Array - https://leetcode.com/problems/remove-duplicates-from-sorted-array/
// James Bebarski - Submission
// Easy Difficulty
// Array Tag

int removeDuplicates(int* nums, int numsSize){
    
    // Check if the input array is empty, return 0 if it is.
    if (numsSize == 0) {
        return 0;
    }

    int i = 0; // Utilize i to keep track of unique elements. 
    
    for (int j = 1; j < numsSize; j++) {
        // If the current element is different than the previous unique element,
        // we need to update the previous unique element and move to the next element. 
        if (nums[j] != nums[i]) {
            i++; // Increment the index of the last unique element.
            nums[i] = nums[j]; // Overite the duplicate with the unique element 
        }
    }
    return i + 1; // Return the length of the subarray containing the unique elements. 
}