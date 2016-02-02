#include <3ds.h>
#include <stdio.h>

//for menus and stuff
char pointer = '>';
//for selecting row and coloumn in \xlb[X;YH for pointer
//example: printf("\xlb[" + x + ";" + y + "H" + pointer);
int x, y;
//main character's name
char mainName = 'Goku';



struct Characters {
        char name[50];
        double health[50]
        double magic[50];
};

//Player Character
struct Characters mainChar;

strcopy(mainChar.name, mainName);
mainChar.health = 20;
mainChar.magic = 15;

//Create battle menu
void createBMenu {
        printf("\xlb[" + x + ";" + y + "H" + pointer);
        printf("\xlb[1;0HAttack");
        printf("\xlb[1;1HDefend");
        
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
        if (kDown && KEY_DOWN) y = y + 1;
        if (kDown && KEY_UP && y > 0) y = y - 1;
        //flush and swap framebuffers
        gfxFlushBuffers();
        gfxSwapBuffers();

        gspWaitForVBlank();
    }
    gfxExit();
    return 0;
}
