// Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_HI_INTERFACE_LIST_GUARD
#define SAPPHIRE_HI_INTERFACE_LIST_GUARD

#include <forward_list>

#include <SA/Collections/Debug>

#include "Object.hpp"

namespace SA
{
	namespace HI
	{
	// { Functor

		template <typename T>
		struct DefaultFunctor
		{
			void operator()(T& _in) { _in.Destroy(); };
		};

		template <typename T>
		struct NoneFunctor
		{
			void operator()(T& _in) { (void)_in; };
		};

	//}


		template <typename T>
		class InterfaceList
		{
			std::forward_list<T> mObjects;

		public:
			InterfaceList() noexcept;

			template <typename... Args>
			T* Emplace(Args&&... _args);

			/**
			 * @brief 
			 * 
			 * @tparam AT       Abstract T type from interface.
			 * @param _object 
			 * @param destroyer 
			 * @return true 
			 * @return false 
			 */
			template <typename AT, typename DestroyFunctor = DefaultFunctor<T>>
			bool Erase(AT* _object, DestroyFunctor _destroyer = DestroyFunctor());

			template <typename DestroyFunctor = DefaultFunctor<T>>
			void Clear(DestroyFunctor _destroyer = DestroyFunctor());
		};
	}
}

#include "InterfaceList.inl"

#endif // SAPPHIRE_HI_INTERFACE_LIST_GUARD
