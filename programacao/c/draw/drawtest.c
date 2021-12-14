#include <stdlib.h>
#include <stdio.h>
#include <xcb/xcb.h>
#include <unistd.h>

int main()
{
	xcb_connection_t	*c;
	xcb_screen_t		*screen;
	xcb_drawable_t		win;
	xcb_gcontext_t		black;
	uint32_t		mask;
	uint32_t		value[1];
	//int screen_nbr;
	//xcb_screen_iterator_t iter;
	
	c = xcb_connect(NULL, NULL);

	screen = xcb_setup_roots_iterator(xcb_get_setup(c)).data;

	//win = xcb_generate_id(c);
	win = screen->root;
	black = xcb_generate_id(c);
	mask = XCB_GC_FOREGROUND;
	value[0] = screen->black_pixel;
	xcb_create_gc(c, black, win, mask, value);
	
	xcb_create_window(c, XCB_COPY_FROM_PARENT, win, screen->root, 0, 0, 150, 150, 10, XCB_WINDOW_CLASS_INPUT_OUTPUT, screen->root_visual, 0, NULL);

	xcb_map_window(c, win);

	xcb_flush(c);

	pause();

	/*
	printf("\n");
	printf("Informations of screen %ld:\n", screen->root);
	printf("	width.......: %d\n", screen->width_in_pixels);
	printf("	height......: %d\n", screen->height_in_pixels);
	printf("	white pixel.: %d\n", screen->white_pixel);
	printf("	black pixel.: %d\n", screen->black_pixel);
	printf("\n");
	*/

	xcb_disconnect(c);

	return 0;
}
