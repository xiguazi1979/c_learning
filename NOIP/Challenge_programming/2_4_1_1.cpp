const int MAX_N = 100;
int heap[MAX_N];
int sz = 0;
void push(int x)
{
    int i = sz++;
    while (i > 0) {
        int p = (i - 1) / 2; // parent node ID
        if (heap[p] <= x) {
            break;
        }
        else {
            heap[i] = heap[p];
            i = p;
        }
    }
    heap[i] = x;
}

int pop()
{
    int ret = heap[0]; // root value to be pop out
    int x = heap[--sz]; // end leaf value to be adjusted from root

    int i = 0;
    while (i * 2 + 1 < sz) {
        int a = i * 2 + 1, b = i * 2 + 2;
        if (b < sz && heap[b] < heap[a]) {
            a = b;
        }
        if (heap[a] >= x) {
            break;
        }
        heap[i] = heap[a];
        i = a;
    }
    heap[i] = x;
    return ret;
}

int main()
{
    return 0;
}