#include "Ice.hpp"
#include "Cure.hpp"
#include "collors.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

class Test
{
	private:
			int tests_passed;
			int tests_total;
	public:
			Test();
			Test(int tests_total);
			Test(const Test& other);
			Test& operator=(const Test& other);
			~Test();

			void	run();
			bool	test_character();
			bool	test_materia();
			bool	test_materia_source();
			bool	test_equip();
			bool	test_clone();
			bool	test_unequip();
			bool	test_output_diff();
			bool 	test_double_delete();
			bool	test_create_materia();
			bool	test_inventory_full();
			bool	test_multiple_clone();
			bool	test_invalid_materia();
			bool	test_duplicate_equip();
			bool	test_copy_after_delete();
			bool	test_deep_copy_character();
			void	run_test(std::string name, bool (Test::*test)());
};
