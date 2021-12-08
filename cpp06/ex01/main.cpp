#include <iostream>
#include <stdint.h>

struct Data
{
	int value;
};

uintptr_t serialize(Data * data)
{
	uintptr_t result;

	result = reinterpret_cast<uintptr_t>(data);
	return result;
}

Data	*	deserialize(uintptr_t raw)
{
	Data * result;

	result = reinterpret_cast<Data *>(raw);
	return result;
}

int		main(void)
{
	uintptr_t raw;

	Data * data = new Data;
	Data * receiver = NULL;

	data->value = 98;
	std::cout << "data->value = " << data->value << std::endl;

	raw = serialize(data);
	receiver = deserialize(raw);

	std::cout << "receiver.value = " << receiver->value << std::endl;
	
	delete data;
	return 0;
}