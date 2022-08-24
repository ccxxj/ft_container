#pragma once

namespace ft
{
    template <bool, typename T = void>
	struct enable_if
	{};

	template <class T>
	struct enable_if<true, T>
	{
		typedef T type;
	};
}