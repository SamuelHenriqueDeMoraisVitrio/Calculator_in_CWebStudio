
#include "definition.c"
#include "dependencies/CWebStudio.h"
#include <string.h>


CwebHttpResponse *main_sever(CwebHttpRequest *request ){

    CWebHyDration *hydration = cweb.hydration.newCWebHyDration(request);
    if(cweb.hydration.is_the_trigger(hydration)){
        return cweb.hydration.generate_response(hydration);
    }

    if(strcmp(request->route,HYDRATION_SCRIPT_ROUTE)){
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

    struct CwebServer server = newCwebSever(5000, main_sever);
    cweb.server.start(&server);
    return 0;
}
