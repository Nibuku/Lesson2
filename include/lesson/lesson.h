#pragma once
#include <string>
#include <iostream>
#include <utility>
#include <cassert>
using namespace std;


	enum LessonType
	{
		LECTURE,
		LAB,
		PRACTICE
	};

	enum Name
	{
		OOP,
		ALGEBRA,
		GEOMETRIYA
	};
	class Lesson;
	using LessonPtr = Lesson*;


	class Lesson {
	private:
		LessonType _type;
		Name _name;
		int _hours;
	public:
		Lesson();
		Lesson(LessonType type, Name name, int hours);
		int compute_paid_hours(int groups, int subgroups);
		Name getName() const;
		LessonType getLessonType() const;
		int gethours() const;
		void setName(Name _name);
		void setLessonType(LessonType _type);
		void sethours(int _hours);
		LessonPtr clone() const;
		void swap(Lesson& other) noexcept;
		friend std::ostream& operator<<(std::ostream& out, Lesson& t);
		friend std::istream& operator>>(std::istream& in, Lesson& t);

	};

	class LessonList {
	private:
		LessonPtr* _lessons;
		int _size ;

	public:
		int get_size();
		void set_size(int size, int);
		LessonPtr get_lessons(int index);
		LessonList(LessonPtr* lesson, int _size);
		LessonList(LessonPtr* lesson, int size, int);
		LessonList();
		LessonList(const LessonList& other);
		int size() const;
		void insert(int index, Lesson f);
		void remove(int index);
		LessonPtr operator[](int index) const;
		int compute_sum(const LessonList& t, int groups, int subgroups, int p) const;
		Name compute_max_paid( const LessonList& t, int groups, int subgroups);
		friend bool operator==(const LessonList& list, const LessonList& other);
		friend bool operator!=(const LessonList& list, const LessonList& other);
		LessonList& operator>>(LessonList& rhs);
		~LessonList();
		LessonList& operator=(const LessonList& rhs);
		void Swap(LessonList& other) noexcept;
		LessonPtr& operator[](int ind);
		void print_current(int index);
		void show_all();
	};
	


	bool operator==(Lesson& lhs, Lesson& rhs);

	bool operator!=(Lesson& lhs,  Lesson& rhs);