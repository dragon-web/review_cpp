#pragma once
#include"common.h"

// vertex 顶点
// edge 边
//weight 权值

//邻接矩阵
namespace matrix
{
	template<class V, class W, bool Direction = false>
	class Graph
	{
		Graph(V *vertexs, int n)
		{
			_vertes.reserve(n);
			for (int i = 0; i < n; ++i)
			{
				_vertes.push_back(vertexs[i]);
				_vertexIndexMap[vertexs[i]] = i;
			}
			_matrix.resize(n);
			for (size_t i = 0; i < n; ++i)
			{
				_matrix[i].resize(n, W());
			}
		}
		int GetVertexIndex(const V &v)
		{
			auto it = _vertexIndexMap.find(v);
			if (it != _vertexIndexMap.end())
			{
				return it->second;
			}
			else
			{
				throw invalid_argument("非法顶点");
			}
		}
		void AddEdge(const V& src, const V &dst, const W& w)
		{
			int srcIndex = GetVertexIndex(src);
			int dstIndex = GetVertexIndex(dst);

			_matrix[srcIndex][dstIndex] = w;
			if (Direction == false)
			{
				_matrix[dstIndex][srcIndex] = w;
			}
		}

	private:
		vector<V> _vertes;
		vector<vector<W>> _matrix;
		map<V, int> _vertexIndexMap;
	};
}


namespace tables
{
	template<class W>
	struct EdgeNode
	{
		int _srcIndex;
		int _dstIndex;
		const W& _w;

		EdgeNode<W> * _next;
	};

	template<class V, class W, bool Direction = false>
	class Graph
	{
		Graph(V *vertexs, int n)
		{
			_vertes.reserve(n);
			for (int i = 0; i < n; ++i)
			{
				_vertes.push_back(vertexs[i]);
				_vertexIndexMap[vertexs[i]] = i;
			}
			_LinkTable.resize(n, nullptr);
		}
		int GetVertexIndex(const V &v)
		{
			auto it = _vertexIndexMap.find(v);
			if (it != _vertexIndexMap.end())
			{
				return it->second;
			}
			else
			{
				throw invalid_argument("非法顶点");
			}
		}
		void AddEdge(const V& src, const V &dst, const W& w)
		{
			int srcIndex = GetVertexIndex(src);
			int dstIndex = GetVertexIndex(dst);
			
			EdgeNode* node = new AddEdge;
			node->_srcIndex = srcIndex;
			node->_dstIndex = dstIndex;
			node->_w = w;
			//头插
			node->_next = _LinkTable[srcIndex];
			_LinkTable[srcIndex] = node;
			if (Direction = false)
			{
				EdgeNode* node = new AddEdge;
				node->_srcIndex = dstIndex;
				node->_dstIndex = srcIndex;
				node->_w = w;
				//头插
				node->_next = _LinkTable[dstIndex];
				_LinkTable[dstIndex] = node;
			}
		}

		void TestGraph()
		{
			string strs[] = { "保罗","詹姆斯","韦德","加内特","科比","库里" };
			Graph<string, int> g(strs,sizeof(strs)/sizeof(string);
			g.AddEdge("保罗", "詹姆斯",95);
			g.AddEdge("韦德", "詹姆斯", 97);
			g.AddEdge("库里", "詹姆斯", 92);
			g.AddEdge("科比", "詹姆斯", 80);
			g.AddEdge("科比", "加内特", 88);
		}

	private:
		vector<V> _vertes;
		map<V, int> _vertexIndexMap;
		vector<EdgeNode<W>*> _LinkTable;
	};
}








