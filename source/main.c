#include <3ds.h>
#include <stdio.h>

char pointer = '>'

struct Characters {
        char name[50];
        double health[50]
        double magic[50];
};

struct Characters mainChar;

strcopy(mainChar.name, mainName);
mainChar.health = 20;
mainChar.magic = 15;

void createBMenu {
        printf(pointer);
        printf("\xlb[1;0HAttack");
}

int main() {
    //initialize both consoles
    gfxInitDefault();
    PrintConsole top, bottom;
    consoleInit(GFX_TOP, &top);
    consoleInit(GFX_BOTTOM, &bottom);

    while (aptMainLoop()) {

        //scan inputs
        hidScanInput();
        //check inputs
        u32 kDown = hidKeysDown();
        if (kDown && KEY_START) break;
        if (kDown && KEY_RIGHT) attack();
        if (kDown && KEY_LEFT) defend();
        //flush and swap framebuffers
        gfxFlushBuffers();
        gfxSwapBuffers();

        gspWaitForVBlank();
    }
    gfxExit();
    return 0;
}
