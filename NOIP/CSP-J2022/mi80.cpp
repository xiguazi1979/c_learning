#include <stdio.h>
#include <stdlib.h>
 
//����������
typedef struct Node {
    int data;           //�������ͣ�����԰�int�͵�data���������������ͣ������ṹ��struct�ȸ�������
    struct Node *next;          //�������ָ����
} Node,*LinkedList;
 
//������ĳ�ʼ��
LinkedList LinkedListInit() {
    Node *L;
    L = (Node *)malloc(sizeof(Node));   //������ռ�
    if(L==NULL){    //�ж�����ռ��Ƿ�ʧ��
        exit(0);    //���ʧ�����˳�����
    }
    L->next = NULL;          //��next����ΪNULL,��ʼ����Ϊ0�ĵ�����
    return L;
}
 
 
//������Ľ���1��ͷ�巨����������
LinkedList LinkedListCreatH() {
    Node *L;
    L = (Node *)malloc(sizeof(Node));   //����ͷ���ռ�
    L->next = NULL;                      //��ʼ��һ��������
 
    int x;                         //xΪ�����������е�����
    while(scanf("%d",&x) != EOF) {
        Node *p;
        p = (Node *)malloc(sizeof(Node));   //�����µĽ��
        p->data = x;                     //���������ֵ
        p->next = L->next;                    //�������뵽��ͷL-->|2|-->|1|-->NULL
        L->next = p;
    }
    return L;
}
 
 
//������Ľ���2��β�巨����������
 
LinkedList LinkedListCreatT() {
    Node *L;
    L = (Node *)malloc(sizeof(Node));   //����ͷ���ռ�
    L->next = NULL;                  //��ʼ��һ��������
    Node *r;
    r = L;                          //rʼ��ָ���ն˽�㣬��ʼʱָ��ͷ���
    int x;                         //xΪ�����������е�����
    while(scanf("%d",&x) != EOF) {
        Node *p;
        p = (Node *)malloc(sizeof(Node));   //�����µĽ��
        p->data = x;                     //���������ֵ
        r->next = p;                 //�������뵽��ͷL-->|1|-->|2|-->NULL
        r = p;
    }
    r->next = NULL;
 
    return L;
}
 
 
//������Ĳ��룬������ĵ�i��λ�ò���x��Ԫ��
 
LinkedList LinkedListInsert(LinkedList L,int i,int x) {
    Node *pre;                      //preΪǰ�����
    pre = L;
    int tempi = 0;
    for (tempi = 1; tempi < i; tempi++) {
        pre = pre->next;                 //���ҵ�i��λ�õ�ǰ�����
    }
    Node *p;                                //����Ľ��Ϊp
    p = (Node *)malloc(sizeof(Node));
    p->data = x;
    p->next = pre->next;
    pre->next = p;
 
    return L;
}
 
 
//�������ɾ������������ɾ��ֵΪx��Ԫ��
 
LinkedList LinkedListDelete(LinkedList L,int x) {
    Node *p,*pre;                   //preΪǰ����㣬pΪ���ҵĽ�㡣
    p = L->next;
     
    while(p->data != x) {              //����ֵΪx��Ԫ��
        pre = p;
        p = p->next;
    }
    pre->next = p->next;          //ɾ������������ǰ��nextָ�����̡�
    free(p);
     
    return L;
}
 
//�������ݵ��޸ģ����������޸�ֵΪx��Ԫ�ر�ΪΪk��
LinkedList LinkedListReplace(LinkedList L,int x,int k) {
    Node *p=L->next;
    int i=0;
    while(p){
        if(p->data==x){
            p->data=k;
        }
        p=p->next;
    }
    return L;
}
 
 
//�������������
void printList(LinkedList L){
    Node *p=L->next;
    int i=0;
    while(p){
        printf("��%d��Ԫ�ص�ֵΪ:%d\n",++i,p->data);
        p=p->next;
    }
} 
 
int main() {
    //���� 
    LinkedList list;
    printf("�����뵥��������ݣ���EOF��β\n");
    list = LinkedLireatTstC();
    //list=LinkedListCreatT();
    printList(list);
     
    //���� 
    int i;
    int x;
    printf("������������ݵ�λ�ã�");
    scanf("%d",&i);
    printf("������������ݵ�ֵ��");
    scanf("%d",&x);
    LinkedListInsert(list,i,x);
    printList(list);
     
    //�޸�
    printf("�������޸ĵ����ݣ�");
    scanf("%d",&i);
    printf("�������޸ĺ��ֵ��");
    scanf("%d",&x);
    LinkedListReplace(list,i,x);
    printList(list);
     
    //ɾ�� 
    printf("������Ҫɾ����Ԫ�ص�ֵ��");
    scanf("%d",&x);
    LinkedListDelete(list,x);
    printList(list);
 
    return 0;
}

