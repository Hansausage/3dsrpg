#include <3ds.h>
#include <stdio.h>

//for menus and stuff
char pointer = '>';
//for selecting row and coloumn in \xlb[X;YH for pointer
//example: printf("\xlb[" + x + ";" + y + "H" + pointer);
int x, y;
//main character's name
char mainName = 'Goku';

struct Enemies {
        char name[50];
        int type[50];
        double health[50];
        double magic[50];
};

struct Characters {
        char name[50];
        double health[50];
        double magic[50];
};

struct Weapons {
        char name[50];
        double damage[50];
}

//Player Character
struct Characters mainChar;
//Test Enemy
struct Enemies testEnemy;
//Test weapon
struct Weapons testWeapon;

strcopy(testWeapon.name, "Test Weapon");
testWeapon.damage = 3;

strcopy(testEnemy.name, "Test Enemy");
testEnemy.health = 10;
testEnemy.magic = 0;
testEnemy.damage = 2;

strcopy(mainChar.name, mainName);
mainChar.health = 20;
mainChar.magic = 15;

//Create battle menu
void createBMenu {
        printf("\xlb[" + x + ";" + y + "H" + pointer);
        printf("\xlb[1;0HAttack");
        printf("\xlb[1;1HDefend");
        
}

double attack() {
        testEnemy.health = testEnemy.health - testWeapon.damage;
        enemyAttack();
        return testEnemy.health;
}

double enemyAttack() {
        mainChar.health = mainChar.health - testEnemy.damage;
        return mainChar.health;
}

double defend() {
        mainChar.health = mainChar.health;
        return 0;
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
        if (kDown && KEY_DOWN) y = y + 1;
        if (kDown && KEY_UP && y > 0) y = y - 1;
        if (y == 0 && kDown && KEY_A) attack();
        if (y == 1 && kDown && KEY_A) {
                enemyAttack();
                bool defend = true;
        }
        
        //flush and swap framebuffers
        gfxFlushBuffers();
        gfxSwapBuffers();

        gspWaitForVBlank();
    }
    gfxExit();
    return 0;
}
