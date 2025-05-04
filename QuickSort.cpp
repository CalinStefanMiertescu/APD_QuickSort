#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <string>
#include <filesystem>
#include <iomanip>

using namespace std;
namespace fs = std::filesystem;

// Sequential QuickSort implementation
void quickSort(vector<long long>& arr, int low, int high) {
    if (low < high) {
        long long pivot = arr[high];
        int i = low - 1;

        for (int j = low; j < high; j++) {
            if (arr[j] <= pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);

        int pi = i + 1;
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    try {
        fs::path execPath = fs::current_path() / "input.txt";
        ifstream inputFile(execPath);
        if (!inputFile.is_open()) {
            cerr << "Error: Could not open input file." << endl;
            return 1;
        }

        // Read the number of elements first
        int n;
        if (!(inputFile >> n)) {
            cerr << "Error: Could not read the number of elements." << endl;
            return 1;
        }

        vector<long long> numbers;
        numbers.reserve(n);  // Pre-allocate space for better performance
        long long num;
        for (int i = 0; i < n; i++) {
            if (!(inputFile >> num)) {
                cerr << "Error: Could not read element " << i + 1 << endl;
                return 1;
            }
            numbers.push_back(num);
        }
        inputFile.close();

        if (numbers.empty()) {
            cerr << "Error: No numbers found in input file." << endl;
            return 1;
        }

        cout << "Number of elements: " << numbers.size() << endl;

        // Measure sorting time
        auto start = chrono::high_resolution_clock::now();
        quickSort(numbers, 0, numbers.size() - 1);
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

        // Output results
        cout << "\nSorted numbers:" << endl;
        for (const auto& n : numbers) {
            cout << n << " ";
        }
        cout << fixed << setprecision(3);
        cout << "\n\nExecution time: " << (duration.count() / 1000.0) << " ms" << endl;

    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }

    return 0;
} 