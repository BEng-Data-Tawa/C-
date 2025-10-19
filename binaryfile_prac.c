#include <stdio.h>
#include <stdlib.h>

#define NO_OF_SHAPES 10

typedef struct {
    char type[15];
    double area;
    char colour[10];
} Shape;

int main(void) {
    FILE *bfile = fopen("binaryfile.bin", "wb+"); // write + read
    if (!bfile) {
        printf("Failed to open file\n");
        return 1;
    }

    Shape shape;

    // 🔹 Input shapes and write to file
    for (int i = 0; i < NO_OF_SHAPES; i++) {
        printf("Input properties of shape (%d):\n", i + 1);

        printf("Enter type: ");
        scanf("%14s", shape.type);

        printf("Enter area: ");
        scanf("%lf", &shape.area);

        printf("Enter colour: ");
        scanf("%9s", shape.colour);

        fwrite(&shape, sizeof(Shape), 1, bfile);
    }

    // 🔹 Read and display every second shape
    Shape s;
    fseek(bfile, 0, SEEK_SET); // go to start

    for (int i = 0; i < NO_OF_SHAPES; i++) {
        if (fread(&s, sizeof(Shape), 1, bfile) != 1)
            break;

        if (i % 2 == 1) { // every second shape
            printf("Shape %d: Type=%s, Area=%.2lf, Colour=%s\n",
                   i + 1, s.type, s.area, s.colour);
        }
    }

    fclose(bfile);
    return 0;
}


