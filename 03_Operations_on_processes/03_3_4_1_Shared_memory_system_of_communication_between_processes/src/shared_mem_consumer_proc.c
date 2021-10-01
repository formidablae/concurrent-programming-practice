#define BUFFER_SIZE 10

typedef struct
{
	//...
} element;

element buffer[BUFFER_SIZE];

int in = 0;
int out = 0;

item next_consumed;

while (true)
{
	// consume an element in next_consumed
	while (in == out); // don't do anything
	next_consumed = buffer[out];
	out = (out + 1) % BUFFER_SIZE;
}
