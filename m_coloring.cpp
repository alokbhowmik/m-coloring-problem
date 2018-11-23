#include<iostream>
using namespace std;
#define V 4
int G[V][V];
int m=3;
int color[V];
/*print all the color nodes*/
void print_color(int color[V]){
	for(int i=0;i<V;i++)
	cout<<"--"<<color[i];
}
/*check is the node safe or not */
bool issafe(int v,int G[V][V],int c){
	for(int i=0;i<V;i++){
		if(G[v][i]==1 && c==color[i])
		return false;
	}
	return true;
}
/*color all the nodes */
bool graphcoloringutil(int G[V][V],int color[V],int m,int v){
	if(v==V)
		return true;
	for(int c=1;c<=m;c++){
		if(issafe(v,G,c)){
			//cout<<"coloring"<<endl;
			color[v]=c;
		//	cout<<color[v]<<"  ";
			if(graphcoloringutil(G,color,m,v+1)==true)
				return true;
		}
		
	}
	//cout<<"reason"<<endl;
	return false;
}
void graphcoloring(int G[V][V],int m){
	/*initialy set all nodes color 0*/
	for(int i=0;i<V;i++)
	color[i]=0;
	
	if(graphcoloringutil(G,color,m,0))
	print_color(color);
	else
	cout<<"color is not enough "<<endl;
}

main(){
	/*(0)---(1)
	   |   / |
	   |  /  |
	   (3)--(2)*/
	   int G[V][V]={
	   {0,1,0,1},
	   {1,0,1,1},
	   {0,1,0,1},
	   {1,1,1,0}};
	   graphcoloring(G,m);
	   
}
