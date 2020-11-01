#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
#include<map>
#include<set>
#include<vector>
#include<string>
#include<unordered_map>
#include<functional>
#include<queue>

using namespace std;
/*
class Solution {
public:
	class Compare
	{
	public:
		// 在set中进行排序时的比较规则
		bool operator()(const pair<string, int>& left, const pair<string, int>&right)
		{
			return left.second > right.second;
		}
	};

	vector<string> topKFrequent(vector<string>& words, int k)
	{
		// 用<单词，单词出现次数>构建键值对，然后将vector中的单词放进去，统计每个单词出现的次数
		map<string, int> m;
		for (size_t i = 0; i < words.size(); ++i)
			++(m[words[i]]);
		// 将单词按照其出现次数进行排序，出现相同次数的单词集中在一块
		multiset<pair<string, int>, Compare> ms(m.begin(), m.end());
		// 将相同次数的单词放在set中，然后再放到vector
		set<string> s;
		size_t count = 0; // 统计相同次数单词的个数
		size_t leftCount = k;
		vector<string> ret;
		for (auto& e : ms)
		{
			if (!s.empty())
			{
				// 相同次数的单词已经全部放到set中
				if (count != e.second)
				{
					if (s.size() < leftCount)
					{
						ret.insert(ret.end(), s.begin(),s.end());
						leftCount -= s.size();
						s.clear();
					}
					else
					{
						break;
					}
				}
			}
			count = e.second;
			s.insert(e.first);
		}
		for (auto& e : s)
		{
			if (0 == leftCount)
				break;
			ret.push_back(e);
			leftCount--;
		}
		return ret;

	}
};




class Solution {
public:
	static bool cmp(const pair<string, int> &p1, const pair<string, int> &p2) {
		if (p1.second > p2.second)
			return true;
		if (p1.second == p2.second) {
			if (p1.first < p2.first)
				return true;
		}
		return false;
	}
public:
	vector<string> topKFrequent(vector<string>& words, int k) {
		unordered_map<string, int> mymap;
		for (int i = 0; i < words.size(); i++) {
			mymap[words[i]]++;
		}
		vector<pair<string, int>> allpair;
		for (pair<string, int> p : mymap)
			allpair.push_back(p);
		sort(allpair.begin(), allpair.end(), cmp);
		vector<string>res;
		for (int i = 0; i < k; i++) {
			res.push_back(allpair[i].first);
		}
		return res;
	}
};



struct TrieNode {
	bool  isEnd;
	TrieNode* branch[26];
	//int times;
	//string s;
	pair<int, string> show;//存储字符串和出现次数
	TrieNode() :isEnd(false) {
		show.first = 0;
		for (int i = 0; i < 26; i++) {
			branch[i] = nullptr;
		}
	}
};

class Solution {
public:
	vector<string> topKFrequent(vector<string>& words, int k) {
		root = new TrieNode();
		for (auto it : words) {
			insert(it);//建立字典树
		}
		K = k;
		vector<string> res(k);
		dfs(root);
		for (int i = 0; i < k; i++) {//从堆中取数据
			res[i] = p.top().second;
			p.pop();
		}
		reverse(res.begin(), res.end()); //逆置
		return res;
	}
	void insert(string &word) {//构建字典树
		TrieNode* node = root;

		for (auto it : word) {
			if (node->branch[it - 'a'] == nullptr) {
				node->branch[it - 'a'] = new TrieNode();
			}
			node = node->branch[it - 'a'];
		}
		node->isEnd = true;
		node->show.first++;
		node->show.second = word;
	}

	void dfs(TrieNode* root) {
		if (root == nullptr) return;
		if (root->isEnd) {//建立堆
			p.push(root->show);
			if (p.size() > K) {
				p.pop();
			}
		}
		for (int i = 0; i < 26; i++) {//深搜
			if (root->branch[i] != nullptr) {
				dfs(root->branch[i]);
			}
		}
	}

	struct comp {
		bool operator()(pair<int, string> a, pair<int, string> b) {
			if (a.first > b.first) return true;//自己写的比较函数
			if (a.first < b.first) return false;
			if (a.second >= b.second) return false;
			return true;
		}
	};
private:
	TrieNode* root;
	int K;
	priority_queue<pair<int, string>, vector<pair<int, string>>, comp> p;
};


int main()
{
//	Solution a;

	system("pause");
	return 0;
} 
*/