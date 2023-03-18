#include<iostream>
#include<algorithm>
#include<cstring>
#define reg register int

using namespace std;

//P1120
//ľ��ƴ�� dfs����������� 

int n, s;
int stick[70];
int used[70];
bool ok;
int first;		//��һ��ľ��

void dfs(int pre, int len)	//��һ������ţ�����ʣ��
{
	//cout <<"first:"<< first <<" pre:"<< pre << " len:" << len << "\n";
	for (int i = pre + 1; i < n; i++)	//��֤stickľ�����ȵ������ڱ��Ϊ[1,pre-1]����
	{
		//cout << pre << " link " << i << '\n';
		if (used[i] || i == first)
			continue;
		if (len - stick[i] > 0)
		{
			used[i] = 1;
			dfs(i, len - stick[i]);
			if (!ok)					//���� ����ɹ������Ϊ��ʹ�õĲ���0
			{
			//	cout << "set " << i << " 0\n";
				used[i] = 0;
			}
			else
			{
			//	cout << "break for ok\n";
				break;
			}

		}
		else if (len - stick[i] == 0)
		{
			ok = 1;
			used[i] = 1;
		//	cout << "retok\n";
			return;
		}
	}
//cout << "ret\n";
}


int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	for (reg i = 1; i <= n; i++)
	{
		cin >> stick[i];
		s += stick[i];
	}
	sort(stick, stick + n + 1, greater<int>());		//�ݼ�,��[0,n+1)������,��ʱ0���,nΪ0,n-1Ϊ��Сľ��
	/*
	for (reg i = 0; i < n; i++)
	{
		cout << stick[i]<<" ";
	}
	
	cout << '\n';
	cout << '\n';
	cout << s << '\n';
	*/
	/*
	if (s % stick[0] == 0)
	{
		cout << stick[0];
		return 0;
	}*/

	for (reg i = stick[0] ; i <= s; i++)
	{
		if (s % i == 0)
		{
			reg j;
			for (j = 0; j < n; j++)
			{	
				/*for (reg k = 0; k < n; k++)
				{
					cout << stick[k] << " ";
				}
				
				cout << '\n';
				cout << '\n';

				cout << "test j " << j << " i " << i << '\n';*/
				if (!used[j])
				{
					used[j] = 1;
					first = j;
				}
				else
					continue;

				dfs(j, i - stick[j]);

				if (!ok)
				{
					break;
				}
				else
				{
				/*	for (reg k = 0; k < n; k++)
					{
						cout << used[k] << "  ";
					//	if (!used[j])
					//		break;
					}
					*/
					ok = 0;
				}
				//cout << '\n';
				//cout << '\n';
			}

		//	cout << i << '\n';
			
			for (j = 0; j < n; j++)
			{
			//	cout << used[j] << " ";
				if (!used[j])
					break;
			}
			//cout << '\n';
			if (j == n)
			{
				cout << i;
				break;
			}
			memset(used, 0, sizeof(used));
		}
	}

	return 0;
}
