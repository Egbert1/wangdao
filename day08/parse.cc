#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <map>
#include "tinyxml2.h"

using namespace std;
using namespace tinyxml2;

void read_tiny(){
    XMLDocument doc;
    doc.LoadFile("shell.xml");
    doc.Print();
}

void getFirstElement(){
    XMLDocument doc;
    doc.LoadFile("shell.xml");

    XMLElement *scene = doc.RootElement();
    XMLElement *surface = scene->FirstChildElement("node");

    while(surface){
        XMLElement *surfaceChild = surface -> FirstChildElement();
        const char * content;
        const XMLAttribute * attributeOfSurface = surface -> FirstAttribute();
        cout << attributeOfSurface->Name() << ":" << attributeOfSurface->Value() << endl;
        while(surfaceChild){
            content = surfaceChild -> GetText();
            surfaceChild = surfaceChild -> NextSiblingElement();
            cout << content << endl;
        }
        surface = surface -> NextSiblingElement();
    }
}


int main()
{
    getFirstElement();
    return 0;
}

