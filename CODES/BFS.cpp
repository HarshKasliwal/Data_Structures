#include <iostream>
#include <conio.h>
using namespace std;

int q[20],top=-1,front=-1,rear=-1,a[20][20],vis[20],stack[20];
int deleteQ();
void add(int item);
void bfs(int s,int n);
void dfs(int s,int n);
void push(int item);
int pop();
int main()
{
int n,i,s,ch,j;
char c,;
cout<<"ENTER THE NUMBER VERTICES ";
cin>>n;
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{
cout<<"ENTER 1 IF "<<i<<" HAS A NODE WITH "<<j<<" ELSE 0 ";
cin>>a[i][j];
}
}
cout<<"THE ADJACENCY MATRIX IS\n";
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{
cout<<"\t"<<a[i][j];
}
cout<<"\n";
}

do
{
for(i=1;i<=n;i++)
vis[i]=0;
cout<<"\nENTER YOUR CHOICE";
cout<<"\n1.BFS Traversal";
cout<<"\n2.DFS Traversal\n";
cin>>ch;
cout<<"ENTER THE SOURCE VERTEX :";
cin>>s;

switch(ch)
{
case 1:bfs(s,n);
break;
case 2:
dfs(s,n);
break;
}
cout<<"\nDO U WANT TO CONTINUE(Y/N) ? ";
cin>>c;
}while((c=='y')||(c=='Y'));
}


//**************BFS**************//
void bfs(int s,int n)
{
int p,i;
add(s);
vis[s]=1;
p=deleteQ();
if(p!=0)
cout<<p<<"\t";
while(p!=0)
{
for(i=1;i<=n;i++)
if((a[p][i]!=0)&&(vis[i]==0))
{
add(i);
vis[i]=1;
}
p=deleteQ();
if(p!=0)
cout<<p<<"\t";
}
for(i=1;i<=n;i++)
if(vis[i]==0)
bfs(i,n);
}


void add(int item)
{
if(rear==19)
cout<<"QUEUE FULL";
else
{
if(rear==-1)
{
q[++rear]=item;
front++;
}
else
q[++rear]=item;
}
}
int deleteQ()
{
int k;
if((front>rear)||(front==-1))
return(0);
else
{
k=q[front++];
return(k);
}
}


//***************DFS******************//
void dfs(int s,int n)
{
int i,k;
push(s);
vis[s]=1;
k=pop();
if(k!=0)
cout<<k<<"\t";
while(k!=0)
{
for(i=1;i<=n;i++)
if((a[k][i]!=0)&&(vis[i]==0))
{
push(i);
vis[i]=1;
}
k=pop();
if(k!=0)
cout<<k<<"\t";
}
for(i=1;i<=n;i++)
if(vis[i]==0)
dfs(i,n);
}
void push(int item)
{
if(top==19)
cout<<"Stack overflow ";
else
stack[++top]=item;
}
int pop()
{
int k;
if(top==-1)
return(0);
else
{
k=stack[top--];
return(k);
}
return 0;
}