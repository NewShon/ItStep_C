const int size = 20;
struct FIFO
{
	int queue[size];
	int head, tail;
};
void push_back(FIFO*st, int data)
{
	if (st->tail + 1 == st->head || st->tail + 1 == size &&st->head == 0)
	{
		cout << " queue is full";
		return;
	}
	st->tail++;
	if (st->tail == size) st->tail = 0;//организация кругового цикла для очереди
	st->queue[st->tail] = data;
}
int pop_front(FIFO *st)
{
	if (st->head == st->tail)
	{
		cout << "queue is empty\n";
		return 0;
	}
	st->head++;
	if (st->head == size) st->head = 0;
	return st->queue[st->head];
}
