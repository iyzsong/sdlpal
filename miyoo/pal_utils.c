#include "main.h"


static int
input_event_filter(const SDL_Event *lpEvent, volatile PALINPUTSTATE *state)
{
    switch (lpEvent->type) {
    case SDL_KEYDOWN:
        switch (lpEvent->key.keysym.sym) {
        case SDLK_SPACE:        // A
            state->dwKeyPress |= kKeySearch;
            break;
        case SDLK_LCTRL:        // B
            state->dwKeyPress |= kKeyMenu;
            break;
        case SDLK_LSHIFT:       // X
            state->dwKeyPress |= kKeyRepeat;
            break;
        case SDLK_LALT:         // Y
            state->dwKeyPress |= kKeyUseItem;
            break;
        case SDLK_ESCAPE:       // SELECT
            state->dwKeyPress |= kKeyFlee;
            break;
        case SDLK_RETURN:       // START
            state->dwKeyPress |= kKeyAuto;
            break;
        case SDLK_TAB:          // L1
            state->dwKeyPress |= kKeyPgUp;
            break;
        case SDLK_BACKSPACE:    // L2
            state->dwKeyPress |= kKeyPgDn;
            break;
        case SDLK_RCTRL:        // HOME
            state->dwKeyPress |= kKeyStatus;
            break;
        default:
            return 0;
        }
        return 1;
    }
    return 0;
}


INT
UTIL_Platform_Init(int argc, char *argv[])
{
    PAL_RegisterInputFilter(NULL, input_event_filter, NULL);
    return 0;
}


VOID
UTIL_Platform_Quit(VOID)
{

}

BOOL
UTIL_IsAbsolutePath(LPCSTR lpszFileName)
{
    return FALSE;
}

BOOL
UTIL_GetScreenSize(DWORD *pdwScreenWidth, DWORD *pdwScreenHeight)
{
    return FALSE;
}
