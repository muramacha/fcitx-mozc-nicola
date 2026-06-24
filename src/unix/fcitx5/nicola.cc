#include "unix/fcitx5/nicola.h"

#include <Fcitx5/Core/fcitx/instance.h>
#include <Fcitx5/Utils/fcitx-utils/log.h>
#include <fcitx-utils/key.h>
#include <fcitx-utils/keysym.h>
#include <fcitx/inputmethodengine.h>

#include <cstdint>
#include <cstdlib>
#include <map>
#include <set>

#include "nicola.h"
#include "unix/fcitx5/mozc_state.h"

namespace Nicola {
uint32_t LeftNicolaKey = fcitx::KeySym::FcitxKey_space;
uint32_t RightNicolaKey = fcitx::KeySym::FcitxKey_Henkan;
// [MYTASK] Add NicolaKeymapJP
const std::map<std::set<uint32_t>, const char*> NicolaKeymapUS = {
    {{'1'}, "１"}, {{LeftNicolaKey, '1'}, "？"},
    {{'2'}, "２"}, {{LeftNicolaKey, '2'}, "／"},
    {{'3'}, "３"}, {{LeftNicolaKey, '3'}, "〜"},
    {{'4'}, "４"}, {{LeftNicolaKey, '4'}, "「"},
    {{'5'}, "５"}, {{LeftNicolaKey, '5'}, "」"},
    {{'6'}, "６"},                               {{RightNicolaKey, '6'}, "［"},
    {{'7'}, "７"},                               {{RightNicolaKey, '7'}, "］"},
    {{'8'}, "８"},                               {{RightNicolaKey, '8'}, "（"},
    {{'9'}, "９"},                               {{RightNicolaKey, '9'}, "）"},
    {{'0'}, "０"},                               {{RightNicolaKey, '0'}, "｀"},
    {{'q'}, "。"}, {{LeftNicolaKey, 'q'}, "ぁ"},
    {{'w'}, "か"}, {{LeftNicolaKey, 'w'}, "え"}, {{RightNicolaKey, 'w'}, "が"},
    {{'e'}, "た"}, {{LeftNicolaKey, 'e'}, "り"}, {{RightNicolaKey, 'e'}, "だ"},
    {{'r'}, "こ"}, {{LeftNicolaKey, 'r'}, "ゃ"}, {{RightNicolaKey, 'r'}, "ご"},
    {{'t'}, "さ"}, {{LeftNicolaKey, 't'}, "れ"}, {{RightNicolaKey, 't'}, "ざ"},
    {{'y'}, "ら"}, {{LeftNicolaKey, 'y'}, "ぱ"}, {{RightNicolaKey, 'y'}, "よ"},
    {{'u'}, "ち"}, {{LeftNicolaKey, 'u'}, "ぢ"}, {{RightNicolaKey, 'u'}, "に"},
    {{'i'}, "く"}, {{LeftNicolaKey, 'i'}, "ぐ"}, {{RightNicolaKey, 'i'}, "る"},
    {{'o'}, "つ"}, {{LeftNicolaKey, 'o'}, "づ"}, {{RightNicolaKey, 'o'}, "ま"},
    {{'p'}, ","},  {{LeftNicolaKey, 'p'}, "ぴ"}, {{RightNicolaKey, 'p'}, "ぇ"},
    {{'['}, "、"},                               {{RightNicolaKey, '['}, "゛"},
    {{']'}, "゛"},                               {{RightNicolaKey, ']'}, "う"},
    {{'a'}, "う"}, {{LeftNicolaKey, 'a'}, "を"}, {{RightNicolaKey, 'a'}, "ゔ"},
    {{'s'}, "し"}, {{LeftNicolaKey, 's'}, "あ"}, {{RightNicolaKey, 's'}, "じ"},
    {{'d'}, "て"}, {{LeftNicolaKey, 'd'}, "な"}, {{RightNicolaKey, 'd'}, "で"},
    {{'f'}, "け"}, {{LeftNicolaKey, 'f'}, "ゅ"}, {{RightNicolaKey, 'f'}, "げ"},
    {{'g'}, "せ"}, {{LeftNicolaKey, 'g'}, "も"}, {{RightNicolaKey, 'g'}, "ぜ"},
    {{'h'}, "は"}, {{LeftNicolaKey, 'h'}, "ば"}, {{RightNicolaKey, 'h'}, "み"},
    {{'j'}, "と"}, {{LeftNicolaKey, 'j'}, "ど"}, {{RightNicolaKey, 'j'}, "お"},
    {{'k'}, "き"}, {{LeftNicolaKey, 'k'}, "ぎ"}, {{RightNicolaKey, 'k'}, "の"},
    {{'l'}, "い"}, {{LeftNicolaKey, 'l'}, "ぽ"}, {{RightNicolaKey, 'l'}, "ょ"},
    {{';'}, "ん"}, {{LeftNicolaKey, ';'}, "ん゙"}, {{RightNicolaKey, ';'}, "っ"},
    {{'z'}, "."},  {{LeftNicolaKey, 'z'}, "ぅ"},
    {{'x'}, "ひ"}, {{LeftNicolaKey, 'x'}, "ー"}, {{RightNicolaKey, 'x'}, "び"},
    {{'c'}, "す"}, {{LeftNicolaKey, 'c'}, "ろ"}, {{RightNicolaKey, 'c'}, "ず"},
    {{'v'}, "ふ"}, {{LeftNicolaKey, 'v'}, "や"}, {{RightNicolaKey, 'v'}, "ぶ"},
    {{'b'}, "へ"}, {{LeftNicolaKey, 'b'}, "ぃ"}, {{RightNicolaKey, 'b'}, "べ"},
    {{'n'}, "め"},                               {{RightNicolaKey, 'n'}, "ぬ"},
    {{'m'}, "そ"}, {{LeftNicolaKey, 'm'}, "ぞ"}, {{RightNicolaKey, 'm'}, "ゆ"},
    {{','}, "ね"}, {{LeftNicolaKey, ','}, "ぺ"}, {{RightNicolaKey, ','}, "む"},
    {{'.'}, "ほ"}, {{LeftNicolaKey, '.'}, "ぼ"}, {{RightNicolaKey, '.'}, "わ"},
    {{'/'}, "・"},                               {{RightNicolaKey, '/'}, "ぉ"},
};

const auto kSpecialKeyMap =
    std::map<uint32_t, mozc::commands::KeyEvent::SpecialKey>({
        {FcitxKey_space, mozc::commands::KeyEvent::SPACE},
        {FcitxKey_Return, mozc::commands::KeyEvent::ENTER},
        {FcitxKey_Left, mozc::commands::KeyEvent::LEFT},
        {FcitxKey_Right, mozc::commands::KeyEvent::RIGHT},
        {FcitxKey_Up, mozc::commands::KeyEvent::UP},
        {FcitxKey_Down, mozc::commands::KeyEvent::DOWN},
        {FcitxKey_Escape, mozc::commands::KeyEvent::ESCAPE},
        {FcitxKey_Delete, mozc::commands::KeyEvent::DEL},
        {FcitxKey_BackSpace, mozc::commands::KeyEvent::BACKSPACE},
        {FcitxKey_Insert, mozc::commands::KeyEvent::INSERT},
        {FcitxKey_Henkan, mozc::commands::KeyEvent::HENKAN},
        {FcitxKey_Muhenkan, mozc::commands::KeyEvent::MUHENKAN},
        {FcitxKey_Hiragana, mozc::commands::KeyEvent::KANA},
        {FcitxKey_Hiragana_Katakana, mozc::commands::KeyEvent::KANA},
        {FcitxKey_Katakana, mozc::commands::KeyEvent::KATAKANA},
        {FcitxKey_Zenkaku, mozc::commands::KeyEvent::HANKAKU},
        {FcitxKey_Hankaku, mozc::commands::KeyEvent::HANKAKU},
        {FcitxKey_Zenkaku_Hankaku, mozc::commands::KeyEvent::HANKAKU},
        {FcitxKey_Eisu_toggle, mozc::commands::KeyEvent::EISU},
        {FcitxKey_Home, mozc::commands::KeyEvent::HOME},
        {FcitxKey_End, mozc::commands::KeyEvent::END},
        {FcitxKey_Tab, mozc::commands::KeyEvent::TAB},
        {FcitxKey_F1, mozc::commands::KeyEvent::F1},
        {FcitxKey_F2, mozc::commands::KeyEvent::F2},
        {FcitxKey_F3, mozc::commands::KeyEvent::F3},
        {FcitxKey_F4, mozc::commands::KeyEvent::F4},
        {FcitxKey_F5, mozc::commands::KeyEvent::F5},
        {FcitxKey_F6, mozc::commands::KeyEvent::F6},
        {FcitxKey_F7, mozc::commands::KeyEvent::F7},
        {FcitxKey_F8, mozc::commands::KeyEvent::F8},
        {FcitxKey_F9, mozc::commands::KeyEvent::F9},
        {FcitxKey_F10, mozc::commands::KeyEvent::F10},
        {FcitxKey_F11, mozc::commands::KeyEvent::F11},
        {FcitxKey_F12, mozc::commands::KeyEvent::F12},
        {FcitxKey_F13, mozc::commands::KeyEvent::F13},
        {FcitxKey_F14, mozc::commands::KeyEvent::F14},
        {FcitxKey_F15, mozc::commands::KeyEvent::F15},
        {FcitxKey_F16, mozc::commands::KeyEvent::F16},
        {FcitxKey_F17, mozc::commands::KeyEvent::F17},
        {FcitxKey_F18, mozc::commands::KeyEvent::F18},
        {FcitxKey_F19, mozc::commands::KeyEvent::F19},
        {FcitxKey_F20, mozc::commands::KeyEvent::F20},
        {FcitxKey_F21, mozc::commands::KeyEvent::F21},
        {FcitxKey_F22, mozc::commands::KeyEvent::F22},
        {FcitxKey_F23, mozc::commands::KeyEvent::F23},
        {FcitxKey_F24, mozc::commands::KeyEvent::F24},
        {FcitxKey_Page_Up, mozc::commands::KeyEvent::PAGE_UP},
        {FcitxKey_Page_Down, mozc::commands::KeyEvent::PAGE_DOWN},

        // Keypad (10-key).
        {FcitxKey_KP_0, mozc::commands::KeyEvent::NUMPAD0},
        {FcitxKey_KP_1, mozc::commands::KeyEvent::NUMPAD1},
        {FcitxKey_KP_2, mozc::commands::KeyEvent::NUMPAD2},
        {FcitxKey_KP_3, mozc::commands::KeyEvent::NUMPAD3},
        {FcitxKey_KP_4, mozc::commands::KeyEvent::NUMPAD4},
        {FcitxKey_KP_5, mozc::commands::KeyEvent::NUMPAD5},
        {FcitxKey_KP_6, mozc::commands::KeyEvent::NUMPAD6},
        {FcitxKey_KP_7, mozc::commands::KeyEvent::NUMPAD7},
        {FcitxKey_KP_8, mozc::commands::KeyEvent::NUMPAD8},
        {FcitxKey_KP_9, mozc::commands::KeyEvent::NUMPAD9},
        {FcitxKey_KP_Equal, mozc::commands::KeyEvent::EQUALS},         // [=]
        {FcitxKey_KP_Multiply, mozc::commands::KeyEvent::MULTIPLY},    // [*]
        {FcitxKey_KP_Add, mozc::commands::KeyEvent::ADD},              // [+]
        {FcitxKey_KP_Separator, mozc::commands::KeyEvent::SEPARATOR},  // enter
        {FcitxKey_KP_Subtract, mozc::commands::KeyEvent::SUBTRACT},    // [-]
        {FcitxKey_KP_Decimal, mozc::commands::KeyEvent::DECIMAL},      // [.]
        {FcitxKey_KP_Divide, mozc::commands::KeyEvent::DIVIDE},        // [/]
        {FcitxKey_KP_Space, mozc::commands::KeyEvent::SPACE},
        {FcitxKey_KP_Tab, mozc::commands::KeyEvent::TAB},
        {FcitxKey_KP_Enter, mozc::commands::KeyEvent::ENTER},
        {FcitxKey_KP_Home, mozc::commands::KeyEvent::HOME},
        {FcitxKey_KP_Left, mozc::commands::KeyEvent::LEFT},
        {FcitxKey_KP_Up, mozc::commands::KeyEvent::UP},
        {FcitxKey_KP_Right, mozc::commands::KeyEvent::RIGHT},
        {FcitxKey_KP_Down, mozc::commands::KeyEvent::DOWN},
        {FcitxKey_KP_Page_Up, mozc::commands::KeyEvent::PAGE_UP},
        {FcitxKey_KP_Page_Down, mozc::commands::KeyEvent::PAGE_DOWN},
        {FcitxKey_KP_End, mozc::commands::KeyEvent::END},
        {FcitxKey_KP_Delete, mozc::commands::KeyEvent::DEL},
        {FcitxKey_KP_Insert, mozc::commands::KeyEvent::INSERT},
        {FcitxKey_Caps_Lock, mozc::commands::KeyEvent::CAPS_LOCK},

        // Shift+TAB.
        {FcitxKey_ISO_Left_Tab, mozc::commands::KeyEvent::TAB},

        // On Linux (X / Wayland), Hangul and Hanja are identical with
        // ImeOn and ImeOff.
        // https://github.com/google/mozc/issues/552
        //
        // Hangul == Lang1 (USB HID) / ImeOn (Windows) / Kana (macOS)
        {FcitxKey_Hangul, mozc::commands::KeyEvent::ON},
        // Hanja == Lang2 (USB HID) / ImeOff (Windows) / Eisu (macOS)
        {FcitxKey_Hangul_Hanja, mozc::commands::KeyEvent::OFF},

        // TODO(mazda): Handle following keys?
        //   - FcitxKey_Kana_Lock? FcitxKey_KEY_Kana_Shift?
    });

Nicola::Nicola(fcitx::MozcState* state, fcitx::EventLoop& loop,
               fcitx::InputContext* ic)
    : mozc_state_(state), loop_(loop), ic_(ic) {
  // [MYTASK] Add code to read config
  // right_shift.keysym = ;
}

void Nicola::SetMozcState(fcitx::MozcState* state) { mozc_state_ = state; }

bool Nicola::ProcessKeyEvent(fcitx::KeySym keyval, uint32_t keycode,
                             fcitx::KeyStates modifiers,
                             mozc::config::Config::PreeditMethod preedit_method,
                             bool layout_is_jp, bool is_key_up) {
  if (modifiers) return false;

  bool is_thumb_key = (keyval == LeftNicolaKey || keyval == RightNicolaKey);
  bool is_printable_char = (keyval >= 0x0020 && keyval <= 0x00ff);

  if (!is_thumb_key && !is_printable_char) {
    if (!buffer_.empty()) {
      is_timer_running_ = false;
      timer_.reset();
      SendKeyEvent();
    }

    return false;
  }

  if (!is_key_up) {
    if (is_timer_running_ && !buffer_.empty()) {
      is_timer_running_ = false;
      timer_.reset();

      std::set<uint32_t> buff = {keyval, *buffer_.begin()};

      auto it = NicolaKeymapUS.find(buff);

      if (it != NicolaKeymapUS.end()) {
        buffer_ = buff;
        SendKeyEvent();
      } else {
        SendKeyEvent();
        buffer_.insert(keyval);
        SetTimer();
      }
    } else {
      buffer_.clear();
      buffer_.insert(keyval);
      SetTimer();
    }
  }

  return true;
}

void Nicola::SendKeyEvent() {
  mozc::commands::KeyEvent event;
  event.Clear();
  if (Translate(event)) {
    FCITX_INFO() << "[Nicola Send] " << "key_code: " << event.key_code()
                 << "key_string: " << event.key_string();
  } else {
    for (uint32_t keyval : buffer_) {
      auto it = kSpecialKeyMap.find(keyval);
      if (it != kSpecialKeyMap.end()) {
        event.set_special_key(it->second);
      } else {
        event.set_key_code(keyval);
      }

      MozcSendKeyEvent(event);
      event.Clear();
    }

    buffer_.clear();
    return;
  }
  buffer_.clear();

  MozcSendKeyEvent(event);
}

void Nicola::MozcSendKeyEvent(mozc::commands::KeyEvent& event) {
  std::string error;
  mozc::commands::Output raw_response;
  if (!mozc_state_->TrySendKeyEvent(ic_, event, &raw_response, &error)) {
    FCITX_INFO() << "[Nicola] in Nicola::SendKeyEvent failed TrySendKeyEvent.";
    return;
  }

  mozc_state_->ParseResponse(raw_response);
}

bool Nicola::Translate(mozc::commands::KeyEvent& key_event) {
  auto it = NicolaKeymapUS.find(buffer_);

  if (it != NicolaKeymapUS.end()) {
    key_event.set_key_string(it->second);
    return true;
  }
  FCITX_INFO() << "[Nicola] Key combination not found in map";
  return false;
}

bool Nicola::TimeoutCallback() {
  if (!is_timer_running_) return false;

  is_timer_running_ = false;
  SendKeyEvent();
  return false;
}

void Nicola::SetTimer() {
  is_timer_running_ = true;
  uint64_t current_time = fcitx::now(CLOCK_MONOTONIC);

  timer_ = loop_.addTimeEvent(
      CLOCK_MONOTONIC, current_time + timeout_len_, 0,
      [this](fcitx::EventSourceTime* src, uint64_t usec) -> bool {
        TimeoutCallback();
        return false;
      });
}

}  // namespace Nicola
