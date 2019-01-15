#include <deque>
#include <exception>

template <typename T>
class Stack
{
	std::deque<T> s;
public: 
	// Класс исключения для методов pop() и head() при пустом стеке
	class ReadEmptyStack : public std::exception { 
	public:
		virtual const char* what() const throw() {
			return "Read empty stack";
		}
	};

	typename std::deque<T>::size_type size() const {
		return s.size();
	}

	bool empty() const {
		return s.empty();
	}

	void push(T&& value) { // вставляет элемент в стек по rvalue-ссылке
		s.push_back(std::move(value));
	}
	
	template <typename ... Args>
	void push_emplace(Args&&... value) {

		for (auto t : std::deque<T>{ value... }) {

			s.push_back(t);

		}
	}
	
	void push(const T& value) { // вставляет элемент в стек 
		s.push_back(value);
	}

	void pop() { // удаляет элемент из стека
		if (s.empty()) throw ReadEmptyStack();
		T value(s.back());
		s.pop_back();

	}

	 const T& head() const { // возвращает элемент на вершине стека
		 if (s.empty()) { throw ReadEmptyStack(); }
		return s.back();
	}
};
