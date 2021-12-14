typedef struct
{
	int x1;
	int y1;
	int x2;
	int y2;
	char * color;
} Line;

Line make_line(int x1, int y1, int x2, int y2, char * color);
void print_line(Line line);
void print_q1(Line line);
void print_q2(Line line);
void print_q3(Line line);
void print_q4(Line line);
