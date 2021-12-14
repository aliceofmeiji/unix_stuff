#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {

	int width = atoi(argv[1]);
        int height = atoi(argv[2]);

        int tela[width][height];

      /*for(int i = 0; i < width; i++){
	  	for(int j = 0; j < height; j++){
	 		tela[i][j] = ((i % 2) * (j % 2));
		}
	}*/

	for(int i = 0; i < width; i++){
		for(int j = 0; j < height; j++){
			tela[i][j] = 0;
		}
	}
	tela[2][2] = 1;
	tela[5][3] = 1;
	
	void drawScreen(int tela[width][height], int width, int height){
		for(int i = 0; i < width; i++){
			for(int j = 0; j < height; j++){
				if(tela[i][j] == 0){
					printf(" ");
				}
				else{
					printf("\u2588");
				}
			}
			printf("\n");
		}
	}
for(;;){
	drawScreen(tela, width, height);

	tela[7][7] = 1;
	tela[1][1] = 1;

	drawScreen(tela, width, height);

	tela[2][2] = 1;
	tela[5][3] = 1;
	
}
}

