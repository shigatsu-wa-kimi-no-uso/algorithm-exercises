##include<iostream>
using namespace std;

unsigned long long n;

//P2181 
//����� & �������˷����� 

int main()
{
	cin >> n;
	if (n == 3)
		cout << 0;
	else
	{
		unsigned long long ans = n * (n - 1) / 2 * (n - 2) / 3 * (n - 3) / 4;	//�������˷���������n n-1�б���2�ı�������n * (n - 1) / 2 ������
																				//����n n-1 n-2�б���3�ı�������n * (n - 1) / 2*(n-2)/3������
																				//n * (n - 1) / 2  ֻ���n*(n-1)�к���2�����ӳ��������n n-1����3�ı����������ƻ�
																				//ͬ��
		cout << ans;
	}
		
	return 0;
}

