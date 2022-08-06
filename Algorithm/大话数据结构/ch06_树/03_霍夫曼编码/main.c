#include <stdio.h>
#include <string.h>
#include "huffman.h"


main(){
    HuffmanTree *hp;
    char *s = "BADCADFEED";

    /* 原始编码 */
    printf("=========================origin_code=========================\n");
    char *code_table[] = {"000", "001", "010", "011", "100", "101"};
    char code_table2[6][MAXWORD];
    char origin[MAXWORD];
    int i;

    for (i = 0; i < 6; i++)
        strcpy(code_table2[i], code_table[i]);
    CharToCode(origin, s, code_table2);
    printf("%s\n", origin);


    /* 初始化Huffman */
    printf("=========================init_Huffman=========================\n");
    int freq[] = {27, 8, 15, 15, 30 ,5};
    hp = InitHuffman(freq, 6);
    PrintData(hp);

    /* 测试排序 */
    printf("=========================quicksort=========================\n");
    WeightQuickSort(hp, 0, hp->count-1);
    PrintData(hp);

    /* 测试合并 */
    printf("=========================merge_tree=========================\n");
    BTree bp;
    bp = MergeNode(hp->data[5], hp->data[4]);
    PostPrint(bp);

    /* 生成Huffman树 */
    printf("=========================get_HuffmanTree=========================\n");
    CreateHuffman(hp);
    PrintHuffman(hp);

    /* 生成Huffman编码 */
    printf("=========================get_HuffmanCode=========================\n");
    char huffmancode[6][MAXWORD];

    GetHuffmanCode(hp->data[0], "", huffmancode);
    for (i = 0; i < 6; i++)
        printf("%c: %s\n", 'A'+i, huffmancode[i]);

    /* 将字符串转为Huffman编码 */
    printf("=========================to_HuffmanCode=========================\n");
    char tohuffman[MAXWORD]; 
    CharToCode(tohuffman, s, huffmancode);
    
    printf("origin:  %s\n", origin);
    printf("huffman: %s\n", tohuffman);   
}
