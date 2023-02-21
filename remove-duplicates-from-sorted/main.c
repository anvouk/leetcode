#include <stdio.h>
#include <string.h>

#define MAX 30000

int removeDuplicates(int *nums, int numsSize)
{
    int new_nums[MAX];
    int new_sz = 0;

    int last_el = nums[0];
    new_nums[new_sz++] = last_el;
    for (int i = 1; i < numsSize; ++i) {
        int curr_el = nums[i];
        if (curr_el != last_el) {
            new_nums[new_sz++] = curr_el;
            last_el = curr_el;
        }
    }

    memcpy(nums, new_nums, sizeof(int) * new_sz);
    return new_sz;
}

#define SZ(x) (sizeof((x)) / sizeof((x)[0]))

/* https://leetcode.com/problems/remove-duplicates-from-sorted-array/ */
int main(void)
{
    int nums[] = { 1, 1, 2 };
    int new_sz = removeDuplicates(nums, SZ(nums));
    printf("sz: %d\n", new_sz);
    for (int i = 0; i < new_sz; ++i) {
        printf("nums[%d]: %d\n", i, nums[i]);
    }
    return 0;
}
