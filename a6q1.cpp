#include <iostream>
#include <string>
#include <complex>
using namespace std;

template<typename T>
class Stack {
    struct Node {
        T data;
        Node* next;
        Node(T v, Node* n=nullptr):data(v),next(n){}
    };
    Node* top;
public:
    Stack():top(nullptr){}
    Stack(const Stack& s){
        top=nullptr;
        if(s.top){
            Node* p=s.top;
            Node* arr[1000];
            int k=0;
            while(p){ arr[k++]=p; p=p->next; }
            for(int i=k-1;i>=0;i--) push(arr[i]->data);
        }
    }
    ~Stack(){ while(top) pop(); }
    void push(T v){ top=new Node(v,top); }
    void pop(){ if(top){ Node* t=top; top=top->next; delete t; } else cout<<"Stack is empty!\n"; }
    bool empty(){ return top==nullptr; }
    T peek(){ return top->data; }
    Stack operator!(){
        Stack r;
        Node* p=top;
        while(p){ r.push(p->data); p=p->next; }
        return r;
    }
    bool operator==(Stack& s){
        Node* p=top; Node* q=s.top;
        while(p&&q){
            if(p->data!=q->data) return false;
            p=p->next; q=q->next;
        }
        return p==nullptr && q==nullptr;
    }
    Stack& operator=(const Stack& s){
        if(this==&s) return *this;
        while(top) pop();
        if(s.top){
            Node* p=s.top;
            Node* arr[1000];
            int k=0;
            while(p){ arr[k++]=p; p=p->next; }
            for(int i=k-1;i>=0;i--) push(arr[i]->data);
        }
        return *this;
    }
    friend istream& operator>>(istream& in, Stack& s){
        T v; in>>v; s.push(v); return in;
    }
    friend ostream& operator<<(ostream& out, Stack& s){
        Node* p=s.top;
        out<<"[Top] ";
        while(p){ out<<p->data<<" -> "; p=p->next; }
        out<<"NULL";
        return out;
    }
};

template<typename T>
void menu(Stack<T>& s){
    int op;
    do{
        cout<<"\n--- Stack Menu ---\n";
        cout<<"1. Push\n";
        cout<<"2. Pop\n";
        cout<<"3. Display\n";
        cout<<"4. Reverse (!)\n";
        cout<<"5. Copy (=)\n";
        cout<<"6. Compare (==)\n";
        cout<<"0. Exit\n";
        cout<<"Enter choice: ";
        cin>>op;

        if(op==1){ 
            cout<<"Enter value: "; 
            T x; cin>>x; 
            s.push(x); 
            cout<<"Pushed!\n"; 
        }
        else if(op==2){ 
            s.pop(); 
        }
        else if(op==3){ 
            cout<<s<<endl; 
        }
        else if(op==4){ 
            Stack<T> r=!s; 
            cout<<"Reversed Stack: "<<r<<endl; 
        }
        else if(op==5){ 
            Stack<T> c; c=s; 
            cout<<"Copied Stack: "<<c<<endl; 
        }
        else if(op==6){ 
            Stack<T> t; 
            int n; 
            cout<<"How many elements in 2nd stack? "; 
            cin>>n; 
            for(int i=0;i<n;i++){ 
                cout<<"Enter value "<<i+1<<": "; 
                T x; cin>>x; 
                t.push(x);
            } 
            if(s==t) cout<<"Stacks are Equal\n"; 
            else cout<<"Stacks are Not Equal\n"; 
        }
        else if(op==0){ 
            cout<<"Exiting...\n"; 
        }
        else cout<<"Invalid choice!\n";

    }while(op!=0);
}

int main(){
    cout<<"Choose datatype for Stack:\n";
    cout<<"1. Integer\n";
    cout<<"2. String\n";
    cout<<"3. Complex Number\n";
    cout<<"Enter choice: ";
    int ch; cin>>ch;

    if(ch==1){
        Stack<int> s; 
        menu(s);
    }
    else if(ch==2){
        Stack<string> s; 
        menu(s);
    }
    else if(ch==3){
        Stack<complex<double>> s; 
        int op;
        do{
            cout<<"\n--- Stack Menu ---\n";
            cout<<"1. Push\n2. Pop\n3. Display\n4. Reverse\n5. Copy\n6. Compare\n0. Exit\n";
            cout<<"Enter choice: "; cin>>op;

            if(op==1){ 
                double a,b; 
                cout<<"Enter real and imag: "; cin>>a>>b; 
                s.push({a,b}); 
                cout<<"Pushed!\n"; 
            }
            else if(op==2){ s.pop(); }
            else if(op==3){ cout<<s<<endl; }
            else if(op==4){ Stack<complex<double>> r=!s; cout<<"Reversed: "<<r<<endl; }
            else if(op==5){ Stack<complex<double>> c; c=s; cout<<"Copied: "<<c<<endl; }
            else if(op==6){ 
                Stack<complex<double>> t; int n; 
                cout<<"How many elements in 2nd stack? "; cin>>n; 
                for(int i=0;i<n;i++){ double a,b; cout<<"Enter real imag: "; cin>>a>>b; t.push({a,b}); }
                if(s==t) cout<<"Stacks are Equal\n"; else cout<<"Stacks are Not Equal\n"; 
            }
            else if(op==0){ cout<<"Exiting...\n"; }
        }while(op!=0);
    }
}
