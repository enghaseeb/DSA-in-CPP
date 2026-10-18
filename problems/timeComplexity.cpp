#include <iostream>
#include <chrono>

// Automatically use the standard C++ namespace
using namespace std;

int main() {
    // 1. Record the start time (no std:: required)
    auto start = chrono::steady_clock::now();

    // 2. Run a task you want to measure
    long long sum = 0;
    for (int i = 0; i < 1000000; i++) {
        sum += i;
    }

    // 3. Record the end time
    auto end = chrono::steady_clock::now();

    // 4. Calculate the duration in milliseconds
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);

    // 5. Print the result
    cout << "Time taken: " << duration.count() << " milliseconds." << endl;

    return 0;
}

