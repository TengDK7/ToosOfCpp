#include"Person.h"
#include"json.h"

namespace JsonClass
{
	Person::Person(const std::string& name, const std::string id, const std::string address, const std::string phoneNum, int age)
	{
		m_name = name;
		m_id = id;
		m_address = address;
		m_phoneNum = phoneNum;
		m_age = age;
	}

	std::string Person::Serialize() const
	{
		static Json::Value def = []() {
			Json::Value def;
			Json::StreamWriterBuilder::setDefaults(&def);
			def["emitUTF8"] = true;
			def["indentation"] = "";
			return def;
		}();
		Json::Value root;

		root["Name"] = m_name.c_str();
		root["Id"] = m_id.c_str();
		root["Address"] = m_address.c_str();
		root["PhoneNumber"] = m_phoneNum.c_str();
		root["Age"] = m_age;

		std::ostringstream stream;
		Json::StreamWriterBuilder stream_builder;
		stream_builder.settings_ = def;
		std::unique_ptr<Json::StreamWriter> writer(stream_builder.newStreamWriter());
		writer->write(root, &stream);
		return stream.str();
	}

	bool Person::Deserialize(const std::string& content)
	{
		if (content.empty())
			return false;
		try
		{
			const char* contentchar = content.data();
			Json::CharReaderBuilder builder;
			Json::CharReader* reader(builder.newCharReader());
			Json::Value root;
			JSONCPP_STRING errs;

			bool isok = reader->parse(contentchar, contentchar + std::strlen(contentchar), &root, &errs);
			if (!isok || errs.size() > 0)
				return false;

			m_name = root["Name"].asString();
			m_id = root["Id"].asString();
			m_address = root["Address"].asString();
			m_phoneNum = root["PhoneNumber"].asString();
			m_age = root["Age"].asInt();
		}
		catch (...)
		{
			return false;
		}
		return true;
	}
}
