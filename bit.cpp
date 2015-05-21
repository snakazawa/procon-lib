// Binary Indexed Tree (BIT)
template <typename T>
class BinaryIndexedTree {
public:
	BinaryIndexedTree(int size_) : size(size_) {
		data.resize(size + 1);
	}

	void add(int index, T value) {
		if (index < 0 || index >= size) return;
		++index;
		while (index <= size) {
			data[index] += value;
			index += index & -index;
		}
	}

	T sum(int index) {
		if (index < 0 || index >= size) return 0;
		++index;
		T ret = 0;
		while (index > 0) {
			ret += data[index];
			index -= index & -index;
		}
		return ret;
	}

	T sum(int l, int r) {
		return sum(r) - sum(l);
	}

private:
	std::vector<T> data;
	int size;
};
