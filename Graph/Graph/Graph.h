#pragma once
#include"common.h"

// vertex ����
// edge ��
//weight Ȩֵ

//�ڽӾ���
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
				throw invalid_argument("�Ƿ�����");
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
				throw invalid_argument("�Ƿ�����");
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
			//ͷ��
			node->_next = _LinkTable[srcIndex];
			_LinkTable[srcIndex] = node;
			if (Direction = false)
			{
				EdgeNode* node = new AddEdge;
				node->_srcIndex = dstIndex;
				node->_dstIndex = srcIndex;
				node->_w = w;
				//ͷ��
				node->_next = _LinkTable[dstIndex];
				_LinkTable[dstIndex] = node;
			}
		}

		void TestGraph()
		{
			string strs[] = { "����","ղķ˹","Τ��","������","�Ʊ�","����" };
			Graph<string, int> g(strs,sizeof(strs)/sizeof(string);
			g.AddEdge("����", "ղķ˹",95);
			g.AddEdge("Τ��", "ղķ˹", 97);
			g.AddEdge("����", "ղķ˹", 92);
			g.AddEdge("�Ʊ�", "ղķ˹", 80);
			g.AddEdge("�Ʊ�", "������", 88);
		}

	private:
		vector<V> _vertes;
		map<V, int> _vertexIndexMap;
		vector<EdgeNode<W>*> _LinkTable;
	};
}








