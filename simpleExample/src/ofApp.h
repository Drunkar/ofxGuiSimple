#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "ofxGuiSimple.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		// color
		ofColor c_black;
		ofColor c_white;
		ofColor c_disabled;
		ofColor c_milky_white;
		ofColor c_transparent_gray;
		ofColor c_transparent;
		ofColor c_main;
		ofColor c_background;
		bool is_white_theme;

		// gui
		ofxTextButton gui_button_a;
		ofxTextButton gui_button_b;
		ofxImageButton gui_button_flash_1;
		ofxImageButton gui_button_flash_2;
		ofxImageButton* p_gui_button_flash_2;
		ofxDropDown gui_image_list;
		std::vector<std::string> gui_images;
		int body_margin_left;

		// gui event
		void button_a_change(bool & value);
		void button_b_change(bool & value);
		void button_flash_1_change(bool & value);
		void button_flash_2_change(bool & value);
		void dropdown_image_change(unsigned int & value);

		// image
		std::string main_image_prefix;
		ofImage main_image;
		uint8_t alpha_main_image_overlay1;
		ofImage main_image_overlay1;
		uint8_t alpha_main_image_overlay2;
		ofImage main_image_overlay2;
		
};
