#include <stdio.h>
#include <string.h>
#define NEDELI 4
#define DENOVI 5

struct RabotnaNedela {
    int rabotniCasovi[5];
    int nedela;
};
struct Rabotnik {
    char ime[50];
    RabotnaNedela niza[4];
};

int maxNedela(Rabotnik *r) {
    int maxIndex = 0;
    for(int i=1;i<5;i++) {

    }
}

int main() {
    int n;
    scanf("%d", &n);
    R rabotnici[n];
    int i;
    for (i = 0; i < n; ++i) {
        scanf("%s", rabotnici[i].ime);
        int j;
        for (j = 0; j < NEDELI; ++j) {
            int k;
            for (k = 0; k < DENOVI; ++k) {
                scanf("%d", &rabotnici[i].nedeli[j].casovi[k]);
            }

        }
    }
    printf("TABLE\n");
    table(rabotnici, n);
    printf("MAX NEDELA NA RABOTNIK: %s\n", rabotnici[n / 2].ime);
    printf("%d\n", maxNedela(&rabotnici[n / 2]));
    return 0;
}
