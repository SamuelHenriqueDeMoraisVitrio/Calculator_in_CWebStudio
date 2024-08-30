

#include "../unique.definition_requirements.h"

void set_result_bridge_handler(CWebHyDrationBridge *set_num_bridge){

    double visor_number  =result.get_double_from_first_element_of_search(set_num_bridge,VISOR_ID);
    double first_num = result.get_double_from_first_element_of_search(set_num_bridge,FIRST_NUMBER);
    char *operator = result.get_string_from_first_element_of_search(set_num_bridge,OPERATOR);

    if(bridge.has_errors(set_num_bridge)){
        return;
    }

    double result = 0;
    if(strcmp(operator,"+") == 0){
        result  = visor_number + first_num;
    }
    if(strcmp(operator,"-") == 0){
        result  = visor_number - first_num;
    }

    if(strcmp(operator,"x") == 0){
        result  = visor_number * first_num;
    }
    if(strcmp(operator,"/") == 0){
        result  = visor_number / first_num;
    }
    CTextStack *result_number = bridge.create_empty_stack(set_num_bridge);
    stack.format(result_number,"%lf",result);

    CTextStack *visor_html = bridge.create_empty_stack(set_num_bridge);
    create_visor(visor_html, result_number->rendered_text);

    actions.replace_element_by_id(set_num_bridge,VISOR_ID,visor_html->rendered_text);


}

void create_set_result_bridge(CWebHyDration *hydration){
    CWebHyDrationBridge *set_result_bridge = bridge.create_bridge(
        hydration,
        SET_RESULT_BRIGE,
        set_result_bridge_handler
    );
    requirements.add_elements_by_id_setting_search_as_same_name(
        set_result_bridge,VISOR_ID
    );

    CWebHyDrationSearchRequirements *first_number = requirements.newSearchRequirements(
        set_result_bridge,
        FIRST_NUMBER
    );
    requirements.add_session_storage_item(first_number,FIRST_NUMBER);

    CWebHyDrationSearchRequirements *operator = requirements.newSearchRequirements(
        set_result_bridge,
        OPERATOR
    );
    requirements.add_session_storage_item(operator,OPERATOR);

}
