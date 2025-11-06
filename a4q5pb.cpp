#include <iostream>
using namespace std;

#define MAX 10   // maximum allowed size

class Matrix {
    int size;
    int mat[MAX][MAX];
public:
    Matrix(int n=0) {
        size=n;
        for(int i=0;i<MAX;i++)
            for(int j=0;j<MAX;j++)
                mat[i][j]=0;
    }
    void setSize(int n) { size=n; }
    void readMatrix() {
        for(int i=0;i<size;i++)
            for(int j=0;j<size;j++)
                cin>>mat[i][j];
    }
    void displayMatrix() {
        for(int i=0;i<size;i++) {
            for(int j=0;j<size;j++) cout<<mat[i][j]<<" ";
            cout<<endl;
        }
    }
    int detMatrix() {
        if(size==1) return mat[0][0];
        if(size==2) return mat[0][0]*mat[1][1]-mat[0][1]*mat[1][0];
        int det=0,sign=1;
        for(int f=0;f<size;f++) {
            Matrix sub(size-1);
            for(int i=1;i<size;i++) {
                int col=0;
                for(int j=0;j<size;j++) {
                    if(j==f) continue;
                    sub.mat[i-1][col]=mat[i][j];
                    col++;
                }
            }
            det+=sign*mat[0][f]*sub.detMatrix();
            sign=-sign;
        }
        return det;
    }
    Matrix addMatrix(Matrix &other) {
        Matrix res(size);
        for(int i=0;i<size;i++)
            for(int j=0;j<size;j++)
                res.mat[i][j]=mat[i][j]+other.mat[i][j];
        return res;
    }
    Matrix subMatrix(Matrix &other) {
        Matrix res(size);
        for(int i=0;i<size;i++)
            for(int j=0;j<size;j++)
                res.mat[i][j]=mat[i][j]-other.mat[i][j];
        return res;
    }
    Matrix multMatrix(Matrix &other) {
        Matrix res(size);
        for(int i=0;i<size;i++)
            for(int j=0;j<size;j++) {
                res.mat[i][j]=0;
                for(int k=0;k<size;k++)
                    res.mat[i][j]+=mat[i][k]*other.mat[k][j];
            }
        return res;
    }
    void CramerRule() {
        cout<<"Enter constants vector:"<<endl;
        int b[MAX];
        for(int i=0;i<size;i++) cin>>b[i];
        int detA=detMatrix();
        if(detA==0) {
            cout<<"No unique solution"<<endl;
            return;
        }
        for(int var=0;var<size;var++) {
            Matrix temp(*this);
            for(int i=0;i<size;i++) temp.mat[i][var]=b[i];
            int detAi=temp.detMatrix();
            cout<<"x"<<var+1<<" = "<<(double)detAi/detA<<endl;
        }
    }
    Matrix(const Matrix &m) {
        size=m.size;
        for(int i=0;i<size;i++)
            for(int j=0;j<size;j++)
                mat[i][j]=m.mat[i][j];
    }
};

int main() {
    int n,choice;
    cout<<"Enter size of square matrix (<= "<<MAX<<"): ";
    cin>>n;
    Matrix A(n),B(n),R(n);
    cout<<"Enter elements of Matrix A:"<<endl;
    A.readMatrix();
    cout<<"Enter elements of Matrix B:"<<endl;
    B.readMatrix();
    do {
        cout<<"\n--- Matrix Menu ---\n";
        cout<<"1. Display Matrix A\n";
        cout<<"2. Display Matrix B\n";
        cout<<"3. Add (A+B)\n";
        cout<<"4. Subtract (A-B)\n";
        cout<<"5. Multiply (A*B)\n";
        cout<<"6. Determinant of A\n";
        cout<<"7. Solve using Cramer's Rule (Ax=b)\n";
        cout<<"0. Exit\n";
        cout<<"Enter choice: ";
        cin>>choice;
        switch(choice) {
            case 1: A.displayMatrix(); break;
            case 2: B.displayMatrix(); break;
            case 3: R=A.addMatrix(B); R.displayMatrix(); break;
            case 4: R=A.subMatrix(B); R.displayMatrix(); break;
            case 5: R=A.multMatrix(B); R.displayMatrix(); break;
            case 6: cout<<"Determinant of A = "<<A.detMatrix()<<endl; break;
            case 7: A.CramerRule(); break;
            case 0: cout<<"Exiting..."<<endl; break;
            default: cout<<"Invalid choice"<<endl;
        }
    } while(choice!=0);
    return 0;
}
