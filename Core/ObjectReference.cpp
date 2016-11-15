#include "CYOND.hpp"

CYOND::Internal::ObjectForwardReference::ObjectForwardReference(Object& AObject) noexcept :
	FObject(AObject),
	FNext(AObject.FNext)
{
	AObject.FNext = this;
}

void CYOND::Internal::ObjectForwardReference::Set(ObjectForwardReference* const ANext) noexcept {
	FNext = ANext;
}

CYOND::Internal::ObjectReference::ObjectReference(Object& AObject) noexcept :
	ObjectForwardReference(AObject),
	FPrevious(&AObject)
{}

CYOND::Internal::ObjectReference::~ObjectReference() {
	FPrevious->Set(FNext);
	FObject.ReferenceRemoved();
}