#include <3ds.h>
#include <stdio.h>

int main() {
    //initialize both consoles
    gfxInitDefault();
    PrintConsole top, bottom;
    ConsoleInit(GFX_TOP, &top);
    ConsoleInit(GFX_BOTTOM, &bottom);

    consoleSelect(&top);
    printf("i'll put things here eventually\n");
    printf("press start to exit\n");

    consoleSelect(&bottom);
    printf("i'll put things here eventually\n");

    while (aptMainLoop()) {
        //scan inputs
        hidScanInput();
        //check inputs
        u32 kDown = hidKeysDown();
        if (kDown & KEY_START) break;
        //flush and swap framebuffers
        gfxFlushBuffers();
        gfxSwapBuffers();

        gspWaitForVBlank();
    }
    gfxExit();
    return 0;
}
