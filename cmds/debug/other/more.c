// cat.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string file;
	object ob;

	seteuid(geteuid(me));
	if (!arg) return notify_fail("ָ���ʽ : more <����>|<�����> \n");
	file = resolve_path(me->query("cwd"), arg);
	if( file_size(file) < 0 ) {
		ob = present(arg, me);
		if( !ob ) ob = present(arg, environment(me));
		if( !ob ) return notify_fail("û�����������\n");
		file = base_name(ob) + ".c";
	}
	me->start_more( read_file(file));
	return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ : topten rich <�����>
HELP
    );
    return 1;
}
