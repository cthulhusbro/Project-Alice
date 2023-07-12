#pragma once
#include "dcon_generated.hpp"
#include "container_types.hpp"
#include "text.hpp"

namespace ai {

void update_ai_general_status(sys::state& state);
void form_alliances(sys::state& state);
bool ai_will_accept_alliance(sys::state& state, dcon::nation_id target, dcon::nation_id from);
void explain_ai_alliance_reasons(sys::state& state, dcon::nation_id target, text::layout_base& contents, int32_t indent);

}