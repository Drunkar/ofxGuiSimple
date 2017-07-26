#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(30);

	// color
	c_white = ofColor(245, 245, 245);
	c_black = ofColor(25, 25, 25);
	c_disabled = ofColor(116, 116, 116);
	c_milky_white = ofColor(245, 245, 245, 200);
	c_transparent_gray = ofColor(25, 25, 25, 200);
	c_transparent = ofColor(0, 0, 0, 0);
	c_main = c_black;
	c_background = c_white;
	is_white_theme = true;

	// gui
	body_margin_left = 100;

	gui_button_a.setup("white", true);
	gui_button_a.setPosition(body_margin_left, 32);
	gui_button_a.setBackgroundColor(c_transparent);
	gui_button_a.setTextColor(c_main);

	gui_button_b.setup("dark", true);
	gui_button_b.setPosition(body_margin_left + 100, 32);
	gui_button_b.setBackgroundColor(c_transparent);
	gui_button_b.setTextColor(c_disabled);

	gui_button_flash_1.setup("flash_black.png", false, 64, 64);
	gui_button_flash_1.setPosition(body_margin_left + 500, body_margin_left + 100);
	gui_button_flash_1.setBackgroundColor(c_transparent);
	gui_button_flash_2.setup("flash_black.png", false, 64, 64);
	gui_button_flash_2.setPosition(body_margin_left + 500, body_margin_left + 100 + 150);
	gui_button_flash_2.setBackgroundColor(c_transparent);

	gui_images = {"hourglass", "gender"};
	gui_image_list.setup(gui_images, 17, 200, 24);
	gui_image_list.setPosition(body_margin_left + 330, 32);
	gui_image_list.setBackgroundColor(c_milky_white);
	gui_image_list.setTextColor(c_main);

	// gui event
	gui_button_a.addListener(this, &ofApp::button_a_change);
	gui_button_b.addListener(this, &ofApp::button_b_change);
	gui_button_flash_1.addListener(this, &ofApp::button_flash_1_change);
	gui_button_flash_2.addListener(this, &ofApp::button_flash_2_change);
	gui_image_list.addListener(this, &ofApp::dropdown_image_change);


	// image
	main_image_prefix = "hourglass";
	main_image.load(main_image_prefix + "_black.png");
	main_image_overlay1.load(main_image_prefix + "_black_1.png");
	alpha_main_image_overlay1 = 0;
	main_image_overlay2.load(main_image_prefix + "_black_2.png");
	alpha_main_image_overlay2 = 0;

}

//--------------------------------------------------------------
void ofApp::update(){
	if (alpha_main_image_overlay1 > 5)
		alpha_main_image_overlay1 -= 5;
	else
		alpha_main_image_overlay1 = 0;

	if (alpha_main_image_overlay2 > 5)
		alpha_main_image_overlay2 -= 5;
	else
		alpha_main_image_overlay2 = 0;
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetBackgroundColor(c_background);

	gui_button_a.draw();
	gui_button_b.draw();
	gui_image_list.draw();
	gui_button_flash_1.draw();
	gui_button_flash_2.draw();

	main_image.draw(body_margin_left + 50, 150, 300, 300);

	ofPushStyle();
	ofSetColor(c_background, alpha_main_image_overlay1);
	ofDrawRectangle(body_margin_left + 50, 150, 300, 300);
	ofSetColor(255, 255, 255, alpha_main_image_overlay1);
	main_image_overlay1.draw(body_margin_left + 50, 150, 300, 300);
	ofPopStyle();

	ofPushStyle();
	ofSetColor(c_background, alpha_main_image_overlay2);
	ofDrawRectangle(body_margin_left + 50, 150, 300, 300);
	ofSetColor(255, 255, 255, alpha_main_image_overlay2);
	main_image_overlay2.draw(body_margin_left + 50, 150, 300, 300);
	ofPopStyle();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

//--------------------------------------------------------------
void ofApp::button_a_change(bool & value) {
	is_white_theme = true;
	c_main = c_black;
	c_background = c_white;
	gui_button_a.setTextColor(c_main);
	gui_button_b.setTextColor(c_disabled);
	gui_image_list.setBackgroundColor(c_milky_white);
	gui_image_list.setTextColor(c_main);
	gui_button_flash_1.setImage("flash_black.png");
	gui_button_flash_2.setImage("flash_black.png");

	std::string img = main_image_prefix;
	if (is_white_theme)
		img += "_black";

	main_image.load(img + ".png");
	main_image_overlay1.load(img + "_1.png");
	main_image_overlay2.load(img + "_2.png");
}

//--------------------------------------------------------------
void ofApp::button_b_change(bool & value) {
	is_white_theme = false;
	c_main = c_white;
	c_background = c_black;
	gui_button_a.setTextColor(c_disabled);
	gui_button_b.setTextColor(c_main);
	gui_image_list.setBackgroundColor(c_transparent_gray);
	gui_image_list.setTextColor(c_main);
	gui_button_flash_1.setImage("flash.png");
	gui_button_flash_2.setImage("flash.png");

	std::string img = main_image_prefix;
	if (is_white_theme)
		img += "_black";

	main_image.load(img + ".png");
	main_image_overlay1.load(img + "_1.png");
	main_image_overlay2.load(img + "_2.png");
}

//--------------------------------------------------------------
void ofApp::button_flash_1_change(bool & value) {
	alpha_main_image_overlay1 = 255;
}

//--------------------------------------------------------------
void ofApp::button_flash_2_change(bool & value) {
	alpha_main_image_overlay2 = 255;
}

//--------------------------------------------------------------
void ofApp::dropdown_image_change(unsigned int & value) {
	main_image_prefix = gui_images[value];

	std::string img = main_image_prefix;
	if (is_white_theme)
		img += "_black";

	main_image.load(img + ".png");
	main_image_overlay1.load(img + "_1.png");
	main_image_overlay2.load(img + "_2.png");
}