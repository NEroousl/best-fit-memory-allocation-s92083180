#include<stdio.h>

int main() {
    int numBlocks, blockSizes[100], numProcesses, processSizes[100], i, j, allocations[100], remainingMemory[100], bestFitBlockIndex;

    printf("BEST-FIT algorithm by s92083180 for EEX5563 MP\n\n");
    printf("Enter the number of available memory blocks: ");
    scanf("%d", &numBlocks);
    printf("Enter the size of each memory block: \n");
    for(i = 0; i < numBlocks; i++) {
        printf("Size of block %d: ", i + 1);
        scanf("%d", &blockSizes[i]);
    }

    printf("Enter the number of processes: ");
    scanf("%d", &numProcesses);
    printf("Enter the size of each process: \n");
    for(i = 0; i < numProcesses; i++) {
        printf("Size of process %d: ", i + 1);
        scanf("%d", &processSizes[i]);
    }

    // Initialize the allocations to -1 (no allocation yet)
    for(i = 0; i < numProcesses; i++) {
        allocations[i] = -1;
    }

    // Best Fit allocation for each process
    for(i = 0; i < numProcesses; i++) {
        bestFitBlockIndex = -1;

        for(j = 0; j < numBlocks; j++) {
            if(blockSizes[j] >= processSizes[i] && blockSizes[j] != -1) {
                if(bestFitBlockIndex == -1 || blockSizes[j] - processSizes[i] < blockSizes[bestFitBlockIndex] - processSizes[i]) {
                    bestFitBlockIndex = j;
                }
            }
        }

        if(bestFitBlockIndex != -1) {
            allocations[i] = bestFitBlockIndex;
            blockSizes[bestFitBlockIndex] -= processSizes[i];  // Decrease block size by process size
        }
    }

    // Display the allocation results
    printf("\nAllocation Results:\n");
    for(i = 0; i < numProcesses; i++) {
        if(allocations[i] != -1)
            printf("Process %d of size %d --> Block %d\n", i + 1, processSizes[i], allocations[i] + 1);
        else
            printf("Process %d of size %d --> is not allocated\n", i + 1, processSizes[i]);
    }

    // Display the remaining memory in each block
    printf("\nRemaining memory in each block:\n");
    for(i = 0; i < numBlocks; i++) {
        printf("Remaining size of block %d: %d\n", i + 1, blockSizes[i]);
    }

    return 0;
}
