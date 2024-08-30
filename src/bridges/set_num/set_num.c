#include "../unique.definition_requirements.h"

void set_num_bridge_handler(CWebHyDrationBridge *set_num_bridge){

    char *visor_text  =result.get_string_from_first_element_of_search(set_num_bridge,VISOR_ID);
    char *num_to_concat = args.get_str_arg(set_num_bridge,0);


    if(bridge.has_errors(set_num_bridge)){
        return;
    }
    CTextStack *new_number = bridge.create_empty_stack(set_num_bridge);
    stack.format(new_number,"%s%s",visor_text,num_to_concat);
    stack.self_replace(new_number,"\n","");
    stack.self_replace(new_number," ","");

    if(strlen(new_number->rendered_text) > 10){
        return;
    }



    CTextStack *visor_html = bridge.create_empty_stack(set_num_bridge);
    create_visor(visor_html, new_number->rendered_text);

    actions.replace_element_by_id(set_num_bridge,VISOR_ID,visor_html->rendered_text);


}

void create_set_num_bridge(CWebHyDration *hydration){
    CWebHyDrationBridge *set_num_bridge = bridge.create_bridge(
        hydration,
        SET_NUM_BRIDGE,
        set_num_bridge_handler
    );
    requirements.add_elements_by_id_setting_search_as_same_name_not_auto_converting(set_num_bridge,VISOR_ID);
}
