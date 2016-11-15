#pragma once

namespace CYOND {
	class Object;
	namespace Internal {
		//! @brief A linked list inherited from 
		class ObjectForwardReference {
		public:
			Object& FObject;	//!< @brief The Object being referenced
		protected:
			ObjectForwardReference* FNext;	//!< @brief The next object in the list
		protected:
			/*!
				@brief Initializer for FObject
				@param AObject The object being referenced
			*/
			ObjectForwardReference(Object& AObject) noexcept;
		public:
			/*!
				@brief Update the forward reference
				@param ANext The new next reference in the list
			*/
			void Set(ObjectForwardReference* const ANext) noexcept;
		};

		//! @brief A double linked list used for objects to track references to itself when Del'd
		class ObjectReference : public ObjectForwardReference {
		private:
			ObjectForwardReference* FPrevious;	//!< @brief The previous object reference in the list
		public:
			/*!
				@brief Creates a new reference on an Object
				@param AObject The object to initialize the reference with
			*/
			ObjectReference(Object& AObject) noexcept;
			/*!
				@brief Removes itself from the list and deletes the Object if it is unreferenced
			*/
			~ObjectReference() noexcept;
		};
	};

};