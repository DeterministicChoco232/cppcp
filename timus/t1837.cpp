// solve function on line 22
#include <bits/stdc++.h>

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using namespace std;
using vl = vector<ll>;
using vvl = vector<vl>;
using pll = pair<ll, ll>;
const ll inf=1e18;

void print() {
    cout<<'\n';
}

template<typename T, typename... Args>
void print(T&& t, Args&&... args) {
    cout << t << ' ';
    print(std::forward<Args>(args)...);
}

void solve() {
	ll n; cin >> n;
	map<string, ll> ans;
	unordered_map<string, unordered_set<string>> neighbours;
	while(n--) {
		string name1, name2, name3;
		cin>>name1>>name2>>name3;
		neighbours[name1].insert(name2); neighbours[name1].insert(name3);
		neighbours[name2].insert(name1); neighbours[name2].insert(name3);
		neighbours[name3].insert(name1); neighbours[name3].insert(name2);
		ans[name1]=-1;
		ans[name2]=-1;
		ans[name3]=-1;
	}
	vector<string> checking;
	vector<string> to_check;
	if(ans.count("Isenbaev")) {
		ans["Isenbaev"]=0;
		checking.insert(to_check.begin(), neighbours["Isenbaev"].begin(), neighbours["Isenbaev"].end());
	}
	unordered_set<string> checked = neighbours["Isenbaev"];
	checked.insert("Isenbaev");


	ll distance = 1;
	while(!checking.empty()) {
		for(auto it = checking.rbegin(); it!=checking.rend();++it) {
			ans[*it] = distance;
			for(auto it2 = neighbours[*it].begin(); it2 != neighbours[*it].end(); ++it2) {
				if(checked.count(*it2)==0) {
					to_check.push_back(*it2);
					checked.insert(*it2);
				}
			}
		}
		checking.swap(to_check);
		to_check.clear();
		++distance;
	}

	for(auto key_value : ans) {
		string value = to_string(key_value.second);
		if (key_value.second == -1) {
			value = "undefined";
		}
		cout << key_value.first << ' ' << value << endl;
	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<fixed<<setprecision(6);

#ifdef TEST_CASES
	ll t;cin >> t;
	while(t--)
#endif
        solve();
    
    return 0;
}
