#include <3ds.h>
#include <stdio.h>

struct Characters {
    char names[50];
    double health[50];
    double stalePineapples[50];
};

struct Characters Char1;

double attack() {

}

double defend() {

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
        if (kDown & KEY_START) break;
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
