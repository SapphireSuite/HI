// Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.

#include <SA/Collections/HI>
using namespace SA;

class AMyClass : private HI::Object
{
public:
	using HI::Object::Create;
	using HI::Object::Destroy;
};

class API_MyClass : public AMyClass
{
};

int main()
{
//{ Init static logger instance

	SA::Logger logger;

	SA::ConsoleLogStream cslStream;
	logger.Register(cslStream);

	SA::FileLogStream fileStream;
	logger.Register(fileStream);

	// Init instance.
	SA::Debug::logger = &logger;

//}

	HI::InterfaceList<API_MyClass> apiObjects;

	API_MyClass* obj1 = apiObjects.Emplace();
	obj1->Create();

	apiObjects.Emplace()->Create();

	apiObjects.Erase(obj1);

	apiObjects.Clear();

	return 0;
}
