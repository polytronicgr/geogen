#pragma once

#include <stdexcept>

#include "CompilerException.hpp"
#include "..\Dimension.hpp"

namespace geogen
{
	namespace compiler
	{		
		/// Exception thrown when error geogen::GGE1412_MinGreaterThanMaxMapSize occurs.
		class MinGreaterThanMaxSizeException : public CompilerException
		{
		private:
			Dimension dimension;
		public:

			/// Constructor.
			/// @param location The location.
			/// @param dimension The dimension.
			MinGreaterThanMaxSizeException(CodeLocation location, Dimension dimension) :
				CompilerException(GGE1412_MinGreaterThanMaxMapSize, location), dimension(dimension) {};

			/// Gets the dimension.
			/// @return The dimension.
			inline Dimension GetDimension() const { return this->dimension; }

			virtual String GetDetailMessage()
			{
				StringStream ss;
				ss << "The minimum size was greater than the maximum size in dimension \"" << DimensionToString(dimension) << "\" on line " << GetLocation().GetLine() << ", column " << GetLocation().GetColumn() << ".";

				return ss.str();
			}
		};
	}
}