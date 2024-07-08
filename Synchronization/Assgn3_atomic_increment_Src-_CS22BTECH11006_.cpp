#include <iostream>
#include <fstream>
#include <vector>
#include <thread>
#include <atomic>
#include <chrono>

using namespace std;
using namespace chrono;

// Shared variables
atomic<int> counter(0);

// Matrix multiplication function for a portion of rows
void multiply(vector<vector<int>>& A, vector<vector<int>>& C, int start, int end) {
    for (int i = start; i < end; ++i) {
        for (int j = 0; j < A.size(); ++j) {
            int sum = 0;
            for (int k = 0; k < A.size(); ++k) {
                sum += A[i][k] * A[k][j];
            }
            C[i][j] = sum;
        }
    }
}

// Worker function for thread
void worker(vector<vector<int>>& A, vector<vector<int>>& C) {
    while (true) {
        int start = counter.fetch_add(1, memory_order_relaxed);
        int end = counter.load(memory_order_relaxed);

        // Exit if there are no more rows to process
        if (start >= A.size())
            break;

        // Perform matrix multiplication for the assigned rows
        multiply(A, C, start, end);
    }
}

int main() {
    ifstream input_file("inp.txt");
    ofstream output_file("out_atomic_increment.txt");

    int n, k, rowInc;
    input_file >> n >> k >> rowInc;

    vector<vector<int>> A(n, vector<int>(n));
    vector<vector<int>> C(n, vector<int>(n));

    // Read matrix A from input file
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            input_file >> A[i][j];
        }
    }

    // Create threads for parallel matrix multiplication
    vector<thread> threads;
    auto start_time = high_resolution_clock::now();
    for (int i = 0; i < k; ++i) {
        threads.push_back(thread(worker, ref(A), ref(C)));
    }

    // Join threads
    for (auto& t : threads) {
        t.join();
    }
    auto end_time = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end_time - start_time).count();

    // Write resulting matrix C to output file
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            output_file << C[i][j] << " ";
        }
        output_file << endl;
    }

    // Write time taken to compute matrix multiplication
    output_file << "Time taken Using Atomic Increment: " << duration * 0.000001 << " seconds" << endl;

    input_file.close();
    output_file.close();

    return 0;
}
