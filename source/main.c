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
    int chrLvl = 1;
    int chrLvlAtk;
    int mgkxp, mgkdmg;

    int chrLvlUp() {
        for (int i; i <= chrLvl; i++) {
          chrLvl = chrLvl + 1;
          chrLvlAtk = chrLvl*2+1;
          if (mgkxp >= chrLvl) {
              mgkdmg = chrLvl*2;
          }


        }
    }

    double attack() {
        int chrAtk = chrLvlAtk + chrCurrWeaponAtk;
        currFoeHP = currFoeHP - chrAtk;
        return currFoeHP;
    }

    double defend() {
        return 0;
    }


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
