void draw_line(uint16_t *image, uint32_t width, uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2)
{
	//fwrite(&x1, 2, 1, stdout);	
}

void print_image(uint16_t *image, uint32_t width, uint32_t height)
{
	uint32_t i, wnl, hnl;
	wnl = htonl(width);
	hnl = htonl(height);
	printf("farbfeld");
	fwrite(&wnl, 4, 1, stdout);
	fwrite(&hnl, 4, 1, stdout);
	for(i = 0; i < width * height * 4; i++)
	{
		*(image + i) = 0xFFFF;
		fwrite(image + i, 4, 1, stdout);
	}
}
