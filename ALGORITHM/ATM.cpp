#include <iostream>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int> > PQ;

int main()
{
	int num;
	int input;
	int sum = 0;
	int res = 0;

	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		cin >> input;
		PQ.push(input);
	}
	while (PQ.size())
	{
		// ��� ��
		sum += PQ.top() + res;
		// ���� ��
		res += PQ.top();
		PQ.pop();
	}
	cout << sum;
	return (0);
}