#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// linkList.h

#ifndef LINKLIST_H  // 防止头文件被多次包含
#define LINKLIST_H

// 定义常量
enum INSERTION
{
	INSERT_TO_HEAD,
	INSERT_TO_TAIL,
	INSERT_TO_RANDOM
};

#define Status int
#define OK 1
#define ERR -1

// 声明结构体
typedef struct elementType {
	int data;
	//char* string;
} elementType;

// 单向链表
typedef struct oneWayLinkList {
	elementType data; // 数据域
	struct oneWayLinkList* next; // 指针域
} linkList, * linkNode;

// 双向链表
typedef struct twoWayLinkList {
	elementType data;
	struct twoWayLinkList* prior;
	struct twoWayLinkList* next;
} tLinkList, *tLinkNode;

// 双向循环链表
typedef struct twoWayCircularLinkList {
	elementType data;
	struct twoWayCircularLinkList* prior;
	struct twoWayCircularLinkList* next;
}tcLinkList, *tcLinkNode;


// 函数声明
//带头单链表
linkNode isNodeNULL();
linkNode creatNewNode();
Status creatLinkList(linkNode* headNodePointer, linkNode* tailNodePointer);
Status initLinkList(const linkNode headNodePointer);
Status insertToHead(const linkNode headNodePointer, linkNode* tailNodePointer, const elementType data);
Status insertToTail(const linkNode headNodePointer, linkNode* tailNodePointer, const elementType data);
Status insertToRandom(const linkNode headNodePointer, const elementType data, int location);
Status addElement(const linkNode headNodePointer, linkNode* tailNodePointer, const elementType data, enum INSERTION insertion, int location);
Status delectElem(const linkNode headNodePointer, int location);
Status cleanLinkList(const linkNode headNodePointer, linkNode* tailNodePointer);
Status destorLinkList(const linkNode headNodePointer, linkNode* tailNodePointer);
Status printLinkList(const linkNode headNodePointer);

// 双向链表
tLinkNode creatNewTwoNode();
Status creatTwoList(tLinkNode* headNodePointer, tLinkNode* tailNodePointer);
Status initTwoList(const tLinkNode headNodePointer);
Status insertToHeadTwo(tLinkNode headNodePointer, tLinkNode* tailNodePointer, elementType data);
Status insertToTailTwo(tLinkNode headNodePointer, tLinkNode* tailNodePointer, elementType data);
Status addElementTwo(tLinkNode headNodePointer, tLinkNode* tailNodePointer, elementType data, enum INSERTION insertion, int location);
Status cleanLinkListTwo(tLinkNode headNodePointer, tLinkNode* tailNodePointer);
Status destoryLinkListTwo(tLinkNode headNodePointer, tLinkNode* tailNodePointer);
int locateElementTwo(tLinkNode headNodePointer, elementType data);
elementType getElement(tLinkNode headNodePointer, int location);
Status printListTwo(tLinkNode headNodePointer);

// 双向循环链表
tcLinkNode creatNewTcNode();
Status creatTcLinkList(tcLinkNode* headNodePointer, tcLinkNode* tailNodePointer);
Status initTcLinkList(tcLinkNode headNodePointer, tcLinkNode* tailNodePointer);
Status cleanTcLinkList(tcLinkNode headNodePointer, tcLinkNode* tailNodePointer);
Status destroyLinkListTc(tcLinkNode* headNodePointer, tcLinkNode* tailNodePointer);
Status printTcList(tcLinkNode headNodePointer);
Status insertToHeadTc(tcLinkNode headNodePointer, tcLinkNode* tailNodePointer, elementType data);
Status insertToTailTc(tcLinkNode headNodePointer, tcLinkNode* tailNodePointer, elementType data);
Status insertToRandomTc(tcLinkNode headNodePointer, elementType data, int location);
Status addElemTc(tcLinkNode headNodePointer, tcLinkNode* tailNodePointer, elementType data, enum INSERTION insertion, int location);
int locateElemTc(tcLinkNode headNodePointer, elementType data);
elementType getElemTc(tcLinkNode headNodePointer, int location);
Status delectTargetNode(tcLinkNode headNodePointer, int location);

#endif

