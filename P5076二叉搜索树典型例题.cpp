#include<iostream>

using namespace std;

//P5076 【深基16.例7】普通二叉树（简化版）
//二叉搜索数典型例题

struct Node {
	int val;
	int size;	//树的大小(包含左右子树和自身的节点数之和)(当值重复时也+1)
	int dupCnt;
	Node* ls;
	Node* rs;
};

Node* root;

void freeTree(Node* node) {
	if (node != nullptr) {
		freeTree(node->ls);
		freeTree(node->rs);
		delete node;
	}

}

void add(Node* &node,int val) {
	if (node == nullptr) {
		node = new Node{ val,1,1,nullptr,nullptr };
	} else {
		++node->size;
		if (val < node->val) {
			add(node->ls,val);
		} else if (val > node->val) {
			add(node->rs, val);
		} else {
			++node->size;
			++node->dupCnt;
		}
	}
}


//寻找后继(给定val找到比val大的最小值)(最小后继)
int findSuccessor(Node* node, int val, int lastSuc) {
	//如果当前节点为空,说明无法继续查找,直接返回最后一次找到的合适的后继
	if (node == nullptr) {
		return lastSuc;
	}
	if (val >= node->val) {
		//val值比当前节点值大(或相等),需要去它的右子树继续寻找,因为右子树的值都比这个节点的值大,且可能会大过val(val的最小后继可能在右子树中)
		return findSuccessor(node->rs, val, lastSuc);
	} else if (val < node->val) {
		//val值比当前节点值小,当前节点值可以作为val的其中一个后继,但不一定是最小后继
		//lastSuc每次被更新都会比上一个更优,因为只有val < node->val情况下才会更新lastSuc,且这个过程只能深入到底再回溯(不是bfs过程而是dfs)
		// 深入时,所处子树是具有lastSuc值的节点的左子树,而左子树的值都比lastSuc小(同时如果不满足val<node->val则压根不会被更新),所得的lastSuc必然是更优的
		//记录当前节点值作为后继(lastSuc),但要深入左子树继续查找,因为左儿子的值可能比当前节点值更小,而且还比val更大(从而更可能作为最小后继)
		return findSuccessor(node->ls, val, node->val);
	}
}


int findPredecessor(Node* node, int val, int lastPred) {
	if (node == nullptr) {
		return lastPred;
	}
	if (val <= node->val) {
		return findPredecessor(node->ls, val, lastPred);
	} else if (val > node->val) {
		return findPredecessor(node->rs, val, node->val);
	}
}


//查找val的排名
void getRank(Node* node,int val,int& rank) {
	if (node == nullptr) {
		++rank; //排名为比val值小的数的个数+1
		return;
	}
	if (val < node->val) {
		//val值比当前节点值小,需深入左子树进一步查询
		getRank(node->ls, val, rank);
	} else if (val > node->val) {
		//val比当前节点值大,则其左子树的所有值都比val小(排在val前面),应加上(当前树大小-右子树大小)
		//同时深入右子树进一步查询
		rank += node->size - (node->rs == nullptr ? 0 : node->rs->size);
		getRank(node->rs, val,rank);
	} else {
		//具有val值的节点,其左子树的节点都是小于val的(排在val前面),加上左子树大小后直接返回,不需要再查找了
		rank += node->ls == nullptr ? 0 : node->ls->size;
		rank += 1;	//排名为比val值小的数的个数+1
		return;
	}
}

//查找排名为rank的值
int getValue(Node* node, int rank,int accumulRank) {
	int lsize = node->ls == nullptr ? 0 : node->ls->size;
	int rsize = node->rs == nullptr ? 0 : node->rs->size;
	if (accumulRank + lsize + node->dupCnt < rank) {
		//判断是否需要深入右子树
		return getValue(node->rs, rank, accumulRank + lsize + node->dupCnt);
	} else if (accumulRank + lsize < rank) {
		//不需要深入右子树,只加左子树又不够排名,说明所要查的排名为rank的值就是当前节点值(节点可重复,重复计数为node->dupCnt)
		return node->val;
	} else {
		//否则说明当前值排名超过了rank,需进入左子树细搜
		return getValue(node->ls, rank, accumulRank);
	}
}


int main() {
	int q;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		int op, x, rank;
		cin >> op >> x;
		switch (op) {
		case 1:
			rank = 0;
			getRank(root, x, rank);
			cout << rank << "\n";
			break;
		case 2:
			cout << getValue(root, x, 0)<<"\n";
			break;
		case 3:
			cout << findPredecessor(root, x, -2147483647) << "\n";
			break;
		case 4:
			cout << findSuccessor(root, x, 2147483647)<<"\n";
			break;
		case 5:
			add(root, x);
			break;
		}
	}
	freeTree(root);
	return 0;
}