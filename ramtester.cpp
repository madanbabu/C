# Lord Madan Babu
# ANSI C Ram tester at 1MB chunks


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TEST_SIZE (1024 * 1024) // 1MB test size

void test_ram() 
{
    void* ptr = malloc(TEST_SIZE);
    if (!ptr) 
    {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }

    // Initialize memory
    unsigned char* data = ptr;
    for (size_t i = 0; i < TEST_SIZE; i++) 
    {
        data[i] = rand() & 255;
    }

    // Measure execution time
    clock_t start = clock();

    // Perform operations on the allocated memory
    for (size_t i = 0; i < 1000000; i++) 
    {
        // Simple arithmetic operation
        *(data + (i * 4)) += 1;
    }

    clock_t end = clock();

    // Free the allocated memory
    free(ptr);

    // Calculate and print execution time
    double elapsed = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Test completed in %.2f seconds\n", elapsed);

    // Verify memory is actually freed
    ptr = malloc(TEST_SIZE);
    if (ptr) 
    {
        fprintf(stderr, "Memory leak detected\n");
        free(ptr);
    }
}

int main() 
{
    srand(time(NULL)); // Seed random number generator
    printf("Starting RAM test...\n");  //echo to conscole
    test_ram(); //call the function
    printf("RAM test completed successfully\n"); //echo to console after completed
    return 0;
}
