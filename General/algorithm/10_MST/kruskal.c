#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <memory.h>

typedef struct _incidentEdges IncidentEdges;
typedef struct _vertices Vertices;
typedef struct _edges Edges;

struct _incidentEdges {
	int edgeindex;
	struct _incidentEdges* next;
};
struct _vertices {
	int num;
	IncidentEdges* head;
};
struct _edges {
	int weight;
	Vertices* endpoints[2];
};
typedef struct _graph {
	Vertices vertex[101];
	Edges edge[1001];
}Graph;
typedef struct _heap {
	int key;					// locator(weight) of Edge in heap(priority queue)
}Heap;
typedef struct _disjointSet {	// �и�����
	struct _disjointSet *Parent;// �θ���
	Vertices* v;				// set�� data (���⼭�� vertex)
}DSet;

Graph grp, T;
int edgecnt = 0, t_edgecnt = 0;
int n, m;	// n = ���� ��, m = ���� ��

Heap heap[100];
int heap_size = 0;

DSet *dset;	// �и�����


/* makeNode*/
// ���������� ��带 ����
IncidentEdges* makeNode(int edgeindex) {
	IncidentEdges* new_node = (IncidentEdges*)malloc(sizeof(IncidentEdges));
	new_node->edgeindex = edgeindex;
	new_node->next = 0;

	return new_node;
}
/* opposite */
// v�� ����� �������� p�� ����� �ٸ� ������ ��ȯ
// V -(p)- W
Vertices* opposite(Vertices* v, IncidentEdges* p) {
	Vertices* w = NULL;

	if (grp.edge[p->edgeindex].endpoints[0]->num == v->num)
		w = grp.edge[p->edgeindex].endpoints[1];
	else if (grp.edge[p->edgeindex].endpoints[1]->num == v->num)
		w = grp.edge[p->edgeindex].endpoints[0];

	return w;
}
/* SetEdge */
// vertex(u)�� vertex(w)�� �����ϴ� ��������
void SetEdge(int unum, int wnum, int weight) {
	grp.edge[edgecnt].endpoints[0] = &grp.vertex[unum - 1];
	grp.edge[edgecnt].endpoints[1] = &grp.vertex[wnum - 1];
	grp.edge[edgecnt].weight = weight;
}
/* insertEdge*/
// vertex(u)�� vertex(w)�� �����ϴ� ���� ����
void insertEdge(int unum, int wnum, int edgeindex) {
	Vertices* u, * w;
	IncidentEdges* new_incident, * p;

	u = &grp.vertex[unum - 1];
	w = &grp.vertex[wnum - 1];

	new_incident = makeNode(edgeindex);
	p = u->head;

	// ������ ������ ���Լ����� �����Ѵ�. (�������� X)
	while (p->next != NULL) {
		if (grp.edge[p->edgeindex].endpoints[0] == u)
			break;
		p = p->next;
	}
	new_incident->next = p->next;
	p->next = new_incident;

	return;
}
/* SetVertex*/
// vertex(v)�� vertex(w)�� ��������
void SetVertex(int vnum, int wnum) {
	Vertices* u, * w;

	u = &grp.vertex[vnum - 1];
	w = &grp.vertex[wnum - 1];

	u->num = vnum;
	w->num = wnum;

	// make header
	if (u->head == NULL)
		u->head = makeNode(0);
	if (w->head == NULL)
		w->head = makeNode(0);
}
/* buildGraph */
// ������ ���߱׷��� ����
void buildGraph() {
	int unum, wnum, weight;

	scanf("%d %d", &n, &m);

	memset(&grp.vertex, 0, sizeof(Vertices) * n);
	memset(&grp.edge, 0, sizeof(Edges) * m);

	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &unum, &wnum, &weight);

		SetVertex(unum, wnum);
		SetEdge(unum, wnum, weight);
		insertEdge(unum, wnum, edgecnt);
		insertEdge(wnum, unum, edgecnt++);
	}
}
/* deallocate */
// ���������� �����޸� �Ҵ�����
void deallocate(void) {
	IncidentEdges* p, * removed;
	for (int i = 0; i < 100; i++) {
		if (grp.vertex[i].num == 0)
			continue;
		p = grp.vertex[i].head;
		while (p != NULL) {
			removed = p;
			p = p->next;
			free(removed);
		}
	}
}
/* printIncident */
// ���������� ����Ѵ�.
void printIncident() {
	IncidentEdges* p;
	for (int i = 0; i < 100; i++) {
		if (grp.vertex[i].num == 0)
			continue;
		printf("v->num : %d \n", grp.vertex[i].num);
		p = grp.vertex[i].head->next;
		while (p != NULL) {
			printf("[0] %d -> [1] %d\t", grp.edge[p->edgeindex].endpoints[0]->num, grp.edge[p->edgeindex].endpoints[1]->num);
			p = p->next;
		}
		printf("\n");
	}
}
////////////////////////Priority queue (heap)
/* DownHeap */
// heap�� i��°�� �������� ����� HeapSort�� �ǽ�
// �ּ����� �����ȴ�.
void DownHeap(int i)
{
	Heap tmp;
	int smaller;

	if (2 * i > heap_size)
		return;
	smaller = 2 * i;						// smaller <- lchild

	if (2 * i + 1 <= heap_size) {
		if (heap[smaller].key > heap[2 * i + 1].key)	// lchild > rchild
			smaller = 2 * i + 1;				// smaller <- rchild
	}

	if (heap[i].key <= heap[smaller].key)
		return;

	if (heap[i].key >= heap[smaller].key) {			// swap
		tmp = heap[i];
		heap[i] = heap[smaller];
		heap[smaller] = tmp;
	}
	DownHeap(smaller);
}
/* rBuildHeap */
// ���������� ������ O(n)
void rBuildHeap(int i)
{
	if (i > heap_size)
		return;
	rBuildHeap(2 * i);
	rBuildHeap(2 * i + 1);
	DownHeap(i);
	return;
}
/* makeHeap */
// Heap�� key���� ������ distance������ ����
// heap�� v���� ����� vertex�� ��ġ�� �ǹ�
// heap�� ���� ���� ������ isLocated�� false���� true�� ��ȯ���ش�.
void makeHeap() {
	memset(heap, 0, sizeof(Heap) * 100);
	for (int i = 1; i <= m; i++) {
		heap[i].key = grp.edge[i - 1].weight;
		heap_size++;
	}
	rBuildHeap(1);
}
/* printHeap */
// Heap�� key���� ���
void printHeap()
{
	for (int i = 1; i <= heap_size; i++)
	{
		printf(" %d", heap[i].key);
	}
	printf("\n");
}
/* removeMin */
// heap�� ó�� Ű���� ���� vertex ��ȯ
Edges* removeMin()
{
	int deleted = heap[1].key;
	heap[1] = heap[heap_size];
	heap[heap_size].key = 0;
	heap_size--;
	rBuildHeap(1);

	for (int i = 0; i < m; i++) {
		if (grp.edge[i].weight == deleted) {
			return &grp.edge[i];
		}
	}

	return NULL;
}
//////////////////// Disjoint Set
/* DS_find */
// ������ �ֻ��� node�� ��ȯ
DSet* DS_find(DSet* set) {
	while (set->Parent != NULL) {
		set = set->Parent;
	}

	return set;
}
/* DS_union */
// set2�� ���� �ֻ���node�� set1�� ���� �ֻ��� node�� ����Ű����
void DS_union(DSet* set1, DSet* set2) {
	set2 = DS_find(set2);
	set2->Parent = DS_find(set1);
}
/* DS_isMember */
// set1�� set2�� �ֻ��� node�� ������ ���� �и����տ� ����
bool DS_isMember(DSet* set1, DSet* set2) {
	set1 = DS_find(set1);
	set2 = DS_find(set2);

	if (set1 == set2)
		return true;
	return false;
}
/* DS_makeSet */
// �и����� ����
void DS_makeSet() {
	dset = (DSet*)malloc(sizeof(DSet) * n);
	memset(dset, 0, sizeof(DSet) * n);
}
/* DS_free */
// �и����� �Ҵ� ����
void DS_free(DSet* set) {
	free(set);
}
//////////////////// KruskalMST
/* initT */
// copy verteices Graph grp to Graph T
void initT() {
	for (int i = 0; i < n; i++)
		T.vertex[i] = grp.vertex[i];
}
void AddEdge(int unum, int wnum, int edgeindex) {
	Vertices* u, * w;
	IncidentEdges* new_incident, * p;

	u = &T.vertex[unum - 1];
	w = &T.vertex[wnum - 1];

	new_incident = makeNode(edgeindex);
	p = u->head;

	// ������ ������ ���Լ����� �����Ѵ�. (�������� X)
	while (p->next != NULL) {
		p = p->next;
	}
	p->next = new_incident;

	return;
}
Graph KruskalMST() {
	int sum = 0;
	Edges* e;
	Vertices* u, * v;

	DS_makeSet();
	for (int i = 0; i < n; i++)									// 1. for each v E G.vertices()
		dset[i].v = &grp.vertex[i];								//		define a Sack(v) <- {v}
	makeHeap();													// 2. a priorty queue containing all the edges of G using weights as keys
	initT();													// 3. T <- NULL
	while (t_edgecnt < n - 1) {									// 4. while(T has fewer han n - 1 edges)
		e = removeMin();										//		(u, v) <- Q.removeMin()
		u = e->endpoints[0];
		v = e->endpoints[1];
		if (!DS_isMember(&dset[u->num-1], &dset[v->num-1])) {	//		if(Sack(u) != Sack(v))
			AddEdge(u->num, v->num, t_edgecnt++);				// Add edge (u, v) to T
			DS_union(&dset[u->num - 1], &dset[v->num - 1]);		// Merge Sack(u) and Sack(v)
			printf("%d ", e->weight);
			sum += e->weight;
		}
		
	}
	printf("\n%d", sum);
	
	DS_free(dset);

	return T;
}

int main(void) {
	buildGraph();
	T = KruskalMST();
	deallocate();
}