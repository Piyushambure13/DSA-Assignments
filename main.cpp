#include<iostream>
using namespace std;

struct student{
    int roll_no;
    string name;
    float sgpa;
};


void bubbleSort(student arr[],int n){
    for (int i=0;i<4;i++){
        for (int j=0;j<4-i;j++){
            if(arr[j].roll_no>arr[j+1].roll_no){
                student a = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=a;
            }
        }
    }
}

void insertionSort(student arr[],int n){
    for(int i=1;i<n;i++){
        student key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j].name>key.name){
            arr[j+1]=arr[j];
            j=j-1;
            
            
        }
        arr[j+1]=key;
    }
}
int partition(student arr[],int low,int high){
    float pivot=arr[high].sgpa;
    int i=low-1;
    for(int j=low;j<high;j++){
        if(arr[j].sgpa>pivot){
            i++;
            student temp=arr[i+1];
            arr[i+1]=arr[high];
            arr[high]=temp;
            }
        }
        student temp=arr[i+1];
        arr[i+1]=arr[high];
        arr[high]=temp;
        return i+1;
    }

void quicksort(student arr[],int low,int high){
    if(low<high){
        int pi=partition(arr,low,high);
        quicksort(arr, low,pi-1);
        quicksort(arr,pi+1,high);
        
    }
}
void searchgpa(student arr[],int n,float search){
    bool found= false;
    for(int i=0;i<n;i++){
        if(arr[i].sgpa == search){
            if(!found)
            {
                cout<<"STUDENT WITH SGPA"<<search<< endl;
              found = true;
            }
            cout<<"NAME"<<arr[i].name<<endl;
            
        }
    }
    if(!found){
        cout<<" NO STUDENT FIND FOR SGPA::"<<search<<endl;
        
    }
}
int binarysearch(student arr[],int size,string key){
    int start =0;
    int end = (size-1);
    int mid= start+(end-start)/2;
    while (start<end) {
        if (arr[mid].name==key) {
            return mid;
        }
        if (key>arr[mid].name) {
            start = mid+1;
        }
        else{
            end = mid-1;
        }
        mid= start + (end-start)/2;
    }
    return -1;
}
int main(){
    student s[5];
    for (int i=0;i<5;i++){
        cout<<"ENTER STUDENT NUMBER :: "<<i+1<<endl;
        cout<<"ENTER NAME ";
        cin>>s[i].name;
        cout<<"ENTER ROLL NUMBER";
        cin>>s[i].roll_no;
        cout<<"ENTER SGPA";
        cin>>s[i].sgpa;
        cout<<endl;
    }
    //output of bubble sort
    bubbleSort(s,5);
    cout<<" SORTED ROLL NUMBERS ARE :: "<<endl;
    for(int i=0;i<5;i++){
        cout<<s[i].roll_no<<endl;
    }
    //insertion sort
    insertionSort(s,5);
    cout<<"SORTED NAMES ARE :: "<<endl;
    for(int i=0;i<5;i++){
        cout<<s[i].name<<endl;
    }
    cout<<endl;
    //output of quicksort
    quicksort(s, 0, 5);
    cout<<"TOP 3 STUDENTS ARE :: "<<endl;
    for(int i=0;i<5;i++){
        cout<<"NAME :: "<<s[i].name<<" ROLL NUMBER :: "<<s[i].roll_no<<" SGPA:: "<<s[i].sgpa<<endl;
    }
    //search acc to sgpa
    float search;
    cout<<"ENTER THE SGPA TO SEARCH"<<endl;
    cin>>search;
    cout<<endl;
    searchgpa(s, 5, search);
    cout<<"endl";
    //binary search searching for perticular name
    string key;
    cout<<"ENTER THE NAME TO SEARCH"<<endl;
    cin>>key;
    cout<<endl;
    insertionSort(s, 5);
    int index;
    index=binarysearch(s, 5, key);
    
    if (index!=-1) {
        cout<<"STUDENT FOUND::"<<endl;
        cout<<endl;
        cout<<"NAME::"<<s[index].name<<endl;
        cout<<"ROLL NUMBER::"<<s[index].roll_no<<endl;
        cout<<"SGPA::"<<s[index].sgpa<<endl;
    }
    else{
        cout<<"STUDENT NOT FOUND"<<endl;
    }
    return 0;
}

