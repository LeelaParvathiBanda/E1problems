#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 1000

// Function to find and print all triplets with zero sum
void findTriplets(int arr[], int n) {
    bool found = false;

    for (int i = 0; i < n - 1; i++) {
        // Initialize a hash table (array) to store elements
        int hashTable[MAX] = {0};
        
        for (int j = i + 1; j < n; j++) {
            int x = -(arr[i] + arr[j]);
            
            // Check if x is in hashTable
            if (x >= -MAX/2 && x <= MAX/2 && hashTable[x + MAX/2] == 1) {
                printf("%d %d %d\n", x, arr[i], arr[j]);
                found = true;
            } else {
                // Store arr[j] in hashTable
                if (arr[j] >= -MAX/2 && arr[j] <= MAX/2) {
                    hashTable[arr[j] + MAX/2] = 1;
                }
            }
        }
    }

    if (!found) {
        printf("No Triplet Found\n");
    }
}

// Driver code
int main() {
    int arr[] = {0, -1, 2, -3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    findTriplets(arr, n);
    return 0;
}
