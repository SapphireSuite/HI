// Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.

#include <Interface.hpp>

namespace SA
{
	namespace HI
	{
		void Interface::Clear()
		{
			CheckCreated();
		}

		void Interface::Destroy()
		{
			Clear();

			Object::Destroy();
		}
	}
}
