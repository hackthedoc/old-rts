#include "include/Save.h"
#include "include/serialization.h"

#include "include/Window.h"

#include <fstream>
#include <filesystem>

namespace fs = std::filesystem;

bool Save::Auto = false;
std::string Save::pathToSaveFolder = "./data/";

/* ----- CONFIG ----- */

void Save::CreateConfig() {
    Struct::Config config{
    .autosave = true,
    .window_mode = 0,
    .controls = {
            { EventID::MOVE_UP          , SDL_SCANCODE_W        },
            { EventID::MOVE_DOWN        , SDL_SCANCODE_S        },
            { EventID::MOVE_LEFT        , SDL_SCANCODE_A        },
            { EventID::MOVE_RIGHT       , SDL_SCANCODE_D        },
            { EventID::SELECT_MULTIPLE  , SDL_SCANCODE_LSHIFT   },
        }
    };

    serialize::config(config);
}

void Save::SaveConfig() {
    Struct::Config config = LoadConfig();

    config.autosave = Save::Auto;

    config.window_mode = 0;
    if (Window::fullscreen)
        config.window_mode = SDL_WINDOW_FULLSCREEN_DESKTOP;

    config.controls = Window::controls;

    serialize::config(config);
}

Struct::Config Save::LoadConfig() {
    if (!fs::exists("config")) CreateConfig();

    Struct::Config config = deserialize::config();

    return config;
}
