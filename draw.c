#include <stdio.h>

void draw(int n);

int main(void)
{
    int n[20] = {2,9,22,7,28,4,62,31,7,41,17,67,46,23,22,51,39,49,30,11};

    for (int i = 0; i < 20; i++) {
      draw(n[i]);
    }

}

void draw(int n)
{
    // If nothing to draw
    if (n <= 0)
    {
        return;
    }

    printf("%i",n);
    for (int i = 0; i < n; i++)
    {
      printf("#");
    }
    printf("\n");
}
