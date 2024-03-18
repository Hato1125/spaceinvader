#include <sweet/keyboard.hpp>
#include <sweet/game_controller_manager.hpp>

#include "log.hpp"
#include "main.hpp"
#include "assets/tl.hpp"
#include "assets/fl.hpp"

namespace spaceinvader {
  sweet::app main::app{ };
  sweet::frame_monitor main::frame{ };
  sweet::texture_bundle<4u> main::texture_bundle{ };
  sweet::font_bundle<4u> main::font_bundle{ };
}

int main(int argc, char **argv) noexcept {
  // Init application and modules.
  {
    auto result = spaceinvader::main::app.init(argc, argv, {
      .on_initing = [] {
        spaceinvader::set_texture_bundle();
        spaceinvader::set_font_bundle();
      },
      .on_inited = [] {
        if(auto rs = spaceinvader::main::texture_bundle.load(); !rs)
          LOG_WARN(rs.error());

        if(auto rs = spaceinvader::main::font_bundle.load(); !rs)
          LOG_WARN(rs.error());
      }
    });
  }

  // Run application!!!
  {
    spaceinvader::main::app.run({
      .loop {
        .on_event = [](SDL_Event &e) {
          sweet::keyboard::update_event(e);
          sweet::game_controller_manager::update_event(e);

          if(e.type == SDL_KEYUP && e.key.keysym.sym == SDLK_ESCAPE)
            spaceinvader::main::app.end();
        },
        .on_update = []() {
          spaceinvader::main::frame.begin();
          sweet::keyboard::update();
          sweet::game_controller_manager::update();
        },
        .on_render = []() {
          spaceinvader::main::frame.end();
        }
      },
      .end {
        .on_finishing = [] {
          if(auto rs = spaceinvader::main::texture_bundle.unload(); !rs)
            LOG_WARN(rs.error());

          if(auto rs = spaceinvader::main::font_bundle.unload(); !rs)
            LOG_WARN(rs.error());
        }
      }
    });
  }
}
