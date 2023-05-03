#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct { // ť Ÿ��
	element data[MAX_QUEUE_SIZE];
	int front, rear;
} QueueType;
// ���� �Լ�
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1); //[juht] 
}
// ���� ���� ���� �Լ�
void init_queue(QueueType* q)
{
	q->front = q->rear = 0;
}
// ���� ���� ���� �Լ�
int is_empty(QueueType* q)
{
	return (q->front == q->rear);
}
// ��ȭ ���� ���� �Լ�
int is_full(QueueType* q)
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}
// ����ť ��� �Լ�
void queue_print(QueueType* q)
{
	printf("QUEUE(front=%d rear=%d) = ", q->front, q->rear);
	if (!is_empty(q)) {
		int i = q->front;
		do {
			i = (i + 1) % (MAX_QUEUE_SIZE);
			printf("%d | ", q->data[i]);
			if (i == q->rear)
				break;
		} while (i != q->front);
	}
	printf("\n");
}
// ���� �Լ�
int enqueue(QueueType* q, element item)
{
	if (is_full(q))
		error("ť�� ��ȭ�����Դϴ�");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}
// ���� �Լ�
element dequeue(QueueType* q)
{
	if (is_empty(q))
		error("ť�� ��������Դϴ�");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

int main(void)
{
	QueueType queue;
	int element;
	init_queue(&queue);
	while (1) {
		int n;
		printf("=========�޴�=========\n");
		printf("1.���ڸ� �Է� �޾Ƽ� ���� ť�� ����\n");
		printf("2.���� ť���� �ϳ��� ������ ���\n");
		printf("3.���� ť�� ȭ�鿡 ���\n");
		printf("4.����\n");
		printf("��ȣ�� �����ϼ���: ");
		scanf_s("%d", &n);

		switch (n)
		{
		case 1:
			if (is_full(&queue)) {
				printf("ť�� ��ȭ�����Դϴ�.\n\n");
			}
			else {
				printf("������ �Է��Ͻÿ�: ");
				scanf_s("%d", &element);
				enqueue(&queue, element);
				printf("\n");
			}
			break;
		case 2:
			if (is_empty(&queue)) {
				printf("ť�� ��������Դϴ�.\n\n");
			}
			else {
				element = dequeue(&queue);
				printf("������ ����: %d \n\n", element);
			}
			break;
		case 3:
			queue_print(&queue);
			printf("\n");
			break;
		case 4:
			return 0;
		default:
			printf("�߸��� �Է��Դϴ�.\n\n");
			break;
		}
	}
	return 0;
}
