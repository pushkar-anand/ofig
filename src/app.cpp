#include "resources.cpp"
#include "frame.h"


int uimain(std::function<int()> run) {
    SciterSetOption(nullptr, SCITER_SET_SCRIPT_RUNTIME_FEATURES,
                    ALLOW_FILE_IO |
                    ALLOW_SOCKET_IO |
                    ALLOW_EVAL |
                    ALLOW_SYSINFO);
    SciterSetOption(nullptr, SCITER_SET_DEBUG_MODE, TRUE);

    sciter::debug_output_console console; //- uncomment it if you will need console window

    sciter::archive::instance().open(
            aux::elements_of(resources)); // bind resources[] (defined in "resources.cpp") with the archive

    auto *pwin = new frame();

    // example, setting "usciter" media variable, check https://sciter.com/forums/topic/debugging-issues/
    SciterSetMediaType(pwin->get_hwnd(), WSTR("desktop,oFig"));

    pwin->load(WSTR("this://app/app.html"));

    pwin->expand();

    return run();
}