
#include <iostream>
#define maxsize 5
using namespace std;
//for arranging roll numbers
void bubblesort(int rollnumber[],int n){
    int i,j,temp;
    for(j=0;j<=maxsize;j++){
        for(i=0;i<n-1;i++){
            if(rollnumber[i]>rollnumber[i+1]){
                temp=rollnumber[i+1];
                rollnumber[i+1]=rollnumber[i];
                rollnumber[i]=temp;
            }
        }
        
    }
    }
    
void insertionSort(string names[], int n) {
    for (int i = 1; i < n; i++) {
        string key = names[i];
        int j = i - 1;
        while (j >= 0 && names[j] > key) {
            names[j + 1] = names[j];
            j = j - 1;
        }
        names[j + 1] = key;
    }
}
void quicksort(){
    
    
}

int main() {
        
        string names[maxsize];
        int rollNumbers[maxsize];
        float sgpas[maxsize];
        
        
        for (int i = 0; i < maxsize; ++i) {
            cout << "Enter name of student " << i + 1 << ": ";
            cin >> names[i];
            cout << "Enter roll number of student " << i + 1 << ": ";
            cin >> rollNumbers[i];
            cout << "Enter SGPA of student " << i + 1 << ": ";
            cin >> sgpas[i];
        }
        
        
        cout << "\n Student Information:" << endl;
        for (int i = 0; i < maxsize; ++i) {
            cout << "Student " << i + 1 << ": Name = " << names[i] << ", Roll Number = " << rollNumbers[i] << ", SGPA = " << sgpas[i] << endl;
        }
    
        return 0;
        
    }
