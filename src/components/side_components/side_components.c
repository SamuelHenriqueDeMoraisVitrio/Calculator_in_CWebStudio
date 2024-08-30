
#include "../unique.definition_requirements.h"


void break_line(CTextStack *s){
    stack.text(s,"<br>");
}

void create_visor(CTextStack *s,const char *content){
    CTextScope_format(s,CTEXT_H5,"id='%s'",VISOR_ID){
        stack.text(s,content);
    }
}

void create_numerical_button(CTextStack *s,int num){
    CTextScope(s,CTEXT_BUTTON){
        stack.format(s,"%d", num);
    }
}

void create_operator_button(CTextStack *s,const char *operator){
    CTextScope(s,CTEXT_BUTTON){
        stack.text(s,operator);
    }
}
