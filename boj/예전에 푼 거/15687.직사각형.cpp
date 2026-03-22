//클레스 구현 문제ㄷ


//class Rectangle {
//public:
//	Rectangle(int width, int hegith) :width(width), height(height) {}
//
//	int get_width()const { return width; }
//	int get_height()const { return height; }
//	void set_width(int width) {
//		if (width <= 0 || width > 1000) return;
//		this->width = width;
//
//		return;
//	}
//	void set_height(int height) {
//		if (height <= 0 || height > 2000) return;
//		this->height = height;
//
//		return;
//	}
//
//	int area()const {
//		return height * width;
//	}
//
//	int perimeter()const {
//		return height * 2 + width * 2;
//	}
//
//	bool is_square()const {
//		return height == width;
//	}
//
//private :
//	int width;
//	int height;
//};