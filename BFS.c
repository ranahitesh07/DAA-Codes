#include<stdio.h> 
#define MAX 10 
int nv; 
struct vertex { 
   char color; 
   int d,pi; 
}
v[MAX]; 
int Q[MAX]; 
int rear=-1,front=0;; 
void BFS(int G[8][8],int); 
void printpath(int,int);  
void enqueue(int); 
int dequeue(); 
int main() 
{ 
  int G[8][8]; 
  int s,i,j,end; 
  printf("Enter the no of vertices for BFS operation:"); 
  scanf("%d",&nv); 
  printf("Enter the graph:\n"); 
  for(i =0;i<nv;i++) 
  { 
   
	  for(j=0;j<nv;j++) 
          {  
            scanf("%d" , &G[i][j]); 
          }  
  }
  printf("Enter the starting vertex:"); 
  scanf("%d",&s); 
  BFS(G,s); 
  printf("Enter the destination vertex:");
  scanf("%d",&end); 
  printf("PATH:"); 
  printpath(s,end); 
  printf("\n");
} 
void printpath(int s,int e) 
{ 
   if(s==e) 
   { 
      printf("%d",s); 
   } 
   else 
   { 
      if(v[e].pi==-1) 
          printf("No path found"); 
      else 
     { 
        printpath(s,v[e].pi); 
        printf("--->%d",e); 
     }   
   }    
} 
void BFS(int G[8][8],int s) 
{ 
    int i,j; 
    for(i=0;i<nv;i++) 
    { 
       if(i==s) 
           continue; 
       v[i].color='W'; 
       v[i].d=1000; 
       v[i].pi=-1; 
    } 
    v[s].color='G'; 
    v[s].d=0; 
    v[s].pi=-1; 
    enqueue(s); 

    while(front<=rear) 
    { 
       i=dequeue(); 
       for(j=0;j<nv;j++)  
       { 
          if(G[i][j]!=0 && v[j].color=='W') 
          { 
             v[j].color='G'; 
             v[j].d=v[i].d+1; 
             v[j].pi=i; 
             enqueue(j); 
         } 
       }      
       v[i].color='B'; 
    } 
} 
void enqueue(int ele) 
{ 
   if(rear==MAX-1) 
         printf("Queue overflow"); 
   else 
         Q[++rear]=ele; 
} 
int dequeue() 
{ 
       int i; 
       if(front>rear) 
       { 
           printf("Underflow"); 
           return -1; 
       }  
       else 
       { 
             i=Q[front]; 
             if(front==rear) 
             { 
                  front=0; 
                  rear=-1; 
             } 
             else 
                  front++; 
                  return i; 
      } 
} 
