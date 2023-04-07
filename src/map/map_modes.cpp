#include "map_modes.hpp"

#include "color.hpp"
#include "demographics.hpp"
#include "system_state.hpp"
#include "dcon_generated.hpp"
#include "province.hpp"
#include "nations.hpp"
#include <unordered_map>

#include "modes/political.hpp"
#include "modes/supply.hpp"
#include "modes/region.hpp"
#include "modes/nationality.hpp"
#include "modes/population.hpp"
#include "modes/sphere.hpp"
#include "modes/diplomatic.hpp"
#include "modes/rank.hpp"
#include "modes/relation.hpp"
#include "modes/recruitment.hpp"
#include "modes/civilization_level.hpp"
#include "modes/migration.hpp"
#include "modes/infrastructure.hpp"
#include "modes/revolt.hpp"
#include "modes/party_loyalty.hpp"

namespace map_mode {

void set_map_mode(sys::state& state, mode mode) {
	std::vector<uint32_t> prov_color;

	switch(mode) {
		case mode::terrain:
			state.map_display.set_terrain_map_mode();
			return;
		case mode::political:
			prov_color = political_map_from(state);
			break;
		case mode::region:
			prov_color = region_map_from(state);
			break;
		case mode::population:
			prov_color = population_map_from(state);
			break;
		case mode::nationality:
			prov_color = nationality_map_from(state);
			break;
		case mode::sphere:
			prov_color = sphere_map_from(state);
			break;
		case mode::diplomatic:
			prov_color = diplomatic_map_from(state);
			break;
		case mode::rank:
			prov_color = rank_map_from(state);
			break;
		case mode::recruitment:
			prov_color = recruitment_map_from(state);
			break;
		case mode::supply:
			prov_color = supply_map_from(state);
			break;
		case mode::relation:
			prov_color = relation_map_from(state);
			break;
		case mode::civilization_level:
			prov_color = civilization_level_map_from(state);
			break;
		case mode::migration:
			prov_color = migration_map_from(state);
			break;
		case mode::infrastructure:
			prov_color = infrastructure_map_from(state);
			break;
		case mode::revolt:
			prov_color = revolt_map_from(state);
			break;
		case mode::party_loyalty:
			prov_color = party_loyalty_map_from(state);
			break;
		default:
			return;
	}
	state.map_display.set_province_color(prov_color, mode);
}

void update_map_mode(sys::state& state) {
	if(state.map_display.active_map_mode == mode::terrain || state.map_display.active_map_mode == mode::region) {
		return;
	}
	set_map_mode(state, state.map_display.active_map_mode);
}
}
