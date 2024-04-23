//#include <stdio.h>
//#include <stdlib.h>
#include "linkList.h"
// 单链表（带头节点）

// 检查节点是否为NULL
linkNode isNodeNULL() {
	linkNode newNode = (linkList*)malloc(sizeof(linkList));
	if (newNode == NULL)
		return NULL;
	return newNode;
}

// 创建新的节点
linkNode creatNewNode() {
	linkNode tempNode = isNodeNULL();
	return tempNode != NULL ? tempNode : NULL;
}

// 创建链表
 Status creatLinkList(linkNode* headNodePointer, linkNode* tailNodePointer) {
	// 让指针指向头节点
	*headNodePointer = creatNewNode();
	*tailNodePointer = *headNodePointer;
	// 指针的非空判断
	if (*headNodePointer == NULL)
		return ERR;
	return OK;
}

// 初始化链表
Status initLinkList(const linkNode headNodePointer) {
	elementType length;
	length.data = 0;
	// 头节点的数据域用来储存链表的长度
	(headNodePointer)->data = length;
	(headNodePointer)->next = NULL;
	return OK;
}

// 插入元素->头插法
Status insertToHead(const linkNode headNodePointer, linkNode* tailNodePointer, elementType data) {
	// 头插法：
	// 1.创建新节点
	// 2.新节点next指向首元节点
	// 3.头节点next指向新节点
	// 4.链表长度自增
	linkNode newNode = creatNewNode();
	if (newNode == NULL)
		return ERR;
	newNode->data = data;
	newNode->next = (headNodePointer)->next;
	(headNodePointer)->next = newNode;
	if (headNodePointer->data.data == 0)
		*tailNodePointer = newNode;
	(headNodePointer)->data.data++; // 链表长度自增
	return OK;
}


// 插入元素->尾插法
Status insertToTail(const linkNode headNodePointer,  linkNode* tailNodePointer, const elementType data) {
	// 尾插法
	// 1.创建新节点
	// 2.尾指针的next赋值给新节点的next
	// 3.新节点赋值给尾指针的next
	linkNode newNode = creatNewNode();
	newNode->data = data;
	newNode->next = (*tailNodePointer)->next;
	(*tailNodePointer)->next = newNode;
	// 更新尾指针
	*tailNodePointer = newNode;
	// 长度自增
	headNodePointer->data.data++;
	return OK;
}


// 在任意位置插入元素
Status insertToRandom(const linkNode headNodePointer, const elementType data, int location) {
	// 在任意位置插入
	// 1. 创建新节点
	// 2. 用循环遍历得到location-1位置的指针
	// 3. 新节点的next赋值为插入位置减一的next
	// 4. 新节点赋值给插入位置减一的next
	// 5. 长度自增
	linkNode curP = (headNodePointer);
	linkNode newNode = creatNewNode();
	if (newNode == NULL)
		return ERR;
	int i = 0; // 细节：curP开始指向头节点
	while (curP != NULL && i < location - 1) {
		curP = curP->next;
		i++;
	}
	if (curP == NULL)
		return ERR;
	newNode->data = data;
	newNode->next = curP->next;
	curP->next = newNode;
	(headNodePointer)->data.data++;
	return OK;
}

// 添加元素 
Status addElement(const linkNode headNodePointer,  linkNode* tailNodePointer, const elementType data, enum INSERTION insertion, int location) {
	// switch方法判断插入方法
	Status status; // 储存状态码
	switch (insertion) {
		case INSERT_TO_HEAD: {
			status = insertToHead(headNodePointer, tailNodePointer, data);
			break;
		}
		case INSERT_TO_TAIL: {
			status = insertToTail(headNodePointer, tailNodePointer, data);
			break;
		}
		case INSERT_TO_RANDOM: {
			// 检查插入的位置是否合法
			if (location > headNodePointer->data.data) 
				status = insertToTail(headNodePointer, tailNodePointer, data);
			else if (location < 1) 
				status = insertToHead(headNodePointer, tailNodePointer, data);
			else 
				status = insertToRandom(headNodePointer, data, location);
			break;
		}
		default: {
			printf("插入方法不存在！");
			status = ERR;
		}
	}
	return status;
}

// 删除元素
Status delectElem(const linkNode headNodePointer, int location) {
	linkNode curP = (headNodePointer);
	linkNode delP = NULL; 
	int i = 0;
	while (curP != NULL && i < location - 1) {
		curP = curP->next;
		i++;
	}
	if (curP == NULL)
		return ERR;
	delP = curP->next;
	curP->next = delP->next;
	free(delP);
	return OK;
}

// 清空链表
Status cleanLinkList(const linkNode headNodePointer,  linkNode* tailNodePointer) {
	linkNode curP = headNodePointer; // 指针指向头节点(不可改变)
	linkNode delP = NULL;
	while (curP->next != NULL) {
		delP = curP->next;
		curP->next = delP->next;
		free(delP);
		headNodePointer->data.data--;
	}
	*tailNodePointer = headNodePointer; // 更新尾指针
	return OK;
}

// 销毁链表
Status destorLinkList(const linkNode headNodePointer, linkNode* tailNodePointer) {
	cleanLinkList(headNodePointer, tailNodePointer);
	free(headNodePointer); // 细节: 头指针和尾指针都指向同一块内存空间（地址相同）释放头指针时尾指针也同时被释放了
	return OK;
}

// 打印链表
Status printLinkList(const linkNode headNodePointer) {
	linkNode curP = headNodePointer->next;
	int index = 1;
	while (curP != NULL) {
		printf("%d->[%d] ", index, curP->data.data);
		curP = curP->next;
		index++;
	}
	return OK;
}
