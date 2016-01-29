#include <3ds.h>
#include <stdio.h>

int main() {
    //initialize both consoles
    gfxInitDefault();
    PrintConsole top, bottom;
    consoleInit(GFX_TOP, &top);
    consoleInit(GFX_BOTTOM, &bottom);
    double currFoeHP = 10;
    double chrCurrWeaponAtk = 2;








    while (aptMainLoop()) {

        drawOptions();

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
