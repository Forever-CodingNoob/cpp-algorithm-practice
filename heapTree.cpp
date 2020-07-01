#include<iostream>
using namespace std;
int sizee;
void heap_sort(int* datas,int size);
void build_node(int* datas, int j, int size);
void showArr(int* arr);
void swap(int& a, int& b){
    int tmp=a;
    a=b;
    b=tmp;
}
int* make_array(){
    cin>>sizee;
    int* a=new int[sizee];
    for(int i=0;i<sizee;i++){
        cin>>a[i];
    }
    return a;
}
void heap_sort(int* datas,int size){
    //if size=9, then i=4,3,2,1, i*2=8,6,4,2, i*2-1=7,5,3,1
    for(int i=(size)/2;i>0;i--){
        build_node(datas,i-1,size);
    }
    showArr(datas);
    for(int i=size-1;i>0;i--){
        swap(datas[0],datas[i]);
        build_node(datas,0,i);
        showArr(datas);
    }
}
void build_node(int* datas, int i, int size){
    //父節點為datas[i],子節點為(datas[j]和datas[j+1]中較大的)
    int j=(i+1)*2-1;
    int tmp=datas[i];//先暫存最初父節點之值
    bool endLoop=false;
    while(j<size && !endLoop){//size指要建立堆積樹的範圍，size以外就不管
        if(j!=size-1){//找出2個子節點中最大的(因為此sort要取最大值)，但要先確保datas[j]不在最後(確定有datas[j+1])
            if(datas[j]<datas[j+1]){
                j++;
            }
        }

        if(tmp>=datas[j]){
            endLoop=true;
        }
        else{
            datas[(j+1)/2-1]=datas[j];//將較大的datas[j]搬移至其父節點位置=>類似insert sort
            j=(j+1)*2-1;//而暫存的tmp(最初父節點之值)則與下一層子節點比較大小
        }
    }
    datas[(j+1)/2-1]=tmp;//暫存的tmp(最初父節點之值)終於找到了比自己更小之值，要至於其上方，故為datas[j/2](父節點位置)
}
void showArr(int* arr){
    cout.width(3);
    for(int i=0;i<sizee;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int* datas=make_array();
    cout<<"before sorted:"<<endl;
    showArr(datas);
    heap_sort(datas,sizee);
    cout<<"after sorted:"<<endl;
    showArr(datas);
    delete [] datas;
    return 0;
}

