#include <lesson/lesson.h>
#include <stdexcept>
#include <algorithm>
using namespace std;
Lesson::Lesson(LessonType type,Name name, int hours)
{
	this->_type = type;
	this->_hours = hours;
	this->_name = name;
}

Lesson::Lesson() {
	_type = LAB;
	_name = OOP;
	_hours = 0;
}

int Lesson::compute_paid_hours(int groups, int subgroups)
{
	switch(_type)
	{
	case LECTURE:
		return _hours;
	case LAB:
		return subgroups * _hours;
	case PRACTICE:
		return groups * _hours;
	default:
		throw runtime_error("error2");
	}
}

LessonPtr Lesson::clone() const {
	return new Lesson(_type, _name, _hours);
}

int LessonList::compute_sum(const LessonList& t, int groups, int subgroups, int p) const{
	const int n = t.size();
	int s = 0;
	Name name;
	switch (p) {
	case 0:
		name = OOP;
		break;
	case 1:
		name = ALGEBRA;
		break;
	case 2:
		name = GEOMETRIYA;
		break;
	default:
		throw runtime_error("error4");
	}
	for (int i = 0; i < n; ++i) {
		const auto value = t[i]->compute_paid_hours(groups, subgroups);
		const auto r = *t[i];
		if (name == r.getName()) {
			s = s + value;

		}
	}
	return s;
}

Name LessonList::compute_max_paid(const LessonList& t, int groups, int subgroups) {
	const auto n = t.size();
	int max = 0;
	int index = 0;
	for (int i = 0; i < n; ++i) {
		const auto value = t[i]->compute_paid_hours(groups, subgroups);
		if (max < value) {
			max =value;
			index = i;
		}
	}
	const auto r = *t[index];
	return r.getName();
}

int LessonList::size() const {
	return _size;
}

LessonType Lesson::getLessonType() const {
	return _type;
}

int Lesson::gethours() const {
	return _hours;
}

Name Lesson::getName() const {
	return _name;
}

void Lesson::sethours(int _hours) {
	this->_hours = _hours;
}

void Lesson::setLessonType(LessonType _type) {
	this->_type = _type;
}

void Lesson::setName(Name _name) {
	this->_name = _name;
}

LessonList::LessonList()
{
	this->_size = 5;
	_lessons = new Lesson * [_size];
	for (int i = 0; i < _size; ++i) _lessons[i] = new Lesson();
}

LessonList::LessonList(const LessonList& other): 
	_lessons(new LessonPtr[other._size]),
	_size(other._size){
	for (int i = 0; i < _size; ++i) {
		_lessons[i] = new Lesson(*other._lessons[i]);
	}
}

LessonList::~LessonList() {
	for (int i = 0; i < _size; ++i) {
		delete _lessons[i];
	} delete[] _lessons;
}

LessonList::LessonList(LessonPtr* lesson,int size1) {
	this->_size = size1;

	_lessons = new Lesson * [_size];
	for (int i = 0; i < size1; ++i) {
		this->_lessons[i] = new Lesson();
		this->_lessons[i]->setLessonType(lesson[i]->getLessonType());
		this->_lessons[i]->setName(lesson[i]->getName());
		this->_lessons[i]->sethours(lesson[i]->gethours());
	}
}
LessonList::LessonList(LessonPtr* lesson, int size, int) {
	this->_size = size;

	_lessons = new Lesson * [_size];
	for (int i = 0; i < size; ++i) {
		this->_lessons[i] = new Lesson();
		this->_lessons[i]->setLessonType(lesson[i]->getLessonType());
		this->_lessons[i]->setName(lesson[i]->getName());
		this->_lessons[i]->sethours(lesson[i]->gethours());
	}
}
void Lesson::swap(Lesson& other) noexcept {
	std::swap(this->_type, other._type);
	std::swap(this->_name, other._name);
	std::swap(this->_hours, other._hours);
}

void LessonList::Swap(LessonList& other) noexcept {
	std::swap(_lessons, other._lessons);
	std::swap(_size, other._size);
}

LessonList& LessonList::operator=(const LessonList& rhs) {
	LessonList copy(rhs);
	copy.Swap(*this);
	return *this;
}

LessonList& LessonList::operator>> (LessonList& rhs) {
	LessonList copy(rhs);
	copy.Swap(*this);
	return *this;
}
  
void LessonList::insert(int index, Lesson f) {
	if (index >= _size || index < 0) {
		throw runtime_error("error1");
	}
	++_size;
	LessonPtr* lesson = new Lesson * [_size];
	for (int i = 0; i < index; ++i) {
		lesson[i] = new Lesson(*this->_lessons[i]);
	}
	lesson[index] = new Lesson(f);
	for (int i = _size - 1; i > index; --i) {
		lesson[i] = new Lesson(*this->_lessons[i - 1]);
	}
	std::swap(this->_lessons,lesson);
	} 

void LessonList::remove(int index) {
	if (index >= _size || index < 0) {
		throw runtime_error("error1");
	}
	for (int i = index; i < _size - 1; ++i) { _lessons[i] = _lessons[i + 1]; }
	--_size;
}

LessonPtr LessonList::operator[](const int index) const {
	if (index >= _size|| index < 0) {
		throw runtime_error("error1");
	}
	return _lessons[index];
}
LessonPtr& LessonList::operator[]( int index) {
	if (index >= _size || index < 0) {
		throw runtime_error("error1");
	}
	return _lessons[index];
}

std::istream& operator>>(std::istream& in, LessonType& t)
{
	int type;
	in >> type;
	switch (type) {
	case 0:
		t = LECTURE;
		break;
	case 1:
		t = LAB;
		break;
	case 2:
		t = PRACTICE;
		break;
	default:
		throw runtime_error("error3");
	}

	return in;
}

std::istream& operator>>(std::istream& in, Name& t)
{
	int name;
	in >> name;
	switch (name) {
	case 0:
		t = OOP;
		break;
	case 1:
		t = ALGEBRA;
		break;
	case 2:
		t = GEOMETRIYA;
		break;
	default:
		throw runtime_error("error4");
	}

	return in;
}
std::ostream& operator<<(std::ostream& out, Lesson& t)
{
	return out << "Lesson(" << t.getLessonType() << ", " << t.getName() << ", " << t.gethours() << ")";
}

std::istream& operator>>(std::istream& in, Lesson& t)
{
		cout << "Введите тип занятия: 0-Лекция, 1-Лабораторная, 2-Практика\n ";
		
		in >> t._type;
		cout << "Введите название предмета:0-OOП, 1-Алгебра, 2-Геометрия\n ";
		in >> t._name;
		cout << "Введите количество часов:\n ";
		in >> t._hours;

		return in;
}

bool operator==( Lesson& lhs,  Lesson& rhs) {
	return
		lhs.getLessonType() == rhs.getLessonType() &&
		lhs.getName() == rhs.getName() &&
		lhs.gethours() == rhs.gethours();

		
}
int LessonList::get_size() {
	return _size;
}
void LessonList::set_size(int size, int) {
	_size = size;
}
LessonPtr LessonList::get_lessons(int index) {
	return _lessons[index];
}


bool operator!=( Lesson& lhs,  Lesson& rhs) {
	return !(lhs == rhs);
}

void LessonList::print_current(int index) {
	cout << *_lessons[index];
}
void LessonList::show_all() {
	cout << "Текущий список:\n";
	for (int i = 0; i < _size; ++i) {
		cout << i << ':';
		print_current(i);
		cout << endl;
	}
}

bool operator==(const LessonList& list, const LessonList& other) {
	return (list._size == other._size && **(list._lessons) == **(other._lessons));
}
bool operator!=(const LessonList& list, const LessonList& other) {
	return !(list == other);
}