//
//  ofxImageButton.cpp
//
//  Created by Drunkar on 20-07-17.
//
//

#include "ofxImageButton.h"
using namespace std;

ofxImageButton::~ofxImageButton(){
	value.removeListener(this,&ofxImageButton::valueChanged);
}

ofxImageButton * ofxImageButton::setup(std::string _imgPath, bool _bVal, float width, float height){
	b.x = 0;
	b.y = 0;
	b.width = width;
	b.height = height;
	bGuiActive = false;
	value = _bVal;
	alpha = 255;

	img.loadImage(_imgPath);
	value.addListener(this, &ofxImageButton::valueChanged);
	registerMouseEvents();
	setNeedsRedraw();

	return this;
}


bool ofxImageButton::mouseMoved(ofMouseEventArgs & args){
	if(isGuiDrawing() && b.inside(ofPoint(args.x,args.y))){
		return true;
	}else{
		return false;
	}
}

bool ofxImageButton::mousePressed(ofMouseEventArgs & args){
	if(setValue(args.x, args.y, true)){
		alpha = 200;
		return true;
	}else{
		return false;
	}
}

bool ofxImageButton::mouseDragged(ofMouseEventArgs & args){
	if(bGuiActive && b.inside(ofPoint(args.x,args.y))){
		alpha = 200;
		return true;
	}else{
		return false;
	}
}

bool ofxImageButton::mouseReleased(ofMouseEventArgs & args){
	alpha = 255;
	bool wasGuiActive = bGuiActive;
	bGuiActive = false;
	if(wasGuiActive && b.inside(ofPoint(args.x,args.y))){
		return true;
	}else{
		return false;
	}
}

void ofxImageButton::generateDraw(){
	bg.clear();
	bg.setFillColor(thisBackgroundColor);
	bg.rectangle(b);

	fg.clear();
}

void ofxImageButton::render(){
	bg.draw();
	fg.draw();

	ofColor c = ofGetStyle().color;
	ofBlendMode blendMode = ofGetStyle().blendingMode;
	if(blendMode!=OF_BLENDMODE_ALPHA){
		ofEnableAlphaBlending();
	}
	ofSetColor(thisTextColor, alpha);

	img.draw(b);

	ofSetColor(c);
	if(blendMode!=OF_BLENDMODE_ALPHA){
		ofEnableBlendMode(blendMode);
	}
}

bool ofxImageButton::operator=(const bool v){
	value = v;
	return v;
}

bool ofxImageButton::operator==(const bool v) {
	return value == v;
}

ofxImageButton::operator const bool & (){
	return value;
}

bool ofxImageButton::setValue(float mx, float my, bool bActive){

	if( !isGuiDrawing() ){
		bGuiActive = false;
		return false;
	}
	if( bActive ){

		if( b.inside(mx, my) ){
			bGuiActive = true;
		}else{
			bGuiActive = false;
		}

	}
	if( bGuiActive ){
		value = true;
		return true;
	}
	return false;
}

ofAbstractParameter & ofxImageButton::getParameter(){
	return value;
}

void ofxImageButton::valueChanged(bool & value){
    setNeedsRedraw();
}

void ofxImageButton::setImage(const std::string imgPath) {
	img.loadImage(imgPath);
}