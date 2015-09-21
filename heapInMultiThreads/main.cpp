#include<iostream>
#include<stdlib.h>
#include<pthread.h>
#include<string.h>

using namespace std;

int count = 0;

struct Node{
    int a;
    char *str;
};

void * work(void *arg){
    Node *pNode = (Node*)arg;
    pNode->a = 2;
    pNode->str = new char[10];
    strcpy(pNode->str, "child thread new char!");
    count++;
    return NULL;
}

void *work4pointer(void *arg){
    char *pStr = (char *)arg;
    pStr = new char[10];
    strcpy(pStr, "child thread new char!");
    return NULL;
}

int main(){
    Node *pNode = new Node();
    pNode->a = 1;
    pNode->str = "main thread!";
    pthread_t tid;

    if(pthread_create(&tid, NULL, work, (void*)pNode) != 0){
    }
    while(count != 1);
    cout<<pNode->a<<endl;
    cout<<pNode->str<<endl;

    cout<<"------------------------"<<endl;

    count = 0;
    char *pStr = "main thread!";
    if(pthread_create(&tid, NULL, work4pointer, (void*)pStr) != 0){
    }
    cout<<pStr<<endl;

    return 0;
}
