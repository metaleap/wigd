#include "./app.h"


/* postponed:
    - footprints
    - conversation / dialog
*/


void App::Initialize() {
  infoDisplay.active                  = true;
  infoDisplay.colorspace              = true;
  infoDisplay.device_name             = true;
  infoDisplay.fpsinfo                 = true;
  infoDisplay.heap_allocation_counter = false;
  infoDisplay.logical_size            = false;
  infoDisplay.pipeline_count          = true;
  infoDisplay.pipeline_creation       = true;
  infoDisplay.resolution              = true;
  infoDisplay.vram_usage              = true;
  infoDisplay.watermark               = true;
  wi::Application::Initialize();
  game.init(window);
  game.Load();
  ActivatePath(&game, 0.321f);
}



int main(int argc, char* argv[]) {
  wi::arguments::Parse(argc, argv);

  if (0 != *sdl2::make_sdlsystem(SDL_INIT_EVERYTHING | SDL_INIT_EVENTS)) {
    fprintf(stderr, "Failed to init SDL: %s", SDL_GetError());
    SDL_Quit();
    exit(1);
  }
  auto sdl_win = sdl2::make_window("WickedEngine simple demos", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1440, 900,
                                   SDL_WINDOW_SHOWN | SDL_WINDOW_VULKAN | SDL_WINDOW_ALLOW_HIGHDPI | SDL_WINDOW_RESIZABLE);
  if (!sdl_win) {
    fprintf(stderr, "Failed to make window: %s", SDL_GetError());
    SDL_Quit();
    exit(1);
  }

  auto hwnd = sdl_win.get();
  app.SetWindow(hwnd);
  wi::renderer::SetShaderPath("../../.wi/.shaders/");
  wi::renderer::SetShaderSourcePath("../../.wi/WickedEngine/shaders/");

  bool quit = false;
  while (!quit) {
    app.Run();

    SDL_Event event;
    while (SDL_PollEvent(&event) != 0) {
      switch (event.type) {
        case SDL_QUIT:
          quit = true;
          break;
        case SDL_WINDOWEVENT:
          switch (event.window.event) {
            case SDL_WINDOWEVENT_CLOSE:
              quit = true;
              break;
            case SDL_WINDOWEVENT_RESIZED:
              app.SetWindow(app.window);
              break;
            case SDL_WINDOWEVENT_FOCUS_LOST:
              app.is_window_active = false;
              break;
            case SDL_WINDOWEVENT_FOCUS_GAINED:
              app.is_window_active = true;
              break;
          }
          break;
      }
      wi::input::sdlinput::ProcessEvent(event);
    }
  }

  SDL_Quit();
  return 0;
}
