#pragma once

#include <iostream>
#include <vector>
#include <string>

namespace decanat {
	
	template<typename T>
	std::ostream& operator<<(std::ostream& os, const std::vector<T>& source)
	{
		if (!source.empty())
		{
			os << "[";
			for (size_t i = 0; i < source.size(); ++i)
			{
				if (i > 0 && i < source.size() - 1)
				{
					os << ",";
				}
				os << source.at(i);
			}
			
			os << "]";
		}

		return os;
	}

}