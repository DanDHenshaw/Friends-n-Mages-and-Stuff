#pragma once

#include <SFML/Graphics.hpp>
#include "../../sqlite/sqlite3.h"

#include "vector"

namespace Insignia
{
	class LeaderboardManager
	{
	public:
		LeaderboardManager();
		~LeaderboardManager() {}

		void SaveScore(const std::string name, const int score);

		struct result
		{
			std::string id;
			std::string name;
			std::string score;

			bool operator<(const result& a) const
			{
				return stoi(score) > stoi(a.score);
			}
		};

		void GetResults();

		std::vector<result> _results;

	private:
		sqlite3* db;

		int _gNumRecords = 0;
		std::string sqlQuery;

		void RunSQL(const std::string& sql, sqlite3* db, int (*pCallback)(void*, int, char**, char**) = nullptr, const std::string& okPrompt = "RunSQL", const std::string& errorPrompt = "RunSQL");

		static int callbackRecords(void* p, int numF, char** arv, char** arn);
		static int callback(void* pNotUsed, int numF, char** arrVals, char** arrNames);
	};
}