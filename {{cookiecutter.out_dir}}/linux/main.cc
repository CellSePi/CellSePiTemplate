// Modified from the original Flet build template
// - Added native_splash_screen initialization on launch
// - Added multiprocessing interception to hide worker splash screen

#include <native_splash_screen_linux/native_splash_screen_linux_plugin.h>
#include "my_application.h"
#include <string>

int main(int argc, char** argv) {
  g_autoptr(MyApplication) app = my_application_new();
  bool is_worker_process = false;
  for (int i = 0; i < argc; i++) {
    std::string arg(argv[i]);
    if (arg == "-c" || arg.find("multiprocessing") != std::string::npos) {
      is_worker_process = true;
      break;
    }
  }

  if (!is_worker_process) {
    show_splash_screen();
  }
  return g_application_run(G_APPLICATION(app), argc, argv);
}
