#include "./wi.hpp"



WiRect wi_graphics_Rect(int32_t left, int32_t top, int32_t right, int32_t bottom) {
  static_assert((sizeof(WiRect)) == (sizeof(wi::graphics::Rect)));
  wi::graphics::Rect ret = wi::graphics::Rect {.left = left, .top = top, .right = right, .bottom = bottom};
  return *((WiRect*)(&ret));
}

WiViewport wi_graphics_Viewport(float top_left_x, float top_left_y, float width, float height, float min_depth, float max_depth) {
  static_assert((sizeof(WiViewport)) == (sizeof(wi::graphics::Viewport)));
  wi::graphics::Viewport ret = wi::graphics::Viewport {
      .top_left_x = top_left_x, .top_left_y = top_left_y, .width = width, .height = height, .min_depth = min_depth, .max_depth = max_depth};
  return *((WiViewport*)(&ret));
}

void wi_graphics_Rect_fromViewport(WiRect* rect, WiViewport* viewport) {
  wi::graphics::Rect* r = (wi::graphics::Rect*)rect;
  wi::graphics::Viewport* vp = (wi::graphics::Viewport*)viewport;
  return r->from_viewport(*vp);
}
