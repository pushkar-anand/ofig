#include "sciter-x-window.hpp"
#include "sciter-x-graphics.hpp"
#include <core/core.h>
#ifndef OFIG_FRAME_H
#define OFIG_FRAME_H

// NOLINT(performance-unnecessary-value-param)
static int native_get_element_uid(sciter::value vel) {
    sciter::dom::element el = (HELEMENT) vel.get_object_data();
    return (int) el.get_element_uid();
}

static sciter::value native_api() {
    sciter::value api_map;

    api_map.set_item(sciter::value("getElementUid"), sciter::vfunc(native_get_element_uid));
    return api_map;

    /* the above returns this:
      return {
        getElementUid(): {native_get_element_uid}
      }
    */
}

class frame : public sciter::window {
public:
    frame() : window(SW_TITLEBAR | SW_CONTROLS | SW_MAIN | SW_GLASSY | SW_ENABLE_DEBUG) {}

    BEGIN_FUNCTION_MAP
    FUNCTION_0("nativeApi", native_api);
    FUNCTION_0("isPHPInstalled", isPHPInstalled)
    END_FUNCTION_MAP
};

#endif //OFIG_FRAME_H