#include <iostream>
using namespace std;

class Matrix {
    int rows, cols;
    int **mat;
public:
    Matrix(int r=0,int c=0) {
        rows=r;
        cols=c;
        if(rows>0 && cols>0) {
            mat=new int*[rows];
            for(int i=0;i<rows;i++) {
                mat[i]=new int[cols];
                for(int j=0;j<cols;j++) mat[i][j]=0;
            }
        }
        else mat=nullptr;
    }
    Matrix(const Matrix &m) {
        rows=m.rows;
        cols=m.cols;
        mat=new int*[rows];
        for(int i=0;i<rows;i++) {
            mat[i]=new int[cols];
            for(int j=0;j<cols;j++) mat[i][j]=m.mat[i][j];
        }
    }
    Matrix operator+(const Matrix &m) {
        Matrix temp(rows,cols);
        for(int i=0;i<rows;i++) {
            for(int j=0;j<cols;j++) {
                temp.mat[i][j]=mat[i][j]+m.mat[i][j];
            }
        }
        Matrix ans=temp;
        return ans;
    }
    Matrix operator-(const Matrix &m) {
        Matrix temp(rows,cols);
        for(int i=0;i<rows;i++) {
            for(int j=0;j<cols;j++) {
                temp.mat[i][j]=mat[i][j]-m.mat[i][j];
            }
        }
        Matrix ans=temp;
        return ans;
    }
    Matrix operator*(const Matrix &m) {
        Matrix temp(rows,m.cols);
        for(int i=0;i<rows;i++) {
            for(int j=0;j<m.cols;j++) {
                int sum=0;
                for(int k=0;k<cols;k++) {
                    sum+=mat[i][k]*m.mat[k][j];
                }
                temp.mat[i][j]=sum;
            }
        }
        Matrix ans=temp;
        return ans;
    }
    Matrix operator/(const Matrix &m) {
        Matrix temp(rows,cols);
        for(int i=0;i<rows;i++) {
            for(int j=0;j<cols;j++) {
                if(m.mat[i][j]!=0) temp.mat[i][j]=mat[i][j]/m.mat[i][j];
                else temp.mat[i][j]=0;
            }
        }
        Matrix ans=temp;
        return ans;
    }
    Matrix operator!() {
        Matrix temp(cols,rows);
        for(int i=0;i<rows;i++) {
            for(int j=0;j<cols;j++) {
                temp.mat[j][i]=mat[i][j];
            }
        }
        Matrix ans=temp;
        return ans;
    }
    bool operator==(const Matrix &m) {
        if(rows!=m.rows || cols!=m.cols) {
            bool ans=false;
            return ans;
        }
        bool res=true;
        for(int i=0;i<rows;i++) {
            for(int j=0;j<cols;j++) {
                if(mat[i][j]!=m.mat[i][j]) {
                    res=false;
                    break;
                }
            }
        }
        bool ans=res;
        return ans;
    }
    Matrix& operator=(const Matrix &m) {
        if(this!=&m) {
            for(int i=0;i<rows;i++) delete[] mat[i];
            delete[] mat;
            rows=m.rows;
            cols=m.cols;
            mat=new int*[rows];
            for(int i=0;i<rows;i++) {
                mat[i]=new int[cols];
                for(int j=0;j<cols;j++) mat[i][j]=m.mat[i][j];
            }
        }
        return *this;
    }
    int& operator[](int index) {
        if(index<0 || index>=rows*cols) {
            cout<<"Out of bound"<<endl;
            static int dummy=0;
            return dummy;
        }
        int r=index/cols;
        int c=index%cols;
        return mat[r][c];
    }
    friend istream& operator>>(istream &in, Matrix &m) {
        for(int i=0;i<m.rows;i++) {
            for(int j=0;j<m.cols;j++) {
                in>>m.mat[i][j];
            }
        }
        return in;
    }
    friend ostream& operator<<(ostream &out, const Matrix &m) {
        for(int i=0;i<m.rows;i++) {
            for(int j=0;j<m.cols;j++) {
                out<<m.mat[i][j]<<" ";
            }
            out<<endl;
        }
        return out;
    }
    ~Matrix() {
        if(mat!=nullptr) {
            for(int i=0;i<rows;i++) delete[] mat[i];
            delete[] mat;
        }
    }
};

int main() {
    Matrix m1(2,2),m2(2,2),m3;
    cout<<"Enter the elements of the first matrix"<<endl;
    cin>>m1;
    cout<<"Enter the elemenets of the third matrix"<<endl;
    cin>>m2;
    m3=m1+m2;
    cout<<m3;
    m3=m1-m2;
    cout<<m3;
    m3=m1*m2;
    cout<<m3;
    m3=!m1;
    cout<<m3;
    if(m1==m2) cout<<"Equal"<<endl;
    else cout<<"Not Equal"<<endl;
    cout<<m1[2]<<endl;
    cout<<m1[10]<<endl;
    return 0;
}
