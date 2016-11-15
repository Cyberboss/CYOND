#pragma once

namespace CYOND {
	//! @brief Basic variable on the stack, should be copied when passed as a function argument
	template <typename ARestriction = void> class Variable {
	public:
		enum class Type : byte {
			NONE,	//!< @brief The variable is unassigned
			NUMBER,	//!< @brief The variable is a double
			OBJECT,	//!< @brief The variable has a valid ObjectReference
		};
	private:
		union {
			double FDouble;	//!< @brief The stored number
			Internal::ObjectReference FObject;	//!< @brief The stored ObjectReference
		};
		Type FType;	//!< @brief The current type of the variable
	public:
		/*!
			@brief Constructs a nulled out Variable
		*/
		Variable();
		/*!
			@brief Needed to properly copy FObject
			@param ACopy The Variable to copy from
		*/
		Variable(const Variable& ACopy);
		/*!
			@brief Copy semantics are enough, this is not required
		*/
		Variable(Variable&&) = delete;
		/*!
			@brief Needed to properly destroy FObject
		*/
		~Variable();
	};
};