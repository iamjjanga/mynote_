#include <stdio.h>
#include <stdlib.h>


// �ߺ�Ű ����
typedef struct _node {
	struct _node* parent;	// �θ� ����Ű�� ������
	int key;				// Ű
	struct _node* lchild;	// �����ڽ�
	struct _node* rchild;	// �������ڽ�
}Node;

Node *root;

int isInternal(Node* v) {	// ���γ������?
	if (v->lchild != NULL || v->rchild != NULL)
		return 1;
	else
		return 0;
}
int isExternal(Node* v) {	// �ܺγ������?
	if (v->lchild == NULL && v->rchild == NULL)
		return 1;
	else
		return 0;
}
Node* sibiling(Node* w) {	// ������� ��ȯ
	if (w == root)
		return NULL;
	if (w->parent->lchild == w)
		return w->parent->rchild;
	else
		return w->parent->lchild;
}
Node* makeNode(int key) {
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->key = key;
	new_node->lchild = NULL;
	new_node->rchild = NULL;

	return new_node;
}
void expandExternal(Node* v) {
	v->lchild = makeNode(0);
	v->rchild = makeNode(0);

	v->lchild->parent = v;
	v->rchild->parent = v;
}
/* Ʈ�� Ž�� */
// 1. �ܺγ��� return �ܺγ��
// 2. �����ϸ� return �����ѳ��
// 3. ���v�� key�� ã������ key���� ������� -> tree ���� Ž��
//								  Ŭ��� -> tree ������ Ž��
Node* treeSearch(Node *v,int k) {
	if (isExternal(v))
		return v;

	if (k == v->key)
		return v;
	else if (k < v->key)
		treeSearch(v->lchild, k);
	else
		treeSearch(v->rchild, k);
}
/* ����ã�� */
// 1. treeSearch�Լ��� k�� key�ΰ��� node�� ã��
// 2. ���ҹ�ȯ
int findElement(int k) {
	Node* w;
	w = treeSearch(root, k);

	if (isExternal(w))
		return -1;
	else
		return w->key;
}
/* ���һ��� */
// 1. key�� ���� node�� ������ return
// 2. ������ �ܺγ�带 Ȯ���Ͽ� key�� ����
void insertItem(int k) {
	Node* w;
	w = treeSearch(root, k);

	if (isInternal(w))
		return;
	else {
		expandExternal(w);
		w->key = k;
	}
}
/* ������ȸ�İ��� ã�� */
// 1. w node�� ������ �ڽ��� ���������ؼ�
// 2. �ܺγ��� return
// 3. �����ڽ��� ���γ���ϰ�쿡�� �����ڽ����� �̵�
// 4. return �����ڽ��� ������ ���γ��
Node* inOrderSucc(Node* w) {
	w = w->rchild;
	if (isExternal(w))
		return NULL;
	while (isInternal(w->lchild)) {
		w = w->lchild;
	}
	return w;
}
/* ��� ���̱� */
// 1. w�� z�� parent�� ����
// 2. zs�� z�� �������� ���ϰ� ���� NULL�̸� return NULL
// 3-1. w�� root�� zs�� root�� �̵��ϰ� zs�� �θ� NULL�� ġȯ
// 3-2. w�� root�� �ƴϸ� g�� w�� �θ���Ͽ� zs�� �θ� g�� ��ũ�ϰ� w�� g�� ��ڽ�������
//		���ؼ� zs�� g�� ��ڽ������� ����.
// 4. free(w), free(z)
// 5. return zs node
Node* reduceExternal(Node* z) {
	Node* w, *zs, *g;

	w = z->parent;
	zs = sibiling(z);
	if (zs == NULL) {
		return NULL;
	}
	if (w == root) {
		root = zs;
		zs->parent = NULL;
	}
	else {
		g = w->parent;
		zs->parent = g;
		if (w == g->lchild)
			g->lchild = zs;
		else
			g->rchild = zs;
	}
	free(w);
	free(z);

	return zs;
}
/* ���� ���� */
// 1. k�� key�� ���� node�� ã�� ���� �ܺγ��� NoSuchKey ��ȯ(Key����)
// 2. key�� elem ������ �����ϰ� w�� �����ڽ����� z�� ����
// 3. ���� z�� ���γ��� z�� w�� �������ڽ����� ����
// 4-1. {case 1} z�� �ܺγ��� reduceExternal(z)�� �ϰ� return ���� Ȯ��
// 4-2. {case 2} z�� ���γ��� inOrderSucc���� ������ȸ �İ��ڸ� ã�� y�� ����
//		y�� �����ڽ��� z�� �Ͽ� w�� y�� ������ �� z�� ���� reduceExternal�� �����ϰ� return ���� Ȯ��
// 5. return elem
int removeElement(int k) {
	Node* w, *z, *y;
	int elem;

	w = treeSearch(root, k);
	if (isExternal(w))
		return -1;
	elem = w->key;
	z = w->lchild;
	
	if (!isExternal(z))
		z = w->rchild;
	// case1
	if (isExternal(z)) {
		if (reduceExternal(z) == NULL)
			return -1;
	}

	// case2
	else {
		y = inOrderSucc(w);
		if (y == NULL)
			return -1;
		z = y->lchild;
		w->key = y->key;
		if (reduceExternal(z) == NULL)
			return -1;
	}

	return elem;
}
/* ������ȸ */
void preOrder(Node* v) {
	if (isExternal(v))
		return;
	printf(" %d", v->key);
	preOrder(v->lchild);
	preOrder(v->rchild);
}
/* ��� ��ȯ */
void putNode(Node *v) {
	if (isExternal(v))
		return;
	putNode(v->lchild);
	putNode(v->rchild);
	free(v);
}

int main(void) {
	char com;
	int key, element;

	root = NULL;

	while (1) {
		scanf("%c", &com);
		if (com == 'q')
			break;

		switch (com) {
		case 'i':
			scanf("%d", &key);
			if (root == NULL) {
				root = makeNode(key);
				expandExternal(root);
				root->parent = NULL;
			}
			else
				insertItem(key);
			break;
		case 'd':
			scanf("%d", &key);
			element = removeElement(key);
			if (element == -1)
				printf("X\n");
			else
				printf("%d\n", element);
			break;
		case 's':
			scanf("%d", &key);
			element = findElement(key);
			if (element == -1)
				printf("X\n");
			else
				printf("%d\n", element);
			break;
		case 'p':
			preOrder(root);
			printf("\n");
			break;
		}

		while (getchar() != '\n') {}
	}

	putNode(root);
	return 0;
}

