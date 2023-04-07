#include <bits/stdc++.h>
using namespace std;
// Remove Max Number of Edges to Keep Graph Fully Traversable(LeetCode)
bool cmp(vector<int> &a, vector<int> &b)
{
	if (a[0] != b[0])
	{
		return a[0] > b[0];
	}
	if (a[1] != b[1])
		return a[1] > b[1];
	else
		return a[2] > b[2];
}
const int N = 1e5 + 7;
class DSU
{
	public:
	int Parent[N], Size[N];
	void make(int v)
	{
		Parent[v] = v;
		Size[v] = 1;
	}
	int Find(int v)
	{
		if (Parent[v] == v)
			return v;
		else
			return Parent[v] = Find(Parent[v]);
	}
	bool Union(int a, int b)
	{
		a = Find(a), b = Find(b);
		if (a == b)
			return false;
		else
		{
			if (Size[a] < Size[b])
				swap(a, b);
			Size[a] += Size[b];
			Parent[b] = a;
		}
		return true;
	}
};
int maxNumEdgesToRemove(int n, vector<vector<int>> &edges)
{
	sort(edges.begin(), edges.end(), cmp);
	DSU alice, bob;
	for (int i = 0; i <= n; ++i)
	{
		alice.make(i);
		bob.make(i);
	}
	int totalEdges=0, removedEdges=0;
	for(auto e: edges){
		if(e[0]==3){
			bool isValidAlice=alice.Union(e[1], e[2]);
			bool isValidBob=bob.Union(e[1], e[2]);
			if(isValidAlice) totalEdges++;
			if(isValidBob) totalEdges++;
			if(!isValidAlice||!isValidBob) removedEdges++;
		}
		if(e[0]==1){
			bool isValidAlice=alice.Union(e[1], e[2]);
			if(isValidAlice) totalEdges++;
			else removedEdges++;
		}
		if(e[0]==2){
			bool isValidBob=bob.Union(e[1], e[2]);
			if(isValidBob) totalEdges++;
			else removedEdges++;
		}
	}
	if(totalEdges!=2*n-2) return -1;
	return removedEdges;
}
