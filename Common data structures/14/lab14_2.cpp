#include <cassert>
#include "integer_queue.hpp"

int main() {

	// создаем очередь для хранения 5 элементов
	IntegerDroppingQueue * pQ = IntegerDroppingQueueCreate(5);

	// заполняем очередь данными до предела
	IntegerDroppingQueuePush(*pQ, 1);
	IntegerDroppingQueuePush(*pQ, 2);
	IntegerDroppingQueuePush(*pQ, 3);
	IntegerDroppingQueuePush(*pQ, 4);
	IntegerDroppingQueuePush(*pQ, 5);

	// убеждаемся в полноте очереди и начальном элементе
	assert(IntegerDroppingQueueIsFull(*pQ));
	assert(IntegerDroppingQueueFront(*pQ) == 1);

	// добавляем новое данное “сверх нормы”
	IntegerDroppingQueuePush(*pQ, 6);

	// Первое число должно было быть отброшено, но очередь при этом полна
	assert(IntegerDroppingQueueIsFull(*pQ));
	assert(IntegerDroppingQueueFront(*pQ) == 2);

	// Уничтожаем очередь
	IntegerDroppingQueueDestroy(pQ);
	return 0;
}