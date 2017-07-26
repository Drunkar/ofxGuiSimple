//
//  ofxTextButton.cpp
//
//  Created by Drunkar on 20-07-17.
//
//

#include "ofxTextButton.h"
#include "ofGraphics.h"
using namespace std;

ofxTextButton::~ofxTextButton(){
	value.removeListener(this,&ofxTextButton::valueChanged);
}

ofxTextButton * ofxTextButton::setup(const std::string& labelName, bool _bVal){
	value.set(labelName, _bVal);
	b = getTextBoundingBox(labelName, 0, 0);
	b.x = 0;
	b.y = 0;
	bGuiActive = false;
	value.makeReferenceTo(value);

	value.addListener(this, &ofxTextButton::valueChanged);
	registerMouseEvents();
	setNeedsRedraw();

	return this;
}


bool ofxTextButton::mouseMoved(ofMouseEventArgs & args){
	if(isGuiDrawing() && b.inside(ofPoint(args.x,args.y))){
		return true;
	}else{
		return false;
	}
}

bool ofxTextButton::mousePressed(ofMouseEventArgs & args){
	if(setValue(args.x, args.y, true)){
		return true;
	}else{
		return false;
	}
}

bool ofxTextButton::mouseDragged(ofMouseEventArgs & args){
	if(bGuiActive && b.inside(ofPoint(args.x,args.y))){
		return true;
	}else{
		return false;
	}
}

bool ofxTextButton::mouseReleased(ofMouseEventArgs & args){
	bool wasGuiActive = bGuiActive;
	bGuiActive = false;
	if(wasGuiActive && b.inside(ofPoint(args.x,args.y))){
		return true;
	}else{
		return false;
	}
}

void ofxTextButton::generateDraw(){
	bg.clear();
	bg.setFillColor(thisBackgroundColor);
	bg.rectangle(b);

	fg.clear();
	textMesh = getTextMesh(getName(), b.x+textPadding, b.y+b.height / 2 + 4);
}

void ofxTextButton::render(){
	bg.draw();
	fg.draw();

	ofColor c = ofGetStyle().color;
	ofBlendMode blendMode = ofGetStyle().blendingMode;
	if(blendMode!=OF_BLENDMODE_ALPHA){
		ofEnableAlphaBlending();
	}
	ofSetColor(thisTextColor);

	bindFontTexture();
	textMesh.draw();
	unbindFontTexture();

	ofSetColor(c);
	if(blendMode!=OF_BLENDMODE_ALPHA){
		ofEnableBlendMode(blendMode);
	}
}

bool ofxTextButton::operator=(const bool v){
	value = v;
	return v;
}

bool ofxTextButton::operator==(const bool v) {
	return value == v;
}

ofxTextButton::operator const bool & (){
	return value;
}

bool ofxTextButton::setValue(float mx, float my, bool bActive){

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

ofAbstractParameter & ofxTextButton::getParameter(){
	return value;
}

void ofxTextButton::valueChanged(bool & value){
    setNeedsRedraw();
}
