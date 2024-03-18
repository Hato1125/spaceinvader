#ifndef _SPACEINVADER_ASSETS_FL_HPP
#define _SPACEINVADER_ASSETS_FL_HPP

#include <memory>
#include <unordered_map>

#include "../main.hpp"

namespace spaceinvader {
  inline void set_font_bundle() noexcept {
    main::font_bundle
      .set_empty_resource(std::make_shared<sweet::font>(main::app.renderer))
      .set_resources(std::unordered_map<std::string, std::shared_ptr<sweet::font>> {
        { "misaki_1nd", std::make_shared<sweet::font>(main::app.renderer, main::app.get_current_dire_s() + "/assets/fonts/misaki_gothic.ttf") },
        { "misaki_2nd", std::make_shared<sweet::font>(main::app.renderer, main::app.get_current_dire_s() + "/assets/fonts/misaki_gothic_2nd.ttf") },
        { "misaki_mincho", std::make_shared<sweet::font>(main::app.renderer, main::app.get_current_dire_s() + "/assets/fonts/misaki_mincho.ttf") },
      });
  }
}

#endif
