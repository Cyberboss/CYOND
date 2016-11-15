#pragma once

namespace CYOND {
	class Object;
	namespace Internal {
		//! @brief A linked list inherited from 
		class ObjectForwardReference {
		protected:
			ObjectForwardReference* FNext;	//!< @brief The next object in the list
		protected:
			/*!
				@brief Initializer for FNext
				@param ANext The initial value of FNext
			*/
			ObjectForwardReference(ObjectForwardReference* ANext);
		};

		//! @brief A double linked list used for objects to track references to itself when Del'd
		class ObjectReference : public ObjectForwardReference {
		private:
			Object& FObject;	//!< @brief The Object being referenced
			ObjectReference* FPrevious;	//!< @brief The previous object reference in the list
		public:
			/*!
				@brief Creates a new reference set on another ObjectForwardReference
				@param AObject The object to initialize the reference with
			*/
			ObjectReference(ObjectForwardReference& AObject);
			/*!
				@brief Removes itself from the list and deletes the Object if it is unreferenced
			*/
			~ObjectReference();
		};
	};

};