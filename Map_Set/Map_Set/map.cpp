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
		// ��set�н�������ʱ�ıȽϹ���
		bool operator()(const pair<string, int>& left, const pair<string, int>&right)
		{
			return left.second > right.second;
		}
	};

	vector<string> topKFrequent(vector<string>& words, int k)
	{
		// ��<���ʣ����ʳ��ִ���>������ֵ�ԣ�Ȼ��vector�еĵ��ʷŽ�ȥ��ͳ��ÿ�����ʳ��ֵĴ���
		map<string, int> m;
		for (size_t i = 0; i < words.size(); ++i)
			++(m[words[i]]);
		// �����ʰ�������ִ����������򣬳�����ͬ�����ĵ��ʼ�����һ��
		multiset<pair<string, int>, Compare> ms(m.begin(), m.end());
		// ����ͬ�����ĵ��ʷ���set�У�Ȼ���ٷŵ�vector
		set<string> s;
		size_t count = 0; // ͳ����ͬ�������ʵĸ���
		size_t leftCount = k;
		vector<string> ret;
		for (auto& e : ms)
		{
			if (!s.empty())
			{
				// ��ͬ�����ĵ����Ѿ�ȫ���ŵ�set��
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
	pair<int, string> show;//�洢�ַ����ͳ��ִ���
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
			insert(it);//�����ֵ���
		}
		K = k;
		vector<string> res(k);
		dfs(root);
		for (int i = 0; i < k; i++) {//�Ӷ���ȡ����
			res[i] = p.top().second;
			p.pop();
		}
		reverse(res.begin(), res.end()); //����
		return res;
	}
	void insert(string &word) {//�����ֵ���
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
		if (root->isEnd) {//������
			p.push(root->show);
			if (p.size() > K) {
				p.pop();
			}
		}
		for (int i = 0; i < 26; i++) {//����
			if (root->branch[i] != nullptr) {
				dfs(root->branch[i]);
			}
		}
	}

	struct comp {
		bool operator()(pair<int, string> a, pair<int, string> b) {
			if (a.first > b.first) return true;//�Լ�д�ıȽϺ���
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