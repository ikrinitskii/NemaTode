/*
 * NumberConversion.h
 *
 *  Created on: Aug 14, 2014
 *      Author: Cameron Karlsson
 *
 *  See the license file included with this source.
 */

#ifndef NUMBERCONVERSION_H_
#define NUMBERCONVERSION_H_


#include <cstdint>
#include <string>
#include <sstream>
#include <exception>
#include <utility>


namespace nmea {

class NumberConversionError : public std::exception {
public:
	std::string message;
	explicit NumberConversionError(std::string msg)
		: message(std::move(msg))
	{};

	NumberConversionError(const NumberConversionError &other) noexcept;
	~NumberConversionError() override = default;

    const char *what() const noexcept override {
	    return message.c_str();
	}
};




double parseDouble(const std::string& s);
int64_t parseInt(const std::string& s, int radix = 10);

//void NumberConversion_test();

}



#endif /* NUMBERCONVERSION_H_ */
