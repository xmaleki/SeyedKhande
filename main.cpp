#include<iostream>
using namespace std;


int main()
{

  return 0;
}

































/*

#include <ftxui/dom/elements.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/component/component.hpp> // <-- این هدر برای Renderer ضروری است

int main() {
  using namespace ftxui;

  // این بخش بدون تغییر است. ما همچنان ساختار بصری را با Element تعریف می‌کنیم.
  Element document = vbox({
    text("FTXUI Getting Started") | bold | center,
    separator(),
    hbox({
      text("Left Panel") | border,
      vbox({
        text("Main Content Area") | flex,
        separator(),
        text("Footer Information") | dim,
      }) | border | flex,
    }) | flex,
  });
  
  // ۱. یک کامپوننت Renderer بسازید.
  // این Renderer یک تابع لامبدا را به عنوان ورودی می‌گیرد.
  // این تابع در هر فریم اجرا شده و باید یک Element برای نمایش برگرداند.
  auto renderer = Renderer([&] {
    return document; // در این مثال ساده، ما همیشه همان document را برمی‌گردانیم.
  });

  auto screen = ScreenInteractive::TerminalOutput();

  // ۲. حالا کامپوننت renderer را به Loop پاس دهید، نه Element را.
  screen.Loop(renderer);

  return 0;
}
*/