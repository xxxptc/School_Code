#include "linkList.h"
// 双向链表

// 创建新节点
tLinkNode creatNewTwoNode() {
	tLinkNode newNode = (tLinkList*)malloc(sizeof(tLinkList));
	return newNode;
}

// 创建链表
Status creatTwoList(tLinkNode* headNodePointer, tLinkNode* tailNodePointer) {
	*headNodePointer = creatNewTwoNode();
	*tailNodePointer = *headNodePointer;
	if (*headNodePointer == NULL)
		return ERR;
	return OK;
}

// 初始化链表
Status initTwoList(const tLinkNode headNodePointer) {
	headNodePointer->data.data = 0; // 链表的长度设置为0
	headNodePointer->prior = NULL; 
	headNodePointer->next = NULL; 
	return OK;
}

// 头插
Status insertToHeadTwo(tLinkNode headNodePointer, tLinkNode* tailNodePointer, elementType data) {
	tLinkNode curP = headNodePointer;
	tLinkNode newNode = creatNewTwoNode();
	if (newNode == NULL)
		return ERR;
	if (headNodePointer->data.data == 0) { 
		newNode->data = data; // 存入数据
		newNode->prior = curP; // 新节点指向头节点
		newNode->next = curP->next; // 新节点指向首元节点
		curP->next = newNode; // 头节点指向新节点
		*tailNodePointer = newNode;
		headNodePointer->data.data++;
		return OK;
	}
	newNode->data = data;
	newNode->prior = curP; 
	newNode->next = curP->next;
	curP->next->prior = newNode;
	curP->next = newNode;
	headNodePointer->data.data++;
	return OK;
}

// 尾插
Status insertToTailTwo(tLinkNode headNodePointer, tLinkNode* tailNodePointer, elementType data) {
	tLinkNode curP = headNodePointer;
	tLinkNode newNode = creatNewTwoNode();
	if (newNode == NULL)
		return ERR;
	newNode->data = data;
	newNode->prior = *tailNodePointer;
	newNode->next = (*tailNodePointer)->next;
	(*tailNodePointer)->next = newNode;
	*tailNodePointer = newNode;
	headNodePointer->data.data++;
	return OK;
}

// 在任意位置插入节点
Status insertToRandomTwo(const tLinkNode headNodePointer, elementType data, int location) {
	tLinkNode curP = headNodePointer;
	for (int i = 0; i < location - 1 && curP != NULL; i++) {
		curP = curP->next;
	}
	tLinkNode newNode = creatNewTwoNode();
	if (newNode == NULL || curP == NULL)
		return ERR;
	newNode->data = data;
	newNode->prior = curP; // 先让新节点指向插入位置前的节点
	newNode->next = curP->next; // 再让新节点指向插入位置原来的节点 
	curP->next->prior = newNode; // 然后让插入位置原来的节点指向新节点
	curP->next = newNode; // 最后让插入位置前一个节点指向新节点
	headNodePointer->data.data++;
	return OK;
}

// 添加节点
Status addElementTwo(tLinkNode headNodePointer, tLinkNode* tailNodePointer, elementType data, enum INSERTION insertion, int location) {
	Status status; // 储存状态码
	switch (insertion) {
		case INSERT_TO_HEAD: {
			status = insertToHeadTwo(headNodePointer, tailNodePointer, data);
			break;
		}
		case INSERT_TO_TAIL: {
			status = insertToTailTwo(headNodePointer, tailNodePointer, data);
			break;
		}
		case INSERT_TO_RANDOM: {
			if (location > headNodePointer->data.data)
				status = insertToTailTwo(headNodePointer, tailNodePointer, data);
			else if (location < 1)
				status = insertToHeadTwo(headNodePointer, tailNodePointer, data);
			else
				status = insertToRandomTwo(headNodePointer, data, location);
			break;
		}
		default: {
			return ERR;
		}
	}
	return status;
}

// 清空链表
Status cleanLinkListTwo(tLinkNode headNodePointer, tLinkNode* tailNodePointer) {
	tLinkNode curP = headNodePointer;
	tLinkNode delP = NULL;
	while (curP->next != NULL) {
		delP = curP->next; // 标记
		curP->next = delP->next; // 换位
		free(delP); // 释放
		headNodePointer->data.data--;
	}
	*tailNodePointer = headNodePointer; // 更新尾指针
	return OK;
}

// 销毁链表
Status destoryLinkListTwo(tLinkNode headNodePointer, tLinkNode* tailNodePointer) {
	cleanLinkListTwo(headNodePointer, tailNodePointer);
	free(headNodePointer);
	return OK;
}

// 查找返回位置
int locateElementTwo(tLinkNode headNodePointer, elementType data) {
	tLinkNode curP = headNodePointer->next;
	int index = 1;
	while (curP != NULL && curP->data.data != data.data) {
		curP = curP->next;
		index++;
	}
	if (curP == NULL)
		return -2;
	return index;
}

// 取值
elementType getElement(tLinkNode headNodePointer, int location) {
	tLinkNode curP = headNodePointer;
	for (int i = 0; i < location && curP != NULL; i++) {
		curP = curP->next;
	}
	if (curP == NULL) {
		elementType result;
		result.data = -999999;
		//result.string = "error";
		return result;
	}	
	return curP->data;
}

// 打印链表
Status printListTwo(tLinkNode headNodePointer) {
	tLinkNode curP = headNodePointer->next;
	int index = 1;
	while (curP != NULL) {
		printf("%d->[%d] ", index, curP->data.data);
		curP = curP->next;
		index++;
	}
	printf("\n");
	return OK;
}
