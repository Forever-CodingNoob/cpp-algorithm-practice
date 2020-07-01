#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
int sizee=10000;
void heap_sort(int* datas,int size);
void build_node(int* datas, int j, int size);
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
int* genArray(int sizee){
    srand(time(NULL));
    int* A=new int[sizee];
    for (int i=0;i<sizee;i++){
        A[i]=(double)rand()/(RAND_MAX-1)*sizee;
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
int* mergesort(int *a,int l,int r){
    if (l==r){
        int* k=new int[1];
        k[0]=a[l];
        return k;
    }
    int* array3=new int[r-l+1];
    int mid=sizee/2;
    int i=0,j=0,k=0,len1=mid-l+1,len2=r-mid;
    if (len1<=0||len2<=0){
        for(int i=l;i<=r;i++){
            array3[k++]=a[i];
        }
        return array3;
    }
    int* array1=mergesort(a,l,mid);
    int* array2=mergesort(a,mid+1,r);


    while(i<len1&&j<len2){
        if(array1[i]<=array2[j]){
            array3[k++]=array1[i++];
        }
        else{
            array3[k++]=array2[j++];
        }
    }
    while(i<len1){
        array3[k++]=array1[i++];
    }
    while(j<len2){
        array3[k++]=array2[j++];
    }
    delete [] array1;
    delete [] array2;
    return array3;
}
void heap_sort(int* datas,int size){
    //if size=9, then i=4,3,2,1, i*2=8,6,4,2, i*2-1=7,5,3,1
    for(int i=(size)/2;i>0;i--){
        build_node(datas,i-1,size);
    }
    for(int i=size-1;i>0;i--){
        swap(datas[0],datas[i]);
        build_node(datas,0,i);
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
int main(){
    clock_t t;
    while (1){

        int *a=genArray(sizee),*b=genArray(sizee),*c=genArray(sizee),*d=genArray(sizee);

        t=clock();
        cout<<"after quicksort:"<<endl;
        quicksort(a,0,sizee-1);
        //showArray(a);
        cout<<"execution time:"<<(float)(clock()-t)/CLOCKS_PER_SEC<<endl<<endl;

        t=clock();
        cout<<"after bubblesort:"<<endl;
        bubblesort(b);
        //showArray(b);
        cout<<"execution time:"<<(float)(clock()-t)/CLOCKS_PER_SEC<<endl<<endl;

        t=clock();
        cout<<"after mergesort:"<<endl;
        mergesort(c,0,sizee-1);
        //showArray(c);
        cout<<"execution time:"<<(float)(clock()-t)/CLOCKS_PER_SEC<<endl<<endl;

        t=clock();
        cout<<"after heapsort:"<<endl;
        heap_sort(d,sizee);
        //showArray(d);
        cout<<"execution time:"<<(float)(clock()-t)/CLOCKS_PER_SEC<<endl<<endl;

        delete [] a;
    }
}
