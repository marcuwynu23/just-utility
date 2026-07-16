/*
 *   Copyright (c) 2023 
 *   All rights reserved.
 */
#include "runner.h"

static void showHelp() {
    cout << "NAME" << endl;
    cout << "     arts - Laravel Artisan command helper" << endl;
    cout << endl;
    cout << "SYNOPSIS" << endl;
    cout << "     arts [--help | -h | <command>]" << endl;
    cout << endl;
    cout << "DESCRIPTION" << endl;
    cout << "     Provides quick access to common Laravel Artisan commands." << endl;
    cout << "     Run without arguments to see the list of available commands." << endl;
    cout << endl;
    cout << "COMMANDS" << endl;
    cout << "     serve             Starts a local development server at http://localhost:8000" << endl;
    cout << "     controller        Creates a new controller class" << endl;
    cout << "     migration         Creates a new database migration" << endl;
    cout << "     model             Creates a new Eloquent model class" << endl;
    cout << "     migrate           Runs any outstanding database migrations" << endl;
    cout << "     migrate_refresh   Rolls back and re-runs all migrations" << endl;
    cout << "     config_cache      Caches the configuration for faster performance" << endl;
    cout << endl;
    cout << "OPTIONS" << endl;
    cout << "     --help, -h  Show this help message and exit" << endl;
    cout << endl;
    cout << "DEPENDENCIES" << endl;
    cout << "     php (PHP CLI)" << endl;
    cout << "     Laravel project with Artisan in the current directory" << endl;
    cout << endl;
    cout << "EXAMPLES" << endl;
    cout << "     arts serve                 Start the dev server" << endl;
    cout << "     arts migration             Create a new migration" << endl;
    cout << "     arts --help                Show this help" << endl;
}

int main(int argc, char const *argv[]) {
  if (argc > 1) {
    string arg1 = argv[1];
    if (arg1 == "--help" || arg1 == "-h") { showHelp(); return 0; }
  }
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
      showHelp();
    }else {

  peculiar::print("Command not found. Run 'help' for a list of available commands.");

    }

	}else{
    showHelp();
	}
  return 0;
}
