
#include "../unique.definition_requirements.h"


void break_line(CTextStack *s){
    stack.text(s,"<br>");
}

void create_visor(CTextStack *s,const char *content){
    CTextScope_format(s, CTEXT_DIV,"id='%s'",VISOR_ID){
        if(content){
            CTextScope(s,CTEXT_H5){
                stack.text(s,content);
            }
            break_line(s);
        }
    }
}


void create_numerical_button(CTextStack *s,int num,CWebHyDrationBridge *set_num){
    CTextScope_format(s,CTEXT_BUTTON,"%s",bridge.onclick(set_num,"'%d'",num)){
        stack.format(s,"%d",num);
    }
}

void create_operator_button(CTextStack *s,const char *operator_text,CWebHyDrationBridge *set_operator){
    CTextScope_format(s,CTEXT_BUTTON,"%s",
        bridge.onclick(set_operator,"'%s'",operator_text)){
        stack.text(s,operator_text);
    }
}
