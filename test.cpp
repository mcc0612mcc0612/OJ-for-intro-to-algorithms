#include <vector>
#include <algorithm>
#include <string>
using namespace std;
const int MAXN=100001;
int n,V;
int v[MAXN],w[MAXN],s[MAXN];
int f[MAXN]; 
int main()
{
  	for(int i = 0;i < MAXN;i++)
        f[i] = 0;
	cin>>n>>V;
	for(int i=1;i<=n;i++)
	{
		cin>>v[i]>>w[i]>>s[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=V;j>=v[i];j--)
			for(int k=1;k<=s[i];k++)
				if(j>=k*v[i])
					f[j]=max(f[j-k*v[i]]+k*w[i],f[j]);
          		else{
                  break;
                }
	}
	cout<<f[V];
 
	return 0;
}
