#include "../unique.definition_requirements.h"

void clear_bridge_handler(CWebHyDrationBridge *clear_bridge){

    actions.remove_session_storage_data(clear_bridge, FIRST_NUMBER);
    actions.remove_session_storage_data(clear_bridge, OPERATOR);

    CTextStack *visor_html = bridge.create_empty_stack(clear_bridge);
    create_visor(visor_html, NULL);
    actions.replace_element_by_id(clear_bridge,VISOR_ID,visor_html->rendered_text);

}

void create_clear_bridge(CWebHyDration *hydration){
    CWebHyDrationBridge *set_operator_bridge = bridge.create_bridge(
        hydration,
        CLEAR_BRIDGE,
        clear_bridge_handler
    );
}
