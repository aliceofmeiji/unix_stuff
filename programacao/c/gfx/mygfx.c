#include "mygfx.h"
#include "gfx.h"

void gfx_box(int x1, int y1, int x2, int y2)
{
	gfx_line(x1, y1, x2, y1);
	gfx_line(x1, y1, x1, y2);
	gfx_line(x2, y1, x2, y2);
	gfx_line(x1, y2, x2, y2);
}

void gfx_char_print(int x, int y, char c, int s)
{
	switch (c)
	{
		case '1':
			gfx_line((x + (150/s)), (y), (x + (150/s)), (y + (150/s)));
			break;
		case '2':
			gfx_line((x), (y), (x + (150/s)), (y));
			gfx_line((x + (150/s)), (y), (x + (150/s)), (y + (75/s)));
			gfx_line((x + (150/s)), (y + (75/s)), (x), (y + (75/s)));
			gfx_line((x), (y + (75/s)), (x), (y + (150/s)));
			gfx_line((x), (y + (150/s)), (x + (150/s)), (y + (150/s)));
			break;
		case '3':	
			gfx_line((x), (y), (x + (150/s)), (y));
			gfx_line((x), (y + (75/s)), (x + (150/s)), (y + (75/s)));
			gfx_line((x), (y + (150/s)), (x + (150/s)), (y + (150/s)));
			gfx_line((x + (150/s)), (y), (x + (150/s)), (y + (150/s)));
			break;
		case '4':	
			gfx_line((x), (y), (x), (y + (75/s)));
			gfx_line((x), (y + (75/s)), (x + (150/s)), (y + (75/s)));
			gfx_line((x + (150/s)), (y), (x + (150/s)), (y + (150/s)));
			break;
		case '5':	
			gfx_line((x), (y), (x + (150/s)), (y));
			gfx_line((x), (y), (x), (y + (75/s)));
			gfx_line((x + (150/s)), (y + (75/s)), (x), (y + (75/s)));
			gfx_line((x + (150/s)), (y + (75/s)), (x + (150/s)), (y + (150/s)));
			gfx_line((x), (y + (150/s)), (x + (150/s)), (y + (150/s)));
			break;
		case '6':	
			gfx_line((x), (y), (x + (150/s)), (y));
			gfx_line((x), (y + (75/s)), (x + (150/s)), (y + (75/s)));
			gfx_line((x), (y + (150/s)), (x + (150/s)), (y + (150/s)));
			gfx_line((x), (y), (x), (y + (150/s)));
			gfx_line((x + (150/s)), (y + (75/s)), (x + (150/s)), (y + (150/s)));
			break;
		case '7':	
			gfx_line((x), (y), (x + (150/s)), (y));
			gfx_line((x + (150/s)), (y), (x + (150/s)), (y + (150/s)));
			break;
		case '8':
			gfx_line((x), (y), (x + (150/s)), (y));
			gfx_line((x), (y), (x), (y + (150/s)));
			gfx_line((x + (150/s)), (y), (x + (150/s)), (y + (150/s)));
			gfx_line((x), (y + (150/s)), (x + (150/s)), (y + (150/s)));
			gfx_line((x), (y + (75/s)), (x + (150/s)), (y + (75/s)));
			break;
		case '9':
			gfx_line((x), (y), (x + (150/s)), (y));
			gfx_line((x), (y + (75/s)), (x + (150/s)), (y + (75/s)));
			gfx_line((x), (y + (150/s)), (x + (150/s)), (y + (150/s)));
			gfx_line((x + (150/s)), (y), (x + (150/s)), (y + (150/s)));
			gfx_line((x), (y), (x), (y + (75/s)));
			break;
		case '0':
			gfx_line((x), (y), (x + (150/s)), (y));
			gfx_line((x), (y), (x), (y + (150/s)));
			gfx_line((x + (150/s)), (y), (x + (150/s)), (y + (150/s)));
			gfx_line((x), (y + (150/s)), (x + (150/s)), (y + (150/s)));
			gfx_line((x), (y), (x + (150/s)), (y + (150/s)));
			break;
		case 'a':
			gfx_line((x), (y + (150/s)), (x + (75/s)), (y));
			gfx_line((x + (75/s)), (y), (x + (150/s)), (y + (150/s)));
			gfx_line((x + (35/s)), (y + (90/s)), (x + (115/s)), (y + (90/s)));
			break;
		case 'b':
			gfx_line((x),(y),(x),(y + (150/s)));	
			gfx_line((x),(y),(x + (150/s)),(y + (40/s)));
			gfx_line((x + (150/s)),(y + (40/s)),(x),(y + (75/s)));
			gfx_line((x),(y + (75/s)),(x + (150/s)),(y + (105/s)));
			gfx_line((x + (150/s)),(y + (105/s)),(x),(y + (150/s)));
			break;
		case 'c':
			gfx_line((x),(y),(x + (150/s)),(y));
			gfx_line((x),(y),(x),(y + (150/s)));
			gfx_line((x),(y + (150/s)),(x + (150/s)),(y + (150/s)));
			break;
		case 'd':
			gfx_line((x),(y),(x),(y + (150/s)));
			gfx_line((x),(y),(x + (150/s)),(y + (75/s)));
			gfx_line((x + (150/s)),(y + (75/s)),(x),(y + (150/s)));
			break;
		case 'e':
			gfx_line((x),(y),(x + (150/s)),(y));
			gfx_line((x),(y + (75/s)),(x + (150/s)),(y + (75/s)));
			gfx_line((x),(y + (150/s)),(x + (150/s)),(y + (150/s)));
			gfx_line((x),(y),(x),(y + (150/s)));
			break;
		case 'f':
			gfx_line((x),(y),(x + (150/s)),(y));
			gfx_line((x),(y + (75/s)),(x + (150/s)),(y + (75/s)));
			gfx_line((x),(y),(x),(y + (150/s)));
			break;
		case 'g':
			gfx_line((x),(y),(x + (150/s)),(y));
			gfx_line((x),(y),(x),(y + (150/s)));
			gfx_line((x),(y + (150/s)),(x + (150/s)),(y + (150/s)));
			gfx_line((x + (150/s)),(y + (150/s)),(x + (150/s)),(y + (75/s)));
			gfx_line((x + (150/s)),(y + (75/s)),(x + (75/s)),(y + (75/s)));
			break;
		case 'h':
			gfx_line((x),(y),(x),(y + (150/s)));
			gfx_line((x + (150/s)),(y),(x + (150/s)),(y + (150/s)));
			gfx_line((x),(y + (75/s)),(x + (150/s)),(y + (75/s)));
			break;
		case 'i':
			gfx_line((x),(y),(x + (150/s)),(y));
			gfx_line((x),(y + (150/s)),(x + (150/s)),(y + (150/s)));
			gfx_line((x + (75/s)),(y),(x + (75/s)),(y + (150/s)));
			break;
		case 'j':
			gfx_line((x),(y + (150/s)),(x + (150/s)),(y + (150/s)));
			gfx_line((x + (150/s)),(y),(x + (150/s)),(y + (150/s)));
			break;
		case 'k':
			gfx_line((x),(y),(x),(y + (150/s)));
			gfx_line((x),(y + (75/s)),(x + (150/s)),(y));
			gfx_line((x),(y + (75/s)),(x + (150/s)),(y + (150/s)));
			break;
		case 'l':
			gfx_line((x),(y),(x),(y + (150/s)));
			gfx_line((x),(y + (150/s)),(x + (150/s)),(y + (150/s)));
			break;
		case 'm':
			gfx_line((x),(y),(x + (150/s)),(y));
			gfx_line((x),(y),(x),(y + (150/s)));
			gfx_line((x + (75/s)),(y),(x + (75/s)),(y + (150/s)));
			gfx_line((x + (150/s)),(y),(x + (150/s)),(y + (150/s)));
			break;
		case 'n':
			gfx_line((x),(y),(x),(y + (150/s)));
			gfx_line((x),(y),(x + (150/s)),(y + (150/s)));
			gfx_line((x + (150/s)),(y),(x + (150/s)),(y + (150/s)));
			break;
		case 'o':
			gfx_box((x),(y),(x + (150/s)),(y + (150/s)));
			break;
		case 'p':
			gfx_line((x),(y),(x + (150/s)),(y));
			gfx_line((x),(y),(x),(y + (150/s)));
			gfx_line((x),(y + (75/s)),(x + (150/s)),(y + (75/s)));
			gfx_line((x + (150/s)),(y),(x + (150/s)),(y + (75/s)));
			break;
		case 'q':
			gfx_line((x + (75/s)),(y + (75/s)),(x + (150/s)),(y + (150/s)));
			gfx_box((x),(y),(x + (150/s)),(y + (150/s)));
			break;
		case 'r':
			gfx_line((x),(y),(x + (150/s)),(y));
			gfx_line((x),(y),(x),(y + (150/s)));
			gfx_line((x),(y + (75/s)),(x + (150/s)),(y + (75/s)));
			gfx_line((x + (150/s)),(y),(x + (150/s)),(y + (75/s)));
			gfx_line((x + (75/s)),(y + (75/s)),(x + (150/s)),(y + (150/s)));
			break;
		case 's':
			gfx_line((x), (y), (x + (150/s)), (y));
			gfx_line((x + (150/s)), (y + (75/s)), (x + (150/s)), (y + (150/s)));
			gfx_line((x + (150/s)), (y + (75/s)), (x), (y + (75/s)));
			gfx_line((x), (y), (x), (y + (75/s)));
			gfx_line((x), (y + (150/s)), (x + (150/s)), (y + (150/s)));
			break;
		case 't':
			gfx_line((x),(y),(x + (150/s)),(y));
			gfx_line((x + (75/s)),(y),(x + (75/s)),(y + (150/s)));
			break;
		case 'u':
			gfx_line((x + (150/s)),(y),(x + (150/s)),(y + (150/s)));
			gfx_line((x),(y),(x),(y + (150/s)));
			gfx_line((x),(y + (150/s)),(x + (150/s)),(y + (150/s)));
			break;
		case 'v':
			gfx_line((x),(y),(x + (75/s)),(y + (150/s)));
			gfx_line((x + (75/s)),(y + (150/s)),(x + (150/s)),(y));
			break;
		case 'w':
			gfx_line((x),(y + (150/s)),(x + (150/s)),(y + (150/s)));
			gfx_line((x),(y),(x),(y + (150/s)));
			gfx_line((x + (75/s)),(y),(x + (75/s)),(y + (150/s)));
			gfx_line((x + (150/s)),(y),(x + (150/s)),(y + (150/s)));
			break;
		case 'x':
			gfx_line((x),(y),(x + (150/s)),(y + (150/s)));
			gfx_line((x + (150/s)),(y),(x),(y + (150/s)));
			break;
		case 'y':
			gfx_line((x),(y),(x + (75/s)),(y + (75/s)));
			gfx_line((x + (150/s)),(y),(x),(y + (150/s)));
			break;
		case 'z':
			gfx_line((x),(y),(x + (150/s)),(y));
			gfx_line((x + (150/s)),(y),(x),(y + (150/s)));
			gfx_line((x),(y + (150/s)),(x + (150/s)),(y + (150/s)));
			break;
		case 'A':
			break;
		case 'B':
			break;
		case 'C':
			break;
		case 'D':
			break;
		case 'E':
			break;
		case 'F':
			break;
		case 'G':
			break;
		case 'H':
			break;
		case 'I':
			break;
		case 'J':
			break;
		case 'K':
			break;
		case 'L':
			break;
		case 'M':
			break;
		case 'N':
			break;
		case 'O':
			break;
		case 'P':
			break;
		case 'Q':
			break;
		case 'R':
			break;
		case 'S':
			break;
		case 'T':
			break;
		case 'U':
			break;
		case 'V':
			break;
		case 'W':
			break;
		case 'X':
			break;
		case 'Y':
			break;
		case 'Z':
			break;
	}
}		
