#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
#include <math.h>
#include <direct.h>
#include <Windows.h>
#include <string.h>
#include "ica.h"

// æoÍp(oÍæÅ[½, Ìæwè[1024](0Í), Ìæ¼)
int img_out(unsigned char origin[][256], int date1[1024], int name) {
	static int temp_sai[256 * 256];
	char output[1000];
	int a, b, i, l, k;
	//gp = _popen(GNUPLOT_PATH, "w");
	printf(" now output  - - - ->");
	for (a = 0; a < 256; a++)
		for (b = 0; b < 256; b++)
			temp_sai[a * 256 + b] = origin[a][b];

	for (i = 0; i < 1024; i++) {
		k = i % 32;
		l = i / 32;
		if (date1[i] == 0) {
			for (b = 0; b < 8; b++) {
				for (a = 0; a < 8; a++) {
					temp_sai[256 * 8 * l + 8 * k + a + 256 * b] = 0;
				}
			}
		}
	}

	sprintf(output, "OUTPUT\\%d.bmp", name);
	img_write_gray(temp_sai, output, 256, 256); // outputÉoÍæð«o·
	name++;

	printf(" end\n\n");
	return name;
}