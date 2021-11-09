#include <iostream>
#include "Text_Preprocessor.h"

using namespace std;
int main() {
    //main class
    char array_text[1000];
    cin >> array_text;
    Text_Preprocessor san(array_text);
    san.preprocess_text();
    int index = san.search_word("a");
    if(index == -1){
        cout << "Word not found!";
    }
    else{
        cout << index << endl;
    }
    ifstream file;
    file.open("C:/Users/aaruz/CLionProjects/ass7/Task2.txt");
    ofstream outfile1 ("Thread_1.txt");
    ofstream outfile2 ("Thread_2.txt");
    double *array1 = new double[1002];
    double ave = 0;
    for(int i = 0; i < 100; ++i){
        file >> array1[i];
        ave += array1[i];
    }
    ave /= 100;
    for(int i = 0; i < 100; ++i){
        if(array1[i] - ave > 0){
            outfile1 << array1[i] << endl;
        }
        else{
            outfile2 << array1[i] << endl;
        }
    }
    outfile1.close();
    outfile2.close();
    return 0;
}