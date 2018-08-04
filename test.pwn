#include "easy-fade.inc"


main() {}


public OnGameModeInit() {
	printf("asd");
	return 1;
}


public OnPlayerConnect(playerid) {
	FadePlayerScreen(playerid, GoBlack, 0x000000FF, 1000, 25);
	return 1;
}


Fade:GoBlack(playerid) {
	printf("black");
    FadePlayerScreen(playerid, GoBack, 0x00000000, 1000, 25);
    return 1;
}


Fade:GoBack(playerid) {
	printf("back");
    FadePlayerScreen(playerid, GoBlack, 0x000000FF, 1000, 25);
    return 1;
}
