
#include "../unique.definition_requirements.h"

void create_main_calculator(CTextStack *s){
    stack.text(s,"<DOCTYPE html>");
    CTextScope(s,CTEXT_HTML){
        CTextScope(s, CTEXT_HEAD){
            CTextScope_format(s, CTEXT_SCRIPT,"src='%s'",HYDRATION_SCRIPT_ROUTE){}

        }
        CTextScope(s,CTEXT_BODY){
            create_visor(s,"");
            create_numerical_button(s, 9);
            create_numerical_button(s, 8);
            create_numerical_button(s, 7);
            break_line(s);
            create_numerical_button(s, 6);
            create_numerical_button(s, 5);
            create_numerical_button(s, 4);
            break_line(s);
            create_numerical_button(s, 3);
            create_numerical_button(s, 2);
            create_numerical_button(s, 1);
            break_line(s);
            create_numerical_button(s, 0);

            create_operator_button(s,"+");
            create_operator_button(s,"-");
            create_operator_button(s,"x");
            create_operator_button(s,"/");

            CTextScope(s,CTEXT_BUTTON){
                stack.text(s,"=");
            }

            CTextScope(s,CTEXT_BUTTON){
                stack.text(s,"CLEAR");
            }

        }
    }
}
