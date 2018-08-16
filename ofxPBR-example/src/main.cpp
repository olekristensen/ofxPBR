#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main() {
    ofGLWindowSettings settings;
    settings.setGLVersion(4, 1);
    settings.setSize(1080, 1920);
    ofCreateWindow(settings);
    ofRunApp(new ofApp());
}
