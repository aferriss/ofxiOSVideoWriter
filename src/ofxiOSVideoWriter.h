//
//  ofxiOSVideoWriter.h
//  Created by Lukasz Karluk on 3/09/13.
//

#include "ofMain.h"
#include "VideoWriter.h"

class ofxiOSVideoWriter {
    
public:
    ofxiOSVideoWriter();
    ~ofxiOSVideoWriter();
    
    void setup(int videoWidth, int videoHeight);
    void setFPS(float fps);
    float getFPS();
    
    void update();
    void draw(float x=0, float y=0);
    
    void startRecording();
    void cancelRecording();
    void finishRecording();
    bool isRecording();
    int getRecordFrameNum();
    
    void begin();
    void end();
    
    VideoWriter * videoWriter;
    ofFbo fbo;
    ofFbo fboBGRA;
    ofShader shaderBGRA;

    float startTime;
    int startFrameNum;
    int recordFrameNum;
    float recordFPS;
    bool bLockToFPS;
};