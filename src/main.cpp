#include "menu.hpp"
#include <dlfcn.h>

extern "C" [[gnu::visibility("default")]] void mod_preinit() {
    auto menuLib = dlopen("libmcpelauncher_menu.so", 0);
    addMenu      = reinterpret_cast<decltype(addMenu)>(dlsym(menuLib, "mcpelauncher_addmenu"));
    showWindow   = reinterpret_cast<decltype(showWindow)>(dlsym(menuLib, "mcpelauncher_show_window"));
    closeWindow  = reinterpret_cast<decltype(closeWindow)>(dlsym(menuLib, "mcpelauncher_close_window"));
}

extern "C" [[gnu::visibility("default")]] void mod_init() {
    MenuEntryABI testEntries[2];

    testEntries[0] = {
        .name  = "Test Button 1",
        .click = [](void*) {
            // Sem função por enquanto
        },
    };

    testEntries[1] = {
        .name  = "Test Button 2",
        .click = [](void*) {
            // Sem função por enquanto
        },
    };

    MenuEntryABI menuEntry{
        .name       = "Test Panel",
        .length     = std::size(testEntries),
        .subentries = testEntries,
    };

    addMenu(1, &menuEntry);
}
