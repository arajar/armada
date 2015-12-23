#pragma once

#include <core/util/singleton.h>
#include "IResource.h"

class Image;
class Font;

namespace content
{
	class manager : public core::singleton<manager>
	{
	public:
		manager() = default;
		virtual ~manager() { Unload(); }

	public:
		void init(const std::string& path)
		{
			m_pathToContent = path;
		}

	public:
		template<class Resource, class... _Types>
		Resource* get(const std::string& name, _Types&&... _Args)
		{
			if (m_resources[name] != nullptr)
			{
				return static_cast<Resource*>(m_resources[name]);
			}

			auto path = m_pathToContent;
			path += name;

			auto res = new Resource(path, std::forward<_Types>(_Args)...);

			if (res)
			{
				res->load();
				m_resources[name] = res;
			}

			return res;
		}

		void Unload()
		{
			for (auto res : m_resources)
			{
				delete res.second;
				res.second = nullptr;
			}

			m_resources.clear();
		}

	private:
		std::string m_pathToContent;

		std::map<std::string, IResource*> m_resources;
	};
}
