#pragma once

#include <algorithm>
#include <iostream>

template<typename T>
typename T::iterator easyfind(T &container, int toFind);

#include "easyfind.tpp"