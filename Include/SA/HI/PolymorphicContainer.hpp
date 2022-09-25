// Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_HI_POLYMORPHIC_CONTAINTER_GUARD
#define SAPPHIRE_HI_POLYMORPHIC_CONTAINTER_GUARD

#include <list>
#include <vector>

namespace SA
{
	namespace HI
	{
		template <template<typename...> class ContainerT, typename T>
		class PolymorphicContainer
		{
			ContainerT<T*> mHandle;

		public:
			using iterator = ContainerT<T*>::iterator;
			using const_iterator = ContainerT<T*>::const_iterator;

			PolymorphicContainer() = default;
			PolymorphicContainer(PolymorphicContainer&&) = default;
			PolymorphicContainer(const PolymorphicContainer&) = delete;

			~PolymorphicContainer()
			{
				Clear();
			}

			template <typename DerivT>
			PolymorphicContainer(std::vector<DerivT>&& _derivVec)
			{
				mHandle.reserve(_derivVec.size());

				for (auto it = _derivVec.begin(); it != _derivVec.end(); ++it)
					mHandle.emplace_back(new DerivT(std::move(*it)));
			}


			void Clear()
			{
				for (T* elem : mHandle)
					delete elem;

				mHandle.clear();
			}


		//{ Iterators

			iterator begin()
			{
				return mHandle.begin();
			}

			const_iterator begin() const
			{
				return mHandle.begin();
			}

			iterator end()
			{
				return mHandle.end();
			}

			const_iterator end() const
			{
				return mHandle.end();
			}

		//}

		//{ Accessors

			T* operator[](uint32_t _index)
			{
				return mHandle[_index];
			}

			const T* operator[](uint32_t _index) const
			{
				return mHandle[_index];
			}

		//}
		};

	//{ Aliases

		template <typename T>
		using PolymorphicVector = PolymorphicContainer<std::vector, T>;

		template <typename T>
		using PolymorphicList = PolymorphicContainer<std::list, T>;

	//}
	}
}

#endif // SAPPHIRE_HI_POLYMORPHIC_CONTAINTER_GUARD
