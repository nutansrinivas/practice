struct A
{
	std::string s;
	int k;

	A() : s("test") { }

	A(const A& o) : s(o.s) { std::cout << "move failed!\n"; }

	A(A&& o) : s(std::move(o.s)) { }

	A(const A& o) : s(o.s), k(o.k) { std::cout << "move failed!\n"; }

	A(A&& o) noexcept :
		s(std::move(o.s)),       // explicit move of a member of class type
		k(std::exchange(o.k, 0)) // explicit move of a member of non-class type
		{ }

	A& operator=(const A& other)
	{
		s = other.s;
		std::cout << "copy assigned\n";
		return *this;
	}

	A& operator=(A&& other)
	{
		s = std::move(other.s);
		std::cout << "move assigned\n";
		return *this;
	}

};
