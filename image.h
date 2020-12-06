#pragma once
/** @file Image.h
 *  @brief Contains declarations of Image class functions.
 * */
#include <stdint.h>
#include "FEHLCD.h"
#include "config.h"
#include <cstdlib>
#include <cstdio>
#include <cmath>


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
         *  @brief Plots a given image with a certain scale, optimization, and coordinate offset
         *  @details Converts hexadecimal color array before optionally optimizing it and then displaying it on screen
         *  @param image_array Source array of image to plot
         *  @param scale (Optional) Default 1. Factor to scale image by. Integers only. 
         *  @param optimize (Optional) Default True. Whether to apply horizontal line optimization to the image.
         *  @param x_off (Optional) Default 0. X-coordinate offset of top left corner of image.
         *  @param y_off (Optional) Default 0. Y-coordinate offset of top left corner of image.
         * */
        void Draw(const uint_fast32_t image_array[], int scale = 1, bool optimize = true, int x_off = 0, int y_off = 0);

    private:
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
         *  @brief Optimizes a proteus color array for line plotting
         *  @details Called by Draw() if optimization is enabled.
         *  Due to PlotImg() using horizontal lines to plot colors for performance, additional
         *  speed can be gained by lengthening the lines that are drawn. Uses parameters found in config.h
         *  to change small sections of colors surrounded by a uniform color in order to create longer lines.
         *  Reduces visual fidelity. Should only be used on images, not graphics that are to be rendered as 
         *  graphics have less noise and the approach taken by this function will liekly cause large amount of artifacting.
         *  Could be made more efficient by consdiering the order colors are plotted and which colors are enabled.
         *  @todo Consider what colors will be plotted over each color to increase line length and thus performace.
         *  @param image_color_array Array to optimize
         * */
        void HorizLineOptimize(uint_fast32_t image_color_array[]);

        /** @author Adam Exley
         *  @brief Plots an array of Proteus-compatible colors on the screen
         *  @details Must be converted by lookupColor first. Called by Draw().
         *  Plots in horizontal lines of like color to increase speed. This is more efficent than plotting
         *  pixel-by-pixel, but less efficent than plotting the largest possible rectangles or circles of each color.
         *  @todo Convert array into list of rectangles/circles of maximum area to plot instead
         *  @param image_array The array of Proteus color ID's to plot
         *  @param scale The factor to enlarge the image by
         *  @param x_off The x-offset of the image on the screen
         *  @param y_off The y-offset of the image on the screen
         * */
        void PlotImg(const uint_fast32_t image_array[], const int scale = 1, int x_off = 0, int y_off = 0);
};


