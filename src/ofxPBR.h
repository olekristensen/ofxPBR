#pragma once
#include "ofMain.h"
#include "ofxPBRCubeMap.h"
#include "ofxPBRLight.h"
#include "ofxPBRShadow.h"
#include "ofxPBROmniShadow.h"
#include "ofxPBRMaterial.h"
#include "shaders/environment.h"
#include "shaders/pbr.h"
#include "shaders/depthThumbnail.h"

class ofxPBR{
public:
    ofxPBR();
    
	void setup(ofCamera* camera, function<void()> scene, int depthMapResolution);
    void begin(ofShader * shader = nullptr, ofCamera * camera = nullptr);
    void end();
    
	void setCubeMap(ofxPBRCubeMap * cubeMap);
	void enableCubeMap(bool enable);
	bool isCubeMapEnable();
    void drawEnvironment(ofCamera * camera = nullptr);
    void resizeDepthMap(int resolution);
    int getDepthMapResolution();
	void updateDepthMaps();
	void addLight(ofxPBRLight* light);
	void removeLight(int index);
    void setEnvShader(ofShader* shader);
    ofShader* getShader();
    ofTexture* getDepthMap(int index);
    
private:
	void setNumLights(int numLights);
    
    void beginPBR(ofCamera * camera);
    void endPBR();
    
    void beginDepthMap(int index);
    void endDepthMap();

	void beginDepthCubeMap(int index, int face);
	void endDepthCubeMap();

    ofxPBRShadow shadow;
	ofxPBROmniShadow omniShadow;
    ofShader* PBRShader;
    ofMesh sphereMesh;
    ofxPBRCubeMap* cubeMap;
    vector<ofMatrix4x4> shadowMatrix;
	
	enum RenderMode {
		Mode_PBR = 0,
		Mode_Shadow = 1,
		Mode_OmniShadow = 2,
		num_Mode = 3
	};
	RenderMode renderMode;

	vector<ofxPBRLight*> lights;
	vector<ofxPBRLight*> normalLights;
	vector<ofxPBRLight*> pointLights;
	bool enableCubemap;
    
    ofShader* envShader;
    Environment environment;
    ofShader defaultShader;
    PBR pbr;
    
    int lightIndex = 0;
	int pointLightIndex = 0;
	int faceIndex = 0;

	vector<ofMatrix4x4> lightViewProjMatrix;
    
    DepthThumbnail depthThumbnail;
    ofFbo depthThumbnailFbo;
    ofShader depthThumbnailShader;
	ofCamera* camera;

	function<void()> scene;
};