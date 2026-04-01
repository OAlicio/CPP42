#include "Test.hpp"
#include <sstream>

Test::Test(): tests_passed(0), tests_total(0){}

Test::~Test(){}

Test::Test(int tests_total)
{
	(void)tests_total;
}

Test::Test(const Test& other)
{
	*this = other;
}

Test& Test::operator=(const Test& other)
{
	(void)other;
	return (*this); 
}

void	Test::run_test(std::string name, bool (Test::*test)())
{
	tests_total++;

	if ((this->*test)())
	{
		tests_passed++;
		std::cout << C_GREEN << "[PASS] " << C_REST << 
		C_MAGENTA << name << C_REST
		<< std::endl;
	}
	else
		std::cout << C_RED << "[FAIL] " << C_REST << 
		C_MAGENTA << name << C_REST 
		<< std::endl;
}

bool Test::test_character()
{
	std::cout << "============= CHARACTER TEST =============\n" << std::endl;
	std::cout << "Creating 2 Character's\n" << std::endl;

	Character	p1("Player 1");
	Character	en("Enemy");
	std::cout << "\n";
	std::cout << "Equip method\n" << std::endl;
	p1.equip(new Ice());
	en.equip(new Cure());
	std::cout << "\n";

	std::cout << "Copy Constructor\n" << std::endl;
	Character newCharacter(en);

	std::cout << "\n";
	std::cout << "Assignment operator" << std::endl;

	std::cout << "\n";
	std::cout << "new Character Before" << std::endl;
	std::cout << "Name: " << newCharacter.getName() << std::endl;
	std::cout << "\n";
	std::cout << "Use Method" << std::endl;
	newCharacter.use(0, en);
	std::cout << "\n";
	std::cout << "Unequip Method" << std::endl;
	newCharacter.unequip(0);
	std::cout << "\n";
	newCharacter = p1;
	std::cout << "\n";
	std::cout << "new Character After" << std::endl;
	std::cout << "newCharacter Name After: " << newCharacter.getName() << std::endl;
	std::cout << "\n";
	std::cout << "Use Method" << std::endl;
	newCharacter.use(0, en);
	std::cout << "\n";

	std::cout << "p1 Before" << std::endl;
	std::cout << "Name: " << p1.getName() << std::endl;
	std::cout << "\n";
	std::cout << "Use Method" << std::endl;
	p1.use(0, en);
	std::cout << "\n";
	std::cout << "Unequip Method" << std::endl;
	p1.unequip(0);
	std::cout << "\n";
	p1 = en;
	std::cout << "\n";
	std::cout << "p1 After" << std::endl;
	std::cout << "Name: " << p1.getName() << std::endl;
	std::cout << "\n";
	std::cout << "Use Method" << std::endl;
	p1.use(0, en);
	std::cout << "\n";

	return true;
}

bool	Test::test_create_materia()
{
	IMateriaSource* src = new MateriaSource();

	src->learnMateria(new Ice());
	AMateria* ice = src->createMateria("ice");

	bool result = (ice != NULL);

	delete src;
	return result;
}

bool Test::test_materia_source()
{
	std::cout << "============= MATERIA TEST =============\n" << std::endl;
	std::cout << "Creating Materia's" << std::endl;
	MateriaSource m1;
	MateriaSource m2;

	std::cout << "\nCREATING PLAYER's" << std::endl;
	Character	p1("Player 1");
	Character	en("Enemy");

	std::cout << "\nLearning Ice" << std::endl;
	std::cout << "\n";
	m1.learnMateria(new Ice());
	std::cout << "\n";
	std::cout << "Assignment operator\n";
	std::cout << "\n";
	m2 = m1;
	std::cout << "\n";
	std::cout << "Copy constructor\n";
	std::cout << "\n";
	MateriaSource m3 = m2;
	std::cout << "\n";
	p1.equip(m3.createMateria("ice"));
	std::cout << "\nShould shoot Ice\n";
	p1.use(0, en);
	std::cout << "\n";
	return true;
}

bool	Test::test_equip()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());

	ICharacter* me = new Character("me");

	AMateria* ice = src->createMateria("ice");

	me->equip(ice);

	bool result = true;

	delete me;
	delete src;

	return result;
}

bool	Test::test_inventory_full()
{
	std::cout << "============ INVENTORY FULL TEST =============" << std::endl;
	std::cout << "Creating Materia Source" << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());

	ICharacter* me = new Character("me");

	for (int i = 0; i < 4; i++)
		me->equip(src->createMateria("ice"));

	AMateria* extra = src->createMateria("ice");

	me->equip(extra); 

	bool result = true;

	delete me;
	delete src;

	return result;
}

bool	Test::test_unequip()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());

	ICharacter* me = new Character("me");

	AMateria* ice = src->createMateria("ice");

	me->equip(ice);
	me->unequip(0);

	bool result = true;

	delete me;
	delete src;

	return result;
}

bool	Test::test_invalid_materia()
{
	IMateriaSource* src = new MateriaSource();

	AMateria* fire = src->createMateria("fire");

	bool result = (fire == NULL);

	delete src;

	return result;
}

//"Expect 1 or 2 uses depending implementation:\n";

bool	Test::test_duplicate_equip()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());

	ICharacter* me = new Character("me");

	AMateria* ice = src->createMateria("ice");

	me->equip(ice);
	me->equip(ice);

	ICharacter* enemy = new Character("enemy");

	std::cout << "\n";
	me->use(0, *enemy);
	std::cout << "\n";
	me->use(1, *enemy);
	std::cout << "\n";

	delete enemy;
	delete me;
	delete src;

	return true;
}

//"If program crashed -> double delete problem";

bool	Test::test_double_delete()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());

	ICharacter* me = new Character("me");

	AMateria* ice = src->createMateria("ice");

	me->equip(ice);

	delete me;
	delete src;

	return true;
}

bool Test::test_clone()
{
	IMateriaSource* src = new MateriaSource();

	src->learnMateria(new Ice());

	AMateria* a = src->createMateria("ice");
	AMateria* b = src->createMateria("ice");

	bool result = (a != b);

	delete src;

	return result;
}

bool	Test::test_deep_copy_character()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());

	Character a("A");

	a.equip(src->createMateria("ice"));

	Character b = a; // copy constructor

	ICharacter* enemy = new Character("enemy");

	std::cout << "\n";
	a.use(0, *enemy);
	std::cout << "\n";

	std::cout << "Should shoot ice\n";
	b.use(0, *enemy);
	std::cout << "\n";

	delete enemy;
	delete src;

	return true;
}

bool	Test::test_multiple_clone()
{
	std::cout << "========== MULTIPLE CLONE ===========" << std::endl;
	IMateriaSource* src = new MateriaSource();

	src->learnMateria(new Ice());

	ICharacter* a = new Character("A");
	ICharacter* b = new Character("B");

	a->equip(src->createMateria("ice"));
	b->equip(src->createMateria("ice"));

	ICharacter* enemy = new Character("enemy");

	std::cout << "\n";
	a->use(0, *enemy);
	std::cout << "\n";
	b->use(0, *enemy);
	std::cout << "\n";

	delete enemy;
	delete a;
	delete b;
	delete src;

	return true;
}

bool Test::test_copy_after_delete()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());

	Character* a = new Character("A");

	a->equip(src->createMateria("ice"));

	Character b = *a;

	delete a;

	ICharacter* enemy = new Character("enemy");

	std::cout << "\n";
	b.use(0, *enemy);
	std::cout << "\n";

	delete src;
	delete enemy;
	return true;
}

bool	Test::test_output_diff()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());

	ICharacter* me = new Character("me");
	ICharacter* bob = new Character("bob");

	me->equip(src->createMateria("ice"));
	std::stringstream buffer;
	std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());
	me->use(0, *bob);
	std::cout.rdbuf(old);

	std::string expected = "* shoots an ice bolt at bob *\n";

	delete bob;
	delete me;
	delete src;

	std::cout << "\n";
	std::cout << "Use method: " << buffer.str() << "Expected: " << expected;
	return buffer.str() == expected;
}

void	Test::run()
{
	run_test("^ Character Test\n", &Test::test_character);
	run_test("^ Create Materia\n", &Test::test_create_materia);
	run_test("^ MateriaSource Test\n", &Test::test_materia_source);
	run_test("^ Equip Materia\n", &Test::test_equip);
	run_test("^ Inventory Full\n", &Test::test_inventory_full);
	run_test("^ Unequip Materia\n", &Test::test_unequip);
	run_test("^ Invalid Materia\n", &Test::test_invalid_materia);

	run_test("^ Duplicate Equip\n", &Test::test_duplicate_equip);
	run_test("^ Double Delete\n", &Test::test_double_delete);
	run_test("^ Clone Materia\n", &Test::test_clone);

	run_test("^ Deep Copy Character\n", &Test::test_deep_copy_character);
	run_test("^ Copy After Delete\n", &Test::test_copy_after_delete);
	run_test("^ Multiple Clone\n", &Test::test_multiple_clone);
	run_test("^ Output Diff\n", &Test::test_output_diff);

	std::cout << "Passed " << tests_passed << "/" << tests_total << " tests" << std::endl;

	if (tests_passed == tests_total)
		std::cout << C_GREEN << "ALL TESTS PASSED\n" << C_REST;
	else
		std::cout << C_RED << "SOME TESTS FAILED\n" << C_REST;
}
