#if defined _EasyFade_included
    #endinput
#endif
#define _EasyFade_included


#include <a_samp>
#include <screen-colour-fader>


#define Fade:%0(%1) forward public Fade@%0(%1); public Fade@%0(%1)

#define FadePlayerScreen(%0,%1, FadePlayerScreen_Internal(%0, #%1,


static ScreenFadeFunction[MAX_PLAYERS][32 char];


stock FadePlayerScreen_Internal(playerid, const name[], colour, time, steps) {
    if (name[0] == EOS || !FadePlayerScreenColour(playerid, colour, time, steps)) {
        return 0;
    }

    new function[32] = "Fade@";
    strcat(function, name);

    strpack(ScreenFadeFunction[playerid], function, 32);
    return 1;
}


stock EasyFade_FadePlayerScreenColour(playerid, colour, time, steps) {
    ScreenFadeFunction[playerid]{0} = EOS;

    return FadePlayerScreenColour(playerid, colour, time, steps);
}

#if defined _ALS_FadePlayerScreenColour
    #undef FadePlayerScreenColour
#else
    #define _ALS_FadePlayerScreenColour
#endif
#define FadePlayerScreenColour EasyFade_FadePlayerScreenColour


stock EasyFade_StopPlayerSCF(playerid) {
    ScreenFadeFunction[playerid]{0} = EOS;

    return StopPlayerScreenColourFade(playerid);
}

#if defined _ALS_StopPlayerScreenColourFade
    #undef StopPlayerScreenColourFade
#else
    #define _ALS_StopPlayerScreenColourFade
#endif
#define StopPlayerScreenColourFade EasyFade_StopPlayerSCF


public OnPlayerConnect(playerid) {
    ScreenFadeFunction[playerid]{0} = EOS;

    #if defined EasyFade_OnPlayerConnect
        return EasyFade_OnPlayerConnect(playerid);
    #else
        return 1;
    #endif
}

#if defined _ALS_OnPlayerConnect
    #undef OnPlayerConnect
#else
    #define _ALS_OnPlayerConnect
#endif
#define OnPlayerConnect EasyFade_OnPlayerConnect

#if defined EasyFade_OnPlayerConnect
    forward EasyFade_OnPlayerConnect(playerid);
#endif


public OnScreenColourFadeComplete(playerid) {
    if (ScreenFadeFunction[playerid]{0} != EOS) {
        new function[32];
        strunpack(function, ScreenFadeFunction[playerid]);
        ScreenFadeFunction[playerid]{0} = EOS;

        CallLocalFunction(function, "i", playerid);
        return 1;
    }

    #if defined EasyFade_OnScreenColourFadeCmp
        return EasyFade_OnScreenColourFadeCmp(playerid);
    #else
        return 1;
    #endif
}

#if defined _ALS_OnScreenColourFadeComplete
    #undef OnScreenColourFadeComplete
#else
    #define _ALS_OnScreenColourFadeComplete
#endif
#define OnScreenColourFadeComplete EasyFade_OnScreenColourFadeCmp

#if defined EasyFade_OnScreenColourFadeCmp
    forward EasyFade_OnScreenColourFadeCmp(playerid);
#endif
