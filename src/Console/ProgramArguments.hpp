#pragma once

#include <vector>
#include <map>
#include <ctime>

#include <GeoGen/GeoGen.hpp>

namespace geogen
{
	namespace console
	{
		struct ProgramArguments
		{
			bool debug = false;
			bool displayHelp = false;
			bool isNonInteractive = false;
			String inputFile = GG_STR("");
			String outputDirectory = GG_STR(".");
			String seed = GG_STR("");
			std::map<String, String> scriptArgumentsStrings;
		};
	}
}