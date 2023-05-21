#include<iostream>
using namespace std;

//用先序遍历中序遍历复原二叉树

struct TreeNode {
	TreeNode* pLeft;
	TreeNode* pRight;
	char val;
};

string vlr, lvr;

void rebuild(TreeNode* pRoot, int vlr_st, int vlr_end, int lvr_st, int lvr_end) {
	char rootval = pRoot->val = vlr[vlr_st];
	int ltree_size = 0;
	while (lvr[lvr_st + ltree_size] != rootval) {
		++ltree_size;
	}
	int vlr_st_ltree = vlr_st + 1;
	int vlr_end_ltree = vlr_st_ltree + ltree_size;
	int vlr_st_rtree = vlr_end_ltree;
	int vlr_end_rtree = vlr_end;
	int lvr_st_ltree = lvr_st;
	int lvr_end_ltree = lvr_st_ltree + ltree_size;
	int lvr_st_rtree = lvr_end_ltree + 1;
	int lvr_end_rtree = lvr_end;
	if (ltree_size != 0) {
		pRoot->pLeft = new TreeNode;
		rebuild(pRoot->pLeft, vlr_st_ltree, vlr_end_ltree, lvr_st_ltree, lvr_end_ltree);
	} else {
		pRoot->pLeft = nullptr;
	}
	if (lvr_st_rtree != lvr_end_rtree) {
		pRoot->pRight = new TreeNode;
		rebuild(pRoot->pRight, vlr_st_rtree, vlr_end_rtree, lvr_st_rtree, lvr_end_rtree);
	} else {
		pRoot->pRight = nullptr;
	}
}

void LRV(TreeNode* pRoot) {
	if (pRoot == nullptr) {
		return;
	}
	LRV(pRoot->pLeft);
	LRV(pRoot->pRight);
	cout << (char)pRoot->val;
}


int main()
{
	while (cin.eof()==false) {
		cin >> vlr >> lvr;
		if (cin.eof()) {
			break;
		}
		TreeNode* pRoot = new TreeNode;
		rebuild(pRoot, 0, vlr.size(), 0, lvr.size());
		LRV(pRoot);
		putchar('\n');
	}
}
