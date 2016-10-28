#pragma once

#include "ObjectReference.hpp"
namespace CYOND {
	//! @brief Basic variable on the stack, should be copied when passed as a function argument
	class Variable {
	public:
		enum class Type {
			NONE,
			INT,
			DOUBLE,
			STRING,
			LIST,
			DATUM,
		};
	private:
		union {
			double FDouble;
			int FInt;
			ObjectReference FObject;
		};
		bool FAssigned;
	};
};