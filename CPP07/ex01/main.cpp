/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofeverei <ofeverei@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 16:35:39 by ofeverei          #+#    #+#             */
/*   Updated: 2026/06/08 15:44:42 by ofeverei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void appendBang(std::string &s)
{
    s += '!';
}
 
void printCharAsInt(const char &c)
{
    std::cout << static_cast<int>(static_cast<unsigned char>(c)) << "\n";
}
 
int main()
{
    // Test 1: print int array (instantiated function template as 3rd arg)
    std::cout << "=== Test 1: print int array ===\n";
    int ints[] = {1, 2, 3, 4, 5};
    iter(ints, 5, print<int>);
 
    // Test 2: mutating function on non-const array
    std::cout << "\n=== Test 2: increment int array ===\n";
    iter(ints, 5, increment<int>);
    iter(ints, 5, print<int>);   // expected: 2 3 4 5 6
 
    // Test 3: double array with doubleVal
    std::cout << "\n=== Test 3: double double[] ===\n";
    double dbls[] = {1.5, 2.5, 3.5};
    iter(dbls, 3, doubleVal<double>);
    iter(dbls, 3, print<double>);   // expected: 3 5 7
 
    // Test 4: const int array – read-only, T deduced as const int
    std::cout << "\n=== Test 4: print const int array ===\n";
    const int cints[] = {10, 20, 30};
    iter(cints, 3, print<int>);
 
    // Test 5: std::string array
    std::cout << "\n=== Test 5: print std::string array ===\n";
    std::string strs[] = {"hello", "world", "iter"};
    iter(strs, 3, print<std::string>);
 
    // Test 6: mutating strings
    std::cout << "\n=== Test 6: append '!' to strings ===\n";
    iter(strs, 3, appendBang);
    iter(strs, 3, print<std::string>);   // expected: hello! world! iter!
 
    // Test 7: char array – doubleVal (instantiated function template)
    std::cout << "\n=== Test 7: double char values ===\n";
    char chars[] = {'A', 'B', 'C'};   // 65, 66, 67
    iter(chars, 3, doubleVal<char>);
    iter(chars, 3, printCharAsInt);    // expected: 130 132 134
 
    // Test 8: zero-length – no iterations, no crash
    std::cout << "\n=== Test 8: zero-length array (no output expected) ===\n";
    iter(ints, static_cast<std::size_t>(0), print<int>);
    std::cout << "(nothing printed above)\n";
 
    // Test 9: single-element array
    std::cout << "\n=== Test 9: single-element array ===\n";
    float single[] = {3.14f};
    iter(single, 1, print<float>);
 
    return 0;
}
