// BStringClass
// A Simple custom String Class for C++ version 1.0.1

#include <iostream>
#include <ostream>
using namespace std;

class BStringClass{
private:
	//Buffer to hold our string data
	char *buff = nullptr;
	//Size of buffer
	unsigned int size = 0;

	void _clean(){
		//Clear up buffer
		if (buff != nullptr){
			memset(buff, 0, sizeof buff);
		}
		size = 0;
	}

public:
	BStringClass() : buff(nullptr), size(0)
	{

	}
	BStringClass(const char c){
		this->size = 1;
		this->buff = new char[1];
		this->buff[0] = c;
		this->buff[1] = '\0';
	}

	BStringClass(const char *buffer){
		size = strlen(buffer);
		buff = new char[size + 1];
		strncpy_s(buff, size + 1, buffer, size);
	}
	BStringClass(const BStringClass & obj){
		size = obj.size;
		buff = new char[size + 1];
		strncpy_s(buff, size + 1, obj.buff, size);
	}

	void append(const char *buffer){
		BStringClass s;
		unsigned int src_len = strlen(buffer);
		s.size = this->size + src_len;
		s.buff = new char[s.size + 1];
		strncpy_s(s.buff, this->size + 1, this->buff, this->size);
		strncpy_s(s.buff + this->size, src_len + 1, buffer, src_len);
		*this = s;
	}

	void append(BStringClass & obj){
		BStringClass s;
		unsigned int src_len = obj.length();
		s.size = this->size + src_len;
		s.buff = new char[s.size + 1];
		strncpy_s(s.buff, this->size + 1, this->buff, this->size);
		strncpy_s(s.buff + this->size, src_len + 1, obj.buff, src_len);
		*this = s;
	}

	int compare(BStringClass obj){
		return strcmp(this->buff, obj.buff);
	}

	int compare(unsigned int pos, unsigned int len, char *s){
		
		BStringClass tmp;
		//Extract the string in this to tmp starting at the positions
		tmp = this->substr(pos, len);
		//Return compare
		return strcmp(tmp.buff, s);
	}

	int compare(char *s){
		return strcmp(this->buff, s);
	}

	void clear(){
		this->_clean();
	}

	void swap(BStringClass & obj){
		BStringClass temp(obj);
		obj = *this;
		*this = temp;
	}

	BStringClass substr(unsigned int pos, unsigned int len){
		
		BStringClass tmp;
		int pi = 0;
		int s = (len - pos);

		//Set buffer size and set aside memory
		tmp.size = s;
		tmp.buff = new char[s];
		//Copy the chars from this->buff to tmp
		for (int y = pos; y < len; y++){
			tmp.buff[pi] = this->buff[y];
			pi++;
		}
		//Set end of tnp
		tmp.buff[pi] = '\0';
		//Return tmp
		return tmp;
	}

	void copy(char out[], unsigned int pos, unsigned int len){
		int pi = 0;
		//Copy chars from buff to out
		for (int y = pos; y < len; y++){
			out[pi] = this->buff[y];
			pi++;
		}
		out[pi] = '\0';
	}

	const unsigned char at(unsigned int pos){
		//Return chat from buff at the index of pos
		return this->buff[pos];
	}

	BStringClass& operator=(const BStringClass & obj){
		//Clear buffer
		this->_clean();
		//Assignment operator
		size = obj.size;
		buff = new char[size + 1];
		//Do the copy
		strncpy_s(buff, size + 1, obj.buff, size);
		return *this;
	}

	BStringClass(BStringClass && obj){
		//Clean buffer
		this->_clean();

		size = obj.size;
		buff = obj.buff;
		obj.buff = nullptr;
	}

	BStringClass& operator=(BStringClass && obj){

		this->_clean();

		size = obj.size;
		buff = obj.buff;
		obj.buff = nullptr;
		return *this;
	}

	BStringClass operator+(BStringClass & obj){
		BStringClass s;

		s.size = this->size + obj.size;
		s.buff = new char[s.size + 1];
		strncpy_s(s.buff, this->size + 1, this->buff, this->size);
		strncpy_s(s.buff + this->size, obj.size + 1, obj.buff,obj.size);

		return s;
	}

	void upper_case(){
		//Uppercase buff
		int x = 0;
		while (x < this->size){
			this->buff[x] = toupper(this->buff[x]);
			x++;
		}
	}

	void lower_case(){
		//Lowercase buff
		int x = 0;
		while (x < this->size){
			this->buff[x] = tolower(this->buff[x]);
			x++;
		}
	}

	void proper_case(){
		//Make first letter of the string uppercase.
		int y = 0;
		//Lower case all the letters
		for (y = 0; y < this->size;y++){
			this->buff[y] = tolower(this->buff[y]);
		}
		//Make this first char uppercase
		this->buff[0] = toupper(this->buff[0]);
	}

	void push_char(const char c){
		int len = this->size;
		int y = 0;
		char *buffer = new char[len + 2];
		//Copy bytes
		while(y < len){
			buffer[y] = this->buff[y];
			y++;
		}
		//Set buf with new char at the end
		buffer[y] = c;
		//Exscape the string
		buffer[y + 1] = '\0';
		//Set the new object
		*this = BStringClass(buffer);
		//Clear up
		delete[]buffer;
	}

	void pop_char(){
		int len = this->size;
		int y = 0;
		char *buffer = new char[len + 1];

		while (y < len){
			buffer[y] = this->buff[y];
			y++;
		}

		buffer[y - 1] = '\0';

		*this = BStringClass(buffer);

		delete[]buffer;
	}

	int find(char *src){
		//Locate a substring in buffer and return the index found at
		//I am sure there are quicker ways of doing this but for now this works ok.
		char c = '\0';
		int s_pos = 0;
		int l_pos = 0;
		int x = 0;
		int y = 0;
		int len = this->size;
		char sub[1024] = { '\0' };
		int pi = 0;
		int ti = 0;
		int idx = -1;

		l_pos = strlen(src);

		while (x < len){
			if (this->buff[x] == src[0]){
				s_pos = x;
				pi = (x + l_pos);
				ti = 0;

				for (y = x; y < pi; y++){
					sub[ti] = this->buff[y];
					ti++;
				}
				sub[ti] = '\0';

				if (strcmp(sub, src) == 0){
					if (s_pos == 0){
						idx = 0;
					}
					else{
						idx = (s_pos - 1);
					}
					break;
				}
			}
			x++;
		}

		//Clear up
		memset(sub, 0, sizeof sub);
		return idx;
	}

	void reverse(){
		int x = (this->size - 1);
		int y = 0;

		char *buffer = new char[this->size];

		while (x >= 0){
			buffer[y] = this->buff[x];
			y++;
			x--;
		}

		buffer[y] = '\0';

		x = 0;
		while (x < this->size){
			this->buff[x] = buffer[x];
			x++;
		}

		x = 0;
		y = 0;
		memset(buffer, 0, sizeof buffer);
	}

	~BStringClass(){
		this->_clean();
	}

	char *CString() const{
		return this->buff;
	}

	unsigned int length(){
		return this->size;
	}
};

