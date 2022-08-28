#include <stdio.h>
#include <stdlib.h>
#include "HashTable.h"


/* InitHashTable: 初始化散列表 */
void InitHashTable(HashTable *hp){
    int i;
    
    hp->elem = (int *)malloc(HASHSIZE * sizeof(int));
    hp->count = 0;
    for (i = 0; i < HASHSIZE; i++)
        hp->elem[i] = NULLKEY;
}


/* Hash: 计算哈希值 */
int Hash(int key){
    return key % HASHSIZE;
}


/* InsertHash: 将key插入哈希表 */
int InsertHash(HashTable *hp, int key){
    int addr;

    if (hp->count == HASHSIZE){         /* 哈希表已满，无法插入 */
        printf("Insert failed: hash table is full\n");
        return 0;
    }

    addr = Hash(key);
    while (hp->elem[addr] != NULLKEY)   /* 如果不为空，则冲突 */
        addr = (addr + 1) % HASHSIZE;   /* 以线性探测的方式搜索下一个地址 */
    hp->elem[addr] = key;
    hp->count++;
}


/* SearchHash：在哈希表中搜索key */
int SearchHash(HashTable H, int key, int *addr){
    *addr = Hash(key);
    while (H.elem[*addr] != key){
        *addr = (*addr + 1) % HASHSIZE;
        if (H.elem[*addr] == NULLKEY || *addr == Hash(key)){
            printf("Not find %d\n", key);
            return 0;
        }   
    }
    return 1;
}


/* 打印哈希表 */
void PrintHash(HashTable H){
    int i;

    for (i = 0; i < HASHSIZE; i++){
        if (H.elem[i] == NULLKEY)
            printf("%d: null\n", i);
        else
            printf("%d: %d\n", i, H.elem[i]);
    }
}