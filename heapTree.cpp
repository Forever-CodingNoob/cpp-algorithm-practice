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
    //���`�I��datas[i],�l�`�I��(datas[j]�Mdatas[j+1]�����j��)
    int j=(i+1)*2-1;
    int tmp=datas[i];//���Ȧs�̪���`�I����
    bool endLoop=false;
    while(j<size && !endLoop){//size���n�إ߰�n�𪺽d��Asize�H�~�N����
        if(j!=size-1){//��X2�Ӥl�`�I���̤j��(�]����sort�n���̤j��)�A���n���T�Odatas[j]���b�̫�(�T�w��datas[j+1])
            if(datas[j]<datas[j+1]){
                j++;
            }
        }

        if(tmp>=datas[j]){
            endLoop=true;
        }
        else{
            datas[(j+1)/2-1]=datas[j];//�N���j��datas[j]�h���ܨ���`�I��m=>����insert sort
            j=(j+1)*2-1;//�ӼȦs��tmp(�̪���`�I����)�h�P�U�@�h�l�`�I����j�p
        }
    }
    datas[(j+1)/2-1]=tmp;//�Ȧs��tmp(�̪���`�I����)�ש���F��ۤv��p���ȡA�n�ܩ��W��A�G��datas[j/2](���`�I��m)
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

