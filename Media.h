#pragma once
class Media {
public:
	virtual void display();
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