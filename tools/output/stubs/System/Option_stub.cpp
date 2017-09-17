/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#ifndef _OPTION_CPP
#define _OPTION_CPP

#include "System/Option.h"

#include "System/Util.h"
#include "System/Exceptions.h"
#include "System/Log/ILog.h"
#include "System/FileSystem/FileSystem.h"
#include "System/FileSystem/ArchiveScanner.h"
#include "Lua/LuaParser.h"
#include "Map/MapParser.h"

#include <assert.h>

static const char* Option_badKeyChars = " =;\r\n\t";

std::string option_getDefString(const Option& option) {

	std::string def = "";

	switch (option.typeCode) {
		case opt_bool:
			def = option.boolDef ? "true" : "false";
			break;
		case opt_list:
			def = option.listDef;
			break;
		case opt_number: {
			static const size_t fltString_sizeMax = 32;
			char fltString[fltString_sizeMax];
			SNPRINTF(fltString, fltString_sizeMax, "%f", option.numberDef);
			def += fltString;
			break;
		}
		case opt_string:
			def = option.stringDef;
			break;
		case opt_error:
		case opt_section:
		default:
			break;
	}

	return def;
}

static void option_parseOption(const LuaTable& root, int index, Option& opt,
		std::set<string>& optionsSet) {

	const LuaTable& optTbl = root.SubTable(index);
	if (!optTbl.IsValid()) {
		throw content_error("parseOption: subtable " + IntToString(index) + " is invalid");
	}

	// common options properties
	opt.key = optTbl.GetString("key", "");
	if (opt.key.empty()
			|| (opt.key.find_first_of(Option_badKeyChars) != string::npos)) {
		throw content_error("parseOption: (key=\"" + opt.key + "\") empty key or key contains bad characters (\"" + Option_badKeyChars + "\")");
	}
	opt.key = StringToLower(opt.key);

	opt.scope = optTbl.GetString("scope", "scope");
	if (opt.scope.find_first_of(Option_badKeyChars) != string::npos) {
		throw content_error("parseOption: (key=" + opt.key + ") scope contains bad characters (\"" + Option_badKeyChars + "\"): \"" + opt.scope + "\"");
	}
	opt.scope = StringToLower(opt.scope);

	if (optionsSet.find(opt.key) != optionsSet.end()) {
		throw content_error("parseOption: key \"" + opt.key + "\" exists already");
	}
	opt.name = optTbl.GetString("name", opt.key);
	if (opt.name.empty()) {
		throw content_error("parseOption: (key=" + opt.key + ") empty name");
	}
	opt.desc = optTbl.GetString("desc", opt.name);

	opt.section = optTbl.GetString("section", "");
	opt.style = optTbl.GetString("style", "");

	opt.type = optTbl.GetString("type", "");
	opt.type = StringToLower(opt.type);

	// option type specific properties
	if (opt.type == "bool") {
		opt.typeCode = opt_bool;
		opt.boolDef = optTbl.GetBool("def", false);
	}
	else if (opt.type == "number") {
		opt.typeCode = opt_number;
		opt.numberDef  = optTbl.GetFloat("def",  0.0f);
		opt.numberMin  = optTbl.GetFloat("min",  -1.0e30f);
		opt.numberMax  = optTbl.GetFloat("max",  +1.0e30f);
		opt.numberStep = optTbl.GetFloat("step", 0.0f);
	}
	else if (opt.type == "string") {
		opt.typeCode = opt_string;
		opt.stringDef    = optTbl.GetString("def", "");
		opt.stringMaxLen = optTbl.GetInt("maxlen", 0);
	}
	else if (opt.type == "list") {
		opt.typeCode = opt_list;

		const LuaTable& listTbl = optTbl.SubTable("items");
		if (!listTbl.IsValid()) {
			throw content_error("parseOption: (key=" + opt.key + ") subtables: items invalid");
		}

		for (int i = 1; listTbl.KeyExists(i); i++) {
			OptionListItem item;

			// string format
			item.key = listTbl.GetString(i, "");
			if (!item.key.empty() &&
			    (item.key.find_first_of(Option_badKeyChars) == string::npos)) {
				item.name = item.key;
				item.desc = item.name;
				opt.list.push_back(item);
				continue;
			}

			// table format  (name & desc)
			const LuaTable& itemTbl = listTbl.SubTable(i);
			if (!itemTbl.IsValid()) {
				throw content_error("parseOption: (key=" + opt.key + ") subtables: subtable " + IntToString(i) + " contains invalid items");
			}
			item.key = itemTbl.GetString("key", "");
			if (item.key.empty() || (item.key.find_first_of(Option_badKeyChars) != string::npos)) {
				throw content_error("parseOption: (key=" + opt.key + ") subtables: (key=\"" + item.key + "\") empty key or key contains bad characters (\"" + Option_badKeyChars + "\")");
			}
			item.key = StringToLower(item.key);
			item.name = itemTbl.GetString("name", item.key);
			if (item.name.empty()) {
				throw content_error("parseOption: (key=" + opt.key + ") subtables: (key=" + item.key + ") empty name");
			}
			item.desc = itemTbl.GetString("desc", item.name);
			opt.list.push_back(item);
		}

		if (opt.list.empty()) {
			throw content_error("parseOption: (key=" + opt.key + ") subtables: empty list");
		}

		opt.listDef = optTbl.GetString("def", opt.list[0].name);
	}
	else if (opt.type == "section") {
		opt.typeCode = opt_section;
	}
	else {
		throw content_error("parseOption: (key=" + opt.key + ") unknown type \"" + opt.type + "\"");
	}

	optionsSet.insert(opt.key);
}


static void option_parseOptionsInternal(
		std::vector<Option>& options,
		LuaParser& luaParser,
		const std::string& luaSourceDesc,
		std::set<std::string>* optionsSet)
{
    //stub method
}

void option_parseOptions(
		std::vector<Option>& options,
		const std::string& fileName,
		const std::string& fileModes,
		const std::string& accessModes,
		std::set<std::string>* optionsSet)
{
    //stub method
}

void option_parseOptionsLuaString(
		std::vector<Option>& options,
		const std::string& optionsLuaString,
		const std::string& accessModes,
		std::set<std::string>* optionsSet)
{
    //stub method
}


void option_parseMapOptions(
		std::vector<Option>& options,
		const std::string& fileName,
		const std::string& mapName,
		const std::string& fileModes,
		const std::string& accessModes,
		std::set<std::string>* optionsSet)
{
    //stub method
}

#endif // _OPTION_CPP
