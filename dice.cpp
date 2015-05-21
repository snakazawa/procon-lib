struct die_t {
	int top, front, right, left, back, bottom;

	die_t (int t, int f, int r, int l, int bk, int b)
	: top(t), front(f), right(r), left(l), back(bk), bottom(b) { }

	void rotate_swap ( int &a, int &b, int &c, int &d ) {
		swap(a, b); swap(b, c); swap(c, d);
	}

	void rotate_right( void ) { rotate_swap(top,left,bottom,right); }
	void rotate_left ( void ) { rotate_swap(top,right,bottom,left); }
	void rotate_front( void ) { rotate_swap(top,back,bottom,front); }
	void rotate_back ( void ) { rotate_swap(top,front,bottom,back); }
	void rotate_cw   ( void ) { rotate_swap(back,left,front,right); }
	void rotate_ccw  ( void ) { rotate_swap(back,right,front,left); }

	void set_tf(int t, int f) {
		// top
		if (t == top){
		}else if (t == bottom){
			rotate_back();
			rotate_back();
		}else {
			while (t != front)
				rotate_cw();
			rotate_back();
		}

		// front
		while (f != front)
			rotate_cw();
	}

	void disp( void ) { printf("%d %d %d %d %d %d", top, bottom, front, back, right, left); };
};
