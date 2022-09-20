// Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.

#include <Object.hpp>

#include <SA/Collections/Debug>

namespace SA
{
	namespace HI
	{
	#if SA_DEBUG

		Object::~Object() noexcept(false)
		{
			SA_ASSERT(Default, SA.HI, !bCreated,
				L"Destructor called without previously calling Destroy().",
				L"Call interface->Destroy() before object destruction.")

		}

	#else

		Object::~Object()
		{
			
		}

	#endif


		void Object::Create()
		{
	#if SA_DEBUG

			bCreated = true;

	#endif
		}

		void Object::Destroy()
		{
			// Ensure single deletion.
			CheckCreated();

	#if SA_DEBUG

			bCreated = false;

	#endif
		}

		void Object::CheckCreated() const
		{
	#if SA_DEBUG

			SA_ASSERT(Default, SA.HI, bCreated,
				L"Interface must be previously created.",
				L"Call interface->Create().");

	#endif
		}
	}
}
