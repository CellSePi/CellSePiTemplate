// Modified from the original Flet build template
// - Added native_splash_screen initialization on launch
#include <native_splash_screen_linux/native_splash_screen_linux_plugin.h>
#include "my_application.h"

int main(int argc, char** argv) {
  gtk_init(&argc, &argv);
  g_autoptr(MyApplication) app = my_application_new();
  show_splash_screen();
  return g_application_run(G_APPLICATION(app), argc, argv);
}