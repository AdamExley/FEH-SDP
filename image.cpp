#include "image.h"

Img::Img(){

    //RGB values of the 22 Proteus LCDColors.h colors
    static const uint_fast32_t temp[3][22] =
    {   {0,255,255,  0,  0,187,102,  0,  0,191,  0,146, 34, 64,128,128,186,135,143,144,165,255},
        {0,255,  0,255,  0,  0,102,  0,128,255,255,211,139,224,  0,  0,184,206, 21,238, 42,255},
        {0,255,  0,  0,255,  0,102,128,128,  0,255,202, 34,208,  0,128,108,235,  0,144, 42,  0}
    };

    //Copy the const array into the class's color lookup_table array
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 22; j++){
            lookup_table[i][j] = temp[i][j];
        }
    }

}




Img::Img(const int enabled_colors[], const int num_enabled){

    //RGB values of the 22 Proteus LCDColors.h colors
    static const uint_fast32_t temp[3][22] =
    {   {0,255,255,  0,  0,187,102,  0,  0,191,  0,146, 34, 64,128,128,186,135,143,144,165,255},
        {0,255,  0,255,  0,  0,102,  0,128,255,255,211,139,224,  0,  0,184,206, 21,238, 42,255},
        {0,255,  0,  0,255,  0,102,128,128,  0,255,202, 34,208,  0,128,108,235,  0,144, 42,  0}
    };

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 22; j++){

            lookup_table[i][j] = DISABLE_VALUE;
            
            for(int k = 0; k < num_enabled; k++){
                if (j == enabled_colors[k]){
                    lookup_table[i][j] = temp[i][j];
                }
                
            }

        }
    }

}


int Img::lookupColor(const uint_fast32_t image_array[], int x) {
    
    //Copy the hex value of the color into the convert char array
	sprintf(convert, "%x", image_array[x]);

	//Colors are in the form "ffBBGGRR"
    //Extract the red, green and blue values of the color
	blue_string[0] = convert[2];
	blue_string[1] = convert[3];
	blue_string[2] = NULL;
	green_string[0] = convert[4];
	green_string[1] = convert[5];
	green_string[2] = NULL;
	red_string[0] = convert[6];
	red_string[1] = convert[7];
	red_string[2] = NULL;

    //Convert the hex string values for each channel into numbers 0-255
    //Consulted https://stackoverflow.com/questions/10156409/convert-hex-string-char-to-int/25681839
	red = (int)strtol(red_string, NULL, 16);
	green = (int)strtol(green_string, NULL, 16);
    blue = (int)strtol(blue_string, NULL, 16);

    int color;
    double min_difference, temp;
	min_difference = temp = 1000;

	for (int i = 0; i < 22; i++) {

        //If this color is disabled, skip trying to find it
        if (lookup_table[0][i] == DISABLE_VALUE){
            continue;
        }

        temp = abs(red - lookup_table[0][i]) + abs(green - lookup_table[1][i]) + abs(blue - lookup_table[2][i]);
		//temp = pow((pow((red - lookup_table[0][i]), 2) + pow((green - lookup_table[1][i]), 2) + pow((blue - lookup_table[2][i]), 2)), 0.5);
		if (temp < min_difference) {
			min_difference = temp;
			color = i;
		}
	}

	return color;

}



void Img::PlotImg(const uint_fast32_t image_array[], int width, int height, int scale, int background){
    int min,r,c;
    for(unsigned int color = 0; color < 22; color++){

        //If this color is disabled, skip trying to draw it
        if (color == background || lookup_table[0][color] == DISABLE_VALUE){
            continue;
        }

        LCD.SetDrawColor(color);
        for (r = 0; r < height; r++){
            c = 0;
            while(c < width){
                min = width;
                while (image_array[r*width + c] != color && c < width){
                    c++;
                }

                min = c;

                while (image_array[r*width + c] == color && c < width){
                    c++;
                }

                if(min != width){
                    LCD.FillRectangle(min*scale, r*scale,(c-min) * scale, scale);
                }
            }
        }
    }
}



void Img::Draw(const uint_fast32_t image_array[], int width, int height, int scale, int background, bool optimize){

    uint_fast32_t *color_array = new uint_fast32_t[width*height];

    for (int i = 0; i < width * height; i++){
        color_array[i] = lookupColor(image_array,i);
    }
    
    if (optimize){
        HorizLineOptimize(color_array, width, height);
    }
    
    PlotImg(color_array, width, height, scale, background);
}



void Img::HorizLineOptimize(uint_fast32_t image_color_array[], int width, int height){

    bool cont;

    for(unsigned int color = 0; color < 22; color++){

        //If this color is disabled, skip trying to optimize it
        if (lookup_table[0][color] == DISABLE_VALUE){
            continue;
        }

        for(int row = 0; row < height; row++){
            for(int column = 0; column < width - (PER_SIDE*2 + OPTIMIZE_WIDTH); column++){
                cont = true;
                for(int j = 0; (j <= PER_SIDE) && cont; j++){
                    if(image_color_array[column + j + row * width] != color){
                        cont = false;
                    }
                }
                for(int j = 0; (j <= PER_SIDE) && cont; j++){
                    if(image_color_array[column + j + PER_SIDE + OPTIMIZE_WIDTH + row * width] != color){
                        cont = false;
                    }
                }
                
                if(cont){
                    for(int k = 1; k <= OPTIMIZE_WIDTH; k++){
                        image_color_array[column + row * width + PER_SIDE + k] = color;
                    }  
                }
            }
        }
    }
}


