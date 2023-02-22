#include "LeaderboardManager.h"
#include "DEFINITIONS.h"

#include <cassert>
#include <iostream>
#include <sstream>

namespace Insignia
{
	int gNumRecords = 0;
	std::vector<LeaderboardManager::result> results;

	LeaderboardManager::LeaderboardManager()
	{
		int rc = sqlite3_open(LEADERBOARD_NAME, &db);

		if(rc)
		{
			std::cout << sqlite3_errmsg(db);
			assert(false);
		}

		// Check if SQL table exists
		sqlQuery = "SELECT name FROM sqlite_master WHERE type = 'table' AND name = 'HIGHSCORES'";
		RunSQL(sqlQuery, db, callbackRecords, "Create Table");
		_gNumRecords = gNumRecords;
		if(_gNumRecords == 0)
		{
			// Create SQL table
			sqlQuery = "CREATE TABLE HIGHSCORES(					 " \
			"ID			INTEGER			PRIMARY KEY			        ," \
			"NAME		CHAR(26)							NOT NULL," \
			"SCORE		INTEGER								NOT NULL);" ;

			RunSQL(sqlQuery, db, nullptr, "HIGHSCORES Table Created");
		}
	}

	int LeaderboardManager::callback(void* pNotUsed, int numF, char** arrVals, char** arrNames) {
		std::stringstream ss;

		result result;

		int i;
		for (i = 0; i < numF; i++) {
			if(strcmp(arrNames[i], "ID") == 0)
			{
				result.id = (arrVals[i] ? arrVals[i] : "NULL");
			} else if (strcmp(arrNames[i], "NAME") == 0)
			{
				result.name = (arrVals[i] ? arrVals[i] : "NULL");
			} else if (strcmp(arrNames[i], "SCORE") == 0)
			{
				result.score = (arrVals[i] ? arrVals[i] : "NULL");

				std::cout << "ID: " << result.id << " NAME: " << result.name << " SCORE: " << result.score << std::endl;
				
				results.push_back(result);
			}
		}

		return 0;
	}

	int LeaderboardManager::callbackRecords(void* p, int numF, char** arv, char** arn) {
		gNumRecords++;
		return 0;
	}

	void LeaderboardManager::RunSQL(const std::string& sql, sqlite3* db, int (* pCallback)(void*, int, char**, char**), const std::string& okPrompt, const std::string& errorPrompt)
	{
		assert(!sql.empty() && db);
		char* zErrMsg = nullptr;
		int rc = sqlite3_exec(db, sql.c_str(), pCallback, 0, &zErrMsg);
		if (rc != SQLITE_OK) {
			std::cout << "SQL error: " << errorPrompt << " " << zErrMsg << std::endl;
			sqlite3_free(zErrMsg);
		}
		else {
			std::cout << "OK: " << okPrompt << std::endl;
		}
	}

	void LeaderboardManager::GetResults()
	{
		this->_results.clear();
		results.clear();

		sqlQuery = "SELECT * FROM HIGHSCORES";
		RunSQL(sqlQuery, db, callback);
		_results.assign(results.begin(), results.end());

		std::sort(_results.begin(), _results.end());
	}

	void LeaderboardManager::SaveScore(const std::string name, const int score)
	{
		GetResults();

		bool notFound = true;

		for(size_t i = 0; i < _results.size(); i++)
		{
			if(_results[i].name == name)
			{
				if (std::stoi(_results[i].score) <= score)
				{
					_results[i].score = std::to_string(score);

					std::stringstream ss;
					ss << "UPDATE HIGHSCORES SET SCORE = '" << _results[i].score << "' WHERE ID = '" << _results[i].id << "';";
					sqlQuery = ss.str();
					RunSQL(sqlQuery, db, nullptr, "Updated HIGHSCORE Data");
				}
				notFound = false;
			}
		}

		if(notFound)
		{
			std::stringstream ss;
			ss << "INSERT INTO HIGHSCORES (NAME,SCORE) VALUES ('" << name << "'," << score << ");";
			sqlQuery = ss.str();
			RunSQL(sqlQuery, db, nullptr, "HIGHSCORE Data Inserted Into Table");
		}

		std::sort(_results.begin(), _results.end());
	}
};