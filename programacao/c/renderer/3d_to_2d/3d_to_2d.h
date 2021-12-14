typedef struct
{
	int x, y, z;
} Point3;

typedef struct
{
	Point3 start, end;
	char * color;
} Line3;

typedef struct
{
	int x, y;
} Point2;

typedef struct
{
	Point2 start, end;
	char * color;
} Line2;

Line2 to_2d_line(Line3 in_line, Point3 scr_start, Point3 scr_end, Point3 focus);
