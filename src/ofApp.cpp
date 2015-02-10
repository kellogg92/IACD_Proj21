#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(0);
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    cam.setFov(80);
    cam.setDistance(600);
	cam.setAspectRatio((float)ofGetWidth()/ofGetHeight());
    
    // ofxVboParticles([max particle number], [particle size]);
    vboPartciles = new ofxVboParticles(20000, 1000);

    // set friction (0.0 - 1.0);
    vboPartciles->friction = 0.001;
    
    particlePosition = ofVec3f(0, 0, 0);
	post.init(ofGetWidth(), ofGetHeight());
	post.createPass<GodRaysPass>();
	post.createPass<BloomPass>();
	//post.createPass<ToonPass>();

}

//--------------------------------------------------------------
void ofApp::update(){
	particlePosition.z = sin(ofGetElapsedTimef()) * 400;
    particlePosition.x  = cos(ofGetElapsedTimef()) * 400;
    particlePosition.y  = sin(ofGetElapsedTimef() / 2.0) * 100;


    for (int i = 0; i < 40; i++) {
        ofVec3f position = particlePosition;
        ofVec3f velocity = ofVec3f(ofRandom(-1, 1), ofRandom(-1, 1), ofRandom(-1, 1));
        ofColor color;
        color.setHsb(ofRandom(60, 160), 100, 200);
        
        // add a particle
        vboPartciles->addParticle(position, velocity, color);
    }

    vboPartciles->update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	
	post.begin();
	ofBackgroundGradient(ofColor(64,64,100,255), ofColor(0), OF_GRADIENT_CIRCULAR);
    
	
    cam.begin();
	ofColor(1.0f);
	ofSphere(ofPoint(0.0f, 0.0f, 100.0f), 100.0f);
    ofRotate(ofGetElapsedTimef() * 10, 0, 1, 1);
    vboPartciles->draw();
	cam.end();
	post.end();
    
    ofSetColor(255);
    //ofDrawBitmapString(ofToString(ofGetFrameRate(), 4) + "fps", 10, 20);
    //ofDrawBitmapString("particle num = " + ofToString(vboPartciles->numParticles, 0), 10, 35);
    //ofDrawBitmapString("[f] key : toggle fullscreen", 10, 50);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == 'f'){
		ofToggleFullscreen();
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
	cam.setAspectRatio((float)ofGetWidth()/ofGetHeight());
	post.init();
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
