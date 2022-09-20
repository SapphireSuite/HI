// Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.

#include <gtest/gtest.h>

#include <SA/Collections/Debug>
#include <SA/HI/Interface.hpp>
using namespace SA;

namespace SA::UT::HI
{
#if SA_DEBUG
	// Only throw on debug.
	#define SA_INTERFACE_THROW_TEST(statement) EXPECT_THROW(statement, Exception_Default)
#else
	// Never throw on release.
	#define SA_INTERFACE_THROW_TEST(statement) EXPECT_NO_THROW(statement)
#endif

	class MyInterface : private SA::HI::Interface
	{
	public:
		using SA::HI::Interface::Create;
		using SA::HI::Interface::Destroy;

		void Hello()
		{
			CheckCreated();

			SA_LOG("Hello, World!");
		}
	};


	TEST(HardwareInterface, NoCreateNoDestroy)
	{
		MyInterface intf;
	}

	TEST(HardwareInterface, CreateNoDestroy)
	{
		SA_INTERFACE_THROW_TEST([]()
		{
			MyInterface intf;

			intf.Create();

			// Destructor throw.

		}());
	}

	TEST(HardwareInterface, NoCreateDestroy)
	{
		SA_INTERFACE_THROW_TEST([]()
		{
			MyInterface intf;

			intf.Destroy();

		}());
	}

	TEST(HardwareInterface, CreateDestroy)
	{
		MyInterface intf;

		intf.Create();
		intf.Destroy();
	}

	TEST(HardwareInterface, NoCreateCheck)
	{
		SA_INTERFACE_THROW_TEST([]()
		{
			MyInterface intf;

			intf.Hello();

		}());
	}

	TEST(HardwareInterface, CreateCheck)
	{
		MyInterface intf;

		intf.Create();

		intf.Hello();

		intf.Destroy();
	}
}
