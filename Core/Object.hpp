#pragma once

namespace CYOND {
	//! @brief Anything that needs to be allocated in the heap (Dynamic lists/strings, datums with unscoped life)
	class Object : public Internal::ObjectForwardReference {
	public:
		/*!
			@brief Initializes it's parent to null
		*/
		Object() noexcept;
		/*!
			@brief Used to implement destructors
		*/
		virtual ~Object() = default;

		/*!
			@brief A signal that a reference to this object has been destroyed and the object should check if it has any other references. If not delete itself
		*/
		void ReferenceRemoved(void) noexcept;
	};
};