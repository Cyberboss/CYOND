#pragma once

namespace CYOND {
	//! @brief Anything that needs to be allocated in the heap (Dynamic lists/strings, datums with unscoped life)
	class Object : public Internal::ObjectForwardReference {
	public:
		/*!
			@brief Initializes it's parent to null
		*/
		Object();
		/*!
			@brief Used to implement destructors
		*/
		virtual ~Object() = default;
	};
};