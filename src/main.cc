#include <Adafruit_NeoPixel.h>
#include <helix.h>

#define PIXELS 32
#define PIN 6
#define MAX_BRIGHTNESS 20
#define DELAY 200

Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXELS, PIN, NEO_GRB + NEO_KHZ800);


int grid[HEIGHT][WIDTH] = {
        {2,0,0,0,1,1,0,2},
        {0,2,0,1,0,0,1,0},
        {0,0,2,0,0,2,0,1},
        {1,1,0,2,2,0,0,0},
};


void setup() {
        strip.begin();
        strip.show();
        strip.setBrightness(MAX_BRIGHTNESS);
}


void loop() {
        printGrid(grid);
        shiftGrid(grid);
        delay(DELAY);
}


void printGrid(int grid[HEIGHT][WIDTH]) {
        int cell = 0;
        for (int i = 0; i < HEIGHT; i++) {
                for (int j = 0; j < WIDTH; j++) {
                        if (grid[i][j] == 1) {
                                strip.setPixelColor(cell, strip.Color(15,15,15));
                        } else if (grid[i][j] == 2) {
                                strip.setPixelColor(cell, strip.Color(15,0,0));
                        } else {
                                strip.setPixelColor(cell, strip.Color(0,0,0));
                        }
                        cell++;
                }
        }

        strip.show();
}


void shiftGrid(int grid[HEIGHT][WIDTH]) {
        for (int i = 0; i < HEIGHT; i++) {
                // Remember first element for when the index reaches the end
                // because by then the first element would have been shifted
                // over and would no longer exist.
                int first = grid[i][0];
                for (int j = 0; j < WIDTH; j++) {
                        if (j == WIDTH-1) {
                                grid[i][j] = first;
                        } else {
                                grid[i][j] = grid[i][j+1];
                        }
                }
        }
}
