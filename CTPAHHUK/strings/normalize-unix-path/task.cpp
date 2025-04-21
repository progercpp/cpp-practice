#include <string>
#include <iterator>
#include <iostream>

using namespace std;

string String_viewToString(string_view path) {
    string result = "";
    for (int i = 0; i < int(path.length()); ++i) {
        result.push_back(path[i]);
    }
    return result;
}

void delete_points(string &path) {
    string result = "";
    path += "~~~~";
    for (int i = 0; i < int(path.length()) - 2 && path[i] != '~'; ++i) {
        if (path[i] == '/' && path[i + 1] == '.' && path[i + 2] != '.') {
            i++;
            continue;
        }
        result.push_back(path[i]);
    }
    path = result;
}

void delete_slash(string &path) {
    if (path != "/" && path.back() == '/') path.pop_back();
    string nw_path = "";
    for (int i = 0; i < int(path.length()) - 1; ++i) {
        nw_path.push_back(path[i]);
        if (path[i] == '/') {
            while (i < int(path.length()) - 1 && path[i + 1] == '/') i++;
        }
    }
    nw_path.push_back(path.back());
    path = nw_path;
}

void exit_from_catalog(string& catalog) {
    if (catalog.back() != '.') {
        while (catalog.back() != '/') {
            catalog.pop_back();
        }
        if (catalog != "/") catalog.pop_back();
    }
}

void go_to_catalog(string& catalog, string to) {
    if (catalog != "/") catalog += '/' + to;
    else catalog += to;
}

void update(string& catalog, string& command) {
    if (command == "..") {
        exit_from_catalog(catalog);
    } else {
        go_to_catalog(catalog, command);
    }
    command = "";
}

string normalize(string_view path_) {
    string path = String_viewToString(path_);

    if (path == "/." || path == "/..") return "/";

    delete_points(path);
    delete_slash(path);

    // path в хорошем виде, теперь будем ходить по нему
    if (path[0] == '/') {
        string command = "";
        string catalog = "/";
        for (int i = 1; i < int(path.length()); ++i) {
            command.push_back(path[i]);
            if (path[i] == '/') {
                command.pop_back();
                update(catalog, command);
            }
        }
        update(catalog, command);
        return catalog;
    } else {
        string pref = "";
        bool flag = path[0] != '.' && path[0] != '/';
        string nw_path = "";
        for (int i = 0; i < int(path.length()); ++i) {

            if (!flag) {
                pref.push_back(path[i]);
                if (path[i] != '.' && path[i] != '/') {
                    flag = true;
                }
            } else {
                nw_path.push_back(path[i]);
            } 
        }
        
        path = "/" + nw_path;
        string command = "";
        string catalog = "/";
        for (int i = 1; i < int(path.length()); ++i) {
            command.push_back(path[i]);
            if (path[i] == '/') {
                command.pop_back();
                update(catalog, command);
            }
        }
        update(catalog, command);

        if (catalog[0] == '/') {
            catalog = catalog.substr(1, catalog.length());
        }
        return pref + catalog;
    }
}
