#include "CYOND.hpp"

template <typename ARestriction> CYOND::Variable<ARestriction>::Variable() noexcept :
	FType(Type::NONE)
{
	static_assert(std::is_same<ARestriction, void>::value || std::is_base_of<Object, ARestriction>::value, "Invalid variable restriction")
}

template <typename ARestriction> template <typename AOtherRestriction> CYOND::Variable<ARestriction>::Variable(const Variable<AOtherRestriction>& ACopy) noexcept {
	if (std::is_same<ARestriction, void>::value
		|| std::is_same<ARestriction, AOtherRestriction>::value
		|| std::is_base_of<ARestriction, AOtherRestriction>::value
		//Simple/downcast
		|| dynamic_cast<ARestriction*>(&ACopy.FObject) != nullptr) {
		//Upcast
		FType = ACopy.FType;
		if (FType == Type::OBJECT)
			FObject = ACopy.FObject;
		else if (FType == Type::NUMBER)
			FNumber = ACopy.FNumber;
	}
	else
		//Badcast, null out
		FType = Type::NONE;
}

template <typename ARestriction> CYOND::Variable<ARestriction>::~Variable() {
	if (FType == Type::OBJECT)
		FObject.~ObjectReference();
}