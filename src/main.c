#define DEBUG
#include "definition.c"
#include "dependencies/CWebStudio.h"
#include <string.h>


CwebHttpResponse *main_sever(CwebHttpRequest *request ){

    CWebHyDration *hydration = cweb.hydration.newCWebHyDration(request);
    create_clear_bridge(hydration);
    create_set_num_bridge(hydration);
    create_set_operator_bridge(hydration);
    create_set_result_bridge(hydration);

    if(cweb.hydration.is_the_trigger(hydration)){
        return cweb.hydration.generate_response(hydration);
    }

    if(strcmp(request->route,HYDRATION_SCRIPT_ROUTE) ==0){
        return cweb.response.send_text(cweb.hydration.create_script(hydration),200);
    }

    CTextStack *s = cweb.request.create_stack(request);
    create_main_calculator(s);
    return cweb.response.send_rendered_CTextStack(s,200);

}

int main(int argc, char *argv[]){
    //initializing namespaes
    cweb = newCwebNamespace();
    stack  = newCTextStackModule();
    bridge = cweb.hydration.bridge;
    requirements = cweb.hydration.search_requirements;
    result = cweb.hydration.search_result;
    args = cweb.hydration.args;
    actions = cweb.hydration.actions;
    #ifdef DEBUG
        for(int i =3000;i < 4000;i++){
            struct CwebServer server = newCwebSever(i, main_sever);
            server.single_process  = true;
            bool error = cweb.server.start(&server);
            if(!error){
                break;
            }
        }
    #endif
    return 0;
}
