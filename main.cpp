
#include <cstdlib>
#include <iostream>
#include <chrono>
#include <iomanip>

using namespace std;
using namespace std::chrono;
void countingSort(int arr[], int (&arr2)[100]);
void histogramSort(int arr[], int (&arr2)[100]);
void myPrint(int (&arrout)[100]);


int main(int argc, char** argv) {

    int array2D[10][10] = {
        {1, 3, 5, 7, 9, 3, 4, 4, 5, 6},
        {1, 3, 5, 7, 9, 3, 4, 4, 5, 6},
        {1, 3, 5, 7, 9, 3, 4, 4, 5, 6},
        {1, 3, 5, 20, 25, 24, 33, 5, 6, 4},
        {1, 3, 5, 20, 35, 24, 32, 5, 6, 4},
        {1, 3, 5, 20, 28, 34, 23, 5, 6, 4},
        {1, 3, 5, 21, 25, 27, 23, 5, 6, 4},
        {1, 3, 5, 7, 9, 3, 4, 4, 5, 6},
        {1, 3, 5, 7, 9, 3, 4, 4, 5, 6},
        {1, 3, 5, 7, 9, 3, 4, 4, 5, 6}
    };

    int array2DLenght = 10; 

    
    int array1D[100]; //TBD: make it automatically.  new int[array2DLenght * array2DLenght];  

    for (int i = 0; i < array2DLenght; i++) {

        for (int j = 0; j < array2DLenght; j++) {

            array1D[(i * array2DLenght) + j] = array2D[i][j];
            //            array1D[(4 * 10) + 3]] = 25;
        }
    }
    myPrint(array1D);
    auto startTime = high_resolution_clock::now();
    int cArr[100];
    countingSort(array1D, cArr);
    auto stopTime = high_resolution_clock::now();
    
    cout << endl<< "Sorted Array Using Counting Sort:" << endl<<endl;
    myPrint(cArr);
    //    std::cout << array1D[43];
    auto duration = duration_cast<nanoseconds>(stopTime - startTime);
    std::cout << "Execution time for Counting sort is:" << duration.count() << endl;


    startTime = high_resolution_clock::now();
    int histArray[100];
    histogramSort(array1D, histArray);
    stopTime = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(stopTime - startTime);
    
    cout << endl<< "Sorted Array Using Histogram Sort:" << endl<<endl;
    myPrint(cArr);
    
    std::cout << "Execution time for Histogram sort is:" << duration.count() << endl;

    // std::cout << histArray[99]q' << endl; // Just for sanity check

    return 0;
}

void histogramSort(int arr[], int (&arrout)[100]) {

    int arrlength = 100;

    int n = arrlength;
    int counter = 0;
    
    int count[256]; 
    for (int i = 0; i < 256; ++i) {
        count[i] = 0;
    }

    for (int i = 0; i < arrlength; ++i) {
        ++count[arr[i]];
    }

    for (int i = 0; i < 256; i++) {

        if (count[i] > 0) {

            int number = count[i];
            while (number > 0) {

                arrout[counter++] = i;
                number--;
            }
        }
    }
   
}

void myPrint(int (&arrout)[100]) {


    int arrlength = 100;
    int n = arrlength;

    for (int i = 1; i < arrlength + 1; i++) {

        cout << setfill(' ') << setw(5) << (arrout[i - 1]);
        if (i % 10 == 0) {
            cout << endl;
        }
    }
    cout << endl;
}

void countingSort(int arr[], int (&arrout)[100]) {

    int arrlength = 100;
    int n = arrlength;
    
    int count[256]; 
    for (int i = 0; i < 256; ++i) {
        count[i] = 0;
    }

    for (int i = 0; i < arrlength; ++i) {
        ++count[arr[i]];
    }
    for (int i = 1; i <= 225; ++i) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {

        arrout[count[arr[i]] - 1] = arr[i];
        --count[arr[i]];
    }
    
}