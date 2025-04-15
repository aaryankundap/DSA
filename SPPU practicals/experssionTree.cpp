#include<bits/stdc++.h>
using namespace std;

struct Node{
    char data;
    Node* left;
    Node* right;
    Node(char data){
        this->data=data;
        left=right=NULL;
    }
};

bool isOperand(char c){
    return !(c=='+' || c=='-' || c=='*' || c=='%' || c=='^');
}

struct Stack{
    Node* arr[100];
    int top;

    Stack(){
        top=-1;
    }

    void push(Node* node){
        arr[++top]=node;
    }

    Node* pop(){
        return arr[top--];
    }

    bool isEmpty(){
        return top == -1;
    }

    Node* peek(){
        return arr[top];
    }
};

int getlength(const char* str){
    int length=0;
    while( str[length]!='\0'){
        length++;
    }
    return length;
}

Node* buildTree(const char* prefix){
    Stack st;
    int len=getlength(prefix);

    for(int i=len-1;i>=0;--i){
        char current = prefix[i];

        if(isOperand(current)){
            Node* node = new Node(current);
            st.push(node);
        }else{
            Node* node=new Node(current);
            node->left=st.pop();
            node->right=st.pop();
            st.push(node);
        }
    }
    return st.peek();
}

void postOrder(Node* root){
    if(!root) return;

    Stack stack1, stack2;
    stack1.push(root);

    while(!stack1.isEmpty()){
        Node* node =stack1.pop();
        stack2.push(node);

        if(node->left)stack1.push(node->left);
        if(node->right)stack1.push(node->right);
    }
    while (!stack2.isEmpty())
    {
        cout<<stack2.pop()->data<<" ";
    }
    cout<<endl;
}

void deleteTree(Node* root){
    if(!root)return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main(){
    char prefix[100];
    cout<<"Enter the prefix expression: ";
    cin>>prefix;
    Node* root =buildTree(prefix);
    cout<<"Post order Traversal: ";
    postOrder(root);
    deleteTree(root);
    cout<<"Tree delete successfully"<<endl;   
    return 0;
}