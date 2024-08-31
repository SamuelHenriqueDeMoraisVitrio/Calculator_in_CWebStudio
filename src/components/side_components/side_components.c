
#include "../unique.definition_requirements.h"


void create_visor(CTextStack *s,const char *content){
    CTextScope_format(s, CTEXT_DIV,"class='display' id='%s'",VISOR_ID){
        /*
        if(content){
            CTextScope(s,CTEXT_H5){
                stack.text(s,content);
            }
            break_line(s);
        }
        */
        stack.text(s, content);
    }
}


void create_numerical_button(CTextStack *s,int num,CWebHyDrationBridge *set_num){
    CTextScope_format(s,CTEXT_BUTTON,"class='btn number' %s",bridge.onclick(set_num,"'%d'",num)){
        stack.format(s,"%d",num);
    }
}

void create_operator_button(CTextStack *s,const char *operator_text,CWebHyDrationBridge *set_operator){
    CTextScope_format(s, CTEXT_BUTTON, "class='btn operator' %s", bridge.onclick(set_operator,"'%s'",operator_text)){
        stack.text(s,operator_text);
    }
}




