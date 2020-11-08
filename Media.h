#pragma once
class Media {
public:
	// Define display as pure virtual
	virtual void display() = 0;
};


class Photo : public Media {
public:
	void display();
};

class Audio : public Media {
public:
	void display();
};

class Video : public Media {
public:
	void display();
};