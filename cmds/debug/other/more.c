// cat.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string file;
	object ob;

	seteuid(geteuid(me));
	if (!arg) return notify_fail("指令格式 : more <档名>|<物件名> \n");
	file = resolve_path(me->query("cwd"), arg);
	if( file_size(file) < 0 ) {
		ob = present(arg, me);
		if( !ob ) ob = present(arg, environment(me));
		if( !ob ) return notify_fail("没有这个档案。\n");
		file = base_name(ob) + ".c";
	}
	me->start_more( read_file(file));
	return 1;
}

int help(object me)
{
write(@HELP
指令格式 : topten rich <物件名>
HELP
    );
    return 1;
}
