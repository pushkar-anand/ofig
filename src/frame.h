#include "sciter-x-window.hpp"
#include "sciter-x-graphics.hpp"

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

static sciter::value test_image_access(const sciter::value &vimg) {
    sciter::image img = sciter::image::from(vimg); /// failed in this code
    UINT w, h;
    img.dimensions(w, h);
    sciter::bytes_writer bw;
    img.save(bw, SCITER_IMAGE_ENCODING_RAW);
    return sciter::value();
}

static sciter::value test_image_generation() {
    BYTE pixmap[10 * 10 * 4];
    memset(pixmap, 0, sizeof(pixmap));
    // image data
    for (int i = 0; i < 10 * 10 * 4; i += 4) {
        pixmap[i] = static_cast<BYTE>(i / 4);
        pixmap[i + 1] = static_cast<BYTE>(255 - i / 4);
        pixmap[i + 2] = 255;
        pixmap[i + 3] = 255;
    }
    sciter::image img = sciter::image::create(10, 10, true, pixmap);
    return img.to_value();
}

class frame : public sciter::window {
public:
    frame() : window(SW_TITLEBAR | SW_CONTROLS | SW_MAIN | SW_GLASSY | SW_ENABLE_DEBUG) {}

    BEGIN_FUNCTION_MAP
        FUNCTION_0("nativeApi", native_api);
        FUNCTION_1("testImageAccess", test_image_access);
        FUNCTION_0("testImageGeneration", test_image_generation);
    END_FUNCTION_MAP
};

#endif //OFIG_FRAME_H