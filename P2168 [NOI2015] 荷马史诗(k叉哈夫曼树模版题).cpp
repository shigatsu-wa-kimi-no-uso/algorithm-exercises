#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <vector>
#include <functional>
#include <map>
#include<vector>

//P2168 [NOI2015] 荷马史诗(k叉哈夫曼树模版题)

using BYTE = unsigned char;
using WORD = unsigned short;
using DWORD = unsigned long;
using QWORD = unsigned long long;

template<typename Elem_t, class Compare_Func_t, class Container_t>
class MyHeap
{
private:
	Compare_Func_t _cmpFunc;
	Container_t _heap;
	int _lastIndex() {
		return _heap.size() - 1;
	}
	int _topIndex() {
		return 0;
	}
	int _leftSon(int index) {
		return (index << 1) + 1;
	}
	int _rightSon(int index) {
		return (index << 1) + 2;
	}
	int _parent(int index) {
		return (index - 1) >> 1;
	}
	void _emerge(int index) {
		int currIndex = index;
		while (currIndex != _topIndex()) {
			int parentIndex = _parent(currIndex);
			Elem_t& curr = _heap[currIndex];
			Elem_t& par = _heap[parentIndex];
			if (_cmpFunc(par, curr)) {           //curr < par
				std::swap(par, curr);
				currIndex = parentIndex;
			} else {
				break;
			}
		}
	}
	void _sink(int index) {
		int currIndex = index;
		while (currIndex != _lastIndex()) {
			int lsindex = _leftSon(currIndex);
			int rsindex = _rightSon(currIndex);
			int toSwapIndex = currIndex;

			//找左右儿子中更大/小的那个
			if (lsindex <= _lastIndex() && _cmpFunc(_heap[currIndex], _heap[lsindex])) {	  //判断是否有左儿子        
				toSwapIndex = lsindex;	//left_son < curr
			}

			if (rsindex <= _lastIndex() && _cmpFunc(_heap[toSwapIndex], _heap[rsindex])) {    //判断是否有右儿子
				toSwapIndex = rsindex;
			}

			if (toSwapIndex == currIndex) {
				break;
			} else {
				std::swap(_heap[currIndex], _heap[toSwapIndex]);
				currIndex = toSwapIndex;
			}
		}
	}


public:
	MyHeap() {}
	MyHeap(int initCapacity) {
		reserve(initCapacity);
	}

	void reserve(int newCapacity) {
		_heap.reserve(newCapacity);
	}

	int _count() {
		return _heap.size();
	}
	int capacity() {
		return _heap.capacity();
	}
	const Elem_t& top() {
		return _heap[_topIndex()];
	}

	void push(const Elem_t& i) {
		_heap.push_back(i);
		_emerge(_lastIndex());
	}

	void pop() {
		std::swap(_heap[_topIndex()], _heap[_lastIndex()]);
		_heap.pop_back();
		_sink(_topIndex());
	}
};

template<typename Elem_t>
class MyHuffman
{
private:
    const int _radix;
	struct HuffmanNode {
		QWORD freq;
		QWORD nodeCnt;
		Elem_t* elem;
		HuffmanNode** pSons;
        int _radix;
		HuffmanNode(QWORD freq, int radix)
			:freq(freq), nodeCnt(0),elem(nullptr), _radix(radix), pSons(new HuffmanNode* [radix]) {
			for (int i = 0; i < _radix; ++i) {
				pSons[i] = nullptr;
			}
		}
		HuffmanNode(QWORD freq, const Elem_t& elem, int radix)
			:freq(freq), nodeCnt(1), elem(new Elem_t(elem)),_radix(radix),pSons(new HuffmanNode*[radix]) {
			for (int i = 0; i < _radix; ++i) {
                pSons[i] = nullptr;
			}
        }
		HuffmanNode(QWORD freq, QWORD nodeCnt, int radix, HuffmanNode** pSons)
			:freq(freq), nodeCnt(nodeCnt), elem(nullptr), _radix(radix), pSons(pSons) {}
		~HuffmanNode() {
			delete elem;
            for (int i = 0; i < _radix; ++i) {
                delete pSons[i];
            }
            delete[] pSons;
		}
	};

	struct CmpFunc_t
	{
		bool operator()(const HuffmanNode* lft, const HuffmanNode* rgt) const {
			if (lft->freq > rgt->freq) {
				return true;
			} else if (lft->freq == rgt->freq) {
				return lft->nodeCnt > rgt->nodeCnt;
			} else {
				return false;
			}
		}
	};

	MyHeap<HuffmanNode*, CmpFunc_t,std::vector<HuffmanNode*>> _freqHeap;
	std::map<Elem_t, QWORD> _freqMap;
	int _count;
	void _dfsTraverse(HuffmanNode* node, std::string& nodeBits, std::string* bitsBuf, Elem_t** pElems, QWORD* freqs, DWORD& index) {
		if (node->elem != nullptr) {
			bitsBuf[index] = nodeBits;
			pElems[index] = node->elem;
			freqs[index] = node->freq;
			index++;
		} else if(node->freq!=0){
            for (int i = 0; i < _radix; ++i) {
                char ch = i > 9 ? (i - 10) + 'A' : i + '0';
				nodeBits += ch;
				_dfsTraverse(node->pSons[i], nodeBits, bitsBuf, pElems, freqs, index);
				nodeBits.pop_back();
            }
		}
	}
public:
    MyHuffman(int radix):_radix(radix){}
	void countFrequency(Elem_t* elems, int _count) {
		this->_count = _count;
		for (int i = 0; i < _count; ++i) {
			if (_freqMap.hasKey(elems[i])) {
				_freqMap[elems[i]]++;
			} else {
				_freqMap.put(elems[i], 1);
			}
		}
	}
    void setFrequencyMap(std::map<Elem_t, QWORD>&& freqMap) {
        _freqMap = std::move(freqMap);
        _count = _freqMap.size();
    }
	void buildTree() {
		_freqHeap.reserve(_freqMap.size());
		for (std::pair<const Elem_t,QWORD>& entry : _freqMap) {
			_freqHeap.push(new HuffmanNode(entry.second, entry.first,_radix));
		}
        //补点
		if ((_count - 1) % (_radix - 1) != 0) {
			int cmplcnt = _radix - 1 - (_count - 1) % (_radix - 1);
			for (int i = 0; i < cmplcnt; ++i) {
                _freqHeap.push(new HuffmanNode(0, _radix));
			}
		}
		while (_freqHeap._count() != 1) {
			QWORD freqs = 0, nodeCnt = 0;
            HuffmanNode** pSons = new HuffmanNode*[_radix];
            for (int i = 0; i < _radix; ++i) {
                HuffmanNode* topNode = _freqHeap.top();
                _freqHeap.pop();
                pSons[i] = topNode;
                freqs += topNode->freq;
				nodeCnt += topNode->nodeCnt;
            }
            _freqHeap.push(new HuffmanNode(freqs,nodeCnt,_radix,pSons));
		}
	}
    void getBitStrings(std::string* bitStringBuf,Elem_t** elems,QWORD* freqs) {
		HuffmanNode* tree = _freqHeap.top();
		std::string nodeBits;
		DWORD index = 0;
		_dfsTraverse(tree, nodeBits, bitStringBuf, elems, freqs, index);
    }
	void print() {
		HuffmanNode* tree = _freqHeap.top();
		std::string nodeBits;
		std::string* bitsBuf = new std::string[_count];
		Elem_t** elems = new Elem_t * [_count];
		QWORD* freqs = new QWORD[_count];
		DWORD index = 0;
		_dfsTraverse(tree, nodeBits, bitsBuf, elems, freqs, index);
		int maxlen = 0;
		for (int i = 0; i < _count; ++i) {
			maxlen = maxlen < bitsBuf[i].length() ? bitsBuf[i].length() : maxlen;
		}
		std::cout << std::left << std::setw(maxlen + 3) << "bits" << std::left << std::setw(10) << "val" << std::left << std::setw(10) << "freq" << "\n";
		for (int i = 0; i < _count; ++i) {
			std::cout << std::left << std::setw(maxlen + 3) << bitsBuf[i] << std::left << std::setw(10) << *elems[i] << std::left << std::setw(10) << freqs[i] << "\n";
		}
		delete[] bitsBuf;
		delete[] elems;
		delete[] freqs;
	}
    ~MyHuffman() {
        delete _freqHeap.top();
    }
};

int main() {
    int n, k;
	QWORD f;
	//freopen(R"(C:\Users\Administrator\Documents\Visual Studio 2022\Projects\ConsoleApplication26\x64\Debug\P2168_9.in)", "rb",stdin);
    std::cin >> n >> k;
    MyHuffman<int> myHuff(k);
    std::map<int, QWORD> freqMap;
    for (int i = 0; i < n; ++i) {
        std::cin >> f;
		freqMap.insert({ i,f });
    }
    myHuff.setFrequencyMap(std::move(freqMap));
    myHuff.buildTree();
	std::string* bitsBuf = new std::string[n];
	int** elems = new int*[n];
	QWORD* freqs = new QWORD[n];
    myHuff.getBitStrings(bitsBuf, elems, freqs);
    size_t len = 0;
    size_t maxLen = 0;
    for (int i = 0; i < n; ++i) {
        len += bitsBuf[i].length() * freqs[i];
        maxLen = std::max(maxLen, bitsBuf[i].length());
    }
    std::cout << len << "\n" << maxLen;
    
}