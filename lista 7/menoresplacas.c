#include <stdio.h>
#include <stdlib.h>

#define min(a, b) (a < b ? a : b)
#define max(a, b) (b < a ? a : b)
#define Item int
#define key(x) (x)
#define less(a, b) (a > b)
#define swap(a, b)  \
    {               \
        Item t = a; \
        a = b;      \
        b = t;      \
    }
#define cmpswap(a, b) \
    if (less(b, a))   \
    swap(a, b)

Item NULL_ITEM = -1;

typedef struct
{
    Item *heap;
    size_t size, capacity;
} PriorityQueue;

void HEAP_fixup(Item *heap, int i)
{
    for (; i > 1 && less(heap[i / 2], heap[i]); i /= 2)
        swap(heap[i], heap[i / 2]);
}

void HEAP_fixdown(Item *heap, size_t size, int i)
{
    for (int larger = i * 2; i * 2 <= size; i = larger, larger = i * 2)
    {
        if (larger < size && less(heap[larger], heap[larger + 1]))
            larger++;

        if (!less(heap[i], heap[larger]))
            break;

        swap(heap[i], heap[larger]);
    }
}

PriorityQueue PQ_init(size_t capacity)
{
    PriorityQueue pq = {.capacity = capacity, .size = 0};
    pq.heap = malloc((capacity + 1) * sizeof(Item));
    return pq;
}

void PQ_free(PriorityQueue pq)
{
    free(pq.heap);
}

int PQ_isEmpty(PriorityQueue pq)
{
    return pq.size == 0;
}

void PQ_ensureCapacity(PriorityQueue *pq, size_t newCapacity)
{
    if (newCapacity <= pq->capacity)
        return;

    pq->capacity *= 4;
    pq->heap = realloc(pq->heap, (pq->capacity + 1) * sizeof(Item));
}

void PQ_insert(PriorityQueue *pq, Item x)
{
    PQ_ensureCapacity(pq, pq->size + 1);
    pq->heap[++pq->size] = x;
    HEAP_fixup(pq->heap, pq->size);
}

Item PQ_getTop(PriorityQueue pq)
{
    return pq.heap[1];
}

Item PQ_extractTop(PriorityQueue *pq)
{
    if (PQ_isEmpty(*pq))
        return NULL_ITEM;

    Item top = PQ_getTop(*pq);
    pq->heap[1] = pq->heap[pq->size--];
    HEAP_fixdown(pq->heap, pq->size, 1);
    return top;
}

int main()
{
    PriorityQueue pq = PQ_init(16);
    int t, p, v[100];

    while (scanf(" %d %d", &t, &p) == 2)
    {
        if (t == 1)
            PQ_insert(&pq, p);
        else
        {
            int n;
            for (n = 0; n < p; n++)
            {
                int top = PQ_extractTop(&pq);
                if (top == NULL_ITEM)
                    break;
                v[n] = top;
            }
            for (int i = 0; i < n; i++)
            {
                printf("%d%c", v[i], " \n"[i == n - 1]);
                PQ_insert(&pq, v[i]);
            }
        }
    }

    PQ_free(pq);

    return 0;
}