// Room: /d/shaolin/cjlou1.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "�ؾ����¥");
	set("long", @LONG
ǧ������������ִ��ԭ����֮ţ�����Դ�Ħ�������£�����
�˲ı����������в��ٸ�ɮ�������棬�㼯�����ճ���������
��������ʮ�����ա����־����������ڴˡ���¥���濪����ȷ��
ͨ�硣�м����������Ŵ���ܡ���������а������Թ��Ķ�����
λ��ɮ��ִ�������ڱ�Ŀ��˼��
LONG );
	set("exits", ([
                "down" : __DIR__"cjlou",
	]));
	set("objects",([
		CLASS_D("shaolin") + "/hui-zhen" : 1,
		"/clone/book/yijinjing" : 1,
		"/clone/book/wuji1" : 1,
		"/clone/book/wuji2" : 1,
		"/clone/book/wuji3" : 1,
	]));
//	set("no_clean_up", 0);
	setup();
}

int valid_leave(object me, string dir)
{
	object ob;

	if (!present("yijin-jing",this_object()) )
		return notify_fail("����֮���׽������, �����ܾ����أ�\n");
        if( present("yijin-jing", me))
                return notify_fail("����֮���׽������, �����ܾ����أ�\n");
	if ( present("huizhen zunzhe", environment(me)) )
	if ( present("shaolin-wuji", me)
	||   objectp(ob = present("corpse", me)) && present("shaolin-wuji", ob) )
	{
		if (dir == "down" )
		{
			return notify_fail("����˵��: �书�ؼ�ֻ���ڲؾ�������ϰ������Я����� !\n");
		}
	}
	return ::valid_leave(me, dir);
}

void init()
{
        add_action("do_ansuan","ansuan");
        add_action("do_give","give");
        add_action("do_put","put");
        add_action("do_disc", ({"sell","pawn","dang","buy","list","shu","check","value","gujia","redeem"}));
//	add_action("do_get","get");
}
int do_ansuan(string arg)
{
        write(this_player()->query("name")+"�������ô��𾭣������ﲻ�������������ˣ�\n");
        return 1;
}
int do_give(string arg)
{
        write(this_player()->query("name")+"���������ߣ�\n");
        return 1;
}
int do_put(string arg)
{
        write(this_player()->query("name")+"������Ķ����벻Ҫ�ŵ���ȥ��\n");
        return 1;
}
int do_get(string arg)
{
       object ob = present(arg, this_object());
       if( objectp(ob) && ob->is_character() ) {
	write(this_player()->query("name")+"���������ﺦ�ˡ�\n");
	return 1;
        }
        return 0;
}

int do_disc(string arg)
{
write("�����ʲô?\n");
return 1;
}
