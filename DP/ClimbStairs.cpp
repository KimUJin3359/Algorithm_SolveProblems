#include <stdio.h>
#pragma warning(disable : 4996)

int N;
int STAIRS[300];
int DP[300];

int main()
{
	scanf("%d", &N);
	// DP ���� ������ �ش� index�� ����� ����� �� �ִ밪�� ������ ����
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &STAIRS[i]);
		if (i == 0)
			DP[i] = STAIRS[i];
		else if (i == 1)
			DP[i] = STAIRS[i] + STAIRS[i - 1];
		else if (i == 2)
			DP[i] = (STAIRS[i - 1] > STAIRS[i - 2]) ? STAIRS[i] + STAIRS[i - 1] : STAIRS[i] + STAIRS[i - 2];
		else
			DP[i] = (DP[i - 2] > DP[i - 3] + STAIRS[i - 1]) ? DP[i - 2] + STAIRS[i] : DP[i - 3] + STAIRS[i - 1] + STAIRS[i];
	}
	// �� �������� ����� ������ ��ƾ� �Ǳ� ������ ����� DP[N - 1]�� ��
	printf("%d", DP[N - 1]);
}
