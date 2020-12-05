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
 *  @details Includes functions to convert and then display complex images. Honestly it's just a party trick.
 *  A majority of the hexadecimal conversion code had been written before this project in order to try to display images,
 *  only to realize that the Proteus was unable (at the time) to reproduce more than 7 colors.
 * */
class Image{
    private:

        /** @brief Stores the RGB values of the 22 LCD Colors.
         *  @details Separated into 3 rows and 22 columns. Rows in the order R, G, B.
         *  RGB values should be integers 0 to 255
         * */
        int lookup_table[3][22];

        /** @brief The width and height of the image object in pixels
         * */
        int width, height;

        /** @brief Stores values of colors not to draw
         * */
        unsigned int no_draw[22];

        /** @brief Stores number of colors that are not being drawn
         * */
        int num_no_draw;

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
         *  @brief Default Image constructor. Enables all 22 LCD Colors for render and drawing.
         *  @param w Image width in pixels
         *  @param h Image height in pixlels
         * */
        Image(int w, int h);

        /** @author Adam Exley
         *  @brief Image constructor. Enabled colors are specified.
         *  @param w Image width in pixels
         *  @param h Image height in pixels
         *  @param enabled_colors Int array corresponding to enabled colors. Use defines in FEHLCDColors.h
         *  @param num_enabled Number of values in enabled_colors
         *  @param do_not_draw Int array that stores colors that should be rendered, but should not be drawn
         *  @param num_no_draw Number of values in do_not_draw
         * */
        Image(int w, int h, const int enabled_colors[], int num_enabled, const int do_not_draw[], int num_no_draw);

        /** @author Adam Exley
         *  @brief Finds the closest proteus color to a specified color in an array
         *  @details Splits the hex color value in the array into red green and blue components.
         *  Then searches the Proteus lookup table, finding the color that hsa the closest R G and B components.
         *  @param image_array The array with hex color values to look up
         *  @param x The index of the color to look up
         *  @returns The proteus ID of the closest color that is enabled
         * */
        int lookupColor(const uint_fast32_t image_array[], int x);

        /** @author Adam Exley
         *  @brief Plots an array of Proteus-compatible colors on the screen
         * 
         * 
         * */
        void PlotImg(const uint_fast32_t image_array[], const int scale = 1, int x_off = 0, int y_off = 0);

        void Draw(const uint_fast32_t image_array[], int scale = 1, bool optimize = true, int x_off = 0, int y_off = 0);

        void HorizLineOptimize(uint_fast32_t image_color_array[]);




};



    // int bailey_enable[] = {BLACK, WHITE, GRAY, OLIVE, BROWN};
    // Image bailey(bailey_enable, 5);
    // bailey.Draw(bailey_data, BAILEY_FRAME_WIDTH, BAILEY_FRAME_HEIGHT, 1, BLACK);

    // int bridgette_enable[] = {BLACK, WHITE, GRAY, OLIVE, BROWN};
    // Image bridgette(bridgette_enable, 5);
    // bridgette.Draw(bridgette_data, BRIDGETTE_FRAME_WIDTH, BRIDGETTE_FRAME_HEIGHT, 1, BLACK);

    // int alex_enable[] = {BLACK, WHITE, GRAY, OLIVE, BROWN, BLUE};
    // Image alex(alex_enable, 6);
    // alex.Draw(alex_data, ALEX_FRAME_WIDTH, ALEX_FRAME_HEIGHT, 1, BLACK);

    // int paul_enable[] = {BLACK, WHITE, GRAY, OLIVE, MAROON, CYAN};
    // Image paul(paul_enable, 6);
    // paul.Draw(paul_data, PAUL_FRAME_WIDTH, PAUL_FRAME_HEIGHT, 1, BLACK, 0);

    // int jamie_enable[] = {BLACK, WHITE, GRAY, OLIVE, BROWN, MAROON};
    // Image jamie(jamie_enable, 6);
    // jamie.Draw(jamie_data, JAMIE_FRAME_WIDTH, JAMIE_FRAME_HEIGHT, 1, BLACK);

    // int jane_enable[] = {BLACK, WHITE, GRAY, OLIVE, BROWN, MAROON};
    // Image jane(jane_enable, 6);
    // jane.Draw(jane_data, JANE_FRAME_WIDTH, JANE_FRAME_HEIGHT, 1, BLACK);