#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;


string name[1000005];

int s[1000005];

int f[1000005];

int postolen[1000005];		//��¼ÿ�����ܹ����LIS���ڳ��ȵ���Ϣ

vector<int> lentopos[1000005];		//��¼��ӦLIS����������Щ�����


//���ű�2021���� ��԰����
//nlogn��LIS�����LIS����

bool cmp(const int& lft, const int& rgt)
{
	return name[lft] < name[rgt];
}

int lis[1000005];

bool notok[1000005];

int maxlen;

bool dfs(int len, int pos)	//dfs�ݹ���LIS·��
{
	if (len == maxlen + 1)
	{
		return true;
	}
	for (int i = 0; i < lentopos[len].size(); i++)
	{
		if (notok[lentopos[len][i]]==0 && lentopos[len][i] > pos)	//����ڽ�����
		{
			lis[len] = lentopos[len][i];
			if (dfs(len + 1, lentopos[len][i]))
			{
				return true;
			}
			
		}
	}
	notok[pos] = true;
	return false;
}



int main()
{
	char ch;
	int n = 0;
	while ((ch = getchar()) != '\n' && ch != EOF && ch != '\0')
	{
		if ('A' <= ch && ch <= 'Z')
		{
			n++;
		}
		name[n].push_back(ch);
	}
	int len = 0;
	for (int i = 1; i <= n; i++)
	{
		if (name[i] > name[f[len]])
		{
			f[++len] = i;
			postolen[i] = len;
			lentopos[len].push_back(i);
		}
		else
		{
			int* t = lower_bound(f + 1, f + len + 1, i, cmp);
			*t = i;
			postolen[i] = t - f;
			lentopos[postolen[i]].push_back(i);
		}
	}

	maxlen = len;

	for (int i = 1; i <= len; i++)
	{
		sort(lentopos[i].begin(), lentopos[i].end(), cmp);
	}
	dfs(1, 0);

	for (int i = 1; i <= len; i++)
	{
		cout << name[lis[i]];
	}
	return 0;

}
