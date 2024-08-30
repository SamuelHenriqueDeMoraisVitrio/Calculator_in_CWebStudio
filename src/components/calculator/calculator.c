
#include "../unique.definition_requirements.h"
#include <time.h>

void create_main_calculator(CTextStack *s,CWebHyDration *hydration){
    CWebHyDrationBridge *set_num = bridge.get_child_bridge(hydration,SET_NUM_BRIDGE);
    CWebHyDrationBridge *set_operator = bridge.get_child_bridge(hydration,SET_OPERATOR_BRIDGE);
    CWebHyDrationBridge *clear  = bridge.get_child_bridge(hydration,CLEAR_BRIDGE);
    CWebHyDrationBridge *set_result = bridge.get_child_bridge(hydration,SET_RESULT_BRIDGE);

    stack.text(s,"<DOCTYPE html>");
    CTextScope(s,CTEXT_HTML){
        CTextScope(s, CTEXT_HEAD){
            CTextScope_format(s, CTEXT_SCRIPT,"src='%s'",HYDRATION_SCRIPT_ROUTE){}

        }
        CTextScope(s,CTEXT_BODY){
            create_visor(s,"");
            create_numerical_button(s, 9,set_num);
            create_numerical_button(s, 8,set_num);
            create_numerical_button(s, 7,set_num);
            create_operator_button(s,"+",set_operator);
            break_line(s);
            create_numerical_button(s, 6,set_num);
            create_numerical_button(s, 5,set_num);
            create_numerical_button(s, 4,set_num);
            create_operator_button(s,"-",set_operator);
            break_line(s);
            create_numerical_button(s, 3,set_num);
            create_numerical_button(s, 2,set_num);
            create_numerical_button(s, 1,set_num);
            create_operator_button(s,"x",set_operator);
            break_line(s);
            create_numerical_button(s, 0,set_num);
            create_operator_button(s,"/",set_operator);
            CTextScope_format(s,CTEXT_BUTTON,"%s",bridge.onclick(set_result,NULL)){
                stack.text(s,"=");
            }

            CTextScope_format(s,CTEXT_BUTTON,"%s",bridge.onclick(clear,NULL)){
                stack.text(s,"CLEAR");
            }

        }
    }
}
