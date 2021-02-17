/*
������� ��
1. brute-force(�ð� �ʰ� : ��� �ð��� �ٿ��� ����)
2. �ð� ���� �ƴ� �ⱸ ��������� ž��
if (time_f % i == 0)
	people -= time_check[i];
if (people <= 0)
{
	int count = 1;

	flag = 0;
	for (int j = 0; j < kind; j++)
	{
		if (i == time[j])
		{
			if ((time_check[i] + people) == count)
				printf("%d", (j + 1));
			count++;
		}
	}
	break;
} -> �ð������� ����ؼ� ����
3. �ذ����� time�� ���� ���ڸ� ó������ ���� ������ ���ϸ鼭 ���ִ°� �ƴ϶�
30�б����� ���ؼ� �񱳴���� ���� => 64%���� ����ϴ� �ð��ʰ�
4. ���� �����غ� ���, count�� ���� kind��ŭ�� �迭�� ���ڸ� �����س����ٰ� people�� ���� ���� ���� ����
*/

#include <stdio.h>
#pragma warning(disable:4996)

int time_check[32] = { 0, };

int main()
{
	int people;
	int kind, time_f;
	int flag = 1;
	int *time;

	scanf("%d %d", &people, &kind);
	time = new int[kind];
	for (int i = 0; i < kind; i++)
	{
		scanf("%d", &time[i]);
		time_check[time[i]]++;
	}
	if (people <= kind)
		printf("%d", people);
	else
	{
		people -= kind;
		time_f = 0;
		while (flag)
		{
			int sum = 0;

			time_f++;
			for (int i = 1; i <= 30; i++)
			{
				if (time_f % i == 0)
					sum += time_check[i];
			}
			people -= sum;
			if (people <= 0)
			{
				int count = 1;

				for (int j = 0; j < kind; j++)
				{
					if (time_f % time[j] == 0)
					{
						if ((sum + people) == count)
						{
							flag = 0;
							printf("%d", (j + 1));
						}
						count++;
					}
					if (!flag)
						break;
				}
				break;
			}
		}
	}
	delete time;
	return (0);
}