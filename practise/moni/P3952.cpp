#include <bits/stdc++.h>

using i64 = long long;

struct node
{
	char F,i;
	std::string x,y;

	node(){F = i = char(0);x = y = "";}
};

bool judge(std::string x)
{
	if(x[0] >= '0' && x[0] <= '9')return true;
	return true;
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t;
	std::cin >> t;

	while(t --){
		int n;
		std::string O;
		std::cin >> n >> O;

		std::deque<node> cs;
		int e = 0,f = 0;
		for(int i = 1;i <= n;i ++){
			node no;
			std::cin >> no.F;
			if(no.F == 'E')cs.push_back(no),e++;
			else{
				f++;
				std::cin >> no.i >> no.x >> no.y;
				cs.push_back(no);
			}
		}

		if(f != e){
			std::cout << "ERR\n";
			continue;
		}

		int ans = 0;
		std::set<char> all;
		while(!cs.empty()){
			node now = cs.front();
			cs.pop_front();

			if(now.F == 'E'){
				e ++;
				while(!q.empty()){
					
				}
			}

			if(now.F == 'F'){
				if(!all.count(now.i)){
					all.insert(now.i);

				}else{
					std::cout << "ERR\n";
					break;
				}
			}
		}
	}

	return 0;
}