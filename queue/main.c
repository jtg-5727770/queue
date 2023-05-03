#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct { // 큐 타입
	element data[MAX_QUEUE_SIZE];
	int front, rear;
} QueueType;
// 오류 함수
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1); //[juht] 
}
// 공백 상태 검출 함수
void init_queue(QueueType* q)
{
	q->front = q->rear = 0;
}
// 공백 상태 검출 함수
int is_empty(QueueType* q)
{
	return (q->front == q->rear);
}
// 포화 상태 검출 함수
int is_full(QueueType* q)
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}
// 원형큐 출력 함수
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
// 삽입 함수
int enqueue(QueueType* q, element item)
{
	if (is_full(q))
		error("큐가 포화상태입니다");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}
// 삭제 함수
element dequeue(QueueType* q)
{
	if (is_empty(q))
		error("큐가 공백상태입니다");
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
		printf("=========메뉴=========\n");
		printf("1.숫자를 입력 받아서 원형 큐에 삽입\n");
		printf("2.원형 큐에서 하나를 꺼내서 출력\n");
		printf("3.원형 큐를 화면에 출력\n");
		printf("4.종료\n");
		printf("번호를 선택하세요: ");
		scanf_s("%d", &n);

		switch (n)
		{
		case 1:
			if (is_full(&queue)) {
				printf("큐는 포화상태입니다.\n\n");
			}
			else {
				printf("정수를 입력하시오: ");
				scanf_s("%d", &element);
				enqueue(&queue, element);
				printf("\n");
			}
			break;
		case 2:
			if (is_empty(&queue)) {
				printf("큐는 공백상태입니다.\n\n");
			}
			else {
				element = dequeue(&queue);
				printf("꺼내진 정수: %d \n\n", element);
			}
			break;
		case 3:
			queue_print(&queue);
			printf("\n");
			break;
		case 4:
			return 0;
		default:
			printf("잘못된 입력입니다.\n\n");
			break;
		}
	}
	return 0;
}
