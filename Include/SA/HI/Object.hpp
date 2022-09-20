// Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_HI_OBJECT_GUARD
#define SAPPHIRE_HI_OBJECT_GUARD

#include <SA/Support/Debug.hpp>

namespace SA
{
	namespace HI
	{
		class Object
		{
	#if SA_DEBUG

			/// Ensure interface as been created / destroyed.
			bool bCreated = false;

	#endif

		protected:

			/**
			*	Check if interface as been properly created (bCreated = true).
			*	Assertion thrown on failure.
			*/
			void CheckCreated() const;

			/**
			*	Virtual destructor.
			*	Ensure correct polymorphism destruction.
			*/
	#if SA_DEBUG
			virtual ~Object() noexcept(false);
	#else
			virtual ~Object();
	#endif

			/**
			*	\brief Create and initialize this interface.
			*/
			virtual void Create();

			/**
			*	\brief Destroy this interface.
			*/
			virtual void Destroy();
		};
	}
}

#endif // SAPPHIRE_HI_OBJECT_GUARD
