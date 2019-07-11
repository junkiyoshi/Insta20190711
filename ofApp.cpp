#include "ofApp.h"	

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openFrameworks");

	ofBackground(239);
	ofSetLineWidth(2);
	ofEnableDepthTest();
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();

	auto r = 100;
	auto R = 300;
	auto v_span = 20;
	auto u_span = 20;
	for (auto v = 0; v < 360; v += v_span) {

		auto u_start = ofMap(ofNoise(ofRandom(1000), ofGetFrameNum() * 0.005), 0, 1, -180, 180);
		for (auto u = u_start; u < u_start + 360; u += u_span) {

			v % 40 == 0 ? ofSetColor(239) : ofSetColor(39);
			ofFill();

			ofBeginShape();
			ofVertex(this->make_point(R, r, u - v_span * 0.5 - 0.2, v - u_span * 0.3 - 0.1));
			ofVertex(this->make_point(R, r, u + v_span * 0.5 - 0.2, v - u_span * 0.3 - 0.1));
			ofVertex(this->make_point(R, r, u + v_span * 0.5 - 0.2, v + u_span * 0.3 - 0.1));
			ofVertex(this->make_point(R, r, u - v_span * 0.5 - 0.2, v + u_span * 0.3 - 0.1));
			ofEndShape(true);

			v % 40 == 0 ? ofSetColor(39) : ofSetColor(239);
			ofNoFill();

			ofBeginShape();
			ofVertex(this->make_point(R, r, u - v_span * 0.5 + 0.2, v - u_span * 0.3 + 0.1));
			ofVertex(this->make_point(R, r, u + v_span * 0.5 + 0.2, v - u_span * 0.3 + 0.1));
			ofVertex(this->make_point(R, r, u + v_span * 0.5 + 0.2, v + u_span * 0.3 + 0.1));
			ofVertex(this->make_point(R, r, u - v_span * 0.5 + 0.2, v + u_span * 0.3 + 0.1));
			ofEndShape(true);
		}
	}

	this->cam.end();
}

//--------------------------------------------------------------
glm::vec3 ofApp::make_point(float R, float r, float u, float v) {

	// 数学デッサン教室 描いて楽しむ数学たち　P.31

	u *= DEG_TO_RAD;
	v *= DEG_TO_RAD;

	auto x = (R + r * cos(u)) * cos(v);
	auto y = (R + r * cos(u)) * sin(v);
	auto z = r * sin(u);

	return glm::vec3(x, y, z);
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}