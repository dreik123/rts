#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "SkirmishAIKey.h"

#include "System/creg/creg_cond.h"
#include <string>

CR_BIND(SkirmishAIKey, )

CR_REG_METADATA(SkirmishAIKey,
                (CR_MEMBER(shortName),
                 CR_MEMBER(version),
                 CR_MEMBER(interface)))

SkirmishAIKey::SkirmishAIKey(const std::string& shortName,
                             const std::string& version,
                             const AIInterfaceKey& interface)
  : shortName(shortName)
  , version(version)
  , interface(interface)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

SkirmishAIKey::SkirmishAIKey(const SkirmishAIKey& base,
		const AIInterfaceKey& interface)
		: shortName(base.shortName),
		version(base.version),
		interface(interface) {}

SkirmishAIKey::SkirmishAIKey(const SkirmishAIKey& toCopy)
		: shortName(toCopy.shortName),
		version(toCopy.version),
		interface(toCopy.interface) {}

SkirmishAIKey::~SkirmishAIKey() {}

bool
SkirmishAIKey::isLessThen(const SkirmishAIKey& otherKey) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

const std::string&
SkirmishAIKey::GetShortName() const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
const std::string&
SkirmishAIKey::GetVersion() const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
const AIInterfaceKey&
SkirmishAIKey::GetInterface() const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
SkirmishAIKey::IsUnspecified() const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
bool
SkirmishAIKey::IsFullySpecified() const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

std::string
SkirmishAIKey::ToString() const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
SkirmishAIKey::operator==(const SkirmishAIKey& otherKey) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
bool
SkirmishAIKey::operator!=(const SkirmishAIKey& otherKey) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
bool
SkirmishAIKey::operator<(const SkirmishAIKey& otherKey) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
bool
SkirmishAIKey::operator>(const SkirmishAIKey& otherKey) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
bool
SkirmishAIKey::operator<=(const SkirmishAIKey& otherKey) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
bool
SkirmishAIKey::operator>=(const SkirmishAIKey& otherKey) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
