#pragma once

#include <stdint.h>
#include "FEHLCD.h"
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include "FEHSD.h"

/** Arbitrary value to set a color's RGB values to when disabled.
 * */
#define DISABLE_VALUE 4000

/** @brief Optimization Constant.
 *  @details The number of pixels required padding a region of pixels in order to
 *  replace the region with the surrounding color. 
 * */
#define PER_SIDE 6

/** @brief Optimization Constant.
 *  @details The number of pixels in a row to attempt to change to another color if
 *  appropriately surounded by other pixels of consatnt color.
 * */
#define OPTIMIZE_WIDTH 3

/** @author Adam Exley
 *  @brief This class displays images exported from https://www.piskelapp.com
 *  @details Includes functions to convert and then display complex images. Honestly it's just a party trick
 * */
class Img{
    private:

        /** @brief Stores the RGB values of the 22 LCD Colors.
         *  @details Separated into 3 rows and 22 columns. Rows in the order R, G, B.
         *  RGB values should be integers 0 to 255
         * */
        int lookup_table[3][22];

        /** @brief Stores the hex string of the color being converted.
         *  @details String should occupy 8 characters.
         * */
        char convert[10];

        /** @brief Stores the hex string of the specified color channel of the color being converted.
         * */
        char red_string[3], green_string[3], blue_string[3];

        /** @brief Stores the integer values of the color channel for the current color being converted.
         * */
        int red, green, blue;

    public:
        /** @author Adam Exley
         *  @brief Default Img constructor. Enables all 22 LCD Colors.
         * */
        Img();

        /** @author Adam Exley
         *  @brief Img constructor. Enabled colors are specified.
         *  @param enabled_colors Int array corresponding to enabled colors. Use defines in FEHLCDColors.h
         *  @param num_enabled Number of values in enabled_colors
         * */
        Img(const int enabled_colors[], const int num_enabled);

        int lookupColor(const uint_fast32_t image_array[], int x);

        void PlotImg(const uint_fast32_t image_array[], int width, int height, const int scale = 1, int background = BLACK);

        void Draw(const uint_fast32_t image_array[], int width, int height, int scale = 1, int background = BLACK, bool optimize = true);

        void HorizLineOptimize(uint_fast32_t image_color_array[], int width, int height);




};
