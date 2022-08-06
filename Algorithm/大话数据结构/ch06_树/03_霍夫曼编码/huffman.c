#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "huffman.h"


/* InitHuffman: 初始化霍夫曼编码，将字符串及权重转为二叉树 */
HuffmanTree * InitHuffman(int weight[], int len){
    HuffmanTree *hp;
    BTree bp;
    int i;

    hp = (HuffmanTree *)malloc(sizeof(HuffmanTree));
    if (!hp){
        printf("No more memory\n");
        return NULL;
    }

    for (i = 0; i < len; i++){
        bp = (BTree)malloc(sizeof(TNode));
        bp->elem = 'A' + i;
        bp->weight = weight[i];
        bp->is_leaf = 1;
        bp->lchild = bp->rchild = NULL;

        hp->data[i] = bp;
    }
    hp->count = len;
    
    return hp;
}


/* WeightQuickSort: 用快排算法对二叉树节点按权重倒序排序 */
void WeightQuickSort(HuffmanTree *hp, int left, int right){
    BTree kp, ip, tp;
    int i, j;

    if (left >= right)
        return;

    kp = hp->data[right];
    for (i = j = left; i < right; i++){
        ip = hp->data[i];
        if (ip->weight > kp->weight){
            tp = hp->data[j];
            hp->data[j] = hp->data[i];
            hp->data[i] = tp;
            j++;
        }
    }

    hp->data[right] = hp->data[j];
    hp->data[j] = kp;

    WeightQuickSort(hp, left, j-1);
    WeightQuickSort(hp, j+1, right);
}


/* MergeNode: 合并两个子树 */
BTree MergeNode(BTree T1, BTree T2){
    BTree MT;
    MT = (BTree)malloc(sizeof(TNode));
    if (MT){
        MT->weight = T1->weight + T2->weight;
        MT->elem = '*';
        MT->is_leaf = 0;
        MT->lchild = T1;
        MT->rchild = T2;
    }
    return MT;
}


/* CreateHuffman: 生成Huffman树 */
void CreateHuffman(HuffmanTree *hp){
    BTree t1, t2;

    while (hp->count > 1){
        WeightQuickSort(hp, 0, hp->count-1);        /* 先按节点权重倒序排序 */
        t1 = hp->data[hp->count-1];                 /* 合并权重最小的两个二叉树 */
        t2 = hp->data[hp->count-2];                 
        hp->data[hp->count-2] = MergeNode(t1, t2);  /* 将合并后的树加入列表 */
        hp->count--;                                /* 直到剩最后一棵树 */
    }
}


/* PrintData: 打印HuffmanTree中的节点数组 */
void PrintData(HuffmanTree *hp){
    int i;
    BTree kp;

    for (i = 0; i < hp->count; i++){
        kp = hp->data[i];
        printf("%c: %d\n", kp->elem, kp->weight);
    }
}


/* PostPrint: 后序打印二叉树 */
void PostPrint(BTree T){
    if (T){
        PostPrint(T->lchild);
        PostPrint(T->rchild);
        printf("%c: %d\n", T->elem, T->weight);
    }
}


/* PrintHuffman: 打印Huffman树 */
void PrintHuffman(HuffmanTree *hp){
    if (hp && hp->count == 1)
        PostPrint(hp->data[0]);
}


/* GetHuffmanCode: 根据Huffman树对字母进行编码 */
void GetHuffmanCode(BTree T, char * prefix, char codelist[][MAXWORD]){
    char left_prefix[MAXWORD], right_prefix[MAXWORD];
    int i;

    if (!T)
        return;

    if (T->is_leaf){
        i = T->elem - 'A';
        //printf("%d %c: %s\n", i, T->elem, copy_prefix);
        strcpy(*(codelist+i), prefix);
    } else {
        if (T->lchild){
            left_prefix[0] = '\0';
            sprintf(left_prefix, "%s0", prefix);
            GetHuffmanCode(T->lchild, left_prefix, codelist);
        }

        if (T->rchild){
            right_prefix[0] = '\0';
            sprintf(right_prefix, "%s1", prefix);
            GetHuffmanCode(T->rchild, right_prefix, codelist);
        }
    }
}



/* CharToCode: 根据字母编码表将字符串转为编码 */
char * CharToCode(char *res, char *s, char codelist[][MAXWORD]){
    char *cp;
    int i;

    cp = s;
    res[0] = '\0';
    while (isalpha(*cp)){
        i = (*cp) - 'A';
        strcat(res, codelist[i]);
        cp++;
    }

    return res;
}



