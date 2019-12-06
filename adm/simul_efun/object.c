// object.c

varargs int getoid(object ob)
{
	int id;

	if (!ob) ob = previous_object();
	sscanf(file_name(ob), "%*s#%d", id);
	return id;
}

// Get the owner of a file.  Used by log_error() in master.c.
string file_owner(string file)
{
    string dir,name,rest;

    if (file[0] != '/') {
        file = "/" + file;
    }
    if (sscanf(file, "/u/%s/%s/%s", dir, name, rest) == 3) {
        return name;
    }
    return 0;
}

// domain_file should return the domain associated with a given file.
string domain_file(string file)
{
        string domain;
        if( sscanf(file, "/d/%s/%*s", domain) )
                return domain;

        return ROOT_UID;
}

// creator_file should return the name of the creator of a specific file.
string creator_file(string file)
{
	string *path;

	path = explode(file, "/") - ({ 0 });
	switch(path[0]) {
		case "adm":
			if( file==SIMUL_EFUN_OB ) return "MudOS";
			else return ROOT_UID;
		case "cmds":
			return ROOT_UID;
		case "u":
			if( sizeof(path)>=4 ) return path[1];
		case "d":
		case "open":
		case "ftp":
			if( sizeof(path)>=3 ) return path[1];
		default:
			if( this_player(1) )
				return getuid(this_player(1));
			else
				return "MudOS";
	}
}

// author_file should return the name of the author of a specific file.
string author_file(string file)
{
	string name;

	if( sscanf(file, "/u/%s/%*s", name) )
		return name;
	return ROOT_UID;
}


varargs string at_domain(mixed who, int f)
{
        string domain;
        
        if( stringp(who) ) {
                domain = domain_file(who);
        } else if( objectp(who) ) {
                while( !who->is_room() ) {
                        who = environment(who);
                        if( !who ) return 0;
                }
                domain = domain_file(base_name(who));
        }
        if( domain == "npc" || domain == "obj" || domain == ROOT_UID )
                domain = "";
        if( !f ) return CHINESE_D->chinese(domain);
        return domain;
}

/*
void destruct(object ob)
{
        if (ob) {
                if( previous_object() ) ob->remove( geteuid(previous_object()) );
                else ob->remove(0);
        }
        efun::destruct(ob);
}
*/
/*
void destruct(object ob)
{
        if( objectp(ob) ){
                object vo = find_object(VOID_OB);
                if( !vo ) vo = load_object(VOID_OB);
                if( ob != vo ) ob->force_move_to_void();
        }
        efun::destruct(ob);
}
*/
