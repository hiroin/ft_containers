#include <vector>
#include <list>
#include <map>
#include <stack>
#include <queue>
#include <iostream>
#include <string>
#include <exception>
#include <sstream>
#include <fstream>

#include "tester.hpp"

static std::stringstream	os;
std::ofstream				logM;

#ifdef TEST
# define MAPFILE "map_std.txt"
#else
# define MAPFILE "map_ft.txt"
#endif

template <typename T>
int		print_pair(const T &iterator)
{
	os << "first: " << iterator->first << " | second: " << iterator->second;
	os << std::endl;
	return (1);
}

template <typename Key, typename T>
int		TESTmap(NAME::map<Key, T> const  &MAP)
{
	typename NAME::map<Key, T>::const_iterator _it = MAP.begin(), _ite = MAP.end();
	os << "[Contents]" << std::endl;
	for (; _it != _ite; ++_it) {
		os << "" << _it->first << "\t\t\t" << _it->second << "\n";
	}
	os << "Size     : " << MAP.size() << '\n';
	os << std::endl;
	return (1);
}

template <typename Key, typename T, class C>
int		TESTmap(NAME::map<Key, T, C> const  &MAP)
{
	typename NAME::map<Key, T, C>::const_iterator _it = MAP.begin(), _ite = MAP.end();
	os << "[Contents]" << std::endl;
	for (; _it != _ite; ++_it) {
		os << "" << _it->first << "\t\t\t" << _it->second << "\n";
	}
	os << "Size     : " << MAP.size() << '\n';
	os << std::endl;
	return (1);
}

int		map_construct()
{
	std::cout << "[Constructor] ";
	os        << "========  [Constructor] ========= \n";
	NAME::map<std::string, int> MAP;
	os << "1. default construct\n";
	if (TESTmap(MAP) == 0)
		return FAILED;
	MAP["A"] = 1;
	MAP["BB"] = 2;
	MAP["CCC"] = 3;

	if (TESTmap(MAP) == 0)
		return FAILED;

	os << "2. range construct\n";
	NAME::map<std::string, int> MAP_A(MAP.begin(), MAP.end());
	if (TESTmap(MAP_A) == 0)
		return FAILED;


	MAP_A["A"] = 42;
	MAP = MAP_A;
	os << "3. copy construct\n";
	NAME::map<std::string, int> MAP_B(MAP);
	if (TESTmap(MAP_B) == 0)
		return FAILED;

	buffer_clean(logM, os);
	return SUCCESS;
}

int map_iterator()
{
	std::cout << "[begin, end] ";
	os        << "========  [begin, end] ========= \n";
	NAME::map<int, char>		MAP;
	for (int i = 0; i < 5; i++) {
		MAP[i + 65] = i + 'A';
	}
	os << "------------------- begin, end ------------------\n";
	NAME::map<int, char>::iterator MAP_it = MAP.begin();
	while (MAP_it != MAP.end())
	{
		os << "MAP : " << MAP_it->first << "\t\t" << MAP_it->second << "\n";
		++MAP_it;
	}
	os << "------------------- rbegin, rend ------------------\n";
	NAME::map<int, char>::reverse_iterator MAP_itr = MAP.rbegin();
	while (MAP_itr != MAP.rend())
	{
		os << "MAP : " << MAP_itr->first << "\t\t" << MAP_itr->second << "\n";
		++MAP_itr;
	}
	return SUCCESS;
}

int		map_access()
{
	std::cout << "[operator[]] ";
	os        << "========  [operator[]] ========= \n";
	NAME::map<char, int> MAP;
	os << "--- before \n";
	if (TESTmap(MAP) == 0)
		return FAILED;

	for (int i = 0; i < 5; i++) {
		MAP[i + 'A'] = i + 65;
	}

	os << "--- after \n";
	os << " MAP['A'] is " <<  MAP['A'] << '\n';
	os << " MAP['B'] is " <<  MAP['B'] << '\n';
	os << " MAP['D'] is " <<  MAP['D'] << '\n';
	if (TESTmap(MAP) == 0)
		return FAILED;
	buffer_clean(logM, os);
	return SUCCESS;
}

int		map_max_size()
{
	std::cout << "[max_size] ";
	os << "========  [max_size] ========= \n";
	{
		NAME::map<char, int> MAP;
		os << " MAP: " << MAP.max_size() << std::endl;
	}
	{
		NAME::map<char, char> MAP;
		os << " MAP: " << MAP.max_size() << std::endl;
	}
	{
		NAME::map<std::string, int> MAP;
		os << " MAP: " << MAP.max_size() << std::endl;
	}
	{
		NAME::map<std::string, std::string> MAP;
		os << " MAP: " << MAP.max_size() << std::endl;
	}
	{
		NAME::map<double, float> MAP;
		os << " MAP: " << MAP.max_size() << std::endl;
	}

	buffer_clean(logM, os);
	return SUCCESS;
}

int		map_empty()
{
	std::cout << "[empty] ";
	os << "========  [empty] ========= \n";
	NAME::map<char, int> MAP;

	if (!MAP.empty()) {
		return failed(logM, os);
	}

	MAP['a'] = 97;
	if (MAP.empty()) {
		return failed(logM, os);
	}

	MAP.clear();
	if (!MAP.empty()) {
		return failed(logM, os);
	}

	buffer_clean(logM, os);
	return SUCCESS;
}
int		map_size()
{
	std::cout << "[size ] ";
	os << "========  [size ] ========= \n";
	NAME::map<int, int> MAP;
	os << "MAP.size(): " << MAP.size()  <<  std::endl;

	for (int i = 0; i < 1000; i++) {

		MAP[i] = i + 1;
	}
	os << "MAP.size(): " << MAP.size()  <<  std::endl;

	MAP.clear();
	os << "MAP.size(): " << MAP.size()  <<  std::endl;

	buffer_clean(logM, os);
	return SUCCESS;
}

int		map_swap()
{
	std::cout << "[swap ] ";
	os        << "========  [swap ] ========= \n";
	NAME::map<std::string, int> MAP_A, MAP_B;
	MAP_A["aa"] = 1;
	MAP_A["bb"] = 2;
	MAP_A["ccc"] = 3;
	NAME::map<std::string, int>::iterator MAP_itr = MAP_A.begin();

	os << "-- (A_of_itr == B.begin()) \n";
	os << (MAP_itr == MAP_B.begin()) << std::endl;

	os << "A contents\n";
	if (TESTmap(MAP_A) == 0)
		return FAILED;
	os << "B contents\n";
	if (TESTmap(MAP_B) == 0)
		return FAILED;

	os << "-- aMAPer swap\n";
	MAP_A.swap(MAP_B);
	os << "A constents\n";
	if (TESTmap(MAP_A) == 0)
		return FAILED;
	os << "B constents\n";
	if (TESTmap(MAP_B) == 0)
		return FAILED;
	os << "-- (A_of_itr == B.begin()) \n";
	os << (MAP_itr == MAP_B.begin()) << std::endl;
	
	buffer_clean(logM, os);
	return SUCCESS;
}

int		map_erase()
{
	std::cout << "[erase ] ";
	os        << "========  [erase ] ========= \n";
	NAME::map<char, int> MAP;
	NAME::map<char, int>::iterator MAP_it = MAP.begin();
	for (int i = 0; i < 5; i++) {
		MAP[i + 'A'] = i + 65;
	}
	if (TESTmap(MAP) == 0)
		return FAILED;

	os << "--- erase 'B' ---\n";
	size_t MAP_ret;
	MAP_ret = MAP.erase('B');
	os << "MAP  return value: " << MAP_ret  <<  std::endl;
	if (TESTmap(MAP) == 0)
		return FAILED;

	os << "--- erase 'C' ---\n";
	MAP_it = MAP.find('C');
	MAP.erase(MAP_it);
	if (TESTmap(MAP) == 0)
		return FAILED;

	os << "--- erase begin to end ---\n";
	MAP.erase(MAP.begin(), MAP.end());
	if (TESTmap(MAP) == 0)
		return FAILED;
	buffer_clean(logM, os);
	return SUCCESS;
}

int		map_erase2()
{
	std::cout << "[erase2 ] ";
	os        << "========  [erase2 ] ========= \n";
	NAME::map<int, int> MAP;
	MAP[10] = 0;
	MAP[7] = 0;
	MAP[12] = 0; 
	MAP[9] = 0;
	MAP[5] = 0;
	MAP[11] = 0;
	MAP[15] = 0;
	MAP[13] = 0;
	MAP[18] = 0;
	MAP[16] = 0;
	MAP[19] = 0;
	MAP[17] = 0;
	if (TESTmap(MAP) == 0)
		return FAILED;
	os << "--- erase '15' ---\n";
	size_t MAP_ret;
	MAP_ret = MAP.erase(15);
	os << "MAP  return value: " << MAP_ret  <<  std::endl;

	if (TESTmap(MAP) == 0)
		return FAILED;

	os << "--- erase root '15' ---\n";
	MAP.clear();
	MAP[15] = 0;
	MAP[9] = 0;
	MAP[19] = 0;
	MAP[22] = 0;
	MAP[20] = 0;
	MAP[25] = 0;
	if (TESTmap(MAP) == 0)
		return FAILED;
	os << "MAP  return value: " << MAP_ret  <<  std::endl;
	if (TESTmap(MAP) == 0)
		return FAILED;

	buffer_clean(logM, os);
	return SUCCESS;
}

int		map_clear()
{
	std::cout << "[clear ] ";
	os        << "========  [clear ] ========= \n";
	NAME::map<char, std::string> MAP;

	for (int i = 0; i < 5; i++) {
		MAP[i + 'A'] = "map " + std::string(1, (i + 'A'));;
	}
	if (TESTmap(MAP) == 0)
		return FAILED;
	os << "--- clear ---\n";
	MAP.clear();
	if (TESTmap(MAP) == 0)
		return FAILED;

	buffer_clean(logM, os);
	return SUCCESS;
}
int		map_insert()
{
	std::cout << "[insert ] ";
	os        << "========  [insert ] ========= \n";
	NAME::map<char, int> MAP;
	NAME::pair<NAME::map<char,int>::iterator, bool> MAP_ret;

	if (TESTmap(MAP) == 0)
		return FAILED;
	os << "--- insert(pair('A', 65)) ---\n";
	MAP_ret = MAP.insert(NAME::pair<char, int>('A', 65));
	os << "MAP return  ite: "; print_pair(MAP_ret.first);
	os << "MAP  return bool: " << MAP_ret.second  <<  std::endl;

	os << "--- insert(pair('A', 65)) ---\n";
	MAP_ret = MAP.insert(NAME::pair<char, int>('A', 65));
	os << "MAP  return  ite: "; print_pair(MAP_ret.first);
	os << "MAP  return bool: " << MAP_ret.second  <<  std::endl;
	if (TESTmap(MAP) == 0)
		return FAILED;

	os << "--- insert 'B' to 'E' ---\n";
	for (int i = 66; i < 70; i++) {
		MAP_ret =  MAP.insert(NAME::pair<char, int>((char)i, i));
	}

	if (TESTmap(MAP) == 0)
		return FAILED;
	
	os << "--- insert(hintposition, val) ---\n";
	NAME::map<char, int>::iterator MAP_it = MAP.find('E');

	MAP_it  = MAP.insert(MAP_it, NAME::pair<char, int>('M', 77));

	os << "MAP  return  ite: "; print_pair(MAP_it);
	if (TESTmap(MAP) == 0)
		return FAILED;

	os << "--- insert(first, last) ---\n";
	MAP_it = MAP.find('D');
	NAME::map<char, int>	B;
	B.insert(MAP.begin(), MAP_it);
	if (TESTmap(B) == 0)
		return FAILED;
	buffer_clean(logM, os);
	return SUCCESS;
}

int		map_find()
{
	std::cout << "[find ] ";
	os        << "========  [find ] ========= \n";
	NAME::map<char, int> MAP;
	os << "--- insert 'A' to 'E' ---\n";
	for (int i = 65; i < 70; i++) {
		MAP[(char)i] = i;
	}
	if (TESTmap(MAP) == 0)
		return FAILED;
	
	os << "--- find E ---\n";
	NAME::map<char, int>::iterator MAP_it = MAP.find('E');
	os << "MAP  return  ite: "; print_pair(MAP_it);
	
	os << "--- find X---\n";
	MAP_it = MAP.find('X');
	if (MAP_it == MAP.end())
		os << "return end()\n";
	else
		return failed(logM, os);

	buffer_clean(logM, os);
	return SUCCESS;
}
int		map_count()
{
	std::cout << "[count ] ";
	os        << "========  [count ] ========= \n";

	NAME::map<int, double> MAP;
	MAP[1] = 0.1;
	MAP[3] = 0.3;
	MAP[7] = 0.7;
	if (TESTmap(MAP) == 0)
		return FAILED;

	os << "--- count ---\n";

	for (int i = 0; i < 10; i++)
	{
		if (MAP.count(i)) 
			os << "MAP : " << i << " is count\n";
	}
	buffer_clean(logM, os);
	return SUCCESS;
}

int		map_lower_bound()
{
	std::cout << "[lower_bound] ";
	os        << "========  [lower_bound] ========= \n";
	NAME::map<char, int> MAP;
	for (int i = 65; i < 78; i += 2) {
		MAP[(char)i] = i;
	}
	NAME::map<char, int>::iterator MAP_it;
	if (TESTmap(MAP) == 0)
		return FAILED;
	
	os << "--- lower_bound('C') ---\n";
	MAP_it =		MAP.lower_bound('C');
	os << "MAP  return  ite: "; print_pair(MAP_it);


	os << "--- lower_bound('F') ---\n";
	MAP_it =		MAP.lower_bound('F');
	os << "MAP  return  ite: "; print_pair(MAP_it);

	os << "--- lower_bound('Z') ---\n";
	MAP_it =		MAP.lower_bound('Z');
	if ((MAP_it == MAP.end()))
		os << "return end()\n";
	else
		return failed(logM, os);

	buffer_clean(logM, os);
	return SUCCESS;
}

int		map_upper_bound()
{
	std::cout << "[upper_bound] ";
	os        << "========  [upper_bound] ========= \n";
	NAME::map<char, int> MAP;
	for (int i = 65; i < 72; i++) {
		MAP[(char)i] = i;
	}
	NAME::map<char, int>::iterator MAP_it;
	if (TESTmap(MAP) == 0)
		return FAILED;

	os << "--- upper_bound('C') ---\n";
	MAP_it =		MAP.upper_bound('C');
	os << "MAP  return  ite: "; print_pair(MAP_it);

	os << "--- upper_bound('F') ---\n";
	MAP_it =		MAP.upper_bound('F');
	os << "MAP  return  ite: "; print_pair(MAP_it);


	os << "--- upper_bound('Z') ---\n";
	MAP_it =		MAP.upper_bound('Z');
	if (MAP_it == MAP.end()) 
		os << "return end()\n";
	else
		return failed(logM, os);
	buffer_clean(logM, os);
	return SUCCESS;
}
int		map_equal_range()
{
	std::cout << "[equal_range] ";
	os        << "========  [equal_range] ========= \n";
	NAME::map<char, int> MAP;
	for (int i = 65; i < 72; i++) {
		MAP[(char)i] = i;
	}
	NAME::pair<NAME::map<char,int>::iterator, NAME::map<char,int>::iterator> MAP_ret;
	if (TESTmap(MAP) == 0)
		return FAILED;
	
	os << "--- equal_range('C') ---\n";
	MAP_ret =	MAP.equal_range('C');
	os << "[return.first]\n";
	os << "MAP  return  ite: "; print_pair(MAP_ret.first);
	os << "[return.second]\n";
	os << "MAP  return  ite: "; print_pair(MAP_ret.second);

	os << "--- equal_range('F') ---\n";
	MAP_ret =	MAP.equal_range('F');
	os << "[return.first]\n";
	os << "MAP  return  ite: "; print_pair(MAP_ret.first);
	os << "[return.second]\n";
	os << "MAP  return  ite: "; print_pair(MAP_ret.second);

	buffer_clean(logM, os);
	return SUCCESS;
}

template <typename T>
struct is_more {
	bool	operator()(const T &first, const T &second) const {
		return (first > second);
	}
};

int		map_key_comp()
{
	std::cout << "[key_comp] ";
	os        << "========  [key_comp] ========= \n";
	NAME::map<char, int, is_more<char> > MAP;
	for (int i = 65; i < 70; i++) {
		MAP[(char)i] = i;
	}

	NAME::map<char,int,  is_more<char> >::key_compare MAPcmp = MAP.key_comp();

	TESTmap(MAP);
	NAME::map<char, int, is_more<char> >::iterator MAP_it = MAP.begin();
	while (MAP_it != MAP.end())
	{
		os << "--- compare " << MAP_it->first << " > 'C' \n";
		os << "MAP: ";
		if (MAPcmp(MAP_it->first, 'C') ) os << "true";
		else os << "false";
		os << std::endl;
		++MAP_it;
	}
	buffer_clean(logM, os);
	return SUCCESS;
}

int		map_value_comp()
{
	std::cout << "[value_comp] ";
	os        << "========  [value_comp] ========= \n";
	NAME::map<char, int> MAP;
	for (int i = 65; i < 70; i++) {
		MAP[(char)i] = i;
	}
	if (TESTmap(MAP) == 0)
		return FAILED;
	NAME::map<char,int>::value_compare MAPcmp = MAP.value_comp();
	bool MAP_ret = MAPcmp(NAME::pair<char, int>('a', 100), NAME::pair<char, int>('b', 200));
	os << "return :" << MAP_ret << "\n";

	NAME::map<char, int>::iterator	MAP_it = MAP.begin();
	while (MAP_it != --MAP.end())
	{
		os << "--- compare " << (*MAP_it).first << " < " << (*MAP_it).first << " + 1\n";
		os << " MAP: ";
		if (MAPcmp(*MAP_it, *(++MAP_it))) os << "true";
		os << std::endl;
	}
	buffer_clean(logM, os);
	return SUCCESS;
}

int		map_operator()
{
	std::cout << "[operator] ";
	os        << "========  [operator] ========= \n";
	NAME::map<int, int> MAP_A, MAP_B;

	os << "------- A, B empty ------\n";
	os << "MAP [A == B]: " << (MAP_A == MAP_B) << std::endl;
	os << "MAP [A != B]: " << (MAP_A != MAP_B) << std::endl;


	MAP_B[42] = 1;
	os << "------- B[42] = 1 ------\n";
	os << "MAP [A != B]: " << (MAP_A != MAP_B) << std::endl;
	os << "MAP [A < B]: " << (MAP_A < MAP_B) << std::endl;
	os << "MAP [A <= B]: " << (MAP_A <= MAP_B) << std::endl;
	os << "MAP [A > B]: " << (MAP_A > MAP_B) << std::endl;
	os << "MAP [A >= B]: " << (MAP_A >= MAP_B) << std::endl;

	MAP_A[42] = 42;
	os << "------- A[42] = 42 ------\n";
	os << "MAP [A != B]: " << (MAP_A != MAP_B) << std::endl;
	os << "MAP [A < B]: " << (MAP_A < MAP_B) << std::endl;
	os << "MAP [A <= B]: " << (MAP_A <= MAP_B) << std::endl;
	os << "MAP [A > B]: " << (MAP_A > MAP_B) << std::endl;
	os << "MAP [A >= B]: " << (MAP_A >= MAP_B) << std::endl;

	buffer_clean(logM, os);
	return SUCCESS;
}

int		MapTest(void)
{
	std::cout << "=======  Map  =======\n";
	logM.open(MAPFILE, std::ios_base::trunc);

	if (map_construct()) OK();
	else KO();
	if (map_iterator()) OK();
	else KO();
	if (map_access()) OK();
	else KO();
	if (map_empty()) OK();
	else KO();
	if (map_max_size()) OK();
	else KO();
	if (map_size()) OK();
	else KO();
	if (map_swap()) OK();
	else KO();
	if (map_erase()) OK();
	else KO();
	if (map_erase2()) OK();
	else KO();
	if (map_clear()) OK();
	else KO();
	if (map_insert()) OK();
	else KO();
	if (map_find()) OK();
	else KO();
	if (map_count()) OK();
	else KO();
	if (map_lower_bound()) OK();
	else KO();
	if (map_upper_bound()) OK();
	else KO();
	if (map_equal_range()) OK();
	else KO();
	if (map_key_comp()) OK();
	else KO();
	if (map_value_comp()) OK();
	else KO();
	if (map_operator()) OK();
	else KO();

	buffer_clean(logM, os);
	logM.close();
	std::cout << "check " << MAPFILE << "!\n";
	return (SUCCESS);
}
