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
void quicksort(int* a, int l, int r){
    if (l>=r){
        return;
    }
    int index=l;
    int small,big;
    //cout<<"its the "<<count<<" time to sort."<<endl;
    //count++;
    //showArray(a);
    //cout<<"l="<<l<<"\tr="<<r<<endl;
    while(1){
        //find small
        //small=r;
        for(small=r;small>=l+1;small--){
            if (a[index]>a[small]){
                break;
            }
        }
        //find big
        //big=l+1;
        for(big=l+1;big<=r;big++){
            if (a[index]<a[big]){
                break;
            }
        }
        //cout<<"find small:"<<small<<endl<<"find big:"<<big<<endl;
        if (small>big){
            swap(a[small],a[big]);
        }
        else{
            break;
        }
    }
    swap(a[index],a[small]);
    quicksort(a,l,small-1);
    quicksort(a,small+1,r);
}
int main(){
    int* a=makeArray();
    cout<<"before sorted:"<<endl;
    showArray(a);
    quicksort(a,0,sizee-1);
    cout<<"after sorted:"<<endl;
    showArray(a);
    delete [] a;
}
