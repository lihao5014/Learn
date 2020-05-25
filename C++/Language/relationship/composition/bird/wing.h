#ifndef _WING_H
#define _WING_H

class Wing
{
public:
	Wing(const string& feature):feature(feature){}
	Wing(const Wing& other):feature(other.feature){}
	
	void operator =(const Wing& other){feature = other.feature;}
	Wing operator =(const char* feature){this->feature = feature;return *this;}
	
	void display()const{cout<<"wing feature ="<<feature<<endl;}
private:
	string feature;
};

#endif //_WING_H