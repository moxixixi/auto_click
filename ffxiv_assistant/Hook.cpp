#include "Hook.h"

HHOOK hook_hanlde;
pHookMouseProc cb;

CHook::CHook(pHookMouseProc pFn)
{
    hook_hanlde = nullptr;
    cb = pFn;
}

CHook::~CHook()
{
}

LRESULT CALLBACK CHook::HookKeyProc(int nCode, WPARAM wParam, LPARAM lParam)
{
    if (wParam == WM_KEYUP)
    {
        PKBDLLHOOKSTRUCT p = (PKBDLLHOOKSTRUCT)lParam;
        if (nullptr != p &&
            nullptr != cb)
        {
            cb(p->vkCode, ::GetTickCount64());
        }
    }

    return(CallNextHookEx(hook_hanlde, nCode, wParam, lParam));
}

void CHook::StartHook()
{
    hook_hanlde = SetWindowsHookEx(WH_KEYBOARD_LL, CHook::HookKeyProc, ::GetModuleHandle(NULL), 0);

    return;
}

void CHook::EndHook()
{
    UnhookWindowsHookEx(hook_hanlde);
    hook_hanlde = nullptr;
}
