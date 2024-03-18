#ifndef _SPACEINVADER_HPP
#define _SPACEINVADER_HPP

#include <sweet/app.hpp>
#include <sweet/frame_monitor.hpp>
#include <sweet/resource_bundle.hpp>

namespace spaceinvader {
struct main final {
  static sweet::app app;
  static sweet::frame_monitor frame;
  static sweet::texture_bundle<4u> texture_bundle;
  static sweet::font_bundle<4u> font_bundle;
};
}

#endif
