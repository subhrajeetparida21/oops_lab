#include <iostream>
#include <string>
#include <complex>
using namespace std;

template<typename T>
class List {
    struct Node {
        T data;
        Node* next;
        Node(T v, Node* n=nullptr):data(v),next(n){}
    };
    Node* head;
public:
    List();
    List(const List& l);
    ~List();
    void insert(T v);
    void clear();
    List operator+(const List& l);
    List operator!();
    bool operator==(const List& l);
    List& operator=(const List& l);
    template<typename U> friend istream& operator>>(istream& in, List<U>& l);
    template<typename U> friend ostream& operator<<(ostream& out, const List<U>& l);
};


template<typename T>
List<T>::List():head(nullptr){}

template<typename T>
List<T>::List(const List& l){
    head=nullptr;
    Node* p=l.head;
    Node* arr[1000];
    int k=0;
    while(p){ arr[k++]=p; p=p->next; }
    for(int i=k-1;i>=0;i--) insert(arr[i]->data);
}

template<typename T>
List<T>::~List(){ clear(); }

template<typename T>
void List<T>::insert(T v){
    if(!head) head=new Node(v);
    else{
        Node* p=head;
        while(p->next) p=p->next;
        p->next=new Node(v);
    }
}

template<typename T>
void List<T>::clear(){
    while(head){
        Node* t=head;
        head=head->next;
        delete t;
    }
}

template<typename T>
List<T> List<T>::operator+(const List& l){
    List r(*this);
    Node* p=l.head;
    while(p){ r.insert(p->data); p=p->next; }
    return r;
}

template<typename T>
List<T> List<T>::operator!(){
    List r;
    Node* p=head;
    while(p){ r.insert(p->data); p=p->next; }
    Node* prev=nullptr;
    Node* curr=r.head;
    Node* next=nullptr;
    while(curr){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    r.head=prev;
    return r;
}

template<typename T>
bool List<T>::operator==(const List& l){
    Node* p=head;
    Node* q=l.head;
    while(p&&q){
        if(p->data!=q->data) return false;
        p=p->next; q=q->next;
    }
    return p==nullptr && q==nullptr;
}

template<typename T>
List<T>& List<T>::operator=(const List& l){
    if(this==&l) return *this;
    clear();
    Node* p=l.head;
    Node* arr[1000];
    int k=0;
    while(p){ arr[k++]=p; p=p->next; }
    for(int i=k-1;i>=0;i--) insert(arr[i]->data);
    return *this;
}

template<typename T>
istream& operator>>(istream& in, List<T>& l){
    T v; in>>v; l.insert(v); return in;
}

template<typename T>
ostream& operator<<(ostream& out, const List<T>& l){
    typename List<T>::Node* p=l.head;
    while(p){ out<<p->data<<" "; p=p->next; }
    return out;
}


int main(){
    cout<<"Select data type:\n1. Integer\n2. String\n3. Complex\nChoice: ";
    int ch; cin>>ch;
    if(ch==1){
        List<int> a,b;
        int n,v;
        cout<<"Enter elements of List A (enter -1 to stop): ";
        while(true){ cin>>v; if(v==-1) break; a.insert(v); }
        cout<<"Enter elements of List B (enter -1 to stop): ";
        while(true){ cin>>v; if(v==-1) break; b.insert(v); }
        cout<<"A: "<<a<<"\nB: "<<b<<"\n";
        cout<<"A==B: "<<(a==b)<<"\n";
        List<int> c=a+b;
        cout<<"A+B: "<<c<<"\n";
        cout<<"Reversed A: "<<!a<<"\n";
    }
    else if(ch==2){
        List<string> a,b;
        string s;
        cout<<"Enter elements of List A (type 'end' to stop): ";
        while(true){ cin>>s; if(s=="end") break; a.insert(s); }
        cout<<"Enter elements of List B (type 'end' to stop): ";
        while(true){ cin>>s; if(s=="end") break; b.insert(s); }
        cout<<"A: "<<a<<"\nB: "<<b<<"\n";
        cout<<"A==B: "<<(a==b)<<"\n";
        List<string> c=a+b;
        cout<<"A+B: "<<c<<"\n";
        cout<<"Reversed A: "<<!a<<"\n";
    }
    else if(ch==3){
        List<complex<double>> a,b;
        complex<double> c1;
        double r,i;
        cout<<"Enter complex numbers for List A (enter 999 to stop): ";
        while(true){ cin>>r; if(r==999) break; cin>>i; a.insert({r,i}); }
        cout<<"Enter complex numbers for List B (enter 999 to stop): ";
        while(true){ cin>>r; if(r==999) break; cin>>i; b.insert({r,i}); }
        cout<<"A: "<<a<<"\nB: "<<b<<"\n";
        cout<<"A==B: "<<(a==b)<<"\n";
        List<complex<double>> c=a+b;
        cout<<"A+B: "<<c<<"\n";
        cout<<"Reversed A: "<<!a<<"\n";
    }
    else cout<<"Invalid choice\n";
}
