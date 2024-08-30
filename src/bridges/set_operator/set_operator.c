#include "../unique.definition_requirements.h"
#include <time.h>

void set_operator_handler(CWebHyDrationBridge *set_operator_bridge){

    char *visor_text  =result.get_string_from_first_element_of_search(set_operator_bridge,VISOR_ID);
    char *operator = args.get_str_arg(set_operator_bridge,0);

    if(bridge.has_errors(set_operator_bridge)){
        return;
    }

    CTextStack *formated_visor = bridge.create_empty_stack(set_operator_bridge);
    stack.text(formated_visor,visor_text);
    stack.self_replace(formated_visor,"\n","");
    stack.self_replace(formated_visor," ","");


    actions.set_session_storage_data(set_operator_bridge,FIRST_NUMBER,formated_visor->rendered_text);

    actions.set_session_storage_data(set_operator_bridge,OPERATOR,operator);


    CTextStack *visor_html = bridge.create_empty_stack(set_operator_bridge);
    create_visor(visor_html, NULL);
    actions.replace_element_by_id(set_operator_bridge,VISOR_ID,visor_html->rendered_text);


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
