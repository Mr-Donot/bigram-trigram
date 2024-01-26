#include <iostream>
#include <omp.h>

int main() {
    const int size = 10;
    int array[size];

    // Initialize array
    for (int i = 0; i < size; ++i) {
        array[i] = 0;
    }

    //Default is 8
    omp_set_num_threads(4);
    #pragma omp parallel
    {
        int threadId = omp_get_thread_num();  // Get the thread ID
        int incrementValue = threadId + 1;    // Increment value based on thread ID

        // Each thread increments its corresponding element in the array
        array[threadId] += incrementValue;
    }

    // Print the modified array
    std::cout << "Modified array: ";
    for (int i = 0; i < size; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
