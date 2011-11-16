solution "Cinema"
	configurations {"Debug", "Release"}

	project "Cinema"
		kind "ConsoleApp"
		language "C++"
		files {"**.h", "**.cpp"}

		configuration "Debug"
			defines {"DEBUG"}
			flags {"Symbols"}

		configuration "Release"
			defines {"NDEBUG"}
			flags {"Optimize"}