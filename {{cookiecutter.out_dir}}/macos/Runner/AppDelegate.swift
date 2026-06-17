// Modified from the original Flet build template
// - Added native_splash_screen initialization on launch
// - Added multiprocessing interception to hide worker splash screen

import Cocoa
import FlutterMacOS
import native_splash_screen_macos

@main
class AppDelegate: FlutterAppDelegate {
  override func applicationShouldTerminateAfterLastWindowClosed(_ sender: NSApplication) -> Bool {
    return true
  }

  override func applicationSupportsSecureRestorableState(_ app: NSApplication) -> Bool {
    return true
  }
  override func applicationWillFinishLaunching(_ notification: Notification) {
      let args = ProcessInfo.processInfo.arguments

      let isWorkerProcess = args.contains("-c") || args.contains(where: { $0.contains("multiprocessing") })
      if !isWorkerProcess {
        NativeSplashScreen.configurationProvider = NativeSplashScreenConfiguration()
        NativeSplashScreen.show()
      }
  }
}
