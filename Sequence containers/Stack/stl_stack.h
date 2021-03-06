#pragma once

#include "stl_deque.h"

namespace STL {

	template <class T, class Sequence = deque<T> >
	class stack {

		template <class _T, class _Sequence>
		friend bool operator==(const stack<_T, _Sequence>&, const stack<_T, _Sequence>&);

		template <class _T, class _Sequence>
		friend bool operator<(const stack<_T, _Sequence>&, const stack<_T, _Sequence>&);
	public:
		using value_type = typename Sequence::value_type;
		using size_type = typename Sequence::size_type;
		using reference = typename Sequence::reference;
		using const_reference = typename Sequence::const_reference;
	private:
		Sequence c;
	public:
		bool empty() const noexcept { return c.empty(); }
		size_type size() const noexcept { return c.size(); }
		const_reference top() const noexcept { return c.back(); }
		void push(const value_type& x) { c.push_back(x); }
		void pop() { c.pop_back(); }
	};

	template <class T, class Sequence>
	bool operator==(const stack<T, Sequence>& x, const stack<T, Sequence>& y) {
		return x.c == y.c;
	}

	template <class T, class Sequence>
	bool operator<(const stack<T, Sequence>& x, const stack<T, Sequence>& y) {
		return x.c < y.c;
	}
}
