// Solving from line 597
// Intended for C++23

// DeterministicChoco232's C++ competitive programming environment:
// https://github.com/DeterministicChoco232/cppcp
#include <bits/stdc++.h>
#ifdef DETCHOCO_ENV
#include "headers/format_containers.hpp"
#endif

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using namespace std;
using vl = vector<ll>;
using vvl = vector<vl>;
using pll = pair<ll, ll>;
const ll inf=1LL<<60;

template<typename T>
void print(T x) {
	print("{}", x);
}

template<typename T>
void println(T x) {
	println("{}", x);
}

// Created just for 1915F kek
// Ik g++ supplies one but I want to avoid too much reliance on non-standard stuff
namespace RB_tree {
	// Red Black Tree
	// Explanation: https://en.wikipedia.org/wiki/Red%E2%80%93black_tree#
	enum class Color {Red, Black};
	enum class iterator_dir {Forward, Backward};
	template<typename T>
	struct Node {
		T value;
		size_t subtree_size;
		Color color = Color::Red;
		Node *parent;
		Node *children[2];
		Node(T v, Color c=Color::Red, Node *p=nullptr, Node *l=nullptr, Node* r=nullptr)
			: value(v), color(c), parent(p) {
				subtree_size=1;
				children[0]=l;
				children[1]=r;
			}
		Node*& left() {
			return children[0];
		}
		Node*& right() {
			return children[1];
		}

		Node* subtree_min() {
			Node *N = this;
			while(N->left()!=nullptr) {
				N=N->left();
			}
			return N;
		}
		Node* subtree_max() {
			Node *N = this;
			while(N->right()!=nullptr) {
				N=N->right();
			}
			return N;
		}

		void subtree_delete() {
			if (left() != nullptr) left()->subtree_delete();
			if (right() != nullptr) right()->subtree_delete();
			delete this;
		}

		bool dir() {
			return parent->right() == this;
		}

		Node* successor() {
			if(right() != nullptr) {
				return right()->subtree_min();
			} else {
				Node *N = this;
				while (true) {
					if (N->parent == nullptr || !N->dir())
						return N->parent;
					N=N->parent;
				}
			}
		}

		Node* predecessor() {
			if(left() != nullptr) {
				return left()->subtree_max();
			} else {
				Node *N = this;
				while (true) {
					if (N->parent == nullptr || N->dir())
						return N->parent;
					N=N->parent;
				}
			}
		}
		
		void rotate() {
			bool d = dir();
			Node* C = children[1-d], *P = parent;
			subtree_size=P->subtree_size;
			P->subtree_size = 1;
			if (P->children[1-d] != nullptr)
				P->subtree_size += P->children[1-d]->subtree_size;
			children[1-d]=P;
			P->children[d]=C;
			if (C!=nullptr) {
				C->parent=P;
				P->subtree_size += C->subtree_size;
			}
			if(P->parent != nullptr)
				P->parent->children[P->dir()]=this;
			parent=P->parent;
			P->parent=this;
		}
	};

	template<typename T>
	bool IsBlack(Node<T> *N) {
		return N==nullptr || N->color==Color::Black;
	}

	template<typename ValueType, typename Comp = std::less<ValueType>>
	class RB_Tree {
		using NodeType = Node<ValueType>;
		using TreeType = RB_Tree<ValueType, Comp>;
	public:
		NodeType* root;
		static const size_t npos = -1;
	private:
	public:
		RB_Tree() {
			root = nullptr;
		}
		
		bool empty() {
			return root == nullptr;
		}

		size_t size() {
			return empty() ? 0 : root->subtree_size;
		}
		
		NodeType* search(ValueType value) {
			NodeType *N = root;
			auto comp = Comp{};
			while(N!=nullptr) {
				if (!comp(N->value, value) && !comp(value, N->value))
					return N;
				N=N->children[comp(N->value, value)];
			}
			return N;
		}

		bool contains(ValueType value) {
			return search(value) != nullptr;
		}

		void insert(ValueType value) {
			auto comp = Comp{};
			NodeType *P = nullptr, *N = root;
			while(N != nullptr) {
				if(!comp(N->value, value) && !comp(value, N->value))
					return;
				P=N;
				N=P->children[ comp(P->value, value) ];
			}
			if(P==nullptr) {
				root = new NodeType(value);
				return;
			}
			N = new NodeType(value, Color::Red, P);
			P->children[ comp(P->value, value) ] = N;
			while(P!=nullptr) {
				P->subtree_size++;
				P=P->parent;
			}
			while(true) {
				// Case I3
				if (root == N) {
					return;
				}
				P = N->parent;
				// Case I4
				if (root == P) 
					P->color = Color::Black;
				// Case I4+I1
				if (P->color == Color::Black)
					return;
				// P non-root red node
				NodeType *G = P->parent, *U = G->children[1-P->dir()];
				// Case I2
				if (!IsBlack(U)) {
					G->color = Color::Red;
					U->color = Color::Black;
					P->color = Color::Black;
					N = G;
					continue;
				}
				// U nullptr or black
				// Case I5
				if(N->dir() != P->dir()) {
					N->rotate();
					std::swap(N, P);
				}
				// Case I5+I6
				if(N->dir() == P->dir()) {
					P->rotate();
					if(root == G)
						root = P;
					P->color = Color::Black;
					G->color = Color::Red;
					return;
				}
			}
		}

		void erase(NodeType* N) {
			auto comp = Comp{};
			NodeType *L = N->left(), *R = N->right(), *P = N->parent;
			if(L == nullptr && R == nullptr) {
				if (P==nullptr) {
					root = nullptr;
					return;
				} else {
					while (P!=nullptr) {
						P->subtree_size--;
						P=P->parent;
					}
				}
				P=N->parent;
				if (N->color == Color::Red) {
					P->children[N->dir()] = nullptr;
					delete N;
					return;
				} else {
					// non-root black leaf
					bool d = N->dir();
					P->children[N->dir()] = nullptr;
					delete N;
					NodeType *S, *C, *D;
					while(true) {
						S = P->children[1-d];
						// S must exist as P can not have only 1 black child
						C = S->children[d], D = S->children[1-d];
						// Case D1+D2
						if(IsBlack(P) && IsBlack(S) && IsBlack(C) && IsBlack(D)) {
							S->color = Color::Red;
							N = P;
							// Case D1
							if(N == root) return;
							d = N->dir();
							P = N->parent;
							continue;
						}
						// Case D3
						if(!IsBlack(S)) {
							S->rotate();
							if(root == P)
								root = S;
							S->color = Color::Black;
							P->color = Color::Red;
							S = C;
							C = S->children[d], D = S->children[1-d];
						}
						if(IsBlack(D)) {
							// Case D3+D4
							if(IsBlack(C)) {
								P->color = Color::Black;
								S->color = Color::Red;
								return;
							}
							// Case D3+D5
							C->rotate();
							S = C;
							C = S->children[d], D = S->children[1-d];
							S->color = Color::Black;
							D->color = Color::Red;
						}
						// Case D3+D5+D6
						S->rotate();
						if(root == P)
							root = S;
						S->color = P->color;
						P->color = Color::Black;
						D->color = Color::Black;
						return;
					}
				}
			} else if (L != nullptr && R != nullptr) {
				NodeType* S = R->subtree_min();
				std::swap(S->value, N->value);
				erase(S);
			} else {
				NodeType *C = (L == nullptr) ? R : L;
				C->parent = P;
				C->color = Color::Black;
				if (P==nullptr) {
					root = C;
				} else {
					P->children[N->dir()]=C;
					while (P!=nullptr) {
						P->subtree_size--;
						P=P->parent;
					}
				}
				delete N;
			}
		}

		void erase(ValueType value) {
			NodeType *N = search(value);
			if(N!=nullptr) erase(N);
		}

		void clear() {
			if (!empty()) root->subtree_delete();
			root = nullptr;
		}

		void swap(TreeType& other) {
			std::swap(root, other.root);
		}

		ValueType operator[](size_t index) {
			if (index < 0 || index >= size())
				throw out_of_range(format("Index {} out of bounds", index));
			NodeType *N = root;
			while(true) {
				size_t L_size = (N->left() == nullptr) ? 0 : N->left()->subtree_size;
				if(index < L_size) {
					N=N->left();
				} else if (index == L_size) {
					return N->value;
				} else {
					index -= L_size + 1;
					N=N->right();
				}
			}
		}

		size_t index(ValueType value) {
			size_t i=0;
			if(empty()) return npos;
			NodeType *N = root;
			auto comp = Comp{};
			while(N!=nullptr) {
				size_t L_size = (N->left() == nullptr) ? 0 : N->left()->subtree_size;
				if (!comp(N->value, value) && !comp(value, N->value))
					return i+L_size;
				if (comp(N->value, value))
					i += 1 + L_size;
				N=N->children[comp(N->value, value)];
			}
			return npos;
		}

		class iterator {
		private:
			NodeType* N;
			iterator_dir dir;
			TreeType* Tree;
		public:
			iterator(TreeType *Tree, NodeType* N, iterator_dir dir = iterator_dir::Forward)
				: Tree(Tree), N(N), dir(dir) {}
			iterator operator++() {
				N = dir == iterator_dir::Forward ? N->successor() : N->predecessor();
				return *this;
			}
			iterator operator--() {
				N = dir == iterator_dir::Forward ? N->predecessor(N) : N->successor();
				return *this;
			}
			iterator operator++(int) {
				iterator ret = *this;
				++(*this);
				return ret;
			}
			iterator operator--(int) {
				iterator ret = *this;
				--(*this);
				return ret;
			}
			ValueType operator*() {
				return N->value;
			}
			ValueType* operator->() {
				return &(N->value);
			}
			bool operator==(iterator other) {
				return N == other.N;
			}
			bool operator!=(iterator other) {
				return !(*this == other);
			}
		};

		iterator begin() {
			return iterator(this, (root==nullptr) ? root : root->subtree_min());
		}

		iterator end() {
			return iterator(this, nullptr);
		}

		iterator rbegin() {
			return iterator(this, (root==nullptr)? root : root->subtree_max(), iterator_dir::Backward);
		}

		iterator rend() {
			return iterator(this, nullptr, iterator_dir::Backward);
		}

		iterator find(ValueType value) {
			return iterator(this, search(value));
		}

		iterator lowerbound(ValueType value) {
			NodeType *N = root, *LB = nullptr;
			auto comp = Comp{};
			while(N!=nullptr) {
				if (!comp(N->value, value) && !comp(value, N->value))
					return iterator(this, N);
				else if (comp(value, N->value))
					LB = N;
				N=N->children[comp(N->value, value)];
			}
			return iterator(this, LB);
		}

		iterator upperbound(ValueType value) {
			NodeType *N = root, *UB = nullptr;
			auto comp = Comp{};
			while(N!=nullptr) {
				if (comp(value, N->value))
					UB = N;
				N=N->children[!comp(value, N->value)];
			}
			return iterator(this, UB);
		}

	};

	// Separate so I can choose what to make public easier.
	template<typename ValueType>
	class indexed_set {
		using TreeType=RB_Tree<ValueType>;
	private:
		TreeType is;
	public:
		static const size_t npos = TreeType::npos;
		indexed_set() = default;

		bool empty() {
			return is.empty();
		}

		size_t size() {
			return is.size();
		}

		bool contains(ValueType value) {
			return is.contains(value);
		}

		size_t index(ValueType value) {
			return is.index(value);
		}

		size_t count(ValueType value) {
			return contains(value);
		}

		void insert(ValueType value) {
			is.insert(value);
		}
		void erase(ValueType value) {
			is.erase(value);
		}

		indexed_set(initializer_list<ValueType> init) {
			for(ValueType value : init) {
				is.insert(value);
			}
		}

		void clear() {
			is.clear();
		}

		void swap(indexed_set<ValueType>& other) {
			is.swap(other.is);
		}

		string tree() {
			return is.tree();
		}

		ValueType operator[](size_t index) {
			return is[index];
		}

		bool isValidRBTree() {
			return !is.redViolation() && is.blackViolation(is.root) != -1;
		}

		using iterator = TreeType::iterator;
		iterator begin() {
			return is.begin();
		}

		iterator end() {
			return is.end();
		}

		iterator rbegin() {
			return is.rbegin();
		}

		iterator rend() {
			return is.rend();
		}

		iterator lowerbound(ValueType value) {
			return is.lowerbound(value);
		}

		iterator upperbound(ValueType value) {
			return is.upperbound(value);
		}

		iterator find(ValueType value) {
			return is.find(value);
		}
	};
}

using RB_tree::indexed_set;

template<typename T>
ostream& operator<<(ostream& os, const indexed_set<T>& s) {
	return os << format("{}", s);
}

#ifndef QUOTE_IF_STRING
#define QUOTE_IF_STRING
string quoteIfString(string s) {
	stringstream ss;
	ss << std::quoted(s);
	return ss.str();
}
template<typename T>
string quoteIfString(T s) {
	stringstream ss;
	ss << s;
	return ss.str();
}
#endif

template<typename T>
struct formatter<indexed_set<T>, char>
{
 
    template<class ParseContext>
    constexpr ParseContext::iterator parse(ParseContext& ctx)
    {
		// No parsing for now
		auto it = ctx.begin();
		if (*it != '}')
			throw std::format_error("Invalid format args for indexed_set.");
        return it;
    }
 
    template<class FmtContext>
    FmtContext::iterator format(indexed_set<T> s, FmtContext& ctx) const
    {
        string ret = "indexed_set{";
		bool first=true;
		for(const auto& element : s) {
			if(!first) ret += ", ";
			first=false;
			ret+=quoteIfString(element);
		}
		ret += "}";
        return ranges::copy(ret, ctx.out()).out;
    }
};

#define MULTIPLE_TESTS
void solve() {
	ll n;
	cin >> n;
	indexed_set<ll> a;
	map<ll, ll> b;
	for(ll i=1; i<=n; ++i) {
		ll a_i, b_i;
		cin >> a_i >> b_i;
		a.insert(a_i);
		b[b_i] = a_i;
	}
	ll passes = 0;
	for(auto b_i : b) {
		passes+=a.index(b_i.second);
		a.erase(b_i.second);
	}
	println(passes);
}

int main() {
	ios_base::sync_with_stdio(false); // slight io speed increase
	// But messes up sync of o streams so I only use std::print()
	cin.tie(NULL); // cout must be manually flushed
	cout<<fixed<<setprecision(6); // floats/doubles correct to 5sf.

#ifdef MULTIPLE_TESTS
	ll t;cin >> t;
	while(t--)
#endif
	solve();
    
	return 0;
}
