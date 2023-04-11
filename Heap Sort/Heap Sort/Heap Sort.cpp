#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Employee.h"

using namespace std;

void maxHeapify(Employee** A, int i, int heapsize, int& comparison) {
    auto largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < heapsize && A[l]->getID() > A[i]->getID()) {
        largest = l;
    }
    comparison++;
    if (r < heapsize && A[r]->getID() > A[largest]->getID()) {
        largest = r;
    }
    comparison++;
    if (largest != i) {
        auto temp = A[i];
        A[i] = A[largest];
        A[largest] = temp;
        maxHeapify(A, largest, heapsize, comparison);
    }
}

void buildMaxHeap(Employee** A, int n, int& comparison) {
    for (int i = n / 2; i >= 0; i--) {
        maxHeapify(A, i, n, comparison);
    }
}

void heapSort(Employee** A, int n, int& comparison) {
    // Print IDs
    for (int z = 0; z < n; z++) {
        cout << A[z]->getID() << " ";
    }
    cout << endl;
    buildMaxHeap(A, n, comparison);
    int heapsize = n;
    for (int i = n - 1; i > 0; i--) {
        // Print IDs
        for (int z = 0; z < n; z++) {
            cout << A[z]->getID() << " ";
        }
        cout << endl;
        auto temp = A[0];
        A[0] = A[i];
        A[i] = temp;
        heapsize = heapsize - 1;
        maxHeapify(A, 0, heapsize, comparison);
    }
    // Print IDs
    for (int z = 0; z < n; z++) {
        cout << A[z]->getID() << " ";
    }
    cout << endl;
}

void printID(Employee** A, int n) {
    for (int z = 0; z < n; z++) {
        cout << A[z]->getID() << " ";
    }
    cout << endl;
}

int main(int argc, char** argv)
{
    //Check for command line error
    if (argc == 1) {
        cout << "You forgot the command line parameter" << endl;
        exit(0);
    }

    //Check for file
    ifstream ifs;
    ifs.open(argv[1], ios::in);
    if (!ifs) {
        cout << "could not find file " << argv[1] << endl;
        exit(0);
    }

    //Get how many lines
    string line;
    getline(ifs, line);
    int n = stoi(line);

    //initializing an array
    Employee** employee = new Employee * [n];

    //loop through file
    for (int i = 0; i < n; i++) {
        int age;
        int id;
        int year;
        string name;
        string job;
        string ids;
        string a;
        string y;
        getline(ifs, name, '|');
        getline(ifs, ids, '|');
        getline(ifs, a, '|');
        getline(ifs, job, '|');
        getline(ifs, y);
        id = stoi(ids);
        age = stoi(a);
        year = stoi(y);
        Employee* emp = new Employee(name, id, age, job, year);

        //Add to array
        employee[i] = emp;


    }

    // HEAP SORT
    int comparison = 0;
    heapSort(employee, n, comparison);
    //Print total comparison
    cout << "It took " << comparison << " comparisons to sort this list." << endl;

}