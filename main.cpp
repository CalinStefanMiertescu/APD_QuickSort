#include <iostream>
#include <vector>
#include <chrono> 

using namespace std;
using namespace std::chrono;

// Funcție pentru a găsi poziția pivotului și a rearanja elementele
int partition(vector<int>& arr, int st, int dr) {
    int pivot = arr[dr]; // Alegem pivotul ca ultimul element
    int i = st - 1; // Poziția pentru elementele mai mici decât pivotul

    for (int j = st; j < dr; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]); 
        }
    }

    swap(arr[i + 1], arr[dr]); // Plasăm pivotul în poziția corectă
    return i + 1;
}

// Funcția QuickSort
void quickSort(vector<int>& arr, int st, int dr) {
    if (st < dr) {
        int pivotIndex = partition(arr, st, dr); // Găsim pivotul
        quickSort(arr, st, pivotIndex - 1); // Sortăm partea stângă
        quickSort(arr, pivotIndex + 1, dr); // Sortăm partea dreaptă
    }
}

int main() {
    int n;
    cout << "Introduceti numarul de elemente: ";
    cin >> n;
    vector<int> v(n);
    cout << "Introduceti " << n << " numere: ";
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    // Începem măsurarea timpului
    auto start = high_resolution_clock::now();

    quickSort(v, 0, v.size() - 1);

    // Terminăm măsurarea timpului
    auto stop = high_resolution_clock::now();

    // Calculăm durata
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Vectorul sortat: ";
    for (int x : v) {
        cout << x << " ";
    }
    cout << "\nTimp de executie: " << duration.count() << " ms" << endl;

    return 0;
}