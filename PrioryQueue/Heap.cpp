#include"Heap.h"
#include<stdio.h>

using namespace std;

MinHeap::MinHeap(const int max) {
	int *heapArray = new int[max];
	maxSize = max;
	currentSize = 0;
}
MinHeap:: ~MinHeap() {
	delete[] heapArray;
}
bool MinHeap::isLeaf(int pos) {
	return leftChild(pos) < currentSize;
}
int MinHeap::leftChild(int pos) {
	return pos * 2 + 1;
}
int MinHeap::rightChild(int pos) {
	return pos * 2 + 2;
}
int MinHeap::parent(int pos) {
	return pos - 1 / 2;
}
bool MinHeap::insert(int &node) {
	if (currentSize == maxSize)
		return false;
	heapArray[currentSize] = node;
	siftUp(currentSize);
	currentSize++;
}
bool MinHeap::remove(int pos, int &node) {
	if (pos < 0 || pos >= currentSize)
		return false;
	int temp = heapArray[pos];
	heapArray[pos] = heapArray[currentSize - 1];
	if (heapArray[pos] > heapArray[parent(pos)])
		siftDown(pos);
	else
		siftUp(pos);
	node = temp;
	return true;
}
int MinHeap::removeMin() {
	if (currentSize == 0)
		return -9999;
	int temp = heapArray[0];
	heapArray[0] = heapArray[currentSize - 1];
	siftDown(0);
	currentSize--;
	return temp;
}
void MinHeap::buildHeap(){
	for (int i = currentSize / 2 - 1; i >= 0; i--) {
		siftDown(i);
	}
}
void MinHeap::siftUp(int pos) {
	int temp = heapArray[pos];
	while (parent(pos)>=0&&temp< heapArray[parent(pos)]) {
		heapArray[pos] = heapArray[parent(pos)];
		pos = parent(pos);
	}
	heapArray[pos] = temp;
}
void MinHeap::siftDown(int pos) {
	int i = pos;//��iλ��siftdown
	int j = leftChild(i);//j��i������
	int temp = heapArray[i];

	while (j < currentSize) {
		if (j<currentSize - 1 && heapArray[j]>heapArray[j + 1]) {
			++j;
		}//���j�������һ��Ԫ�� ���� �������ֵܴ���j�Ƶ�����һ��λ�ã��������ֵ�

		if (temp > heapArray[j]) {// ������׵�ֵtemp�ȶ��Ӵ�
			heapArray[i] = heapArray[j];//�����ӵ�ֵ�ƶ���ȥ
			i = j;//i�ߵ�����λ��
			j = leftChild(j);//j�ߵ���ʱi�������λ��
		}
		else break;
	}
	heapArray[i] = temp;
}