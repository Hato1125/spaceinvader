#ifndef _SPACEINVADER_ASSETS_TL_HPP
#define _SPACEINVADER_ASSETS_TL_HPP

#include <memory>
#include <unordered_map>

#include "../main.hpp"

namespace spaceinvader {
  inline void set_texture_bundle() noexcept {
    main::texture_bundle
      .set_empty_resource(std::make_shared<sweet::texture>(main::app.renderer))
      .set_resources(std::unordered_map<std::string, std::shared_ptr<sweet::texture>> {
      });
  }
}

#endif
