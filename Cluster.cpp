// Jana El Midany 900226145
//Checks what cluster is closest to a point (class 1-D dynamic arrays)
#include <iostream>
#include <cstdlib>
#include "point.h"
using namespace std;

point Center(point*,int);
char ClosestCluster(point*,point*,point,int,int);
void Populate(point*,int, int, int);

int main(){
    point *A, *B, *P;
    int n, m;
    cout<<"Enter size of clusters: ";
    cin>>n;
    cout<<"Enter number of points: ";
    cin>>m;
    A= new point[n];
    B= new point[n];
    P= new point [m];

    Populate(A,n,90,70);
    Populate(B,n,40,20);
    Populate(P,m,100,5);

    for(int i=0;i<m;i++){
        point current_p=*(P+i);
        char closest=ClosestCluster(A,B,current_p,n,n);
        cout<<"Point P"<<i+1<<" should belong to cluster "<<closest<<endl;
    }
    
    delete[]A;
    delete[]B;
    delete[]P;
    return 0;

}

point Center(point* C, int n){
    point center;
    float sumX=0, sumY=0;
    for(int i=0;i<n;i++){
        sumX=sumX+(*(C+i)).getX();
        sumY=sumY+(*(C+i)).getY();
    }
    center.setX(sumX/n);
    center.setY(sumY/n);
    return center;
}
char ClosestCluster(point* A,point* B,point P, int Asize, int Bsize){
    point centerA=Center(A,Asize);
    point centerB=Center(B,Bsize);
    float distancefromA=P.distance(centerA);
    float distancefromB=P.distance(centerB);
    if(distancefromA<distancefromB){
        return 'A';
    }
    return 'B';
}
void Populate(point* C, int size, int upper_bound, int lower_bound){
    srand(time(0));
    float x,y;
    for (int i=0;i<size;i++){
        x=rand()%(upper_bound-lower_bound)+lower_bound;
        y=rand()%(upper_bound-lower_bound)+lower_bound;
        (*(C+i)).setX(x);
        (*(C+i)).setY(y);
    }
}

