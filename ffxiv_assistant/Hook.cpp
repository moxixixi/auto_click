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

LRESULT CALLBACK CHook::HookMouseProc(int nCode, WPARAM wParam, LPARAM lParam)
{
    if (wParam == WM_LBUTTONUP)
    {
        PMOUSEHOOKSTRUCT p = (PMOUSEHOOKSTRUCT)lParam;
        POINT pt = p->pt;
        ::ScreenToClient(p->hwnd, &pt);
        if (nullptr != cb)
        {
            cb(pt.x, pt.y, ::GetTickCount64());
        }
    }

    return(CallNextHookEx(hook_hanlde, nCode, wParam, lParam));
}

void CHook::StartHook()
{
    hook_hanlde = SetWindowsHookEx(WH_MOUSE_LL, CHook::HookMouseProc, ::GetModuleHandle(NULL), 0);

    return;
}

void CHook::EndHook()
{
    UnhookWindowsHookEx(hook_hanlde);
    hook_hanlde = nullptr;
}
