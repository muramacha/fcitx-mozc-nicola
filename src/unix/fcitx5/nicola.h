#ifndef UNIX_FCITX5_FCITX_NICOLA_H_
#define UNIX_FCITX5_FCITX_NICOLA_H_

#include <Fcitx5/Core/fcitx/inputcontext.h>
#include <fcitx-utils/event.h>
#include <fcitx-utils/key.h>
#include <fcitx-utils/keysym.h>
#include <fcitx/inputcontext.h>
#include <fcitx/instance.h>

#include <cstdint>
#include <memory>
#include <set>
#include <string>
#include <utility>

#include "protocol/commands.pb.h"
#include "unix/fcitx5/mozc_client_interface.h"

namespace fcitx {
class MozcState;
}

namespace Nicola {
struct shift_key {
  fcitx::KeySym keysym;
  bool is_pritable;
};

class Nicola {
 public:
  fcitx::EventLoop& loop_;
  std::set<uint32_t> buffer_;
  std::unique_ptr<fcitx::EventSourceTime> timer_;
  shift_key right_shift, left_shift;
  bool is_timer_running_ = false;
  uint64_t timeout_len_ = 40000;
  fcitx::MozcState* mozc_state_;
  fcitx::InputContext* ic_;

  Nicola();
  Nicola(fcitx::MozcState* state, fcitx::EventLoop& loop,
         fcitx::InputContext* ic);

  void SetMozcState(fcitx::MozcState* state);

  // Return if KeyEvent was consumed.
  bool ProcessKeyEvent(fcitx::KeySym keyval, uint32_t keycode,
                       fcitx::KeyStates modifiers,
                       mozc::config::Config::PreeditMethod preedit_method,
                       bool layout_is_jp, bool is_key_up,
                       mozc::commands::KeyEvent* key);

  bool ProcessKeyEvent(fcitx::KeySym keyval, uint32_t keycode,
                       fcitx::KeyStates modifiers,
                       mozc::config::Config::PreeditMethod preedit_method,
                       bool layout_is_jp, bool is_key_up);

  void SetTimer();

  bool TimeoutCallback();

  bool Translate(mozc::commands::KeyEvent& key_event);

  // Make and send mozc::KeyEvent
  void SendKeyEvent();
  void SendKeyEvent(fcitx::KeySym keyval, uint32_t keycode,
                    fcitx::KeyStates modifiers,
                    mozc::config::Config::PreeditMethod preedit_method,
                    bool layout_is_jp, bool is_key_up,
                    mozc::commands::KeyEvent* key);

  void MozcSendKeyEvent(mozc::commands::KeyEvent& event);
};
}  // namespace Nicola

#endif
