//
//  ofxTextButton.h
//
//  Created by Drunkar on 20-07-17.
//
//

#pragma once

#include "ofxGuiSimple.h"

class ofxTextButton : public ofxBaseGui{
public:
	ofxTextButton(){};
	~ofxTextButton();
	ofxTextButton * setup(const std::string& labelName, bool _bVal);


	virtual bool mouseMoved(ofMouseEventArgs & args);
	virtual bool mousePressed(ofMouseEventArgs & args);
	virtual bool mouseDragged(ofMouseEventArgs & args);
	virtual bool mouseReleased(ofMouseEventArgs & args);
	virtual bool mouseScrolled(ofMouseEventArgs & args){return false;}


	template<class ListenerClass, typename ListenerMethod>
	void addListener(ListenerClass * listener, ListenerMethod method){
		value.addListener(listener,method);
	}

	template<class ListenerClass, typename ListenerMethod>
	void removeListener(ListenerClass * listener, ListenerMethod method){
		value.removeListener(listener,method);
	}

	bool operator=(const bool v);
	bool operator==(const bool v);
	operator const bool & ();

	virtual ofAbstractParameter & getParameter();

protected:
	virtual void render();
	ofParameter<bool> value;
	bool bGuiActive;

	bool setValue(float mx, float my, bool bActive);
	void generateDraw();
	void valueChanged(bool & value);
	ofPath bg,fg;
	ofVboMesh textMesh;
};
