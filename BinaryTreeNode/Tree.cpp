#include"Tree.h"

BinaryTreeNode::BinaryTreeNode(){}
BinaryTreeNode::BinaryTreeNode(int info){}
BinaryTreeNode::BinaryTreeNode(int info, BinaryTreeNode *left, BinaryTreeNode *right){}
int BinaryTreeNode::value()const{
	return info;
}

void BinaryTreeNode::visit() {
	cout << info << endl;
}

BinaryTreeNode* BinaryTreeNode::leftChild()const{}
BinaryTreeNode* BinaryTreeNode::rightChild()const{}
void BinaryTreeNode::setLeftChild(BinaryTreeNode *left){}
void BinaryTreeNode::setRightChild(BinaryTreeNode *right){}
void BinaryTreeNode::setValue(const int& value){}
bool BinaryTreeNode::isLeaf()const{}
BinaryTreeNode& BinaryTreeNode::operator=(BinaryTreeNode& node){}

// Stack model
Stack::Stack(){
	head = NULL;
}
Stack::~Stack(){
	while (head != NULL) {
		StackNode *temp = head;
		head = head->next;
		delete temp;
	}
}
void Stack::push(BinaryTreeNode *binaryTreeNode){
	StackNode *newNode = new StackNode;
	newNode->root = binaryTreeNode;
	newNode->next = head;
	head = newNode;

}
BinaryTreeNode* Stack::pop(){
	StackNode *temp = head;
	BinaryTreeNode *toBeReturn = temp->root;
	head = head->next;
	delete temp;
	return toBeReturn;

}
//�������ݽṹ
Queue::Queue(){
	arr = new BinaryTreeNode*[CAPACITY];
	front = 0;
	rear = -1;
}
Queue::~Queue(){
	delete[] arr;
}
bool Queue::enqueue(BinaryTreeNode *binaryTreeNode){
	if ((rear + 2) % CAPACITY == front)
		return false;
	rear = (rear + 1) % CAPACITY;
	arr[rear] = binaryTreeNode;
	return true;
}
bool Queue::dequeue(){
	if (isEmpty())
		return false;
	front=(front+1)%CAPACITY;
	return true;
}
BinaryTreeNode* Queue::getFront(){
	return arr[front];
}
bool Queue::isEmpty(){
	return rear == front + 1;
}
int Queue::getLength(){}


BinaryTreeNode* Stack::top(){
	return head->root;
}
bool Stack::isEmpty(){
	return head == NULL;
}

BinaryTree::BinaryTree(){root = NULL;}
BinaryTree::~BinaryTree() { deleteBinaryTree(root); }
void BinaryTree::visit(BinaryTreeNode *binaryTreeNode) {
	cout << binaryTreeNode->value() << endl;
}
bool BinaryTree::isEmpty(){}
BinaryTreeNode* BinaryTree::Root() { return root; }
BinaryTreeNode* BinaryTree::parent(BinaryTreeNode *curRoot,BinaryTreeNode *current){
	/*
	���ڴ˶�����û��ָ���׵�ָ�루�������У���������Ҫ�Ӹ����root��ʼ����current���ĸ��ڵ�
	�ݹ�ʵ�֣�
	*/
	BinaryTreeNode *temp;
	if (curRoot == NULL)
		return NULL;
	if (current == curRoot->leftChild() || current == curRoot->rightChild())
		return curRoot;
	if ((temp = parent(curRoot->leftChild(), current)) != NULL)
		return temp;
	if ((temp = parent(curRoot->rightChild(), current)) != NULL)
		return temp;
	return NULL;
}
BinaryTreeNode* BinaryTree::parent(BinaryTreeNode *current) {
	//�ǵݹ�ʵ��
	Stack aStack;
	BinaryTreeNode *pointer = root;
	aStack.push(NULL);
	while (pointer) {
		if (current == pointer->leftChild() || current == pointer->rightChild())
			return pointer;
		if (pointer->rightChild() != NULL)
			aStack.push(pointer->rightChild());
		if (pointer->leftChild() != NULL)
			pointer = pointer->leftChild();
		else {
			pointer = aStack.pop();
		}
		
	}
}
BinaryTreeNode* leftSibling(BinaryTreeNode *current){}
BinaryTreeNode* rightSibling(BinaryTreeNode *current){}
void BinaryTree::createTree(int info, BinaryTreeNode leftTree, BinaryTreeNode rightTree){}
void BinaryTree::preOrder(BinaryTreeNode *root){
	/*�ǵݹ���������
	steps:
	1:����һ����ջ������һ��ֵΪNULL��ջ�׼�����ѹ��ջ��
	2.��root��ʼ������һ���ڵ�ͷ��������������ķǿ��Һ���ѹ��ջ��
	3.Ȼ���½�ȥ������������
	4.���������������ʹ�ջ�е���һ����㣬��������ͬ�Ĳ��Է��ʴ˽�������
	*/
	stack<int> aStack;
	BinaryTreeNode *pointer = root;
	aStack.push(NULL);//ջ�׼�����
	while (pointer) {
		visit(pointer);//���ʵ�ǰ�ڵ�
		if (pointer->rightChild() != NULL)
			aStack.push(pointer->rightChild());//�Һ�����ջ

		if (pointer->leftChild() != NULL)//�����½�
			pointer = pointer->leftChild();
		else//�˷�֧Ϊ���ʵ���Ҷ�ӽڵ㣬�������Һ��Ӷ�Ϊ��
			pointer = aStack.pop();//pointer��Ϊջ��Ԫ�أ�������Ԫ�ص�ջ
	}

}
void BinaryTree::inOrder(BinaryTreeNode *root){
	/*
	steps��
	1.����һ���ڵ㣬����ѹջ������������������
	2.����������������ջ������һ����㲢����֮��
	3.������������ַ�����ý�����������
	*/
	Stack aStack;
	BinaryTreeNode *pointer = root;
	while (pointer != NULL || !aStack.isEmpty()) {
		if (pointer) {
			//visit(pointer);
			aStack.push(pointer);
			pointer = pointer->leftChild();
		}
		else {
			pointer = aStack.pop();
			visit(pointer);//���ʵ�ǰ���
			pointer = pointer->rightChild();
		}
	}
	
}
void BinaryTree::postOrder(BinaryTreeNode *root){

}
void BinaryTree::levelOrder(BinaryTreeNode *root){
	/*
	1.�������������
	2.���в�Ϊ�գ���ȡ������һ����㲢����֮���������ڵ�������Һ�������
	3.���в�Ϊ�գ���ȡ������һ����㲢����֮���������ڵ�������Һ�������
	*/
	Queue aQueue;
	BinaryTreeNode* pointer = root;
	aQueue.enqueue(pointer);
	while (!aQueue.isEmpty()) {
		pointer = aQueue.getFront();
		aQueue.dequeue();
		visit(pointer);
		if (pointer->leftChild() != NULL)
			aQueue.enqueue(pointer->leftChild());
		if (pointer->rightChild() != NULL)
			aQueue.enqueue(pointer->rightChild());
	}
}
void BinaryTree::depthOrder(BinaryTreeNode *root) {
	//�ݹ�ط������е�ÿ�����
	if (root != NULL) {
		//visit(root);ǰ��
		depthOrder(root->leftChild());//�ݹ����������
		//visit(root);����
		depthOrder(root->rightChild());//�ݹ����������
		//visit(root);����
	}
}
void BinaryTree::deleteBinaryTree(BinaryTreeNode *root){}