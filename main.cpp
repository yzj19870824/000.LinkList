#include "stdlib.h"
#include "stdio.h"
#include "malloc.h"
#include "string.h"

typedef int DataType;

struct ListNode{
    DataType m_nKey;
    struct ListNode* m_pNext;
};

typedef struct ListNode* LinkList;

LinkList CreateLinkListTail(LinkList root, int arr[], int len){
    int idx;
    for(idx = 0; idx < len; idx++){
        LinkList tmp = (LinkList)malloc(sizeof(ListNode));
        tmp->m_nKey = arr[idx];
        tmp->m_pNext = root->m_pNext;
        root->m_pNext = tmp;
    }

    return root;
}

LinkList CreateLinkListHead(LinkList root, int arr[], int len){
    int i;
    LinkList cur = root;
    for(i = 0; i < len; i++){
        LinkList tmp = (LinkList)malloc(sizeof(struct ListNode));
        tmp->m_nKey = arr[i];
        tmp->m_pNext = cur->m_pNext;
        cur->m_pNext = tmp;
        cur = tmp;
    }
    return root;
}

/*输出倒数第idx个节点
 * 思路1：
 *      a 计算整个链表长度len
 *      b 指针步进len-k时，指向倒数第k个节点
 * 思路2：
 *      a 两个指针初始指向root，前指针步进k
 *      b 两个指针同时步进，前指针指向尾节点时，则后指针则为倒数第k个节点
*/
LinkList ShowBackNode(LinkList root, int idx){
    LinkList pre = root;
    LinkList post = root;

    for(; idx>0 && post!=NULL;idx--){
        post = post->m_pNext;
    }
    if(idx>0){
        return NULL;
    }

    while(NULL != post){
        pre = pre->m_pNext;
        post = post->m_pNext;
    }

    return pre;
}

LinkList ReverseLinkList(LinkList root){
    return root;
}

bool IsCycleInLinkList(LinkList root){
    LinkList p = root;
    LinkList q = root;
    while(q!=NULL){
        p = p->m_pNext;
        q= q->m_pNext->m_pNext;
        if(p == q){
            return true;
        }
    }
    return false;
}

void ShowLinkList(LinkList root){
    LinkList tmp = root->m_pNext;
    while(NULL != tmp){
        printf("%d ",tmp->m_nKey);
        tmp = tmp->m_pNext;
    }
    printf("\n");
}

void DeleteLinkList(LinkList root){
    int i;
    for(i = 0;i < 5; i++){
        LinkList tmp = root->m_pNext;
        while(NULL != tmp){
            tmp = tmp->m_pNext;
        }
        free(tmp);
    }
    free(root);
}

int main() {
    int arr[5]={2,4,8,5,1};
    LinkList root = (LinkList)malloc(sizeof(struct ListNode));
    root->m_pNext = NULL;

    LinkList list2 = CreateLinkListHead(root,arr,5);
    ShowLinkList(list2);

    LinkList list3 = ReverseLinkList(root);
    ShowLinkList(list3);

    int idx = 8;
    LinkList list4 = ShowBackNode(root, idx);
    if(NULL == list4){
        printf("idx is longer than list length\n");
    }else{
        printf("back %d node is %d\n", idx, list4->m_nKey);
    }

    bool isCycle = IsCycleInLinkList(root);
    printf("%s\n",isCycle?"cycle is in link list":"cycle is not in link list");

    DeleteLinkList(list2);
    return 0;
}