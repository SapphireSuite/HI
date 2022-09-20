// Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_HI_INTERFACE_GUARD
#define SAPPHIRE_HI_INTERFACE_GUARD

#include "Object.hpp"

namespace SA
{
	namespace HI
	{
		class Interface : protected Object
		{
		protected:
			/**
			*	\brief Clear all previously created/registered elements from this interface.
			*/
			virtual void Clear();

			/// Calls Clear().
			void Destroy() override;
		};
	}
}

#endif // SAPPHIRE_HI_INTERFACE_GUARD
