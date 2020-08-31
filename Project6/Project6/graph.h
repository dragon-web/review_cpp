#pragma once
#include"common.h"

template<class W>
struct LinkEdge
{
	LinkEdge<W>* _pNext;
	W _weight; // 节点的权值
	size_t _src; // 起点的下标(后面使用)
	size_t _dst; // 终点的下标
	LinkEdge(size_t src, size_t dst, const W& weight)
		: _src(src)
		, _dst(dst)
		, _weight(weight)
		, _pNext(NULL)
	{}
};


template<class V, class W, bool IsDirect = false>
class Graph
{
	typedef LinkEdge<W> LinkEdge;
	typedef Graph<V, W, IsDirect> Self;
public:
	Graph(const V* array, size_t size)
		: _v(array, array + size)
	{
		_linkEdges.resize(size);
	}// g.AddEdge('A', 'D', 10);
	void AddEdge(const V& v1, const V& v2, const W& weight)
	{
		size_t src = GetIndexOfV(v1);
		size_t dst = GetIndexOfV(v2);
		_AddEdge(src, dst, weight);
		if (!IsDirect)
			_AddEdge(dst, src, weight);
	}
	// 获取顶点元素在其数组中的下标
	size_t GetIndexOfV(const V& v)
	{
		for (size_t i = 0; i < _v.size(); ++i)
		{
			if (v == _v[i])
				return i;
		}
		assert(false);
		return -1;
	}
	void PrintGraph()
	{
		for (size_t index = 0; index < _v.size(); ++index)
		{
			cout << "v[" << _v[index] << "]--->";
			LinkEdge* pCur = _linkEdges[index];
			while (pCur)
			{
				cout << "v[" << _v[pCur->_dst] << "]--->";
				pCur = pCur->_pNext;
			} c
				out << "NULL" << endl;
		}
	} 
	int GetVDev(const V& v)
	{
		size_t index = GetIndexOfV(v);
		LinkEdge* pCur = _linkEdges[index];
		size_t count = 0;
		// 出度
		while (pCur)
		{
			count++;
			pCur = pCur->_pNext;
		}
		if (IsDirect)   //是否为有向图，如果不是则将过程反向进行一遍
		{
			// 入度
			int dst = index;
			for (size_t src = 0; src < _v.size(); ++src)
			{
				if (src == dst)
					continue;
				else
				{
					LinkEdge* pCur = _linkEdges[src];
					while (pCur)
					{
						if (pCur->_dst == dst)
							count++;
						pCur = pCur->_pNext;
					}
				}
			}
		}
		return count;
	}
private:
	void _AddEdge(size_t src, size_t dst, const W& weight)
	{
		LinkEdge* pCur = _linkEdges[src];
		// 检测当前边是否存在
		while (pCur)
		{
			if (pCur->_dst == dst)
				return;
			pCur = pCur->_pNext;
		}
		LinkEdge* pNewNode = new LinkEdge(src, dst, weight);
		pNewNode->_pNext = _linkEdges[src];
		_linkEdges[src] = pNewNode;
	}

private:
	vector<V> _v;
	vector<LinkEdge*> _linkEdges;
};