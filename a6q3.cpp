#include <iostream>
#include <vector>
#include <string>
#include <complex>
using namespace std;

template<typename T>
class Matrix {
    vector<vector<T>> m;
    int r, c;
public:
    Matrix();
    Matrix(int r_, int c_);
    Matrix(const Matrix& other);
    void input();
    void display() const;
    Matrix operator!() const;
    bool operator==(const Matrix& other) const;
    Matrix& operator=(const Matrix& other);
    vector<T>& operator[](int i);
    template<typename U>
    friend istream& operator>>(istream& in, Matrix<U>& M);
    template<typename U>
    friend ostream& operator<<(ostream& out, const Matrix<U>& M);
};

template<typename T>
Matrix<T>::Matrix():r(0),c(0){}

template<typename T>
Matrix<T>::Matrix(int r_, int c_):r(r_),c(c_){
    m.resize(r, vector<T>(c));
}

template<typename T>
Matrix<T>::Matrix(const Matrix& other){
    r=other.r;
    c=other.c;
    m=other.m;
}

template<typename T>
void Matrix<T>::input(){
    cout<<"Enter rows and columns: ";
    cin>>r>>c;
    m.resize(r, vector<T>(c));
    cout<<"Enter elements:\n";
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            cin>>m[i][j];
}

template<typename T>
void Matrix<T>::display() const{
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++)
            cout<<m[i][j]<<" ";
        cout<<endl;
    }
}

template<typename T>
Matrix<T> Matrix<T>::operator!() const{
    Matrix<T> t(c,r);
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            t.m[j][i]=m[i][j];
    return t;
}

template<typename T>
bool Matrix<T>::operator==(const Matrix& other) const{
    if(r!=other.r || c!=other.c) return false;
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            if(m[i][j]!=other.m[i][j]) return false;
    return true;
}

template<typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix& other){
    if(this!=&other){
        r=other.r;
        c=other.c;
        m=other.m;
    }
    return *this;
}

template<typename T>
vector<T>& Matrix<T>::operator[](int i){
    if(i<0 || i>=r){
        cout<<"Row index out of bounds!"<<endl;
        static vector<T> dummy;
        return dummy;
    }
    return m[i];
}

template<typename T>
istream& operator>>(istream& in, Matrix<T>& M){
    cout<<"Enter rows and columns: ";
    in>>M.r>>M.c;
    M.m.resize(M.r, vector<T>(M.c));
    cout<<"Enter elements:\n";
    for(int i=0;i<M.r;i++)
        for(int j=0;j<M.c;j++)
            in>>M.m[i][j];
    return in;
}

template<typename T>
ostream& operator<<(ostream& out, const Matrix<T>& M){
    for(int i=0;i<M.r;i++){
        for(int j=0;j<M.c;j++)
            out<<M.m[i][j]<<" ";
        out<<endl;
    }
    return out;
}

template<typename T>
void menu(Matrix<T>& A){
    int op;
    do{
        cout<<"\n--- Matrix Menu ---\n";
        cout<<"1. Input Matrix\n";
        cout<<"2. Display Matrix\n";
        cout<<"3. Invert (!)\n";
        cout<<"4. Copy (=)\n";
        cout<<"5. Compare (==)\n";
        cout<<"6. Subscript Access ([])\n";
        cout<<"0. Exit\n";
        cout<<"Enter choice: ";
        cin>>op;

        if(op==1) cin>>A;
        else if(op==2) cout<<A;
        else if(op==3){ Matrix<T> B=!A; cout<<"Inverted (Transposed):\n"<<B; }
        else if(op==4){ Matrix<T> B; B=A; cout<<"Copied Matrix:\n"<<B; }
        else if(op==5){ Matrix<T> B; cin>>B; if(A==B) cout<<"Matrices are Equal\n"; else cout<<"Matrices are Not Equal\n"; }
        else if(op==6){ int i,j; cout<<"Enter row and column index: "; cin>>i>>j; if(i>=0 && i<A[i].size() && j>=0 && j<A[i].size()) cout<<"Element: "<<A[i][j]<<endl; }
        else if(op==0) cout<<"Exiting...\n";
        else cout<<"Invalid choice!\n";
    }while(op!=0);
}

int main(){
    cout<<"Choose datatype for Matrix:\n";
    cout<<"1. Integer\n";
    cout<<"2. String\n";
    cout<<"3. Complex Number\n";
    cout<<"Enter choice: ";
    int ch; cin>>ch;

    if(ch==1){
        Matrix<int> A;
        menu(A);
    }
    else if(ch==2){
        Matrix<string> A;
        menu(A);
    }
    else if(ch==3){
        Matrix<complex<double>> A;
        int op;
        do{
            cout<<"\n--- Matrix Menu ---\n";
            cout<<"1. Input Matrix\n2. Display Matrix\n3. Invert\n4. Copy\n5. Compare\n6. Subscript Access\n0. Exit\n";
            cout<<"Enter choice: "; cin>>op;
            if(op==1){
                int r,c; cout<<"Enter rows and columns: "; cin>>r>>c; 
                A=Matrix<complex<double>>(r,c);
                cout<<"Enter elements (real imag):\n";
                for(int i=0;i<r;i++)
                    for(int j=0;j<c;j++){
                        double a,b; cin>>a>>b;
                        A[i][j]={a,b};
                    }
            }
            else if(op==2) cout<<A;
            else if(op==3){ Matrix<complex<double>> B=!A; cout<<"Inverted:\n"<<B; }
            else if(op==4){ Matrix<complex<double>> B; B=A; cout<<"Copied:\n"<<B; }
            else if(op==5){ Matrix<complex<double>> B; cin>>B; if(A==B) cout<<"Equal\n"; else cout<<"Not Equal\n"; }
            else if(op==6){ int i,j; cout<<"Enter row and column index: "; cin>>i>>j; if(i>=0 && j>=0 && i<A[i].size() && j<A[i].size()) cout<<"Element: "<<A[i][j]<<endl; }
            else if(op==0) cout<<"Exiting...\n";
        }while(op!=0);
    }
}
