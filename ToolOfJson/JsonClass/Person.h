#pragma once
#include"../Interface/IJson.h"
#include<string>

namespace JsonClass
{
	class Person:JsonInterface::IJson
	{
	public:
		Person() {}
		Person(const std::string& name,const std::string id,const std::string address,const std::string phoneNum,int age);
		virtual std::string Serialize() const override;
		virtual bool Deserialize(const std::string& content) override;
	private:
		std::string m_name;
		std::string m_id;
		std::string m_address;
		std::string m_phoneNum;
		int m_age;
	};
}
