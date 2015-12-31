#pragma once

#include <iostream>
#include <sstream>
#include <memory>
#include <mutex>

#if defined(_WIN32)
#include <Windows.h>
#endif

#include "format.h"

namespace util
{
	template <typename charT = char>
	class basic_logger
	{
	public:
		enum class Level
		{
			Debug,
			Info,
			Warning,
			Error,
		};

	public:
		basic_logger(Level minLevel = Level::Debug,
			bool color = false,
			std::basic_ostream<charT>& os = std::cout)
			: m_minLevel(minLevel)
			, m_color(color)
			, m_os(os)
		{}

		Level minLevel() const
		{
			return m_minLevel;
		}

#if defined(_WIN32)
		template <class... Ts>
		basic_logger& operator()(Level level, Ts... args)
		{
			if (level >= m_minLevel)
			{
				HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

				switch (level)
				{
				case Level::Debug:
					SetConsoleTextAttribute(hConsole, 15 | FOREGROUND_INTENSITY);
					_log("[DEBUG] ");
					SetConsoleTextAttribute(hConsole, 15 & FOREGROUND_INTENSITY);
					break;
				case Level::Info:
					SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
					_log("[INFO] ");
					SetConsoleTextAttribute(hConsole, 15 & FOREGROUND_INTENSITY);
					break;
				case Level::Warning:
					SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
					_log("[WARNING] ");
					SetConsoleTextAttribute(hConsole, 15 & FOREGROUND_INTENSITY);
					break;
				case Level::Error:
					SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
					_log("[ERROR] ");
					SetConsoleTextAttribute(hConsole, 15 & FOREGROUND_INTENSITY);
					break;
				}

				auto message = util::format(args..., "\n");
				message += "\n";
				_log(message);

				m_os.flush();
			}

			return *this;
		}
#else
		template <class... Ts>
		basic_logger& operator()(Level level, Ts... args)
		{
			if (level >= (int)m_minLevel)
			{
				std::string prefix =
					level == Level::Debug ? ">>> [DEBUG] " :
					level == Level::Info ? ">> [INFO] " :
					level == Level::Warning ? std::string(m_color ? "\e[33m" : "")
					+ "> [WARNING] " :
					/*level == ERROR  */ std::string(m_color ? "\e[31m" : "")
					+ " [ERROR] ";
				_log(prefix, args...);
				if (m_color)
				{
					_log("\e[37m");
				}

				m_os.flush();
			}

			return *this;
		}
#endif

		template <class... Ts>
		basic_logger& debug(Ts... args)
		{
#if defined(_DEBUG)
			return operator()(Level::Debug, args...);
#else
			return *this;
#endif
		}

		template <class... Ts>
		basic_logger& info(Ts... args)
		{
			return operator()(Level::Info, args...);
		}

		template <class... Ts>
		basic_logger& warning(Ts... args)
		{
			return operator()(Level::Warning, args...);
		}

		template <class... Ts>
		basic_logger& error(Ts... args)
		{
			return operator()(Level::Error, args...);
		}

	private:
		Level m_minLevel;
		bool m_color;
		std::basic_ostream<charT>& m_os;

		template<class T>
		void _log(const T& x)
		{
			m_os << x;
		}

		template <class T, class... Ts>
		void _log(const T& x, Ts... args)
		{
			_log(x);
			_log(args...);
		}
	};

	using logger = basic_logger < >;

	static logger log;

#define LOGI(...) util::log.info(...)
}