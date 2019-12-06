/* 
 * /adm/daemons/securityd.c
 * modify by byp@jyqxz 2000/09/07
 *
 * 保护一些文件不允许在游戏运行中编辑
 * 但为了应急提供 (superuser) 巫师等级
 * (superuser) 同时是监督者
*/

#include <login.h>

private mapping wiz_status;

private string *wiz_levels = ({
	"(player)",
	"(immortal)",
	"(apprentice)",
	"(wizard)",
	"(arch)",
	"(admin)",
	"(superuser)",
});

private mapping exclude_read = ([
	"adm"           : ({"(wizard)"}),
	"adm/daemons/"	: ({"(arch)"}),
	"adm/obj"	: ({"(arch)"}),
	"adm/etc"	: ({"(arch)"}),
	"adm/single"    : ({"(arch)"}),
	"include"	: ({"(immortal)"}),
	"feature"	: ({"(immortal)"}),
	"inherit"	: ({"(immortal)"}),
	"cmds"          : ({"(immortal)"}),
	"cmds/adm"	: ({"(arch)"}),
	"cmds/arch"	: ({"(wizard)"}),
	"cmds/wiz"	: ({"(apprentice)"}),
	"data"          : ({"(wizard)"}),
	"data/user"	: ({"(arch)"}),
	"backup"        : ({"(admin)"}),
	"kungfu"        : ({"(immortal)"}),
	"quest"         : ({"(immortal)"}),
	"clone"	        : ({"(immortal)"}),
	"log"           : ({"(wizard)"}),
	"d"		: ({"(immortal)"}),
	"u"		: ({"(immortal)"}),
	"open"		: ({"(immortal)"}),
	"ftp"		: ({"(immortal)"}),
	"adm/daemons/securityd.c"     : ({"arch"}),
	"adm/daemons/commandd.c"      : ({"arch"}),
	"cmds/arch/promote.c"         : ({"arch"}),
	"feature/command.c"           : ({"arch"}),
	"include/command.h"           : ({"arch"}),
]);

private mapping exclude_write = ([
	"adm"		: ({ "(arch)" }),
        "adm/obj"	: ({ "(admin)"}),
        "adm/simul_efun": ({ "(arch)"}),
	"backup"        : ({ "(admin)"}),
	"feature"	: ({ "(arch)" }),
	"include"       : ({ "(arch)" }),
	"data/login"    : ({ "(admin)"}),
	"data/user"     : ({ "(admin)"}),
	"log"		: ({ "(admin)"}),
	"cmds"		: ({ "(arch)" }),
	"include/runtime_config.h"      : ({"admin"}),
	"include/globals.h"             : ({"arch"}),
	"include/dbase.h"               : ({"arch"}),
	"include/origin.h"              : ({"arch"}),
	"include/daemons.h"             : ({"arch"}),
	"feature/treemap.c"             : ({"admin"}),
	"feature/dbase.c"               : ({"admin"}),
	"feature/save.c"                : ({"admin"}),
]);

private mapping trusted_write = ([
	"/":          ({ "Root", "(admin)"}),
	"u"		: ({ "(arch)"}),
	"open"		: ({ "(wizard)"}),
        "d"             : ({ "(arch)"}),
        "kungfu"        : ({ "(arch)"}),
]);

void create()
{
	string *wizlist, wiz_name, wiz_level;
	int i;

	wizlist = explode(read_file(WIZLIST), "\n");
	wiz_status = allocate_mapping(sizeof(wizlist));
	for(i=0; i<sizeof(wizlist); i++) {
	if( wizlist[i][0]=='#' 
	|| sscanf(wizlist[i], "%s %s", wiz_name, wiz_level)!=2 ) continue;
		wiz_status[wiz_name] = wiz_level;
	}
}

string *query_wizlist() { return keys(wiz_status); }

//通过等级查状态
string query_wiz_status(int i) { return wiz_levels[i]; }

//通过状态查等级 -1 为错误
int query_wiz_level(string str) { return member_array(str, wiz_levels); }

//因旧程序兼容问题，暂时保留该函数。应该用 query_wiz_status() 代替
string wizlevel(int i) { return wiz_levels[i]; }

string get_status(mixed ob)
{
	string euid;
	
	if( objectp(ob) ) {
		euid = geteuid(ob);
		if( !euid ) euid = getuid(ob);
	}
	else if( stringp(ob) ) euid = ob;

	if (!mapp(wiz_status)) return "(player)";
	if( !undefinedp(wiz_status[euid]) ) return wiz_status[euid];
	else if( member_array(euid, wiz_levels)!=-1 ) return euid;
	return "(player)";
}

int get_wiz_level(object ob)
{
	return member_array(get_status(ob), wiz_levels);
}

int set_status(mixed ob, string status)
{
	string uid, *wiz, wizlist;
	int i;

	if( geteuid(previous_object())!= ROOT_UID ) return 0;

        if(previous_object() != find_object("/cmds/arch/promote")) return 0;
        
        if(clonep(previous_object())) return 0;
        
	if( userp(ob) )	uid = getuid(ob);
	else if(stringp(ob)) uid = ob;
	else return 0;
	
	if( member_array(status, wiz_levels) == -1 )
	        error("->error message: Invalid argument type of wizard levels.\n");
	
	if( status == "(player)" )
		map_delete(wiz_status, uid);
	else
		wiz_status[uid] = status;
	wiz = keys(wiz_status);
	for(wizlist = "", i=0; i<sizeof(wiz); i++)
		wizlist += wiz[i] + " " + wiz_status[wiz[i]] + "\n";
	rm(WIZLIST);
	write_file(WIZLIST, wizlist);

	log_file( "static/promotion", capitalize(uid)
	 + " become a " + status + " on " + ctime(time()) + "\n" );
	return 1;
}

string *get_wizlist() { return keys(wiz_status); }

int valid_read(string file, mixed user, string func)
{
	string euid, status, *path, dir;
	int i, j;

	if (this_player()) user = this_player();
	if( !objectp(user) )
		error("->valid_read: Invalid argument type of user.\n");
/* swapped out by atu
	if (	func != "read_file" &&
		func != "read_bytes" &&
		func != "file_size" &&
		func != "get_dir" &&
		func != "stat" &&
		func != "tail" &&
		func != "ed_start"
	) return 1;
*/
	// 允许对指定目录下的文件进行restore()操作 ..atu
	if( func=="restore_object" ) {
		if(sscanf(base_name(user), "/obj/%*s")
		   || sscanf(file, "/data/%*s")
		   || file == (string)user->query_save_file()+".o"  )
                        return 1;
		//允许无条件读取board数据
		if( sscanf(file,"/data/board/%*s"))
			return 1;
	}

	euid = geteuid(user);
	if( !euid || euid == ROOT_UID) return 1;
	if( sscanf(file, "/u/" + euid + "/%*s") ) return 1;

	status = get_status(user);
	path = explode(file, "/");

	for(i=sizeof(path)-1; i>=0; i--) {
		dir = implode(path[0..i], "/");
		if( undefinedp(exclude_read[dir]) ) continue;
		if( member_array(euid, exclude_read[dir])!=-1 ) return 0;
		if( sizeof(exclude_read[dir]) > 0 )
		for(j=0;j<sizeof(exclude_read[dir]);j++) {
			if( wiz_level(status) > 0 )
				if( wiz_level(status) < wiz_level(exclude_read[dir][j])+1 )
					return 0;
		}
	}
	return 1;
}

int valid_write(string file, mixed user, string func)
{
	string euid, status, *path, dir;
	int i, j;

	if( !objectp(user) )
		error("->valid_write: Invalid argument type of user.\n");
//特殊写部分
	if( func=="save_object" ) {
		if( sscanf(base_name(user), "/clone/%*s")
		&& sscanf(file, "/data/%*s")
                && (file == (string)user->query_save_file()+ __SAVE_EXTENSION__) )
			return 1;

            if( sscanf(base_name(user), "/d/taohuacun/obj/%*s")
                && sscanf(file, "/data/playerhomes/%*s")
                && (file == (string)user->query_save_file()+ __SAVE_EXTENSION__) )
                        return 1;

	}

	if( sscanf(file, LOG_DIR + "%*s") && func=="write_file" ) return 1;

	euid = geteuid(user);
	if( !euid ) return 0;
	if( euid == ROOT_UID ) return 1;
	if( sscanf(file, "/u/" + euid + "/%*s") ) return 1;
//特殊写 end
	status = get_status(user);
	path = explode(file, "/");

// 检查是否拒绝读
	for(i=sizeof(path)-1; i>=0; i--) {
		dir = implode(path[0..i], "/");
		if( undefinedp(exclude_read[dir]) ) continue;
		if( member_array(euid, exclude_read[dir])!=-1 ) return 0;
		if( sizeof(exclude_read[dir]) > 0 )
		for(j=0;j<sizeof(exclude_read[dir]);j++) {
			if( wiz_level(status) > 0 )
				if( wiz_level(status) < wiz_level(exclude_read[dir][j])+1 )
					return 0;
		}
	}

// 检查是否拒绝写
	for(i=sizeof(path)-1; i>=0; i--) {
		dir = implode(path[0..i], "/");
		if( undefinedp(exclude_write[dir]) ) continue;
		if( member_array(euid, exclude_write[dir])!=-1 ) return 0;
		if( sizeof(exclude_write[dir]) > 0 )
		for(j=0;j<sizeof(exclude_write[dir]);j++) {
			if( wiz_level(status) > 0 )
				if( wiz_level(status) < wiz_level(exclude_write[dir][j])+1 )
					return 0;
		}
	}

// 检查是否允许写根目录
	if( member_array(euid, trusted_write["/"])!=-1 ) return 1;
	//if( member_array(status, trusted_write["/"])!=-1 ) return 1;
	for(j=0;j<sizeof(trusted_write["/"]);j++) {
			if( wiz_level(status) > 0 )
				if( wiz_level(status) >= wiz_level(trusted_write["/"][j]) )
					return 1;
	}
		
	
// 检查是否允许写
	for(i=sizeof(path)-1; i>=0; i--) {
		dir = implode(path[0..i], "/");
		if( undefinedp(trusted_write[dir]) ) continue;
                if( member_array(euid, trusted_write[dir])!=-1 ) return 1;
		if( sizeof(trusted_write[dir]) > 0 )
		for(j=0;j<sizeof(trusted_write[dir]);j++) {
			if( wiz_level(status) > 0 )
				if( wiz_level(status) >= wiz_level(trusted_write[dir][j]) )
					return 1;
		}
	}

	log_file("FILES", sprintf("%s(%s) write attempt on %s failed.\n", geteuid(user), wizhood(user), file));
	return 0;
}

int valid_seteuid( object ob, string uid )
{
	if( uid==0 ) return 1;
	if( uid==getuid(ob) ) return 1;
	if( getuid(ob)==ROOT_UID ) return 1;
	if( sscanf(file_name(ob), "/adm/%*s") ) return 1;
	if( wiz_status[uid] != "(admin)"
	&&	wiz_status[getuid(ob)] == "(admin)" )
		return 1;
	return 0;
}
