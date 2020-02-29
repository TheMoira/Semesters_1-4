#include "ConsolePrinter.h"
#include "MyText.h"
#include "MyLine.h"
#include <iostream>

ConsolePrinter::ConsolePrinter(unsigned int width)
	: m_width(width) 
{

}

////////////////////////////////////////////////////////////////////////
//  Jedyna metoda klasy MyPrinter ktora powinni Panstwo modyfikowac.  //
////////////////////////////////////////////////////////////////////////
void ConsolePrinter::print( const StringConvertable & obj ) const
{
	const AttColor* col = dynamic_cast<const AttColor*>(&obj); //musi byc dynamic_cast!!!
	const AttFormat* form = dynamic_cast<const AttFormat*>(&obj);
	
		if(form)
	{
		std::cout<<ConsolePrinter::controlSeq(form->getFormat());
	}

	if(col)
	{
		std::cout<<ConsolePrinter::controlSeq(col->getColor());
	}


	std::cout<<obj.rawString()<<std::endl;
	
}

////////////////////////////////////////////////////////////////////////
///                                                                  ///
///          ANSI/VT100 TERMINAL OUTPUT CONTROL SEQUENCES            ///
///                                                                  ///
////////////////////////////////////////////////////////////////////////

const char * ConsolePrinter::resetSeq()
{
	return "\e[0m";
}

// formats: BOLD, DIM, UNDERLINED, RESET
const char * ConsolePrinter::controlSeq( AttFormat::Option opt )
{
	switch(opt)
	{
		case AttFormat::BOLD :
			return "\e[1m";
		case AttFormat::DIM :
			return "\e[2m";
		case AttFormat::UNDERLINED :
			return "\e[4m";
		default:
			return resetSeq();
	}
}

// colors: BLACK, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, GRAY, WHITE, RESET
const char * ConsolePrinter::controlSeq( AttColor::Option opt )
{
	switch(opt)
	{
		case AttColor::BLACK :
			return "\e[30m";
		case AttColor::RED :
			return "\e[31m";
		case AttColor::GREEN :
			return "\e[32m";
		case AttColor::YELLOW :
			return "\e[33m";
		case AttColor::BLUE :
			return "\e[34m";
		case AttColor::MAGENTA :
			return "\e[35m";
		case AttColor::CYAN :
			return "\e[36m";
		case AttColor::GRAY :
			return "\e[90m";
		case AttColor::WHITE  :
			return "\e[97m";
		default:
			return resetSeq();
	}
}

