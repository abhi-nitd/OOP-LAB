#include<bits/stdc++.h>
using namespace std;
#define ll long long
void dfs(vector <ll> adj[],int visited[],ll root)
{
	stack <ll> st;
	
	visited[root]=1;
	st.push(root);
	while(!st.empty())
	{
		ll x=st.top();
		st.pop();
		for(auto itr=adj[x].begin();itr!=adj[x].end();itr++)
		{
			if(visited[*itr]==0)
			{
				st.push(*itr);
				visited[*itr]=1;
			}
		}
	}
}
int main()
{
	// ios_base::sync_with_stdio(false);
 //    cin.tie(NULL);
    ll n,e;
    cout<<"Enter the number of nodes in graph : ";
    cin>>n;
    cout<<"Enter the number of edges in the graph : ";
    cin>>e;
    vector <ll> adj[1000];
    int visited[1000]={0};
    
    while(e--)
    {
    	ll a,b;
    	cin>>a>>b;
    	adj[a].push_back(b);
    	adj[b].push_back(a);
    }
    dfs(adj,visited,1);
    ll i, connected=1;
    for(i=1;i<=n;i++)
    {
    	if(visited[i]==0)
    	{
    		connected++;
    		dfs(adj,visited,i);
    	}
    }
    cout<<"The number of connected components in the graph is : "<<connected<<endl;
    cout<<"The adjacent list is :"<<endl;
    for(i=1;i<=n;i++)
    {
    	cout<<i<<" : ";
    	for(auto itr=adj[i].begin();itr!=adj[i].end();itr++)
    	{
    		cout<<*itr<<" ";
    	}
    	cout<<endl;
    }
}