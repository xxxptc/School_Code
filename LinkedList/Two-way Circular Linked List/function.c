#include "linkList.h"
// 双向循环链表

//创建新节点
tcLinkNode creatNewTcNode() {
	return (tcLinkList*)malloc(sizeof(tcLinkList));
}

// 创建链表 -》作用就是让头指针指向新小创建的头节点
Status creatTcLinkList(tcLinkNode* headNodePointer, tcLinkNode* tailNodePointer) {
	tcLinkNode newNode = creatNewTcNode();
	if (newNode == NULL)
		return ERR;
	*headNodePointer = newNode;
	initTcLinkList(*headNodePointer, tailNodePointer); // 初始化链表
	return OK;
}

// 初始化链表
Status initTcLinkList(tcLinkNode headNodePointer, tcLinkNode* tailNodePointer) {
	headNodePointer->data.data = 0; //设置长度
	headNodePointer->prior = NULL; // 初始化前继指针
	headNodePointer->next = NULL; // 初始化后继指针
	*tailNodePointer = headNodePointer; // 初始化尾指针
	(*tailNodePointer)->next = headNodePointer; // 首尾连接
	return OK;
}

// 删除全部指定数值元素
Status delecElemTc(tcLinkNode headNodePointer, tcLinkNode* tailNodePointer, elementType data) {
	tcLinkNode curP = headNodePointer->next;
	tcLinkNode delP = NULL;
	while (curP != NULL) {
		while (curP != NULL && curP->data.data != data.data) {
			curP = curP->next;
		}
		if (curP == NULL)
			return ERR;
		if (curP->next == NULL) { // 要删除元素位于最后一个位置
			delP = curP;
			delP->prior->next = headNodePointer->next; // 指向首元节点
			*tailNodePointer = delP->prior; // 更新尾指针
			free(delP);
			return OK; // 直接return
		}
		else {
			delP = curP;
			delP->next->prior = delP->prior;
			delP->prior->next = delP->next;
			curP = curP->next; // 更新curP指针
			free(delP);
		} // end else
	} // end  while
	return OK;
}

// 删除指定节点
Status delectTargetNode(tcLinkNode headNodePointer, int location) {
	if (location > headNodePointer->data.data || location < 1) {
		return ERR;
	}
	// 节点存在
	tcLinkNode curP = headNodePointer->next; // 指向首元节点
	for (int i = 1; i < location; i++) {
		curP = curP->next;
	}
	// 循环结束 curP指向目标节点
	tcLinkNode delP = curP; // 标记
	curP->prior->next = curP->next;
	curP->next->prior = curP->prior;
	free(delP);
	return OK;
}

// 清空链表
Status cleanTcLinkList(tcLinkNode headNodePointer, tcLinkNode* tailNodePointer) {
	tcLinkNode curP = headNodePointer->next; // 指向首元节点
	tcLinkNode delP = NULL;
	while (curP != headNodePointer) { // 只要还没有指向头节点
		delP = curP; // 标记首元节点
		curP = curP->next; // 指向下一个节点
		free(delP); // 释放内存
		headNodePointer->data.data--; // 长度自减
	}
	*tailNodePointer = headNodePointer; // 更新尾指针
	return OK;
}

// 销毁链表
Status destroyLinkListTc(tcLinkNode* headNodePointer, tcLinkNode* tailNodePointer) {
	cleanTcLinkList(*headNodePointer, tailNodePointer);
	free(*headNodePointer);
	*headNodePointer = NULL; // 重置头指针和尾指针，避免出现悬挂指针
	*tailNodePointer = NULL;
	return OK;
}

// 打印链表
Status printTcList(tcLinkNode headNodePointer) {
	tcLinkNode curP = headNodePointer->next;
	int index = 1;
	while (curP != headNodePointer) {
		printf("%d->[%d] ", index, curP->data.data);
		curP = curP->next;
		index++;
	}
	return OK;
}

// 头插
Status insertToHeadTc(tcLinkNode headNodePointer, tcLinkNode* tailNodePointer, elementType data) {
	tcLinkNode newNode = creatNewTcNode();
	if (newNode == NULL)
		return ERR;
	if (headNodePointer->data.data == 0) { // 链表元素为空的情况下
		newNode->data = data;
		newNode->prior = headNodePointer;
		newNode->next = headNodePointer->next;
		headNodePointer->next->prior = newNode;
		headNodePointer->next = newNode;
		*tailNodePointer = newNode;
		headNodePointer->data.data++;
	}
	newNode->data = data;
	newNode->prior = headNodePointer;
	newNode->next = headNodePointer->next;
	headNodePointer->next->prior = newNode;
	headNodePointer->next = newNode;
	headNodePointer->data.data++;
	return OK;
}

// 尾插
Status insertToTailTc(tcLinkNode headNodePointer, tcLinkNode* tailNodePointer, elementType data) {
	tcLinkNode newNode = creatNewTcNode();
	if (newNode == NULL)
		return ERR;
	newNode->data = data;
	newNode->prior = (*tailNodePointer); // 新节点的前继指针指向尾节点
	newNode->next = headNodePointer; // 新节点的后记指针指向头节点
	headNodePointer->next->prior = newNode; // 头节点的前继节点指向新节点
	(*tailNodePointer)->next = newNode; // 尾节点的后记节点指向新节点
	(*tailNodePointer) = newNode; // 更新尾指针
	headNodePointer->data.data++;
	return OK;
}

// 在任意位置插入元素
Status insertToRandomTc(tcLinkNode headNodePointer, elementType data, int location) {
	tcLinkNode curP = headNodePointer->next;
	tcLinkNode newNode = creatNewTcNode();
	if (newNode == NULL)
		return ERR;
	newNode->data = data;
	for (int i = 1; curP != headNodePointer && i < location - 1; i++) {
		curP = curP->next;
	}
	if (curP == headNodePointer)
		return ERR;
	newNode->prior = curP;
	newNode->next = curP->next;
	curP->next->prior = newNode;
	curP->next = newNode;
	headNodePointer->data.data++;
	return OK;
}

Status addElemTc(tcLinkNode headNodePointer, tcLinkNode* tailNodePointer, elementType data, enum INSERTION insertion, int location) {
	Status status = -2;
	switch (insertion)
	{
		case INSERT_TO_HEAD: {
			status = insertToHeadTc(headNodePointer, tailNodePointer, data);
			break;
		}
		case INSERT_TO_TAIL: {
			status = insertToTailTc(headNodePointer, tailNodePointer, data);
			break;
		}
		case INSERT_TO_RANDOM: {
			if (location > headNodePointer->data.data)
				status = insertToHeadTc(headNodePointer, tailNodePointer, data);
			else if (location < 1)
				status = insertToHeadTc(headNodePointer, tailNodePointer, data);
			else
				status = insertToRandomTc(headNodePointer, data, location);
			break;
		}
		default: {
			puts("error");
			return ERR;
		}
	}
	return status;
}

// 查找
int locateElemTc(tcLinkNode headNodePointer, elementType data) {
	tcLinkNode curP = headNodePointer->next;
	int index = 1;
	while (curP != headNodePointer && curP->data.data != data.data) {
		curP = curP->next;
		index++;
	}
	if (curP == headNodePointer)
		return ERR;
	return index;
}

// 取值
elementType getElemTc(tcLinkNode headNodePointer, int location) {
	tcLinkNode curP = headNodePointer->next;
	for (int i = 1; curP != headNodePointer && i < location; i++) {
		curP = curP->next;
	}
	if (curP == headNodePointer) {
		elementType data;
		data.data = ERR;
		return data;
	}
	return curP->data;
}
