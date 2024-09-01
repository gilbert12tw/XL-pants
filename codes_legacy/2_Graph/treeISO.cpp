const int MAXN=100005;
const long long X=12327,P=0xdefaced;
vector<int> g[MAXN];
bool vis[MAXN];
long long dfs(int u){//hash ver
	vis[u]=1;
	vector<long long> tmp;
	for(auto v:g[u])if(!vis[v])tmp.PB(dfs(v));
	if(tmp.empty())return 177;
	long long ret=4931;
	sort(tmp.begin(),tmp.end());
	for(auto v:tmp)ret=((ret*X)^v)%P;
	return ret;
}
//-----------------------------
string dfs(int x,int p){
	vector<string> c;
	for(int y:g[x])
		if(y!=p)c.emplace_back(dfs(y,x));
	sort(c.begin(),c.end());
	string ret("(");
	for(auto &s:c)ret+=s;
	ret+=")";
	return ret;
}
