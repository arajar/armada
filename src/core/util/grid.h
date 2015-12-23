#pragma once

namespace core 
{
	// utility class that represents an X * Y grid
	template<class T>
	class grid 
	{
	public:
		grid() : grid(0, 0, T()) {}
		grid(uint32_t rows, uint32_t cols, const T& initialValue = T()) { resize(rows, cols, initialValue); }

	public:
		uint32_t numRows() const { return rows_; }
		uint32_t numCols() const { return cols_; }
		bool empty() const { return array_.empty(); }
		void clear() { array_.clear(); rows_ = cols_ = 0; }
		void resize(uint32_t rows, uint32_t cols, const T& initialValue = T())
		{
			rows_ = rows;
			cols_ = cols;
			if (rows_ == 0)
			{
				cols_ = 0;
			}

			array_.resize(rows_ * cols_, initialValue);
		}

	public:
		T* operator[](uint32_t row) { return &array_[row * cols_]; }
		const T* operator[](uint32_t row) const { return &array_[row * cols_]; }

	private:
		uint32_t rows_;
		uint32_t cols_;

		std::vector<T> array_;
	};
}