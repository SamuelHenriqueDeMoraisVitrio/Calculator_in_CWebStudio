#include "../unique.definition_requirements.h"

void set_operator_handler(CWebHyDrationBridge *set_operator_handler){

    char *visor_text  =result.get_string_from_first_element_of_search(set_operator_handler,VISOR_ID);
    char *operator = args.get_str_arg(set_operator_handler,0);

    if(bridge.has_errors(set_operator_handler)){
        return;
    }


    actions.set_session_storage_data(set_operator_handler,FIRST_NUMBER,visor_text);
    actions.set_session_storage_data(set_operator_handler,OPERATOR_NUMBER,operator);


    CTextStack *visor_html = bridge.create_empty_stack(set_operator_handler);
    create_visor(visor_html, "");
    actions.replace_element_by_id(set_operator_handler,VISOR_ID,visor_html->rendered_text);


}

void create_set_operator_bridge(CWebHyDration *hydration){
    CWebHyDrationBridge *set_operator_bridge = bridge.create_bridge(
        hydration,
        SET_OPERATOR_BRIDGE,
        set_operator_handler
    );

    requirements.add_elements_by_id_setting_search_as_same_name_not_auto_converting(
        set_operator_bridge,
        VISOR_ID
    );
}
