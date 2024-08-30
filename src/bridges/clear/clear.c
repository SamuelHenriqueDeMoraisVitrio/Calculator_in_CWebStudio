#include "../unique.definition_requirements.h"
#include <time.h>

void clear_bridge_handler(CWebHyDrationBridge *set_operator_handler){

    actions.execute_script(set_operator_handler,
        "sessionStorage.removeItem('%s')",
        OPERATOR
        );

    actions.execute_script(set_operator_handler,
        "sessionStorage.removeItem('%s')",
        FIRST_NUMBER
    );

    CTextStack *visor_html = bridge.create_empty_stack(set_operator_handler);
    create_visor(visor_html, NULL);
    actions.replace_element_by_id(set_operator_handler,VISOR_ID,visor_html->rendered_text);

}

void create_clear_bridge(CWebHyDration *hydration){
    CWebHyDrationBridge *set_operator_bridge = bridge.create_bridge(
        hydration,
        CLEAR_BRIDGE,
        clear_bridge_handler
    );
}
