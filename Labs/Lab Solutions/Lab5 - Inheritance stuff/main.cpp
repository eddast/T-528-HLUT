#include <iostream>
#include <string>
using namespace std;

namespace a {
	class Base {
	public:
		Base( std::string str ) : str_(str) {}
		void out() { cout << "Base: " << str_ << '\n'; }
	protected:
		std::string str_;
	};
	class Derived : public Base { public:
		Derived( std::string str ) : Base( str ) {}
	};
}

namespace b {
    // Copy your classes from a) in here and modify.
    class Base
    {
        public:
            Base( std::string str ) : str_(str) {}
            void out() { cout << "Base: " << str_ << '\n'; }
        protected:
            std::string str_;
	};
	class Derived : public Base
	{
            public:
                Derived( std::string str ) : Base( str ) {}
                void out() { cout << "Derived: " << str_ << '\n'; }
	};
}

namespace c {
    // Copy your classes from b) in here and modify.
    class Base {
	public:
		Base( std::string str ) : str_(str) {}
		virtual void out() { cout << "Base: " << str_ << '\n'; }
	protected:
		std::string str_;
	};
	class Derived : public Base { public:
		Derived( std::string str ) : Base( str ) {}
		virtual void out() { cout << "Derived: " << str_ << '\n'; }
	};
}

namespace d {
    // Copy your classes from c) in here and modify.
    class Base {
        public:
            Base( std::string str ) : str_(str) {}
            virtual void out(int num = 5) { cout << "Base: " << str_ << " " << num << '\n'; }
        protected:
            std::string str_;
	};
	class Derived : public Base { public:
		Derived( std::string str ) : Base( str ) {}
		virtual void out(int num) { cout << "Derived: " << str_ << " " << num << '\n'; }
	};
}

namespace e {
    // Copy your classes from d) in here and modify.
    class Base {
        public:
            Base( std::string str ) : str_(str) {}
            virtual void out(int num = 5) { cout << "Base: " << str_ << " " << num << '\n'; }
        protected:
            std::string str_;
	};
	class Derived : public Base { public:
		Derived( std::string str ) : Base( str ) {}
		virtual void out(int num = 7) { cout << "Derived: " << str_ << " " << num << '\n'; }
	};
}

namespace f {
    // Copy your classes from e) in here and modify.
    class Base {
        public:
            Base( std::string str ) : str_(str) {}
            void out(){ out_(); }
        protected:
            std::string str_;
        private:
            virtual void out_(int num = 5) { cout << "Base: " << str_ << " " << num << '\n'; }
	};
	class Derived : public Base {
        public:
            Derived( std::string str ) : Base( str ) {}
        private:
            virtual void out_(int num = 7) { cout << "Derived: " << str_ << " " << num << '\n'; }
	};
}

namespace g {
    // Copy your classes from f) in here and modify.
    class Base {
        public:
            Base( std::string str ) : str_(str) {}
            friend ostream& operator<< ( ostream& os, const Base& rhs ) {
                rhs.out_( os );
                return os;
            }
        protected:
            std::string str_;
        private:
            virtual void out_(ostream &out) const { out << "Base: " << str_ << '\n'; }
	};

	class Derived : public Base {
        public:
            Derived( std::string str ) : Base( str ) {}
        private:
            virtual void out_(ostream &out) const { out << "Derived: " << str_ << '\n'; }
	};
}

//using namespace a;
//using namespace b;
//using namespace c;
//using namespace d;
//using namespace e;
//using namespace f;
using namespace g;

int main() {
	Base b("A");
	Derived d("B");
	Derived *pdd = new Derived("C");
	Base *pdb = pdd;

	// Part a) -f)
	/*
	b.out();
	d.out();
	pdd->out();
	pdb->out();
	//*/

	// Part g)
    // ... to be added.
    //*
    cout << b;
    cout << d;
    cout << *pdd;
    cout << *pdb;
    //*/

	delete pdd;
}
