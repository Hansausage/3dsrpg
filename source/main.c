#include <3ds.h>
#include <stdio.h>
//for menus and stuff
char pointer = '>';
//for selecting row and coloumn in \xlb[X;YH for pointer
//example: printf("\xlb[" + x + ";" + y + "H" + pointer);
int x, y;
//main character's name
char mainName[3] = "Goku";

struct Weapon {
        char name[50];
        double damage;
};

struct Character {
        char name[50];
        double health;
        double magic;
};

struct Enemy {
        char name[50];
        double health;
        double damage;

};

struct Character mainChar;
struct Enemy testEnemy;
struct Weapon testWeapon;



//Create battle menu
void createBMenu() {
        printf("\x1b[%i;%iH%c\n", x, y, pointer);
        printf("\x1b[0;2HAttack\n");
        printf("\x1b[1;2HDefend\n");
        printf("Your Health: %d\n", mainChar.health);
        printf("Enemy Health: %d\n", testEnemy.health);

}



double enemyAttack() {
        mainChar.health = mainChar.health - testEnemy.damage;
        return mainChar.health;
}

double attack() {
        testEnemy.health = testEnemy.health - testWeapon.damage;
        enemyAttack();
        return testEnemy.health;
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

    strcpy(testWeapon.name, "Test Weapon");
    testWeapon.damage = 3;

    strcpy(testEnemy.name, "Test Enemy");
    testEnemy.health = 10;
    testEnemy.damage = 2;

    strcpy(mainChar.name, mainName);
    mainChar.health = 20;
    mainChar.magic = 15;

    while (aptMainLoop()) {

        createBMenu();


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
