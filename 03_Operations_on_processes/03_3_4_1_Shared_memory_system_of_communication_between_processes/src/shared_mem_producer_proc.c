#define BUFFER_SIZE 10

typedef struct
{
	//...
} element;

element buffer[BUFFER_SIZE];

int in = 0;
int out = 0;

item next_produced;

while (true)
{
	// produce an element in next_produced
	while (((in + 1) % BUFFER_SIZE) == out); // don't do anything
	buffer[in] = next_produced;
	in = (in + 1) % BUFFER_SIZE;
}
