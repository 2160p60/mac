#include "macos_ui_plugin.h"
#include <obs-module.h>

OBS_DECLARE_MODULE()
OBS_MODULE_USE_DEFAULT_LOCALE("macos-ui-plugin", "en-US")

bool obs_module_load(void)
{
    blog(LOG_INFO, "macOS UI Plugin loaded!");
    return true;
}
