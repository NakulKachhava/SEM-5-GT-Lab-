#include <stdio.h>
#include <math.h>

void printSubsets(int set[], int set_size) {
    // Total number of subsets is 2^set_size
    unsigned int pow_set_size = 1 << set_size; 

    // Run from counter 000..0 to 111..1
    for (int counter = 1; counter < pow_set_size; counter++) {
        printf("{ ");
        for (int j = 0; j < set_size; j++) {
            // Check if jth bit in the counter is set
            if (counter & (1 << j)) {
                printf("%d ", set[j]);
            }
        }
        printf("}\n");
    }
}

int main() {
    int mySet[] = {1, 2, 3};
    printSubsets(mySet, 3);
    return 0;
}
