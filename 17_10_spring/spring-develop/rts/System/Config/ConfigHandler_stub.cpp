#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "ConfigHandler.h"
#include "ConfigLocater.h"
#include "ConfigSource.h"
#include "System/Log/ILog.h"
#include "System/Util.h"

#ifdef WIN32
#include <io.h>
#endif
#include <stdio.h>
#include <string.h>

#include <list>
#include <stdexcept>

#include <boost/thread/mutex.hpp>

/******************************************************************************/

using std::list;
using std::map;
using std::string;
using std::vector;

typedef map<string, string> StringMap;

ConfigHandler* configHandler = NULL;

/******************************************************************************/

class ConfigHandlerImpl : public ConfigHandler
{
   public:
	ConfigHandlerImpl(const vector<string>& locations, const bool safemode);
	~ConfigHandlerImpl();

	void SetString(const string& key, const string& value, bool useOverlay);
	string GetString(const string& key) const;
	bool IsSet(const string& key) const;
	bool IsReadOnly(const string& key) const;
	void Delete(const string& key);
	string GetConfigFile() const;
	const StringMap GetData() const;
	StringMap GetDataWithoutDefaults() const;
	void Update();
	void EnableWriting(bool write) { writingEnabled = write; }

protected:
	struct NamedConfigNotifyCallback {
		NamedConfigNotifyCallback(ConfigNotifyCallback c, void* h)
		: callback(c)
		, holder(h)
		{}
		ConfigNotifyCallback callback;
		void* holder;
	};

protected:
	void AddObserver(ConfigNotifyCallback observer, void* holder);
	void RemoveObserver(void* holder);

private:
	void RemoveDefaults();

	OverlayConfigSource* overlay;
	FileConfigSource* writableSource;
	vector<ReadOnlyConfigSource*> sources;

	// observer related
	list<NamedConfigNotifyCallback> observers;
	boost::mutex observerMutex;
	StringMap changedValues;
	bool writingEnabled;
};

ConfigHandlerImpl::~ConfigHandlerImpl()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/**
 * @brief Remove config variables that are set to their default value.
 *
 * Algorithm is as follows:
 *
 * 1) Take all defaults from the DefaultConfigSource
 * 2) Go in reverse through the FileConfigSources
 * 3) For each one:
 *  3a) delete setting if equal to the one in `defaults'
 *  3b) add new value to `defaults' if different
 */
void
ConfigHandlerImpl::RemoveDefaults()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

StringMap
ConfigHandlerImpl::GetDataWithoutDefaults() const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
ConfigHandlerImpl::Delete(const string& key)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
ConfigHandlerImpl::IsSet(const string& key) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
ConfigHandlerImpl::IsReadOnly(const string& key) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

string
ConfigHandlerImpl::GetString(const string& key) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/**
 * @brief Sets a config string
 *
 * This does:
 * 1) Lock file.
 * 2) Read file (in case another program modified something)
 * 3) Set data[key] = value.
 * 4) Write file (so we keep the settings in the event of a crash or error)
 * 5) Unlock file.
 *
 * We do not want conflicts when multiple instances are running
 * at the same time (which would cause data loss).
 * This would happen if e.g. unitsync and spring would access
 * the config file at the same time, if we would not lock.
 */
void
ConfigHandlerImpl::SetString(const string& key,
                             const string& value,
                             bool useOverlay)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
ConfigHandlerImpl::Update()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

string
ConfigHandlerImpl::GetConfigFile() const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

const StringMap
ConfigHandlerImpl::GetData() const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
ConfigHandlerImpl::AddObserver(ConfigNotifyCallback observer, void* holder)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
ConfigHandlerImpl::RemoveObserver(void* holder)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/******************************************************************************/

void
ConfigHandler::Instantiate(const std::string configSource, const bool safemode)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
ConfigHandler::Deallocate()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/******************************************************************************/
