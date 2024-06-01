/*
 *   Copyright (c) 2023 
 *   All rights reserved.
 */
#include "runner.h"

int main(int argc, char const *argv[]) {
  // clone current  instance of terminal.
  if (argv[1] != NULL) {
string arg1,arg2;
    arg1 = argv[1];
    if (arg1 == "serve") {
      peculiar::runExe("php artisan serve");
    }else if (arg1 == "controller") {
      peculiar::runExe("php artisan make:controller");
    }else if (arg1 == "migration") {
      peculiar::runExe("php artisan make:migration");
    }else if (arg1 == "model") {
      peculiar::runExe("php artisan make:model");
    }else if (arg1 == "migrate") {
      peculiar::runExe("php artisan migrate");
    } else if (arg1 == "migrate_refresh") {
      peculiar::runExe("php artisan migrate:refresh");
    }else if (arg1 == "config_cache") {
      peculiar::runExe("php artisan config:cache");
    }else if (arg1 == "help") {
      peculiar::print("Available commands:");
      peculiar::print("serve: Starts a local development server at http://localhost:8000");
      peculiar::print("controller: Creates a new controller class");
      peculiar::print("migration: Creates a new database migration");
      peculiar::print("model: Creates a new Eloquent model class");
      peculiar::print("migrate: Runs any outstanding database migrations");
      peculiar::print("migrate_refresh: Rolls back and re-runs all migrations");
      peculiar::print("config_cache: Caches the configuration for faster performance");
    }else {

  peculiar::print("Command not found. Run 'help' for a list of available commands.");

    }

	}else{
		 peculiar::print("Available commands:");
      peculiar::print("serve: Starts a local development server at http://localhost:8000");
      peculiar::print("controller: Creates a new controller class");
      peculiar::print("migration: Creates a new database migration");
      peculiar::print("model: Creates a new Eloquent model class");
      peculiar::print("migrate: Runs any outstanding database migrations");
      peculiar::print("migrate_refresh: Rolls back and re-runs all migrations");
      peculiar::print("config_cache: Caches the configuration for faster performance");
	}
  return 0;
}
