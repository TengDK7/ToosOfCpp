#pragma once
#include<string>

namespace JsonInterface
{
	class IJson
	{
	public:
		virtual std::string Serialize() const = 0;
		virtual bool Deserialize(const std::string& content) = 0;
	};
}