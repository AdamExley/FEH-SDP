#include "Image.h"
/** @file Image.cpp
 *  @brief Contains Image class defintions
 * */

Image::Image(int w, int h)
:width(w), height(h), num_no_draw(0)
{

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



Image::Image(int w, int h, const int enabled_colors[], int num_enabled, const int do_not_draw[], int no_draw_num)
:width(w), height(h)
{

    //RGB values of the 22 Proteus LCDColors.h colors
    static const uint_fast32_t temp[3][22] =
    {   {0,255,255,  0,  0,187,102,  0,  0,191,  0,146, 34, 64,128,128,186,135,143,144,165,255},
        {0,255,  0,255,  0,  0,102,  0,128,255,255,211,139,224,  0,  0,184,206, 21,238, 42,255},
        {0,255,  0,  0,255,  0,102,128,128,  0,255,202, 34,208,  0,128,108,235,  0,144, 42,  0}
    };

    //Set number of colors to render but not to draw
    num_no_draw = no_draw_num;
    //Copy to internal array
    for(int i = 0; i < num_no_draw; i++){
        no_draw[i] = do_not_draw[i];
    }

    //Initialize lookup array
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 22; j++){

            //Initially disable
            lookup_table[i][j] = DISABLE_VALUE;
            
            //If color is enabled for render, store actual value in lookup table
            for(int k = 0; k < num_enabled; k++){
                if (j == enabled_colors[k]){
                    lookup_table[i][j] = temp[i][j];
                }
                
            }

        }
    }

}



void Image::Draw(const uint_fast32_t image_array[], int scale, bool optimize, int x_off, int y_off){

    //Make a Proteus color array the same size as the hex color array
    uint_fast32_t *color_array = new uint_fast32_t[width*height];

    //Lookup every color in the hex color array, storing in Proteus color array
    for (int i = 0; i < width * height; i++){
        color_array[i] = lookupColor(image_array,i);
    }
    
    //Optimize if enabled
    if (optimize){
        HorizLineOptimize(color_array);
    }
    
    //Plot image
    PlotImg(color_array, scale, x_off, y_off);
}



int Image::lookupColor(const uint_fast32_t image_array[], int x) {
    
    //Copy the hex value of the color into the convert char array
	sprintf(convert, "%x", image_array[x]);

	//Colors are in the form "ffBBGGRR"
    //Extract the red, green and blue values of the color
	blue_string[0] = convert[2];
	blue_string[1] = convert[3];
	blue_string[2] = (char) NULL;
	green_string[0] = convert[4];
	green_string[1] = convert[5];
	green_string[2] = (char) NULL;
	red_string[0] = convert[6];
	red_string[1] = convert[7];
	red_string[2] = (char) NULL;

    //Convert the hex string values for each channel into numbers 0-255
    //Consulted https://stackoverflow.com/questions/10156409/convert-hex-string-char-to-int/25681839
	red = (int)strtol(red_string, NULL, 16);
	green = (int)strtol(green_string, NULL, 16);
    blue = (int)strtol(blue_string, NULL, 16);

    //Find the enabled Proteus color with the least distance from the actual color
    int color;
    double min_difference, temp;
	min_difference = temp = 1000; //Set these to values outside of range of difference

    //Cycle through all Proteus colors
	for (int i = 0; i < 22; i++) {

        //If this color is disabled, skip trying to find it
        if (lookup_table[0][i] == DISABLE_VALUE){
            continue;
        }

        //Find distance in each channel to the color for each color
        temp = abs(red - lookup_table[0][i]) + abs(green - lookup_table[1][i]) + abs(blue - lookup_table[2][i]);

        //If this is the closest color so far, store it
		if (temp < min_difference) {
			min_difference = temp;
			color = i;
		}
	}

    //Return the closest color
	return color;

}


void Image::HorizLineOptimize(uint_fast32_t image_color_array[]){

    bool cont;

    //Try to optimize each color
    for(unsigned int color = 0; color < 22; color++){

        //If this color is disabled, skip trying to optimize it
        if (lookup_table[0][color] == DISABLE_VALUE){
            continue;
        }

        //Do for entire height
        for(int row = 0; row < height; row++){

            //Check starting at column = 0 to max column that has sufficent padding on the left
            //Innately cannot optimize PER_SIDE first and last pixels
            for(int column = 0; column < width - (PER_SIDE*2 + OPTIMIZE_WIDTH); column++){

                //Assume it's a continuous color on either side of optimization area
                cont = true;

                //Check that left side is a single color
                for(int j = 0; (j <= PER_SIDE) && cont; j++){
                    if(image_color_array[column + j + row * width] != color){
                        cont = false;
                    }
                }

                //Check that right side is a single color
                for(int j = 0; (j <= PER_SIDE) && cont; j++){
                    if(image_color_array[column + j + PER_SIDE + OPTIMIZE_WIDTH + row * width] != color){
                        cont = false;
                    }
                }
                
                //If left and right areas of PER_SIDE width are all one color, make OPTIMIZE_WIDTH
                //Area in between them the same color
                if(cont){
                    for(int k = 1; k <= OPTIMIZE_WIDTH; k++){
                        image_color_array[column + row * width + PER_SIDE + k] = color;
                    }  
                }
            }
        }
    }
}



void Image::PlotImg(const uint_fast32_t image_array[], int scale, int x_off, int y_off){
    int min,r,c;
    for(unsigned int color = 0; color < 22; color++){

        //If this color is totally disabled, skip trying to draw it
        if (lookup_table[0][color] == DISABLE_VALUE){
            continue;
        }

        //Also skip if drawing is disabled for this color
        bool disabled = false;

        //Check if it's on disabled list
        for(int i = 0; i < num_no_draw; i++){
            if(no_draw[i] == color){
                disabled = true;
            }
        }
        if(disabled){ //If disabled for draw, skip
            continue;
        }

        //Set draw color to current color
        LCD.SetDrawColor(color);

        //Draw row by row
        for (r = 0; r < height; r++){

            //Start in column 0
            c = 0;

            //Search the row, finding the longest uninterrupted line to draw
            while(c < width){

                //Set first occurace to last column
                min = width;
                //Find actual first occurance. If no occurance, skip line
                while (image_array[r*width + c] != color && c < width){
                    c++;
                }
                min = c; //Store this as min value

                //Increase column until a different color is found or end is reached
                while (image_array[r*width + c] == color && c < width){
                    c++;
                }

                //Make sure this isn't all the last pixel of the row
                if(min != width){
                    //Draw line
                    LCD.FillRectangle(min*scale + x_off, r*scale + y_off,(c-min) * scale, scale);
                }
            }
        }
    }
}
