#include <iostream>
#include <cairo/cairo-svg.h>
#include <utility>
#include <vector>
#include <string>


class Painter {
    size_t x;
    size_t y;
    std::string string;
public:
    Painter(std::string str, size_t x, size_t y) : string(std::move(str)), x(x), y(y) {}
    void operator() (const std::vector<std::vector<int>>& field) {
        cairo_surface_t *surface;
        cairo_t *cr;
        surface = (cairo_surface_t *)cairo_svg_surface_create(string.c_str(), double (x* 20), double (y * 20));
        cr = cairo_create(surface);
        cairo_pattern_t* pattern;
        cairo_rectangle(cr, 0, 0, double (x* 20), double (y * 20));
        pattern = cairo_pattern_create_rgb(0,0,0);
        cairo_set_source(cr, pattern);
        cairo_fill(cr);
        cairo_pattern_destroy(pattern);
        for (int i = 0; i < field.size(); ++i) {
            for (int j = 0; j < field.size(); ++j) {
                switch(field[i][j]) {
                    case 1:
                        cairo_rectangle(cr, i * 20, j * 20, 19, 19);
                        pattern = cairo_pattern_create_rgb(1, 1, 1);
                        cairo_set_source(cr, pattern);
                        cairo_fill(cr);
                        cairo_pattern_destroy(pattern);
                        pattern = cairo_pattern_create_rgb(1, 0, 0);
                        cairo_rectangle(cr,i * 20 + 5,j * 20 + 17,1,2);
                        cairo_rectangle(cr,i * 20 + 12,j * 20 + 17,1,2);
                        cairo_rectangle(cr,i * 20 + 4,j * 20 + 13,1,5);
                        cairo_rectangle(cr,i * 20 + 11,j * 20 + 13,1,5);
                        cairo_rectangle(cr,i * 20 + 4,j * 20 + 13,8,1);
                        cairo_rectangle(cr,i * 20 + 7,j * 20 + 12,2,2);
                        cairo_rectangle(cr,i * 20 + 5,j * 20 + 4,6,8);
                        cairo_rectangle(cr,i * 20 + 5,j * 20 + 11,13,1);
                        cairo_rectangle(cr,i * 20 + 2,j * 20 + 8,12,1);
                        cairo_rectangle(cr,i * 20 + 3,j * 20 + 7,10,2);
                        cairo_rectangle(cr,i * 20 + 4,j * 20 + 5,8,4);
                        cairo_rectangle(cr,i * 20 + 7,j * 20 + 3,2,1);
                        cairo_set_source(cr, pattern);
                        break;
                    case 0:
                        cairo_rectangle(cr, i * 20, j * 20, 19, 19);
                        pattern = cairo_pattern_create_rgb(1, 1, 1);
                        cairo_set_source(cr, pattern);
                        break;
                    case 2:
                        cairo_rectangle(cr, i * 20, j * 20, 19, 19);
                        pattern = cairo_pattern_create_rgb(0, 1, 0);
                        cairo_set_source(cr, pattern);
                        break;
                }
                cairo_fill(cr);
                cairo_pattern_destroy(pattern);
            }
        }
        cairo_destroy (cr);
        cairo_surface_destroy (surface);
    }
};

int main() {
    int x_size = 50, y_size = 50;
    bool pointer = false;
    Painter print("canvas.svg", x_size, y_size);
    std::string command;
    char c;
    std::vector<std::vector<int>> field(x_size, std::vector<int>(y_size, 0));
    int x = 0, y = 0;
    field[x][y] = 1;
    print(field);
    while(true) {
        bool quit = false;
        std::cin >> command;

        if(field[x][y] == 1){

        }
        switch (command[0]) {
            case 'q':
                quit = true;
                break;
            case 'w':
                if(y > 0) {
                    if(field[x][y] == 1) {
                        field[x][y] = 0;
                    }
                    --y;
                    field[x][y] = 1;
                }
                break;
            case 'a':
                if(x > 0) {
                    if(field[x][y] == 1) {
                        field[x][y] = 0;
                    }
                    --x;
                    field[x][y] = 1;
                }
                break;
            case 's':
                if(y < y_size) {
                    if(field[x][y] == 1) {
                        field[x][y] = 0;
                    }
                    ++y;
                    field[x][y] = 1;
                }
                break;
            case 'd':
                if(x < x_size) {
                    if(field[x][y] == 1) {
                        field[x][y] = 0;
                    }
                    ++x;
                    field[x][y] = 1;
                }
                break;
            case 'p':
                field[x][y] = 2;
                break;
            case 'c':
                field[x][y] = 1;
                break;
        }
        if (quit) {
            break;
        }
        print(field);
    }
    return 0;
}