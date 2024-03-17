#include<iostream>
#include<queue>
#include<stack>
using namespace std;
class graph_by_matrix{
	int **arr;
	int row,col;
	public:
		graph_by_matrix(){}
		graph_by_matrix(int r, int c)
		{
			row=r;
			col=c;
			arr=new int*[row];
			for(int i=0; i<row; i++)
			{
				arr[i]=new int[col];
			}
			for(int i=0; i<row; i++)
			{
				for(int j=0; j<col; j++)
				{
					arr[i][j]=0;
				}
			}
		}
		void insert(int i,int j,int weight)
		{
			arr[i][j]=weight;
			//arr[j][i]=weight;//for undirected graph
		}
		void display()
		{
			int num=0;
			for(int i=0; i<col; i++)
			cout << "    " << num++ << " ";
			cout<<endl<<" ";
			for(int i=0; i<col; i++)
			cout<<"------";
			cout<<endl;
			num=0;
			for(int i=0; i<row; i++){
			cout<<" "<<num++<<" | ";
			for(int j=0; j<col; j++)
			cout<<" "<<arr[i][j]<<" | ";
			cout<<endl;
			}
		}
		int findmin(int *ptr,bool *ptr1)
		{
			int min=101;
			int index=0;
			for(int i=0; i<row; i++)
			{
				if(ptr[i]<=min && ptr1[i]==false)
				{
					min=ptr[i];
					index=i;
				}
			}
			return index;
		}
		//*********Array Base BFS and DFS*************
		void breath_first_array(int source) {
        bool* visited = new bool[row];
        for (int i = 0; i < row; i++)
            visited[i] = false;
        queue<int> q;
        q.push(source);
        visited[source] = true;
        while (!q.empty()) {
            int curr = q.front();
            cout << " " << curr << " ";
            q.pop();
            for (int i = 0; i < row; i++) {
                if (arr[curr][i] && visited[i] == false) {
                    q.push(i);
                    visited[i] = true;
                	}
            	}
        	}
    	}
	    void Depth_first_array(int source) {
	        bool* visited = new bool[row];
	        for (int i = 0; i < row; i++)
	            visited[i] = false;
	        stack<int> s;
	        s.push(source);
	        visited[source] = true;
	        while (!s.empty()) {
	            int curr = s.top();
	            cout << " " << curr << " ";
	            s.pop();
	            for (int i = 0; i < row; i++) {
	                if (arr[curr][i] && visited[i] == false) {
	                    s.push(i);
	                    visited[i] = true;
	                }
	            }
	        }
	    }
		void prims(int s)
		{
			int *key=new int[row];
			for(int i=0; i<row; i++)
				key[i]=100;
			int *parent=new int[row]; // you can take row or col because both are same
			for(int i=0; i<row; i++)
				parent[i]=-1;
			bool* MST=new bool[row];
			for(int i=0; i<row; i++)
				MST[i]=false;
			key[s]=s;
			for(int i=0; i<row; i++)
			{
				int curr=findmin(key,MST);
				MST[curr]=true;
				for(int j=0; j<row; j++)
				{
					if(arr[curr][j] && arr[curr][j]<key[j])
					{
						key[j]=arr[curr][j];
						parent[j]=curr;
					}
				}
			}
			int sum=0;
			cout<<"Parent List : ";
			for(int i=0; i<row; i++)
			{
				cout<<parent[i]<<" ";
				sum=sum+key[i];
			}
			cout<<endl;
			cout<<"Minimum Graph Weight is :"<<sum;
		}
		void dijkstra(int s)
		{
			int *key=new int[row];
			for(int i=0; i<row; i++)
				key[i]=100;
			int *parent=new int[row]; // you can take row or col because both are same
			for(int i=0; i<row; i++)
				parent[i]=-1;
			bool* MST=new bool[row];
			for(int i=0; i<row; i++)
				MST[i]=false;
			key[s]=0;
			for(int i=0; i<row; i++)
			{
				int curr=findmin(key,MST);
				MST[curr]=true;
				for(int j=0; j<row; j++)
				{
					if(MST[j]==false && arr[curr][j] && (key[curr]+arr[curr][j])<key[j])
					{
						key[j]=key[curr]+arr[curr][j];
						parent[j]=curr;
					}
				}
			}
			cout<<"Parent List : ";
			for(int i=0; i<row; i++)
			{
				cout<<parent[i]<<" ";
			}
			cout<<"\nShortest Distance \n";
			cout<<"Vertex 0: "<<parent[s]<<" It is a source\n";
			for(int i=1; i<row; i++)
			{
				cout<<"Vertex "<<i<<" : Parent "<<parent[i]<<" Shortest Path ( "<<parent[i]<<"->"<<i<<")"<<endl;
			}
		}
};
class node{
	public:
	int data;
	node*next;
	node(int val)
	{
		data=val;
		next=NULL;
	}
};
class adjacent_list{
	node*head,*tail;
	public:
	adjacent_list()
	{
		head=NULL;
		tail=NULL;
	}
	void insertadj(int n)
	{
		if(head==NULL)
		{
			head=new node(n);
			tail=head;
			return;
		}
		else
		{
			tail->next=new node(n);
			tail=tail->next;
		}
	}
	void display()
	{
		node* temp=head;
		while(temp)
		{
			cout<<"->"<<temp->data;
			temp=temp->next;
		}
	}
	node* gethead()
	{
		return head;
	}
};
class graph_by_list{
	adjacent_list* adj;
	int n;
	public:
		graph_by_list(int num)
		{
			n=num;
			adj=new adjacent_list[n];
			
		}
		void insert(int i,int j)
		{
			adj[i].insertadj(j);
			//adj[j].insertadj(i);
		}
		//*********Linked List Base BFS and DFS*************
		void breath_first(int source)
		{
			bool *arr=new bool[n];
			for(int i=0; i<n; i++)
			arr[i]=false;
			queue<int>q;
			q.push(source);
			arr[source]=true;
			while(!q.empty())
			{
				int current=q.front();
				cout<<" "<<current<<" ";
				q.pop();
				node* temp=adj[current].gethead();
				while(temp)
				{
					int adjacent=temp->data;
					if(!arr[adjacent])
					{
						arr[adjacent]=true;
						q.push(adjacent);
					}
					temp=temp->next;
				}
			}
		}
		void depth_first(int source)
		{
			bool *arr=new bool[n];
			for(int i=0; i<n; i++)
			arr[i]=false;
			stack<int>s;
			s.push(source);
			arr[source]=true;
			while(!s.empty())
			{
				int current=s.top();
				cout<<" "<<current<<" ";
				s.pop();
				node* temp=adj[current].gethead();
				while(temp)
				{
					int adjacent=temp->data;
					if(!arr[adjacent])
					{
						arr[adjacent]=true;
						s.push(adjacent);
					}
					temp=temp->next;
				}
			}
		}
		void display()
		{
			int c=0;
			for(int i=0; i<n; i++)
			{
				if(i!=n)
				cout<<c++<<" ";
				adj[i].display();
				cout<<endl;
			}
		}
};
int main()
{
	graph_by_matrix g(4,4);
	g.insert(0, 1,3);
	g.insert(1, 0,2);
	g.insert(0, 3,7);
	g.insert(1, 2,5);
	g.insert(3, 2,4);
	g.insert(2, 3,6);
	cout<<"Graph By Matrix\n";
	g.display();
	cout<<"BFS by Array : ";
	g.breath_first_array(0);
	cout<<"\nDFS by Array : ";
	g.Depth_first_array(0);
	cout<<endl;
	cout<<"Prim's Algorithm \n";
	g.prims(0);
	cout<<"\nDijkstra Algorithm \n";
	g.dijkstra(0);
	cout<<endl;
	graph_by_list g1(4);
	g1.insert(0,1);
	g1.insert(1,0);
	g1.insert(0,3);
	g1.insert(1,2);
	g1.insert(3,2);
	g1.insert(2,3);
	cout<<"Graph By Adjacent List\n";
	g1.display();
	cout<<"BFS by Linked List : ";
	g1.breath_first(0);
	cout<<"\nDFS by Linked List : ";
	g1.depth_first(0);
}
