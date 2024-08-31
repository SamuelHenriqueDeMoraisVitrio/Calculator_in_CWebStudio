
#include "../unique.definition_requirements.h"

void create_main_calculator(CTextStack *s,CWebHyDration *hydration){
    CWebHyDrationBridge *set_num = bridge.get_child_bridge(hydration,SET_NUM_BRIDGE);
    CWebHyDrationBridge *set_operator = bridge.get_child_bridge(hydration,SET_OPERATOR_BRIDGE);
    CWebHyDrationBridge *clear  = bridge.get_child_bridge(hydration,CLEAR_BRIDGE);
    CWebHyDrationBridge *set_result = bridge.get_child_bridge(hydration,SET_RESULT_BRIDGE);

    stack.text(s,"<DOCTYPE html>");
    CTextScope_format(s,CTEXT_HTML, "lang='pt-BR'"){
        CTextScope(s, CTEXT_HEAD){
            stack.text(s, "<meta charset='UTF-8'>\n\
            <meta name='viewport' content='width=device-width, initial-scale=1.0'>\n\
            <title>Calculadora</title>\n\
            <link rel='stylesheet' href='/static/teste.css'>\
            ");
            CTextScope_format(s, CTEXT_SCRIPT,"src='%s'",HYDRATION_SCRIPT_ROUTE){}

        }
        CTextScope(s,CTEXT_BODY){
            CTextScope_format(s, CTEXT_DIV, "class='logo_c'"){
                stack.text(s, "<img src='/static/imgs/C.png' alt=\"Language 'C'\" class='logo'>");
            }
            CTextScope_format(s, CTEXT_DIV, "class='calculator'"){

                create_visor(s,"");

                CTextScope_format(s, CTEXT_DIV, "class='buttons'"){
                    create_numerical_button(s, 7, set_num);
                    create_numerical_button(s, 8, set_num);
                    create_numerical_button(s, 9, set_num);
                    create_numerical_button(s, 4, set_num);
                    create_numerical_button(s, 5, set_num);
                    create_numerical_button(s, 6, set_num);
                    create_numerical_button(s, 1, set_num);
                    create_numerical_button(s, 2, set_num);
                    create_numerical_button(s, 3, set_num);
                    create_numerical_button(s, 0, set_num);
                    CTextScope_format(s, CTEXT_BUTTON, "class='btn equals' %s", bridge.onclick(set_result,NULL)){
                        stack.text(s,"=");
                    }
                }
                CTextScope_format(s, CTEXT_DIV, "class='operators'"){
                    CTextScope_format(s,CTEXT_BUTTON,"%s class='btn clear'", bridge.onclick(clear,NULL)){
                        stack.text(s,"C");
                    }
                    create_operator_button(s,"/",set_operator);
                    create_operator_button(s,"*",set_operator);
                    create_operator_button(s,"-",set_operator);
                    create_operator_button(s,"+",set_operator);
                }

            }
            CTextScope_format(s, CTEXT_DIV, "class='copryth'"){
                CTextScope_format(s, CTEXT_A, "href='https://pt.wikipedia.org/wiki/Ken_Thompson' target='_blank' rel='noopener noreferrer'"){
                    stack.text(s, "<img src='/static/imgs/KenThompson.png' alt='Ken Thompson' class='copyright'>");
                }
            }
        }
    }
}



