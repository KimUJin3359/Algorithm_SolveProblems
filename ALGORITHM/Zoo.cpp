#include <iostream>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int> > PQ;
int N;

int main()
{
	int num;
	int size = 0;
	int res = 1;
	int flag = 0;
	bool dup = false;

	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		PQ.push(num);
	}
	while(PQ.size())
	{
		// ó�� ���� �ϳ��� �����ϵ� ���� �����ϵ� A, B�׷쿡 �Ѵ� ���Ե� �� �����Ƿ� * 2
		if (size == 0 && PQ.top() == size)
		{
			res *= 2;
			PQ.pop();
		}
		// �� ���� ���� �̹� �տ� ���� ���� �̾��� ����
		else if (PQ.top() == size)
			PQ.pop();
		// ���ӵ� ���ڰ� �ƴ� ��� �׷��� ���� �� ����
		else
			break;

		// �� ���� 0, 0 / 1, 1 / �� ���ٰ� �������� �ϳ��� ���� ��� A, B�׷� �Ѵ� ���Ե� �� �����Ƿ� * 2
		// 0, 0 / 1, 1 / 2, 3, 4 �� ��쵵 ����
		if (dup && size != 0 && PQ.size() == 0)
		{
			res *= 2;
			break;
		}
		// 0 �� �Է¹޾��� ��, 0, 1, 2, 3... �� �ٷθ� ������ �� �׳� ����
		else if (PQ.size() == 0)
			break;

		// 0, 0 / 1, 1 / �޴ٰ� ������ ���� �ƴԿ��� �ϳ��� ���� ������ ��� ���� �Է����� �ٲ���
		// 0, 0 / 1, 1 / 2 / 3 ���� ���
		if (flag == 1 && PQ.top() != size)
			flag = 0;
		// 0, 1, 2, 3 .. ���ٷ� �޴ٰ� �ΰ��� ���� �Է¹��� ��� ����
		// 0 / 1 / 2 / 3, 3 ���� ���
		else if (size != 0 && flag == 0 && PQ.top() == size)
			break;
		// 0, 0 / 1, 1 ���� ���
		// 2 * 2 ���� �� ���� �ߺ��� �߰��� ���� ����� ���� * 2
		else if (size != 0 && PQ.top() == size)
		{
			flag = 1;
			dup = true;
			res *= 2;
			PQ.pop();
		}
		// ù ��° ���ǿ��� * 2�� �̹� ����
		else if (size == 0 && PQ.top() == size)
		{
			flag = 1;
			dup = true;
			PQ.pop();
		}
		size++;
	}
	if (PQ.size())
		cout << 0;
	else
		cout << res;
}