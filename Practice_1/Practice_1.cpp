#include <iostream>
#include <vector>
#include <string>
#include <fstream>

class Student
{
	std::string m_firstName		{"First"};
	std::string m_lastName		{"Last"};
	int			m_id			{0};
	float		m_avg			{0};

public:

	Student() {}

	Student(std::string first, std::string last, int id, float avg)
		: m_firstName	(first)
		, m_lastName	(last)
		, m_id			(id)
		, m_avg			(avg)
	{
	}

	int GetAverage() const {
		return m_avg;
	}

	int GetId() const {
		return m_id;
	}

	std::string GetFirstName() const {
		return m_firstName;
	}

	std::string GetLastName() const {
		return m_lastName;
	}

	void Print() const {
		std::cout << m_firstName << " " << m_lastName << " " << m_id << " " << m_avg << std::endl;
	}

};

class Course 
{
	std::string m_name{ "Course" };
	std::vector<Student> m_students;

public:

	Course() {}

	Course(const std::string& name) 
		: m_name(name)
	{
	}

	void addStudent(const Student& student) 
	{
		m_students.push_back(student);
	}

	const std::vector<Student>& getStudent() const 
	{
		return m_students;
	}

	void loadFromFile(const std::string& filename) 
	{
		std::ifstream fin(filename);
		std::string first, last;
		int id;
		float avg;

		while (fin >> first) 
		{
			fin >> last >> id >> avg;

			addStudent(Student(first, last, id, avg));
		}
		
	}

	void Print() const 
	{
		for (auto& s : m_students) {
			s.Print();
		}
	}

};

int main(int argc, char * argv[]) {

	Course course("Comp 4300");
	course.loadFromFile("StudentList.txt");
	course.Print();



	/*

	const Student Student_Nr_1("Per", "Normann", 444, 4.4);
	const Student Student_Nr_2("Eirik", "Juelsen", 1337, 99.9);
	const Student Student_Nr_3("Askeladden", "Troll", 9, 11.1);

	Student_Nr_2.Print();

	Course comp4300("Comp 4300");
	comp4300.addStudent(Student_Nr_2);
	comp4300.addStudent(Student_Nr_1);
	comp4300.addStudent(Student_Nr_3);

	comp4300.Print();
	*/

	/*
	std::vector<int> vec;
	vec.push_back(42);
	vec.push_back(11);
	vec.push_back(33);
	vec.push_back(22);

	for (size_t i{ 0 }; i < vec.size(); i++) {
		std::cout << vec[i] << "\n";
	}

	std::cout << std::endl;

	for (auto a : vec) {
		std::cout << a << "\n";
	}
	*/
	return 0;
}