#include <stdio.h> 
#include <conio.h> 
#include <stdbool.h> 
#define MAX 100 
int stack[MAX], TOP = -1; 
int queue[MAX], front = -1, rear = -1; 
int mat[MAX][MAX]; 
void push(int), enqueue(int); 
bool stackIsEmpty(), queueIsEmpty(); 
int pop(), dequeue(); 
void dfs(int), bfs(int); 
void addEdge(int, int), clearGraph(); 
int edges = 0; 
int root; 
int main() 
{ 
 int ch, element, v1, v2; 
 clearGraph(); 
 addEdge(1, 2); 
 addEdge(1, 3); 
 addEdge(1, 4); 
 addEdge(2, 5); 
 addEdge(3, 5); 
 addEdge(4, 6); 
 addEdge(5, 7); 
 addEdge(5, 6); 
 do 
 { 
 printf("\n\n1-Add edge\n2-Clear graph\n3-Depth first search\n4-Breadth first search\n5-Exit\n"); 
 printf("Enter your choice : "); 
 scanf("%d", &ch); 
 switch(ch) 
 { 
 case 1: 
 printf("Enter edge 1 : "); 
 scanf("%d", &v1); 
 printf("Enter edge 2 : "); 
 scanf("%d", &v2); 
 break; 
 case 2: 
 clearGraph(); 
 break; 
 case 3: 
 dfs(root); 
 break; 
 case 4: 
 bfs(root); 
 break; 
 case 5: 
 break; 
 default: 
 printf("Enter a valid choice\n"); 
 } ;
 } 
 while(ch != 5); 
 return 0; 
} 
void dfs(int start) 
{ 
 int i, j, h = start; 
 bool visited[MAX]; 
 for(i = 0; i < MAX; i++) 
 visited[i] = false; 
 visited[h] = true; 
 while(true) 
 { 
 printf("%d ", h); 
 for(j = 0; j < MAX; j++) 
 { 
 if(mat[h][j] && !visited[j]) 
 { 
 push(j); 
 visited[j] = true; 
 } 
 } 
 if(stackIsEmpty()) 
 return; 
 else 
 h = pop(); 
 } 
} 
void bfs(int start) 
{ 
 int i, j, h = start; 
 bool visited[MAX]; 
 for(i = 0; i < MAX; i++) 
 visited[i] = false; 
 visited[h] = true; 
 while(true) 
 { 
 printf("%d ", h); 
 for(j = 0; j < MAX; j++) 
 { 
 if(mat[h][j] && !visited[j]) 
 { 
 enqueue(j); 
 visited[j] = true; 
 } 
 } 
 if(queueIsEmpty()) 
 return; 
 else 
 h = dequeue(); 
 } 
} 
void addEdge(int v1, int v2) 
{ 
 if(edges == 0) 
 root = v1; 
 mat[v1][v2] = true; 
 mat[v2][v1] = true; 
 edges++; 
} 
void clearGraph() 
{ 
 edges = 0; 
 for(int i = 0; i < MAX; i++) 
 for(int j = 0; j < MAX; j++) 
 mat[i][j] = 0; 
} 
void push(int element) 
{ 
 stack[++TOP] = element; 
} 
int pop() 
{ 
 return stack[TOP--]; 
} 
bool stackIsEmpty() 
{ 
 return TOP == -1; 
} 
void enqueue(int element) 
{ 
 if(queueIsEmpty()) 
 { 
 front = 0; 
 rear = 0; 
 queue[rear] = element; 
 } 
 else 
 { 
 queue[++rear] = element; 
 } 
} 
int dequeue() 
{ 
 int temp = queue[front]; 
 if(front == rear) 
 { 
 front = -1; 
 rear = -1; 
 } 
 else 
 front++; 
 return temp; 
} 
bool queueIsEmpty() 
{ 
 return front == -1 && rear == -1; 
} 