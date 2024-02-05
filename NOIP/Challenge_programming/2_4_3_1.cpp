#include <cstddef>
#include <stdio.h>

struct node {
    int val;
    node *lch, *rch;
};

node *root = NULL;
node *insert(node *p, int x)
{
    if (p == NULL) {
        node *q = new node;
        q->val = x;
        q->lch = q->rch = NULL;
        return q;
    }
    else {
        if (x < p->val) {
            p->lch = insert(p->lch, x);
        }
        else {
            p->rch = insert(p->rch, x);
        }
        return p;
    }
}

bool find(node *p, int x)
{
    if (p == NULL) {
        return false;
    }
    else if (x == p->val) {
        return true;
        printf("Find!");
    }
    else if (x < p->val) {
        return find(p->lch, x);
    }
    else {
        return find(p->rch, x);
    }
}

node *remove(node *p, int x)
{
    if (p == NULL) {
        return NULL;
    }
    else if (x < p->val) {
        p->lch = remove(p->lch, x);
    }
    else if (p->lch == NULL) {
        node *q = p->rch;
        delete p;
        return q;
    }
    else if (p->lch->rch == NULL) {
        node *q = p->lch;
        q->rch = p->rch;
        delete p;
        return q;

    }
    else {
        node *q;
        for (q = p->lch; q->rch->rch != NULL; q = q->rch) {
            ;
        }
        node *r = q->rch;
        q->rch = r->lch;
        r->lch = p->lch;
        r->rch = p->rch;
        delete p;
        return r;
    }
    return p;
}

/**int main()
{
    int A[10] = {7,9,8,3,5,6,4,1,2,10};
    node *p;
    for (int i = 0; i < 10; i++) {
        
        insert(p, A[i]);
    }
    find(p, 5);
    return 0;
    
}
**/
int main()
{
    return 0;
}