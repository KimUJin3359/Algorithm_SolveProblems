/* ������� ��
1. push button�� ���� ���� (ó���� num <= 5000000���� �����ؼ� num�� 5000000�� �� num���� ũ�鼭 ������� ���� ��츦 �������� ������)
2. 0�� ó�� (0�� ���� �� ���� ��, 10�� ������� 11���� ������ �Ǵµ� ó�� § ���������� 10�� ���� cnt != 0 ������ �߰������ν� �ذ�)
3. 0�� ���ѹݺ� (num == 0 && cnt > 1�� �߰������ν� �ذ�)
4. button[10] = { true, }�� �����ص״µ� button[0]���� true��, �������� ���� false���� �� �־���
5. ���� ���� ������ ���� ���� �ʱ�ȭ�� ��ġ�� �� �� �����
6. ABS(x) (x > 0) ? x : -x �� �ߴµ� 9999 �� 5457���� ������ ���� ����
4, 6�� ���� ���� �м��ϱ�
*/

#include <stdio.h>
#pragma warning(disable : 4996)
#define SIZE 1000000

int find, res;
bool button[10];

void push_button(int num, int cnt)
{
	if (num == 0 && cnt > 1)
		return;
	if (num > SIZE)
		return;
	if (cnt != 0 && res > cnt + ((find > num) ? find - num : num - find))
		res = cnt + ((find > num) ? find - num : num - find);
	for (int i = 0; i < 10; i++)
	{
		if (button[i])
			push_button((num * 10) + i, cnt + 1);
	}
}

int main()
{
	int rep, input;

	//initialize
	for (int i = 0; i < 10; i++)
		button[i] = true;
	scanf("%d", &find);
	scanf("%d", &rep);
	for (int i = 0; i < rep; i++)
	{
		scanf("%d", &input);
		button[input] = false;
	}

	//for only up, down button
	res = ((find > 100) ? find - 100 : 100 - find);

	//push button
	push_button(0, 0);

	printf("%d", res);
	return (0);
}