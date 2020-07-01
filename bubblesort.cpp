#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
int sizee;
void swap(int& a, int& b){
    int tmp=a;
    a=b;
    b=tmp;
}
int* makeArray(){
    cin>>sizee;
    int* A=new int[sizee];
    for (int i=0;i<sizee;i++){
        cin>>A[i];
    }
    return A;
}
void showArray(int *a){
    cout<<"array:";
    for(int i=0;i<sizee;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
void bubblesort(int* a){
    bool hasswapped;
    for (int i=sizee-1;i>=1;i--){
        hasswapped=false;
        for(int j=1;j<=i;j++){
            if(a[j]<a[j-1]){
                swap(a[j],a[j-1]);
                hasswapped=true;
            }
        }
        if (!hasswapped){
            return;
        }
    }
}
int main(){
    int* a=makeArray();
    cout<<"before sorted:"<<endl;
    showArray(a);
    bubblesort(a);
    cout<<"after sorted:"<<endl;
    showArray(a);
    delete [] a;
}
