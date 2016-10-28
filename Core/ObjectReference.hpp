#pragma once
#include "Object.hpp"
namespace CYOND {
	//! @brief A double linked list used for objects to track references to itself when Del'd
	class ObjectReference {
	private:
		Object& FObject;
		ObjectReference* FPrevious, *FNext;
	};
};